// spike_detector.cpp
// detects spikes in the spectrum

#include <vector>
#include <algorithm>
#include <sift/spike_detector.hpp>
#include <queue>
#include <utility>

namespace sift {

  std::vector<sift::SpikeData> detect_spikes(std::vector<double>& spectrum, double threshold_ratio) {
    size_t N = spectrum.size();
    std::vector<sift::SpikeData> spike_vector;
    double max_magnitude = *max_element(spectrum.begin(), spectrum.end());
    double threshold = threshold_ratio * max_magnitude;

    for (size_t i = 1; i < N; i++) { // skip DC bin
      if (spectrum[i] > threshold) {
        double cycle_length = static_cast<double>(N) / i;
        spike_vector.push_back({static_cast<int>(i), cycle_length, spectrum[i]});
      }
    }

    return spike_vector;
  }

  std::vector<sift::DominantFrequency> detect_spikes(
    std::vector<double>& spectrum,
    double threshold_ratio,
    int top_n,
    int window_start
  ) {
    std::vector<DominantFrequency> top_spikes;
    size_t N = spectrum.size();

    double max_magnitude = *max_element(spectrum.begin(), spectrum.end());
    double threshold = threshold_ratio * max_magnitude;

    auto cmp = [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
      return a.first > b.first;
    };

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, decltype(cmp)> min_heap(cmp);

    for (int i = 1; i < static_cast<int>(N); i++) { // skip DC component (bin 0)
      if (spectrum[i] > threshold) {
        min_heap.emplace(spectrum[i], i);
        if (min_heap.size() > top_n) {
          min_heap.pop();
        }
      }
    }

    while (!min_heap.empty()) {
      auto [magnitude, bin] = min_heap.top();
      min_heap.pop();

      double cycle_length = static_cast<double>(N) / bin;
      top_spikes.push_back({window_start, bin, magnitude, cycle_length});
    }

    return top_spikes;
  }

}