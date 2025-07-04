//map_signals_to_time_series.cpp

#include <vector>
#include <unordered_map>
#include <sift/map_signal_to_time_series.hpp>
#include <sift/csv_reader.hpp>

namespace sift {
  std::vector<sift::TimeSeriesSignal> map_signal_to_time_series(std::vector<sift::TradeSignals> trade_signals) {
    std::vector<sift::TimeSeriesSignal> mapped_signal;

    // Read the full time-price series
    std::vector<std::pair<std::string, double>> time_price = sift::read_csv("../data/nvda_data.csv", 0, 1);

    // Create a lookup for trade signals based on window index
    std::unordered_map<int, std::string> window_signal_map;
    for (const auto& ts : trade_signals) {
      window_signal_map[ts.window] = ts.trade_signal;
    }

    // For each point in the time series, attach a signal if available
    for (int i = 0; i < time_price.size(); ++i) {
      std::string time = time_price[i].first;
      double price = time_price[i].second;

      std::string signal = "";

      // Check if a signal is issued at this time index (i.e., window start)
      if (window_signal_map.find(i) != window_signal_map.end()) {
        signal = window_signal_map[i];
      }

      mapped_signal.push_back({time, price, signal});
    }

    return mapped_signal;
  }
}
