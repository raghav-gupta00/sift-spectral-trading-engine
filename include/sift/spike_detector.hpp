//spike_detector.hpp

#pragma once
#include<vector>

namespace sift {
  struct SpikeData {
    int bin;
    double magnitude;
    double cycle_length;
  };

  std::vector<SpikeData> detect_spikes(std::vector<double>& spectrum, double threshold);
}
