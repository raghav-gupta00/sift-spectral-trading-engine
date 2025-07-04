//generate_trade_signals.hpp

#pragma once
#include<vector>
#include<string>
#include<sift/spike_detector.hpp>

namespace sift {
  struct FrequencyStats{
    int count{0};
    double total_magnitude{0.0};
    double last_magnitude{0.0};
    double average_magnitude{0.0};
    std::vector<int> windows;
  };

  struct TradeSignals {
    int window;
    std::string trade_signal;
  };

  std::vector<sift::TradeSignals> generate_trade_signals(std::vector<sift::DominantFrequency> spectral_drift_data, std::string strategy);

}