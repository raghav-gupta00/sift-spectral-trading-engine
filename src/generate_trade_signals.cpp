#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sift/generate_trade_signals.hpp>
#include <sift/spike_detector.hpp>

namespace sift {

  std::vector<TradeSignals> generate_trade_signals(std::vector<DominantFrequency> spectral_drift_data, std::string strategy){
    std::unordered_map<int, FrequencyStats> bin_stats;

    // Aggregate stats for each bin
    for (const auto& spike : spectral_drift_data) {
      FrequencyStats& stats = bin_stats[spike.bin];
      stats.count++;
      stats.total_magnitude += spike.magnitude;
      stats.last_magnitude = spike.magnitude; 
      stats.windows.push_back(spike.window_start);
    }

    // Compute average magnitudes
    for (auto& [bin, stats] : bin_stats) {
      stats.average_magnitude = stats.total_magnitude / stats.count;
    }

    // Identify dominant bins globally
    std::unordered_set<int> dominant_bins;
    for (const auto& [bin, stats] : bin_stats) {
      if (stats.count >= 3 && stats.average_magnitude >= 50.0) {
        dominant_bins.insert(bin);
      }
    }

    // Build window -> set of bins map
    std::unordered_map<int, std::unordered_set<int>> window_to_bins;
    for (const auto& spike : spectral_drift_data) {
      window_to_bins[spike.window_start].insert(spike.bin);
    }

    // Sort window keys to ensure deterministic signal sequence
    std::vector<int> sorted_windows;
    for (const auto& [window, _] : window_to_bins) {
      sorted_windows.push_back(window);
    }
    std::sort(sorted_windows.begin(), sorted_windows.end());

    std::unordered_set<int> prev_bins;
    std::vector<TradeSignals> signals;

    for (int window : sorted_windows) {
      const auto& bins = window_to_bins[window];
      std::string signal = "HOLD";
      bool appeared = false;
      bool vanished = false;

      for (int bin : dominant_bins) {
        if (bins.count(bin) && !prev_bins.count(bin)) appeared = true;
        if (!bins.count(bin) && prev_bins.count(bin)) vanished = true;
      }

      if (appeared) signal = "BUY";
      else if (vanished) signal = "SELL";

      signals.push_back({window, signal});
      prev_bins = bins;
    }

    return signals;
  }

}
