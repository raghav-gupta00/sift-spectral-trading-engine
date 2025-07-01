//spike_detector.hpp

#pragma once
#include<vector>

namespace sift {
  struct SpikeData {
    int bin;
    double magnitude;
    double cycle_length;
  };

  struct DominantFrequency {
    int window_start;
    int bin;
    double magnitude;
    double cycle_length;
  };

  std::vector<SpikeData> detect_spikes(std::vector<double>& spectrum, double threshold_ratio);

  std::vector<DominantFrequency> detect_spikes(std::vector<double>& spectrum, double threshold_ratio, int top_n, int window_start);
}
