// analyse_spectral_drift.cpp
#include <vector>
#include <span>
#include <sift/fft.hpp>
#include <sift/spike_detector.hpp>

namespace sift {

  std::vector<sift::DominantFrequency> analyse_spectral_drift(std::vector<double>& time_series, int window, int jump) {
    size_t N = time_series.size();
    std::vector<DominantFrequency> spectral_drift_data;

    // perform a rolling window fft on windows
    for (int i = 0; i <= static_cast<int>(N) - window; i += jump) {

      std::span<const double> chunk(time_series.begin() + i, window);

      std::vector<double> spectrum = fft_wrapper(chunk);

      auto spectral_drift_chunk = detect_spikes(spectrum, 0.5, 5, i);
      
      spectral_drift_data.insert(spectral_drift_data.end(), spectral_drift_chunk.begin(), spectral_drift_chunk.end());
    }

    return spectral_drift_data;
  }

}
