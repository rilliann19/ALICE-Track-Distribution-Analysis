#include <TFile.h>
#include <TH2D.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <cmath>

struct Chip {
    int layer, stave, localID, globalID;
    double phi, eta;
};

std::vector<Chip> LoadChipGeometry(const std::string& filename) {
    std::vector<Chip> chips;
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "[ERROR] Could not open geometry file!" << std::endl;
        return chips;
    }

    int layer, stave, localID, globalID;
    double phi, eta;
    while (infile >> layer >> stave >> localID >> globalID >> phi >> eta) {
        chips.push_back({layer, stave, localID, globalID, phi, eta});
    }

    std::cout << "[INFO] Loaded " << chips.size() << " chips from geometry." << std::endl;
    return chips;
}

int FindClosestChip(const std::vector<Chip>& chips, double phi, double eta) {
    double minDist = 1e9;
    int closestID = -1;
    for (const auto& chip : chips) {
        double dPhi = chip.phi - phi;
        double dEta = chip.eta - eta;
        double dist = std::sqrt(dPhi * dPhi + dEta * dEta);
        if (dist < minDist) {
            minDist = dist;
            closestID = chip.globalID;
        }
    }
    return closestID;
}

// Updated to restrict outlier detection to |η| < 1.35
std::vector<std::tuple<int, double>> DetectOutliers(TH1D* reference, TH1D* single, double threshold) {
    std::vector<std::tuple<int, double>> outliers;
    int nBins = reference->GetNbinsX();
    for (int i = 1; i <= nBins; ++i) {
        double eta = single->GetXaxis()->GetBinCenter(i);
        if (std::abs(eta) > 1.35) continue;  // Skip η outside the allowed range

        double refVal = reference->GetBinContent(i);
        double singleVal = single->GetBinContent(i);
        if (refVal == 0) continue;

        double dev = std::abs(singleVal - refVal) / refVal;
        if (dev > threshold)
            outliers.push_back(std::make_tuple(i, dev));
    }
    return outliers;
}

// Updated analyzeALPIDE function to accept threshold as a parameter
void analyzeALPIDE(int runNumber, long long timeStamp, double threshold = 0.1) {  // Added threshold as input parameter
    gStyle->SetOptStat(0); // Remove status box

    // Load chip geometry
    std::vector<Chip> chips = LoadChipGeometry("ChipGeometry.txt");
    if (chips.empty()) return;

    TFile* file = TFile::Open("fout_mw.root");
    if (!file || file->IsZombie()) {
        std::cerr << "[ERROR] Could not open file!" << std::endl;
        return;
    }

    // Use runNumber and timeStamp to construct the histogram name
    std::string histName = Form("run%d_AngularDistribution_%lld", runNumber, timeStamp);
    auto* hAngular = (TH2D*)file->Get(histName.c_str());
    if (!hAngular) {
        std::cerr << "[ERROR] Histogram not found!" << std::endl;
        return;
    }

    // Projection of the histogram: φ is on X-axis, η is on Y-axis (swapped)
    TH1D* reference = hAngular->ProjectionX("ref_phi");
    reference->Scale(1.0 / reference->Integral());

    int nEtaBins = hAngular->GetNbinsY();  // η is on the Y-axis now
    for (int i = 1; i <= nEtaBins; ++i) {
        double eta = hAngular->GetYaxis()->GetBinCenter(i);

        // Project along X-axis for the slice at the current eta
        TH1D* single = hAngular->ProjectionX(Form("phi_eta_%d", i), i, i);
        single->Scale(1.0 / single->Integral());

        // Detect outliers
        auto outliers = DetectOutliers(reference, single, threshold);  // Use the threshold parameter

        // If no outliers are detected, skip the plot creation
        if (outliers.empty()) {
            continue;
        }

        // Create a canvas to plot the results
        TCanvas* c = new TCanvas(Form("c_%d", i), Form("Eta %.2f", eta), 800, 600);

        // Set up color for the reference and single histograms
        reference->SetLineColor(kGreen+2);
        single->SetLineColor(kBlue);

        // Manually swap axes for better visualization
        reference->GetXaxis()->SetTitle("#eta");
        reference->GetYaxis()->SetTitle("#phi [rad]");
        reference->SetTitle(Form("#eta = %.2f; #eta; #phi [rad]", eta));

        reference->Draw("HIST");
        single->Draw("HIST SAME");

        // Set Y-axis range from 0 to 0.045
        reference->GetYaxis()->SetRangeUser(0, 0.045);
        single->GetYaxis()->SetRangeUser(0, 0.045);

        TGraph* g = new TGraph();
        g->SetMarkerStyle(20);
        g->SetMarkerColor(kRed);
        for (auto& o : outliers) {
            int bin = std::get<0>(o);
            double phi = single->GetXaxis()->GetBinCenter(bin);
            double val = single->GetBinContent(bin);

            // Find chip with closest (phi, eta)
            int chipID = FindClosestChip(chips, phi, eta);
            std::cout << "[OUTLIER] φ = " << phi << ", η = " << eta
                      << " → Closest chip ID: " << chipID << std::endl;

            g->SetPoint(g->GetN(), phi, val);
        }
        g->Draw("P SAME");

        // Reposition legend to bottom left corner
        TLegend* leg = new TLegend(0.2, 0.2, 0.4, 0.4); // bottom left
        leg->AddEntry(reference, "Reference (avg. #phi)", "l");
        leg->AddEntry(single, "Phi slice at #eta", "l");
        leg->AddEntry(g, "Outliers", "p");
        leg->Draw();

        // Save plot
        c->SaveAs(Form("detection%d.pdf", i));
    }
}
