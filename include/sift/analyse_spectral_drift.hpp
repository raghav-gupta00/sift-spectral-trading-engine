//analyse_spectral_drift.hpp

#pragma once
#include<vector>
#include<sift/spike_detector.hpp>

namespace sift {
  std::vector<sift::DominantFrequency> analyse_spectral_drift(std::vector<double>& time_series, int window, int jump);
}