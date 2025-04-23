# 🔬 ALICE Track Distribution Analysis

This project analyzes the angular distribution of particle tracks in the ALICE detector at CERN, with the goal of detecting malfunctioning chips using ROOT-based statistical analysis.

## 🚀 Overview

Using experimental data from the ALICE detector at the LHC, this C++ project implements an automated method for detecting outliers in η–φ (pseudorapidity–azimuth) space. The analysis identifies deviations in track distributions and maps them to chip locations using detector geometry data.

## 🛠️ Technologies Used

- **C++**
- **CERN ROOT Framework**
- Data visualization and histogram analysis
- Physics-inspired anomaly detection

## 📸 Sample Output
 
👉 _<img src="plots/detection50.png" width="600"/>_

## 🧠 Key Features

- 📊 2D and 1D histogram analysis in η–φ space  
- 🧪 Automatic outlier detection based on customizable thresholds  
- 🧭 Correlation of anomalies with detector chip geometry  
- 🖼️ ROOT-based visualization with labeled results  

## 📂 Project Structure


## ▶️ How to Run

> 💡 Requires [ROOT](https://root.cern/) installed.

```bash
root -l
analyzeALPIDE (runNumber, timeStamp, threshhold)
