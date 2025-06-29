//spike_detector.cpp
//detects spikes in the spectrum

#include<vector>
#include<algorithm>
#include<sift/spike_detector.hpp>

namespace sift{
  std::vector<sift::SpikeData> detect_spikes(std::vector<double>& spectrum, double threshold_ratio){
    size_t N = spectrum.size();
    std::vector<sift::SpikeData> spike_vector;
    double max_magnitude = *max_element(spectrum.begin(),spectrum.end());
    double threshold = threshold_ratio * max_magnitude;
    
    for(size_t i = 1; i < N; i++){
      if(spectrum[i] > threshold){
        double cycle_length = static_cast<double> (N / i);
        SpikeData foo{};
        foo.bin = i;
        foo.magnitude = spectrum[i];
        foo.cycle_length = cycle_length;

        spike_vector.push_back(foo);
      }
    }

    return spike_vector;
  }
}