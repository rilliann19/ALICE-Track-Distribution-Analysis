rilliann@rkompani-1 ~ % root
   ------------------------------------------------------------------
  | Welcome to ROOT 6.32.06                        https://root.cern |
  | (c) 1995-2024, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for macosxarm64 on Sep 21 2024, 18:21:53                   |
  | From tags/6-32-06@6-32-06                                        |
  | With Apple clang version 15.0.0 (clang-1500.3.9.4)               |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0] TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root [1] if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [2]    std::cout << "Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [3]} else {
root (cont'ed, cancel with .@) [4]    std::cout << "File opened successfully!" << std::endl;
root (cont'ed, cancel with .@) [5]}
File opened successfully!
root [6] void CheckSlices() {
root (cont'ed, cancel with .@) [7]    // Open ROOT file
root (cont'ed, cancel with .@) [8]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [9]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [10]        std::cout << " Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [11]        return;
root (cont'ed, cancel with .@) [12]    }
root (cont'ed, cancel with .@) [13]
root (cont'ed, cancel with .@) [13]    // Load histogram
root (cont'ed, cancel with .@) [14]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [15]    if (!hist2D) {
root (cont'ed, cancel with .@) [16]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [17]        return;
root (cont'ed, cancel with .@) [18]    }
root (cont'ed, cancel with .@) [19]
root (cont'ed, cancel with .@) [19]    // Get X-axis range
root (cont'ed, cancel with .@) [20]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [21]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [22]    int nSlices = 12;
root (cont'ed, cancel with .@) [23]    double sliceWidth = (xMax - xMin) / nSlices;
root (cont'ed, cancel with .@) [24]
root (cont'ed, cancel with .@) [24]    std::cout << " Histogram found! X-axis: " << xMin << " to " << xMax << " radians" << std::endl;
root (cont'ed, cancel with .@) [25]
root (cont'ed, cancel with .@) [25]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [26]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [27]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [28]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [29]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [30]
root (cont'ed, cancel with .@) [30]        std::cout << "Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
root (cont'ed, cancel with .@) [31]                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [32]    }
root (cont'ed, cancel with .@) [33]}
root [34] TIter next(f1->GetListOfKeys());
ROOT_prompt_34:1:1: warning: 'next' shadows a declaration with the same name in the 'std' namespace; use '::next' to reference this declaration
TIter next(f1->GetListOfKeys());
^
root [35] TKey *key;
root [36] while ((key = (TKey*)next())) {
root (cont'ed, cancel with .@) [37]    std::cout << "Found: " << key->GetName() << ", Type: " << key->GetClassName() << std::endl;
root (cont'ed, cancel with .@) [38]}
ROOT_prompt_36:1:22: error: reference to 'next' is ambiguous
while ((key = (TKey*)next())) {
                     ^
ROOT_prompt_34:1:7: note: candidate found by name lookup is 'next'
TIter next(f1->GetListOfKeys());
      ^
/Library/Developer/CommandLineTools/SDKs/MacOSX14.sdk/usr/include/c++/v1/__iterator/next.h:30:5: note: candidate found by name lookup is 'std::next'
    next(_InputIter __x, typename iterator_traits<_InputIter>::difference_type __n = 1) {
    ^
root [39] TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root [40] if (!hist2D) {
root (cont'ed, cancel with .@) [41]    std::cout << "Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [42]} else {
root (cont'ed, cancel with .@) [43]    std::cout << "Histogram loaded successfully!" << std::endl;
root (cont'ed, cancel with .@) [44]    hist2D->Draw("COLZ");  // Show the histogram
root (cont'ed, cancel with .@) [45]}
Histogram loaded successfully!
Info in <TCanvas::MakeDefCanvas>:  created default TCanvas with name c1
root [46] std::cout << "Starting phi slice analysis..." << std::endl;
Starting phi slice analysis...
root [47] for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [48]    std::cout << "Processing slice " << i << "..." << std::endl;
root (cont'ed, cancel with .@) [49]    int binMin = hist2D->GetXaxis()->FindBin(xMin + i * sliceWidth);
root (cont'ed, cancel with .@) [50]    int binMax = hist2D->GetXaxis()->FindBin(xMin + (i + 1) * sliceWidth);
root (cont'ed, cancel with .@) [51]    
root (cont'ed, cancel with .@) [51]    TH1D *phiProj = hist2D->ProjectionY(Form("phiProj_%d", i), binMin, binMax);
root (cont'ed, cancel with .@) [52]    if (!phiProj) {
root (cont'ed, cancel with .@) [53]        std::cout << "Error: Could not create projection for slice " << i << std::endl;
root (cont'ed, cancel with .@) [54]        continue;
root (cont'ed, cancel with .@) [55]    }
root (cont'ed, cancel with .@) [56]
root (cont'ed, cancel with .@) [56]    std::cout << "Phi Projection for slice " << i << " created successfully!" << std::endl;
root (cont'ed, cancel with .@) [57]    phiProj->Draw();
root (cont'ed, cancel with .@) [58]}

 *** Break *** segmentation violation
[/usr/lib/system/libsystem_platform.dylib] _sigtramp (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenFunction::EmitScalarConversion(llvm::Value*, clang::QualType, clang::QualType, clang::SourceLocation) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenFunction::EmitScalarConversion(llvm::Value*, clang::QualType, clang::QualType, clang::SourceLocation) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenFunction::EvaluateExprAsBool(clang::Expr const*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenFunction::EmitForStmt(clang::ForStmt const&, llvm::ArrayRef<clang::Attr const*>) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenFunction::EmitCompoundStmtWithoutScope(clang::CompoundStmt const&, bool, clang::CodeGen::AggValueSlot) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenFunction::GenerateCode(clang::GlobalDecl, llvm::Function*, clang::CodeGen::CGFunctionInfo const&) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenModule::EmitGlobalFunctionDefinition(clang::GlobalDecl, llvm::GlobalValue*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenModule::EmitGlobalDefinition(clang::GlobalDecl, llvm::GlobalValue*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenModule::EmitGlobal(clang::GlobalDecl) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGen::CodeGenModule::EmitTopLevelDecl(clang::Decl*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::CodeGeneratorImpl::HandleTopLevelDecl(clang::DeclGroupRef) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] clang::MultiplexConsumer::HandleTopLevelDecl(clang::DeclGroupRef) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] cling::DeclCollector::HandleTopLevelDecl(clang::DeclGroupRef) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] cling::IncrementalParser::ParseInternal(llvm::StringRef) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] cling::IncrementalParser::Compile(llvm::StringRef, cling::CompilationOptions const&) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] cling::Interpreter::EvaluateInternal(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, cling::CompilationOptions, cling::Value*, cling::Transaction**, unsigned long) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] cling::Interpreter::process(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, cling::Value*, cling::Transaction**, bool) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] cling::MetaProcessor::process(llvm::StringRef, cling::Interpreter::CompilationResult&, cling::Value*, bool) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] HandleInterpreterException(cling::MetaProcessor*, char const*, cling::Interpreter::CompilationResult&, cling::Value*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCling.so] TCling::ProcessLine(char const*, TInterpreter::EErrorCode*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libRint.so] TRint::ProcessLineNr(char const*, char const*, int*) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libRint.so] TRint::HandleTermInput() (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCore.so] TUnixSystem::CheckDescriptors() (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCore.so] TMacOSXSystem::DispatchOneEvent(bool) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCore.so] TSystem::InnerLoop() (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCore.so] TSystem::Run() (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libCore.so] TApplication::Run(bool) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/lib/root/libRint.so] TRint::Run(bool) (no debug info)
[/opt/homebrew/Cellar/root/6.32.06/bin/root.exe] main (no debug info)
[/usr/lib/dyld] start (no debug info)
Root > void CheckSlices() {
root (cont'ed, cancel with .@) [59]    // Open file
root (cont'ed, cancel with .@) [60]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [61]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [62]        std::cout << "Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [63]        return;
root (cont'ed, cancel with .@) [64]    }
root (cont'ed, cancel with .@) [65]
root (cont'ed, cancel with .@) [65]    // Load histogram
root (cont'ed, cancel with .@) [66]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [67]    if (!hist2D) {
root (cont'ed, cancel with .@) [68]        std::cout << "Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [69]        return;
root (cont'ed, cancel with .@) [70]    }
root (cont'ed, cancel with .@) [71]
root (cont'ed, cancel with .@) [71]    // Define slices
root (cont'ed, cancel with .@) [72]    int nSlices = 12;
root (cont'ed, cancel with .@) [73]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [74]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [75]    double sliceWidth = (xMax - xMin) / nSlices;
root (cont'ed, cancel with .@) [76]
root (cont'ed, cancel with .@) [76]    std::cout << "Histogram X-axis range: " << xMin << " to " << xMax << " radians" << std::endl;
root (cont'ed, cancel with .@) [77]
root (cont'ed, cancel with .@) [77]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [78]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [79]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [80]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [81]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [82]
root (cont'ed, cancel with .@) [82]        std::cout << "Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd << "]" 
root (cont'ed, cancel with .@) [83]                  << " | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [84]    }
root (cont'ed, cancel with .@) [85]}
root [86] void CheckSlices() {
root (cont'ed, cancel with .@) [87]    // Open ROOT file
root (cont'ed, cancel with .@) [88]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [89]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [90]        std::cout << " Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [91]        return;
root (cont'ed, cancel with .@) [92]    }
root (cont'ed, cancel with .@) [93]
root (cont'ed, cancel with .@) [93]    // Load histogram
root (cont'ed, cancel with .@) [94]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [95]    if (!hist2D) {
root (cont'ed, cancel with .@) [96]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [97]        return;
root (cont'ed, cancel with .@) [98]    }
root (cont'ed, cancel with .@) [99]
    // Get X-axis range
    double xMin = hist2D->GetXaxis()->GetXmin();
    double xMax = hist2D->GetXaxis()->GetXmax();
    int nSlices = 12;
    double sliceWidth = (xMax - xMin) / nSlices;

    std::cout << "✅ Histogram found! X-axis: " << xMin << " to " << xMax << " radians" << std::endl;

    for (int i = 0; i < nSlices; i++) {
        double sliceStart = xMin + i * sliceWidth;
        double sliceEnd = sliceStart + sliceWidth;
        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);

        std::cout << "Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
    }
}
root (cont'ed, cancel with .@) [99]    // Get X-axis range
root (cont'ed, cancel with .@) [100]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [101]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [102]    int nSlices = 12;
root (cont'ed, cancel with .@) [103]    double sliceWidth = (xMax - xMin) / nSlices;
root (cont'ed, cancel with .@) [104]
root (cont'ed, cancel with .@) [104]    std::cout << " Histogram found! X-axis: " << xMin << " to " << xMax << " radians" << std::endl;
root (cont'ed, cancel with .@) [105]
root (cont'ed, cancel with .@) [105]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [106]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [107]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [108]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [109]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [110]
root (cont'ed, cancel with .@) [110]        std::cout << "Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
root (cont'ed, cancel with .@) [111]                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [112]    }
root (cont'ed, cancel with .@) [113]}
root [114] void DebugHistogram() {
root (cont'ed, cancel with .@) [115]    // Open ROOT file
root (cont'ed, cancel with .@) [116]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [117]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [118]        std::cout << " Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [119]        return;
root (cont'ed, cancel with .@) [120]    }
root (cont'ed, cancel with .@) [121]
root (cont'ed, cancel with .@) [121]    // Load histogram
root (cont'ed, cancel with .@) [122]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [123]    if (!hist2D) {
root (cont'ed, cancel with .@) [124]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [125]        return;
root (cont'ed, cancel with .@) [126]    }
root (cont'ed, cancel with .@) [127]
root (cont'ed, cancel with .@) [127]    // Get X-axis details
root (cont'ed, cancel with .@) [128]    int nBinsX = hist2D->GetNbinsX();
root (cont'ed, cancel with .@) [129]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [130]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [131]
root (cont'ed, cancel with .@) [131]    std::cout << " Histogram found!" << std::endl;
root (cont'ed, cancel with .@) [132]    std::cout << "X-axis range: " << xMin << " to " << xMax << " radians" << std::endl;
root (cont'ed, cancel with .@) [133]    std::cout << "Number of bins on X-axis: " << nBinsX << std::endl;
root (cont'ed, cancel with .@) [134]
root (cont'ed, cancel with .@) [134]    // Check the bin content for first few bins
root (cont'ed, cancel with .@) [135]    std::cout << " Checking first 10 X-bins:" << std::endl;
root (cont'ed, cancel with .@) [136]    for (int i = 1; i <= 10; i++) {
root (cont'ed, cancel with .@) [137]        std::cout << "Bin " << i << " (X = " << hist2D->GetXaxis()->GetBinCenter(i) 
root (cont'ed, cancel with .@) [138]                  << ") -> Content: " << hist2D->GetBinContent(i, 1) << std::endl;
root (cont'ed, cancel with .@) [139]    }
root (cont'ed, cancel with .@) [140]}
root [141] std::cout << "ROOT is running!" << std::endl;
root [142] root -l
root [143] .q
rilliann@rkompani-1 ~ % root
   ------------------------------------------------------------------
  | Welcome to ROOT 6.32.06                        https://root.cern |
  | (c) 1995-2024, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for macosxarm64 on Sep 21 2024, 18:21:53                   |
  | From tags/6-32-06@6-32-06                                        |
  | With Apple clang version 15.0.0 (clang-1500.3.9.4)               |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0] std::cout << "ROOT is running!" << std::endl;
ROOT is running!
root [1] TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root [2] void DebugHistogram(); // Declare function
root [3] DebugHistogram();      // Call function
input_line_14:2:3: error: use of undeclared identifier 'DebugHistogram'
 (DebugHistogram())
  ^
root [4] void DebugHistogram() {
root (cont'ed, cancel with .@) [5]    // Open ROOT file
root (cont'ed, cancel with .@) [6]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [7]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [8]        std::cout << " Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [9]        return;
root (cont'ed, cancel with .@) [10]    }
root (cont'ed, cancel with .@) [11]
root (cont'ed, cancel with .@) [11]    // Load histogram
root (cont'ed, cancel with .@) [12]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [13]    if (!hist2D) {
root (cont'ed, cancel with .@) [14]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [15]        return;
root (cont'ed, cancel with .@) [16]    }
root (cont'ed, cancel with .@) [17]
root (cont'ed, cancel with .@) [17]    // Get X-axis details
root (cont'ed, cancel with .@) [18]    int nBinsX = hist2D->GetNbinsX();
root (cont'ed, cancel with .@) [19]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [20]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [21]
root (cont'ed, cancel with .@) [21]    std::cout << " Histogram found!" << std::endl;
root (cont'ed, cancel with .@) [22]    std::cout << "X-axis range: " << xMin << " to " << xMax << " radians" << std::endl;
root (cont'ed, cancel with .@) [23]    std::cout << "Number of bins on X-axis: " << nBinsX << std::endl;
root (cont'ed, cancel with .@) [24]
root (cont'ed, cancel with .@) [24]    // Check the bin content for first few bins
root (cont'ed, cancel with .@) [25]    std::cout << " Checking first 10 X-bins:" << std::endl;
root (cont'ed, cancel with .@) [26]    for (int i = 1; i <= 10; i++) {
root (cont'ed, cancel with .@) [27]        std::cout << "Bin " << i << " (X = " << hist2D->GetXaxis()->GetBinCenter(i) 
root (cont'ed, cancel with .@) [28]                  << ") -> Content: " << hist2D->GetBinContent(i, 1) << std::endl;
root (cont'ed, cancel with .@) [29]    }
root (cont'ed, cancel with .@) [30]}
root [31] DebugHistogram();
 Histogram found!
X-axis range: -2 to 2 radians
Number of bins on X-axis: 40
 Checking first 10 X-bins:
Bin 1 (X = -1.95) -> Content: 0
Bin 2 (X = -1.85) -> Content: 5.229e-06
Bin 3 (X = -1.75) -> Content: 0.000233696
Bin 4 (X = -1.65) -> Content: 0.00123927
Bin 5 (X = -1.55) -> Content: 0.00313579
Bin 6 (X = -1.45) -> Content: 0.005482
Bin 7 (X = -1.35) -> Content: 0.00788051
Bin 8 (X = -1.25) -> Content: 0.0096998
Bin 9 (X = -1.15) -> Content: 0.0109608
Bin 10 (X = -1.05) -> Content: 0.0118582
root [32] void AnalyzePhiSlices() {
root (cont'ed, cancel with .@) [33]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [34]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [35]        std::cout << " Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [36]        return;
root (cont'ed, cancel with .@) [37]    }
root (cont'ed, cancel with .@) [38]
root (cont'ed, cancel with .@) [38]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [39]    if (!hist2D) {
root (cont'ed, cancel with .@) [40]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [41]        return;
root (cont'ed, cancel with .@) [42]    }
root (cont'ed, cancel with .@) [43]
root (cont'ed, cancel with .@) [43]    int nSlices = 12;  // We divide into 12 slices (0.5 radians each)
root (cont'ed, cancel with .@) [44]    double xMin = hist2D->GetXaxis()->GetXmin(); // -2 radians
root (cont'ed, cancel with .@) [45]    double xMax = hist2D->GetXaxis()->GetXmax(); // 2 radians
root (cont'ed, cancel with .@) [46]    double sliceWidth = 0.5; // Each slice is 0.5 radians
root (cont'ed, cancel with .@) [47]
root (cont'ed, cancel with .@) [47]    std::cout << " Histogram loaded! X-axis range: " << xMin << " to " << xMax << " radians" << std::endl;
root (cont'ed, cancel with .@) [48]
root (cont'ed, cancel with .@) [48]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [49]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [50]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [51]
root (cont'ed, cancel with .@) [51]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [52]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [53]
root (cont'ed, cancel with .@) [53]        std::cout << " Processing Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
root (cont'ed, cancel with .@) [54]                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [55]
root (cont'ed, cancel with .@) [55]        // Create 1D projection
root (cont'ed, cancel with .@) [56]        TH1D *phiProj = hist2D->ProjectionY(Form("phiProj_%d", i), binMin, binMax);
root (cont'ed, cancel with .@) [57]
root (cont'ed, cancel with .@) [57]        if (!phiProj || phiProj->GetEntries() == 0) {
root (cont'ed, cancel with .@) [58]            std::cout << " Warning: Projection for slice " << i << " is EMPTY!" << std::endl;
root (cont'ed, cancel with .@) [59]            continue;
root (cont'ed, cancel with .@) [60]        }
root (cont'ed, cancel with .@) [61]
root (cont'ed, cancel with .@) [61]        std::cout << " Phi Projection for slice " << i << " created successfully!" << std::endl;
root (cont'ed, cancel with .@) [62]
root (cont'ed, cancel with .@) [62]        TCanvas *c = new TCanvas(Form("c%d", i), "Phi Projection", 800, 600);
root (cont'ed, cancel with .@) [63]        phiProj->SetLineColor(kBlue);
root (cont'ed, cancel with .@) [64]        phiProj->SetTitle(Form("Phi Projection (Slice %d); Phi; Tracks", i));
root (cont'ed, cancel with .@) [65]        phiProj->Draw();
root (cont'ed, cancel with .@) [66]        c->SaveAs(Form("Phi_Projection_Slice%d.png", i));
root (cont'ed, cancel with .@) [67]    }
root (cont'ed, cancel with .@) [68]}
root [69] void TestFunction() {
root (cont'ed, cancel with .@) [70]    std::cout << " Function is running!" << std::endl;
root (cont'ed, cancel with .@) [71]}
root [72] TestFunction();
 Function is running!
root [73] void CheckHistogram() {
root (cont'ed, cancel with .@) [74]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [75]    if (!f1 || f1->IsZombie()) {
root (cont'ed, cancel with .@) [76]        std::cout << " Error: Failed to open file!" << std::endl;
root (cont'ed, cancel with .@) [77]        return;
root (cont'ed, cancel with .@) [78]    }
root (cont'ed, cancel with .@) [79]
root (cont'ed, cancel with .@) [79]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [80]    if (!hist2D) {
root (cont'ed, cancel with .@) [81]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [82]        return;
root (cont'ed, cancel with .@) [83]    }
root (cont'ed, cancel with .@) [84]
root (cont'ed, cancel with .@) [84]    std::cout << " Histogram loaded successfully!" << std::endl;
root (cont'ed, cancel with .@) [85]    std::cout << "Number of bins in X: " << hist2D->GetNbinsX() << std::endl;
root (cont'ed, cancel with .@) [86]    std::cout << "X-axis range: " << hist2D->GetXaxis()->GetXmin() << " to " << hist2D->GetXaxis()->GetXmax() << std::endl;
root (cont'ed, cancel with .@) [87]}
root [88] CheckHistogram();
 Histogram loaded successfully!
Number of bins in X: 40
X-axis range: -2 to 2
root [89] void CheckSlices() {
root (cont'ed, cancel with .@) [90]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [91]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [92]
root (cont'ed, cancel with .@) [92]    if (!hist2D) {
root (cont'ed, cancel with .@) [93]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [94]        return;
root (cont'ed, cancel with .@) [95]    }
root (cont'ed, cancel with .@) [96]
root (cont'ed, cancel with .@) [96]    int nSlices = 12;
root (cont'ed, cancel with .@) [97]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [98]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [99]    double sliceWidth = 0.5;
root (cont'ed, cancel with .@) [100]
root (cont'ed, cancel with .@) [100]    std::cout << " Histogram loaded! Checking slices..." << std::endl;
root (cont'ed, cancel with .@) [101]
root (cont'ed, cancel with .@) [101]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [102]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [103]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [104]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [105]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [106]
root (cont'ed, cancel with .@) [106]        std::cout << " Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
root (cont'ed, cancel with .@) [107]                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [108]    }
root (cont'ed, cancel with .@) [109]}
root [110] CheckSlices();
 Histogram loaded! Checking slices...
 Slice 0: X range [-2, -1.5] | Bin range: [1, 6]
 Slice 1: X range [-1.5, -1] | Bin range: [6, 11]
 Slice 2: X range [-1, -0.5] | Bin range: [11, 16]
 Slice 3: X range [-0.5, 0] | Bin range: [16, 21]
 Slice 4: X range [0, 0.5] | Bin range: [21, 26]
 Slice 5: X range [0.5, 1] | Bin range: [26, 31]
 Slice 6: X range [1, 1.5] | Bin range: [31, 36]
 Slice 7: X range [1.5, 2] | Bin range: [36, 41]
 Slice 8: X range [2, 2.5] | Bin range: [41, 41]
 Slice 9: X range [2.5, 3] | Bin range: [41, 41]
 Slice 10: X range [3, 3.5] | Bin range: [41, 41]
 Slice 11: X range [3.5, 4] | Bin range: [41, 41]
root [111] void TestProjections() {
root (cont'ed, cancel with .@) [112]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [113]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [114]
root (cont'ed, cancel with .@) [114]    if (!hist2D) {
root (cont'ed, cancel with .@) [115]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [116]        return;
root (cont'ed, cancel with .@) [117]    }
root (cont'ed, cancel with .@) [118]
root (cont'ed, cancel with .@) [118]    int binMin = hist2D->GetXaxis()->FindBin(-2.0);
root (cont'ed, cancel with .@) [119]    int binMax = hist2D->GetXaxis()->FindBin(-1.5);
root (cont'ed, cancel with .@) [120]
root (cont'ed, cancel with .@) [120]    std::cout << "Extracting Projection from X bins " << binMin << " to " << binMax << std::endl;
root (cont'ed, cancel with .@) [121]
root (cont'ed, cancel with .@) [121]    TH1D *phiProj = hist2D->ProjectionY("testProjection", binMin, binMax);
root (cont'ed, cancel with .@) [122]    if (!phiProj || phiProj->GetEntries() == 0) {
root (cont'ed, cancel with .@) [123]        std::cout << " Warning: Projection is EMPTY!" << std::endl;
root (cont'ed, cancel with .@) [124]        return;
root (cont'ed, cancel with .@) [125]    }
root (cont'ed, cancel with .@) [126]
root (cont'ed, cancel with .@) [126]    std::cout << " Projection created successfully!" << std::endl;
root (cont'ed, cancel with .@) [127]
root (cont'ed, cancel with .@) [127]    TCanvas *c = new TCanvas("cTest", "Test Projection", 800, 600);
root (cont'ed, cancel with .@) [128]    phiProj->Draw();
root (cont'ed, cancel with .@) [129]}
root [130] TestProjections();
Extracting Projection from X bins 1 to 6
 Projection created successfully!
root [131] Info in <TCanvas::Print>: pdf file /Users/rilliann/1st_slice.pdf has been created
void GenerateAllPhiProjections() {
root (cont'ed, cancel with .@) [132]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [133]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [134]
root (cont'ed, cancel with .@) [134]    if (!hist2D) {
root (cont'ed, cancel with .@) [135]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [136]        return;
root (cont'ed, cancel with .@) [137]    }
root (cont'ed, cancel with .@) [138]
root (cont'ed, cancel with .@) [138]    int nSlices = 12;
root (cont'ed, cancel with .@) [139]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [140]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [141]    double sliceWidth = 0.5;
root (cont'ed, cancel with .@) [142]
root (cont'ed, cancel with .@) [142]    std::cout << " Generating projections for 12 slices..." << std::endl;
root (cont'ed, cancel with .@) [143]
root (cont'ed, cancel with .@) [143]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [144]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [145]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [146]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [147]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [148]
root (cont'ed, cancel with .@) [148]        std::cout << " Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
root (cont'ed, cancel with .@) [149]                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [150]
root (cont'ed, cancel with .@) [150]        TH1D *phiProj = hist2D->ProjectionY(Form("phiProj_%d", i), binMin, binMax);
root (cont'ed, cancel with .@) [151]        if (!phiProj || phiProj->GetEntries() == 0) {
root (cont'ed, cancel with .@) [152]            std::cout << " Warning: Projection for slice " << i << " is EMPTY!" << std::endl;
root (cont'ed, cancel with .@) [153]            continue;
root (cont'ed, cancel with .@) [154]        }
root (cont'ed, cancel with .@) [155]
root (cont'ed, cancel with .@) [155]        std::cout << " Phi Projection for slice " << i << " created successfully!" << std::endl;
root (cont'ed, cancel with .@) [156]
root (cont'ed, cancel with .@) [156]        TCanvas *c = new TCanvas(Form("c%d", i), "Phi Projection", 800, 600);
root (cont'ed, cancel with .@) [157]        phiProj->SetLineColor(kBlue);
root (cont'ed, cancel with .@) [158]        phiProj->SetTitle(Form("Phi Projection (Slice %d); Phi; Tracks", i));
root (cont'ed, cancel with .@) [159]        phiProj->Draw();
root (cont'ed, cancel with .@) [160]        c->SaveAs(Form("Phi_Projection_Slice%d.png", i));
root (cont'ed, cancel with .@) [161]    }
root (cont'ed, cancel with .@) [162]}
root [163] GenerateAllPhiProjections();
 Generating projections for 12 slices...
 Slice 0: X range [-2, -1.5] | Bin range: [1, 6]
 Phi Projection for slice 0 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice0.png has been created
 Slice 1: X range [-1.5, -1] | Bin range: [6, 11]
 Phi Projection for slice 1 created successfully!
Warning in <TCanvas::Constructor>: Deleting canvas with same name: c1
2025-02-07 16:04:57.429 root.exe[1506:34827] Fatal error: requested non-existing drawable 49
2025-02-07 16:04:57.429 root.exe[1506:34827] This window not found among allocated/deleted drawables
Info in <TCanvas::Print>: file Phi_Projection_Slice1.png has been created
 Slice 2: X range [-1, -0.5] | Bin range: [11, 16]
 Phi Projection for slice 2 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice2.png has been created
 Slice 3: X range [-0.5, 0] | Bin range: [16, 21]
 Phi Projection for slice 3 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice3.png has been created
 Slice 4: X range [0, 0.5] | Bin range: [21, 26]
 Phi Projection for slice 4 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice4.png has been created
 Slice 5: X range [0.5, 1] | Bin range: [26, 31]
 Phi Projection for slice 5 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice5.png has been created
 Slice 6: X range [1, 1.5] | Bin range: [31, 36]
 Phi Projection for slice 6 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice6.png has been created
 Slice 7: X range [1.5, 2] | Bin range: [36, 41]
 Warning: Projection for slice 7 is EMPTY!
 Slice 8: X range [2, 2.5] | Bin range: [41, 41]
 Warning: Projection for slice 8 is EMPTY!
 Slice 9: X range [2.5, 3] | Bin range: [41, 41]
 Warning: Projection for slice 9 is EMPTY!
 Slice 10: X range [3, 3.5] | Bin range: [41, 41]
 Warning: Projection for slice 10 is EMPTY!
 Slice 11: X range [3.5, 4] | Bin range: [41, 41]
 Warning: Projection for slice 11 is EMPTY!
root [164] Info in <TCanvas::Print>: pdf file /Users/rilliann/slice6.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/slice5.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/slice4.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/slice3.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/slice2.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/slice1.pdf has been created
void CalculatePhiAverages() {
root (cont'ed, cancel with .@) [165]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [166]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [167]        if (!phiProj) {
root (cont'ed, cancel with .@) [168]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [169]            continue;
root (cont'ed, cancel with .@) [170]        }
root (cont'ed, cancel with .@) [171]
root (cont'ed, cancel with .@) [171]        double sum = 0;
root (cont'ed, cancel with .@) [172]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [173]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [174]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [175]        }
root (cont'ed, cancel with .@) [176]        
root (cont'ed, cancel with .@) [176]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [177]        std::cout << " Slice " << i << ": Average phi track count = " << avg << std::endl;
root (cont'ed, cancel with .@) [178]    }
root (cont'ed, cancel with .@) [179]}
root [180] CalculatePhiAverages();
 Slice 0: Average phi track count = 0.0110525
 Slice 1: Average phi track count = 0.061804
 Slice 2: Average phi track count = 0.0800285
 Slice 3: Average phi track count = 0.0802306
 Slice 4: Average phi track count = 0.0792185
 Slice 5: Average phi track count = 0.0773075
 Slice 6: Average phi track count = 0.050062
 Slice 7: Average phi track count = 0.00484525
 Slice 8: Average phi track count = 0
 Slice 9: Average phi track count = 0
 Slice 10: Average phi track count = 0
 Slice 11: Average phi track count = 0
root [181] void IdentifyProblematicRegions() {
root (cont'ed, cancel with .@) [182]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [183]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [184]        if (!phiProj) {
root (cont'ed, cancel with .@) [185]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [186]            continue;
root (cont'ed, cancel with .@) [187]        }
root (cont'ed, cancel with .@) [188]
root (cont'ed, cancel with .@) [188]        double sum = 0;
root (cont'ed, cancel with .@) [189]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [190]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [191]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [192]        }
root (cont'ed, cancel with .@) [193]        
root (cont'ed, cancel with .@) [193]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [194]        std::cout << " Slice " << i << ": Average = " << avg << std::endl;
root (cont'ed, cancel with .@) [195]
root (cont'ed, cancel with .@) [195]        // Check each bin for deviations
root (cont'ed, cancel with .@) [196]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [197]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [198]            if (fabs(content - avg) > 0.1 * avg) {
root (cont'ed, cancel with .@) [199]                std::cout << " Deviation in Slice " << i << " at Phi bin " << bin 
root (cont'ed, cancel with .@) [200]                          << " (Value: " << content << " vs. Expected: " << avg << ")" << std::endl;
root (cont'ed, cancel with .@) [201]            }
root (cont'ed, cancel with .@) [202]        }
root (cont'ed, cancel with .@) [203]    }
root (cont'ed, cancel with .@) [204]}
root [205] IdentifyProblematicRegions();
 Slice 0: Average = 0.0110525
 Deviation in Slice 0 at Phi bin 30 (Value: 0.00984299 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 36 (Value: 0.0125005 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 41 (Value: 0.0121908 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 44 (Value: 0.0125009 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 46 (Value: 0.0122841 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 55 (Value: 0.00994073 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 60 (Value: 0.00900394 vs. Expected: 0.0110525)
 Slice 1: Average = 0.061804
 Slice 2: Average = 0.0800285
 Slice 3: Average = 0.0802306
 Slice 4: Average = 0.0792185
 Deviation in Slice 4 at Phi bin 24 (Value: 0.0896339 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 47 (Value: 0.0684388 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 48 (Value: 0.0689898 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 49 (Value: 0.065624 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 50 (Value: 0.06974 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 51 (Value: 0.0708477 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 56 (Value: 0.0886758 vs. Expected: 0.0792185)
 Slice 5: Average = 0.0773075
 Deviation in Slice 5 at Phi bin 35 (Value: 0.0872258 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 45 (Value: 0.0690172 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 47 (Value: 0.0611873 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 48 (Value: 0.0644909 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 49 (Value: 0.0624693 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 50 (Value: 0.0683736 vs. Expected: 0.0773075)
 Slice 6: Average = 0.050062
 Deviation in Slice 6 at Phi bin 23 (Value: 0.0445354 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 35 (Value: 0.0592595 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 46 (Value: 0.0567479 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 47 (Value: 0.0432225 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 48 (Value: 0.0398969 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 49 (Value: 0.0410127 vs. Expected: 0.050062)
 Slice 7: Average = 0.00484525
 Deviation in Slice 7 at Phi bin 1 (Value: 0.00417194 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 11 (Value: 0.00534565 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 30 (Value: 0.00401949 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 34 (Value: 0.0055544 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 36 (Value: 0.00547758 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 39 (Value: 0.00552665 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 41 (Value: 0.00545586 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 44 (Value: 0.00566944 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 46 (Value: 0.00552987 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 48 (Value: 0.0030469 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 49 (Value: 0.00407701 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 60 (Value: 0.00374799 vs. Expected: 0.00484525)
 Slice 8: Average = 0
 Slice 9: Average = 0
 Slice 10: Average = 0
 Slice 11: Average = 0
root [206] void PlotDeviations() {
root (cont'ed, cancel with .@) [207]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [208]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [209]        if (!phiProj) {
root (cont'ed, cancel with .@) [210]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [211]            continue;
root (cont'ed, cancel with .@) [212]        }
root (cont'ed, cancel with .@) [213]
root (cont'ed, cancel with .@) [213]        double sum = 0;
root (cont'ed, cancel with .@) [214]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [215]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [216]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [217]        }
root (cont'ed, cancel with .@) [218]
root (cont'ed, cancel with .@) [218]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [219]        TH1D *deviationHist = (TH1D*)phiProj->Clone(Form("deviationHist_%d", i));
root (cont'ed, cancel with .@) [220]        deviationHist->SetTitle(Form("Deviation in Phi (Slice %d); Phi Bin; Deviation", i));
root (cont'ed, cancel with .@) [221]
root (cont'ed, cancel with .@) [221]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [222]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [223]            double deviation = (content - avg) / avg * 100;  // Percentage deviation
root (cont'ed, cancel with .@) [224]            deviationHist->SetBinContent(bin, deviation);
root (cont'ed, cancel with .@) [225]        }
root (cont'ed, cancel with .@) [226]
root (cont'ed, cancel with .@) [226]        TCanvas *c = new TCanvas(Form("c_dev%d", i), "Deviation Plot", 800, 600);
root (cont'ed, cancel with .@) [227]        deviationHist->SetLineColor(kRed);
root (cont'ed, cancel with .@) [228]       
root (cont'ed, cancel with .@) [228]void PlotDeviations() {
root (cont'ed, cancel with .@) [229]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [230]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [231]        if (!phiProj) {
root (cont'ed, cancel with .@) [232]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [233]            continue;
root (cont'ed, cancel with .@) [234]        }
root (cont'ed, cancel with .@) [235]
root (cont'ed, cancel with .@) [235]        double sum = 0;
root (cont'ed, cancel with .@) [236]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [237]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [238]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [239]        }
root (cont'ed, cancel with .@) [240]
root (cont'ed, cancel with .@) [240]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [241]        TH1D *deviationHist = (TH1D*)phiProj->Clone(Form("deviationHist_%d", i));
root (cont'ed, cancel with .@) [242]        deviationHist->SetTitle(Form("Deviation in Phi (Slice %d); Phi Bin; Deviation", i));
root (cont'ed, cancel with .@) [243]
root (cont'ed, cancel with .@) [243]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [244]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [245]            double deviation = (content - avg) / avg * 100;  // Percentage deviation
root (cont'ed, cancel with .@) [246]            deviationHist->SetBinContent(bin, deviation);
root (cont'ed, cancel with .@) [247]        }
root (cont'ed, cancel with .@) [248]
root (cont'ed, cancel with .@) [248]        TCanvas *c = new TCanvas(Form("c_dev%d", i), "Deviation Plot", 800, 600);
root (cont'ed, cancel with .@) [249]        deviationHist->SetLineColor(kRed);
root (cont'ed, cancel with .@) [250]        deviationHist->Draw();
root (cont'ed, cancel with .@) [251]        c->SaveAs(Form("Deviation_Slice%d.png", i));
root (cont'ed, cancel with .@) [252]
root (cont'ed, cancel with .@) [252]        std::cout << " Deviation plot saved for Slice " << i << std::endl;
root (cont'ed, cancel with .@) [253]    }
root (cont'ed, cancel with .@) [254]}
root (cont'ed, cancel with .@) [255]PlotDeviations();
root (cont'ed, cancel with .@) [256]void PlotDeviations() {
root (cont'ed, cancel with .@) [257]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [258]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [259]        if (!phiProj) {
root (cont'ed, cancel with .@) [260]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [261]            continue;
root (cont'ed, cancel with .@) [262]        }
root (cont'ed, cancel with .@) [263]
root (cont'ed, cancel with .@) [263]        double sum = 0;
root (cont'ed, cancel with .@) [264]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [265]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [266]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [267]        }
root (cont'ed, cancel with .@) [268]
root (cont'ed, cancel with .@) [268]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [269]        TH1D *deviationHist = (TH1D*)phiProj->Clone(Form("deviationHist_%d", i));
root (cont'ed, cancel with .@) [270]        deviationHist->SetTitle(Form("Deviation in Phi (Slice %d); Phi Bin; Deviation", i));
root (cont'ed, cancel with .@) [271]
root (cont'ed, cancel with .@) [271]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [272]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [273]            double deviation = (content - avg) / avg * 100;  // Percentage deviation
root (cont'ed, cancel with .@) [274]            deviationHist->SetBinContent(bin, deviation);
root (cont'ed, cancel with .@) [275]        }
root (cont'ed, cancel with .@) [276]
root (cont'ed, cancel with .@) [276]        TCanvas *c = new TCanvas(Form("c_dev%d", i), "Deviation Plot", 800, 600);
root (cont'ed, cancel with .@) [277]        deviationHist->SetLineColor(kRed);
root (cont'ed, cancel with .@) [278]        deviationHist->Draw();
root (cont'ed, cancel with .@) [279]        c->SaveAs(Form("Deviation_Slice%d.png", i));
root (cont'ed, cancel with .@) [280]
root (cont'ed, cancel with .@) [280]        std::cout << " Deviation plot saved for Slice " << i << std::endl;
root (cont'ed, cancel with .@) [281]    }
root (cont'ed, cancel with .@) [282]}
root (cont'ed, cancel with .@) [283]PlotDeviations();
root (cont'ed, cancel with .@) [284]void TestFunction() {
root (cont'ed, cancel with .@) [285]    std::cout << " Function is running!" << std::endl;
root (cont'ed, cancel with .@) [286]}
root (cont'ed, cancel with .@) [287]TestFunction();
root (cont'ed, cancel with .@) [288].q
rilliann@rkompani-1 ~ % root
   ------------------------------------------------------------------
  | Welcome to ROOT 6.32.06                        https://root.cern |
  | (c) 1995-2024, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for macosxarm64 on Sep 21 2024, 18:21:53                   |
  | From tags/6-32-06@6-32-06                                        |
  | With Apple clang version 15.0.0 (clang-1500.3.9.4)               |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0] TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root [1] void GenerateAllPhiProjections() {
root (cont'ed, cancel with .@) [2]    TFile *f1 = new TFile("/Users/rilliann/Downloads/fout_mw.root");
root (cont'ed, cancel with .@) [3]    TH2D *hist2D = (TH2D*)f1->Get("run559362_AngularDistribution_1730354984354");
root (cont'ed, cancel with .@) [4]
root (cont'ed, cancel with .@) [4]    if (!hist2D) {
root (cont'ed, cancel with .@) [5]        std::cout << " Error: Histogram not found!" << std::endl;
root (cont'ed, cancel with .@) [6]        return;
root (cont'ed, cancel with .@) [7]    }
root (cont'ed, cancel with .@) [8]
root (cont'ed, cancel with .@) [8]    int nSlices = 12;
root (cont'ed, cancel with .@) [9]    double xMin = hist2D->GetXaxis()->GetXmin();
root (cont'ed, cancel with .@) [10]    double xMax = hist2D->GetXaxis()->GetXmax();
root (cont'ed, cancel with .@) [11]    double sliceWidth = 0.5;
root (cont'ed, cancel with .@) [12]
root (cont'ed, cancel with .@) [12]    std::cout << " Generating projections for 12 slices..." << std::endl;
root (cont'ed, cancel with .@) [13]
root (cont'ed, cancel with .@) [13]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [14]        double sliceStart = xMin + i * sliceWidth;
root (cont'ed, cancel with .@) [15]        double sliceEnd = sliceStart + sliceWidth;
root (cont'ed, cancel with .@) [16]        int binMin = hist2D->GetXaxis()->FindBin(sliceStart);
root (cont'ed, cancel with .@) [17]        int binMax = hist2D->GetXaxis()->FindBin(sliceEnd);
root (cont'ed, cancel with .@) [18]
root (cont'ed, cancel with .@) [18]        std::cout << " Slice " << i << ": X range [" << sliceStart << ", " << sliceEnd 
root (cont'ed, cancel with .@) [19]                  << "] | Bin range: [" << binMin << ", " << binMax << "]" << std::endl;
root (cont'ed, cancel with .@) [20]
root (cont'ed, cancel with .@) [20]        TH1D *phiProj = hist2D->ProjectionY(Form("phiProj_%d", i), binMin, binMax);
root (cont'ed, cancel with .@) [21]        if (!phiProj || phiProj->GetEntries() == 0) {
root (cont'ed, cancel with .@) [22]            std::cout << " Warning: Projection for slice " << i << " is EMPTY!" << std::endl;
root (cont'ed, cancel with .@) [23]            continue;
root (cont'ed, cancel with .@) [24]        }
root (cont'ed, cancel with .@) [25]
root (cont'ed, cancel with .@) [25]        std::cout << " Phi Projection for slice " << i << " created successfully!" << std::endl;
root (cont'ed, cancel with .@) [26]
root (cont'ed, cancel with .@) [26]        TCanvas *c = new TCanvas(Form("c%d", i), "Phi Projection", 800, 600);
root (cont'ed, cancel with .@) [27]        phiProj->SetLineColor(kBlue);
root (cont'ed, cancel with .@) [28]        phiProj->SetTitle(Form("Phi Projection (Slice %d); Phi; Tracks", i));
root (cont'ed, cancel with .@) [29]        phiProj->Draw();
root (cont'ed, cancel with .@) [30]        c->SaveAs(Form("Phi_Projection_Slice%d.png", i));
root (cont'ed, cancel with .@) [31]    }
root (cont'ed, cancel with .@) [32]}
root [33] GenerateAllPhiProjections();
 Generating projections for 12 slices...
 Slice 0: X range [-2, -1.5] | Bin range: [1, 6]
 Phi Projection for slice 0 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice0.png has been created
 Slice 1: X range [-1.5, -1] | Bin range: [6, 11]
 Phi Projection for slice 1 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice1.png has been created
 Slice 2: X range [-1, -0.5] | Bin range: [11, 16]
 Phi Projection for slice 2 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice2.png has been created
 Slice 3: X range [-0.5, 0] | Bin range: [16, 21]
 Phi Projection for slice 3 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice3.png has been created
 Slice 4: X range [0, 0.5] | Bin range: [21, 26]
 Phi Projection for slice 4 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice4.png has been created
 Slice 5: X range [0.5, 1] | Bin range: [26, 31]
 Phi Projection for slice 5 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice5.png has been created
 Slice 6: X range [1, 1.5] | Bin range: [31, 36]
 Phi Projection for slice 6 created successfully!
Info in <TCanvas::Print>: file Phi_Projection_Slice6.png has been created
 Slice 7: X range [1.5, 2] | Bin range: [36, 41]
 Warning: Projection for slice 7 is EMPTY!
 Slice 8: X range [2, 2.5] | Bin range: [41, 41]
 Warning: Projection for slice 8 is EMPTY!
 Slice 9: X range [2.5, 3] | Bin range: [41, 41]
 Warning: Projection for slice 9 is EMPTY!
 Slice 10: X range [3, 3.5] | Bin range: [41, 41]
 Warning: Projection for slice 10 is EMPTY!
 Slice 11: X range [3.5, 4] | Bin range: [41, 41]
 Warning: Projection for slice 11 is EMPTY!
root [34] void CalculatePhiAverages() {
root (cont'ed, cancel with .@) [35]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [36]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [37]        if (!phiProj) {
root (cont'ed, cancel with .@) [38]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [39]            continue;
root (cont'ed, cancel with .@) [40]        }
root (cont'ed, cancel with .@) [41]
root (cont'ed, cancel with .@) [41]        double sum = 0;
root (cont'ed, cancel with .@) [42]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [43]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [44]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [45]        }
root (cont'ed, cancel with .@) [46]        
root (cont'ed, cancel with .@) [46]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [47]        std::cout << " Slice " << i << ": Average phi track count = " << avg << std::endl;
root (cont'ed, cancel with .@) [48]    }
root (cont'ed, cancel with .@) [49]}
root [50] CalculatePhiAverages();
 Slice 0: Average phi track count = 0.0110525
 Slice 1: Average phi track count = 0.061804
 Slice 2: Average phi track count = 0.0800285
 Slice 3: Average phi track count = 0.0802306
 Slice 4: Average phi track count = 0.0792185
 Slice 5: Average phi track count = 0.0773075
 Slice 6: Average phi track count = 0.050062
 Slice 7: Average phi track count = 0.00484525
 Slice 8: Average phi track count = 0
 Slice 9: Average phi track count = 0
 Slice 10: Average phi track count = 0
 Slice 11: Average phi track count = 0
root [51] void IdentifyProblematicRegions() {
root (cont'ed, cancel with .@) [52]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [53]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [54]        if (!phiProj) {
root (cont'ed, cancel with .@) [55]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [56]            continue;
root (cont'ed, cancel with .@) [57]        }
root (cont'ed, cancel with .@) [58]
root (cont'ed, cancel with .@) [58]        double sum = 0;
root (cont'ed, cancel with .@) [59]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [60]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [61]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [62]        }
root (cont'ed, cancel with .@) [63]        
root (cont'ed, cancel with .@) [63]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [64]        std::cout << " Slice " << i << ": Average = " << avg << std::endl;
root (cont'ed, cancel with .@) [65]
root (cont'ed, cancel with .@) [65]        // Check each bin for deviations
root (cont'ed, cancel with .@) [66]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [67]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [68]            if (fabs(content - avg) > 0.1 * avg) {
root (cont'ed, cancel with .@) [69]                std::cout << " Deviation in Slice " << i << " at Phi bin " << bin 
root (cont'ed, cancel with .@) [70]                          << " (Value: " << content << " vs. Expected: " << avg << ")" << std::endl;
root (cont'ed, cancel with .@) [71]            }
root (cont'ed, cancel with .@) [72]        }
root (cont'ed, cancel with .@) [73]    }
root (cont'ed, cancel with .@) [74]}
root [75] IdentifyProblematicRegions();
 Slice 0: Average = 0.0110525
 Deviation in Slice 0 at Phi bin 30 (Value: 0.00984299 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 36 (Value: 0.0125005 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 41 (Value: 0.0121908 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 44 (Value: 0.0125009 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 46 (Value: 0.0122841 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 55 (Value: 0.00994073 vs. Expected: 0.0110525)
 Deviation in Slice 0 at Phi bin 60 (Value: 0.00900394 vs. Expected: 0.0110525)
 Slice 1: Average = 0.061804
 Slice 2: Average = 0.0800285
 Slice 3: Average = 0.0802306
 Slice 4: Average = 0.0792185
 Deviation in Slice 4 at Phi bin 24 (Value: 0.0896339 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 47 (Value: 0.0684388 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 48 (Value: 0.0689898 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 49 (Value: 0.065624 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 50 (Value: 0.06974 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 51 (Value: 0.0708477 vs. Expected: 0.0792185)
 Deviation in Slice 4 at Phi bin 56 (Value: 0.0886758 vs. Expected: 0.0792185)
 Slice 5: Average = 0.0773075
 Deviation in Slice 5 at Phi bin 35 (Value: 0.0872258 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 45 (Value: 0.0690172 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 47 (Value: 0.0611873 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 48 (Value: 0.0644909 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 49 (Value: 0.0624693 vs. Expected: 0.0773075)
 Deviation in Slice 5 at Phi bin 50 (Value: 0.0683736 vs. Expected: 0.0773075)
 Slice 6: Average = 0.050062
 Deviation in Slice 6 at Phi bin 23 (Value: 0.0445354 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 35 (Value: 0.0592595 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 46 (Value: 0.0567479 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 47 (Value: 0.0432225 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 48 (Value: 0.0398969 vs. Expected: 0.050062)
 Deviation in Slice 6 at Phi bin 49 (Value: 0.0410127 vs. Expected: 0.050062)
 Slice 7: Average = 0.00484525
 Deviation in Slice 7 at Phi bin 1 (Value: 0.00417194 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 11 (Value: 0.00534565 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 30 (Value: 0.00401949 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 34 (Value: 0.0055544 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 36 (Value: 0.00547758 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 39 (Value: 0.00552665 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 41 (Value: 0.00545586 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 44 (Value: 0.00566944 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 46 (Value: 0.00552987 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 48 (Value: 0.0030469 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 49 (Value: 0.00407701 vs. Expected: 0.00484525)
 Deviation in Slice 7 at Phi bin 60 (Value: 0.00374799 vs. Expected: 0.00484525)
 Slice 8: Average = 0
 Slice 9: Average = 0
 Slice 10: Average = 0
 Slice 11: Average = 0
root [76] void PlotDeviations() {
root (cont'ed, cancel with .@) [77]    for (int i = 0; i < 12; i++) {
root (cont'ed, cancel with .@) [78]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [79]        if (!phiProj) {
root (cont'ed, cancel with .@) [80]            std::cout << " Error: Could not find histogram for slice " << i << std::endl;
root (cont'ed, cancel with .@) [81]            continue;
root (cont'ed, cancel with .@) [82]        }
root (cont'ed, cancel with .@) [83]
root (cont'ed, cancel with .@) [83]        double sum = 0;
root (cont'ed, cancel with .@) [84]        int nBins = phiProj->GetNbinsX();
root (cont'ed, cancel with .@) [85]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [86]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [87]        }
root (cont'ed, cancel with .@) [88]
root (cont'ed, cancel with .@) [88]        double avg = sum / nBins;
root (cont'ed, cancel with .@) [89]        TH1D *deviationHist = (TH1D*)phiProj->Clone(Form("deviationHist_%d", i));
root (cont'ed, cancel with .@) [90]        deviationHist->SetTitle(Form("Deviation in Phi (Slice %d); Phi Bin; Deviation", i));
root (cont'ed, cancel with .@) [91]
root (cont'ed, cancel with .@) [91]        for (int bin = 1; bin <= nBins; bin++) {
root (cont'ed, cancel with .@) [92]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [93]            double deviation = (content - avg) / avg * 100;  // Percentage deviation
root (cont'ed, cancel with .@) [94]            deviationHist->SetBinContent(bin, deviation);
root (cont'ed, cancel with .@) [95]        }
root (cont'ed, cancel with .@) [96]
root (cont'ed, cancel with .@) [96]        TCanvas *c = new TCanvas(Form("c_dev%d", i), "Deviation Plot", 800, 600);
root (cont'ed, cancel with .@) [97]        deviationHist->SetLineColor(kRed);
root (cont'ed, cancel with .@) [98]        deviationHist->Draw();
root (cont'ed, cancel with .@) [99]        c->SaveAs(Form("Deviation_Slice%d.png", i));
root (cont'ed, cancel with .@) [100]
root (cont'ed, cancel with .@) [100]        std::cout << " Deviation plot saved for Slice " << i << std::endl;
root (cont'ed, cancel with .@) [101]    }
root (cont'ed, cancel with .@) [102]}
root [103] PlotDeviations();
Info in <TCanvas::Print>: file Deviation_Slice0.png has been created
 Deviation plot saved for Slice 0
Info in <TCanvas::Print>: file Deviation_Slice1.png has been created
 Deviation plot saved for Slice 1
Info in <TCanvas::Print>: file Deviation_Slice2.png has been created
 Deviation plot saved for Slice 2
Info in <TCanvas::Print>: file Deviation_Slice3.png has been created
 Deviation plot saved for Slice 3
Info in <TCanvas::Print>: file Deviation_Slice4.png has been created
 Deviation plot saved for Slice 4
Info in <TCanvas::Print>: file Deviation_Slice5.png has been created
 Deviation plot saved for Slice 5
Info in <TCanvas::Print>: file Deviation_Slice6.png has been created
 Deviation plot saved for Slice 6
Info in <TCanvas::Print>: file Deviation_Slice7.png has been created
 Deviation plot saved for Slice 7
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev8 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
Info in <TCanvas::Print>: file Deviation_Slice8.png has been created
 Deviation plot saved for Slice 8
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev9 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
Info in <TCanvas::Print>: file Deviation_Slice9.png has been created
 Deviation plot saved for Slice 9
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev10 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
Info in <TCanvas::Print>: file Deviation_Slice10.png has been created
 Deviation plot saved for Slice 10
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev11 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
Info in <TCanvas::Print>: file Deviation_Slice11.png has been created
 Deviation plot saved for Slice 11
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev8 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev9 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
Warning in <TCanvas::ResizePad>: Inf/NaN propagated to the pad. Check drawn objects.
Warning in <TCanvas::ResizePad>: c_dev10 height changed from 0 to 10

Error in <TGaxis::PaintAxis>: wmin (0.000000) == wmax (0.000000)
root [104] Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation7.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation6.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation5.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation4.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation3.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation2.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation1.pdf has been created
Info in <TCanvas::Print>: pdf file /Users/rilliann/deviation0.pdf has been created
convert -delay 100 -loop 0 Phi_Projection_Slice*.png Phi_Animation.gif
ROOT_prompt_104:1:15: error: expected ';' after expression
convert -delay 100 -loop 0 Phi_Projection_Slice*.png Phi_Animation.gif
              ^
              ;
ROOT_prompt_104:1:21: error: use of undeclared identifier 'loop'
convert -delay 100 -loop 0 Phi_Projection_Slice*.png Phi_Animation.gif
                    ^
root [105] .q
rilliann@rkompani-1 ~ % convert -delay 100 -loop 0 Phi_Projection_Slice*.png Phi_Animation.gif
root
zsh: command not found: convert
   ------------------------------------------------------------------
  | Welcome to ROOT 6.32.06                        https://root.cern |
  | (c) 1995-2024, The ROOT Team; conception: R. Brun, F. Rademakers |
  | Built for macosxarm64 on Sep 21 2024, 18:21:53                   |
  | From tags/6-32-06@6-32-06                                        |
  | With Apple clang version 15.0.0 (clang-1500.3.9.4)               |
  | Try '.help'/'.?', '.demo', '.license', '.credits', '.quit'/'.q'  |
   ------------------------------------------------------------------

root [0] void HeatmapDeviations() {
root (cont'ed, cancel with .@) [1]    int nSlices = 12;
root (cont'ed, cancel with .@) [2]    int nBinsPhi = 40; // Assuming each projection has 40 bins
root (cont'ed, cancel with .@) [3]    TH2D *heatmap = new TH2D("heatmap", "Deviation Heatmap;Time Slice;Phi Bin", nSlices, 0, nSlices, nBinsPhi, 0, nBinsPhi);
root (cont'ed, cancel with .@) [4]
root (cont'ed, cancel with .@) [4]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [5]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [6]        if (!phiProj) continue;
root (cont'ed, cancel with .@) [7]
root (cont'ed, cancel with .@) [7]        double sum = 0;
root (cont'ed, cancel with .@) [8]        for (int bin = 1; bin <= nBinsPhi; bin++) {
root (cont'ed, cancel with .@) [9]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [10]        }
root (cont'ed, cancel with .@) [11]        double avg = sum / nBinsPhi;
root (cont'ed, cancel with .@) [12]
root (cont'ed, cancel with .@) [12]        for (int bin = 1; bin <= nBinsPhi; bin++) {
root (cont'ed, cancel with .@) [13]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [14]            double deviation = (content - avg) / avg * 100;
root (cont'ed, cancel with .@) [15]            heatmap->SetBinContent(i + 1, bin, deviation);
root (cont'ed, cancel with .@) [16]        }
root (cont'ed, cancel with .@) [17]    }
root (cont'ed, cancel with .@) [18]
root (cont'ed, cancel with .@) [18]    TCanvas *c = new TCanvas("cHeatmap", "Heatmap", 800, 600);
root (cont'ed, cancel with .@) [19]    heatmap->Draw("COLZ");
root (cont'ed, cancel with .@) [20]    c->SaveAs("Deviation_Heatmap.png");
root (cont'ed, cancel with .@) [21]}
root [22] HeatmapDeviations();
Info in <TCanvas::Print>: file Deviation_Heatmap.png has been created
root [23] void IdentifyProblematicStaves() {
root (cont'ed, cancel with .@) [24]    int staveCount = 10;  // Assume 10 staves for simplicity
root (cont'ed, cancel with .@) [25]    int nSlices = 12;
root (cont'ed, cancel with .@) [26]    int nBinsPhi = 40;
root (cont'ed, cancel with .@) [27]
root (cont'ed, cancel with .@) [27]    std::map<int, double> staveProblems; // Stave ID -> Total Deviation
root (cont'ed, cancel with .@) [28]
root (cont'ed, cancel with .@) [28]    for (int i = 0; i < nSlices; i++) {
root (cont'ed, cancel with .@) [29]        TH1D *phiProj = (TH1D*)gROOT->FindObject(Form("phiProj_%d", i));
root (cont'ed, cancel with .@) [30]        if (!phiProj) continue;
root (cont'ed, cancel with .@) [31]
root (cont'ed, cancel with .@) [31]        double sum = 0;
root (cont'ed, cancel with .@) [32]        for (int bin = 1; bin <= nBinsPhi; bin++) {
root (cont'ed, cancel with .@) [33]            sum += phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [34]        }
root (cont'ed, cancel with .@) [35]        double avg = sum / nBinsPhi;
root (cont'ed, cancel with .@) [36]
root (cont'ed, cancel with .@) [36]        for (int bin = 1; bin <= nBinsPhi; bin++) {
root (cont'ed, cancel with .@) [37]            double content = phiProj->GetBinContent(bin);
root (cont'ed, cancel with .@) [38]            double deviation = (content - avg) / avg * 100;
root (cont'ed, cancel with .@) [39]
root (cont'ed, cancel with .@) [39]            if (fabs(deviation) > 10.0) {
root (cont'ed, cancel with .@) [40]                int staveID = bin % staveCount; // Simplified stave mapping
root (cont'ed, cancel with .@) [41]                staveProblems[staveID] += fabs(deviation);
root (cont'ed, cancel with .@) [42]            }
root (cont'ed, cancel with .@) [43]        }
root (cont'ed, cancel with .@) [44]    }
root (cont'ed, cancel with .@) [45]
root (cont'ed, cancel with .@) [45]    std::cout << " Stave Problem Ranking:\n"; 
root (cont'ed, cancel with .@) [46]    for (auto it : staveProblems) {
root (cont'ed, cancel with .@) [47]        std::cout << "Stave " << it.first << ": Total Deviation = " << it.second << "%" << std::endl;
root (cont'ed, cancel with .@) [48]    }
root (cont'ed, cancel with .@) [49]}
root [50] IdentifyProblematicStaves();
 Stave Problem Ranking:
root [51] nano
ROOT_prompt_51:1:1: warning: declaration does not declare anything [-Wmissing-declarations]
nano
^~~~
root [52] nano my_root_script.C
ROOT_prompt_52:1:20: error: expected ';' at end of declaration
nano my_root_script.C
                   ^
                   ;
root [53] nano my_root_script.C
ROOT_prompt_53:1:20: error: expected ';' at end of declaration
nano my_root_script.C
                   ^
                   ;
root [54] 
