// map_signal_to_time_series.hpp

#pragma once
#include<vector>
#include<sift/generate_trade_signals.hpp>

namespace sift {
  struct TimeSeriesSignal {
    std::string time;
    double price;
    std::string signal;
  };

  std::vector<sift::TimeSeriesSignal> map_signal_to_time_series(std::vector<sift::TradeSignals> trade_signals);
 
}
