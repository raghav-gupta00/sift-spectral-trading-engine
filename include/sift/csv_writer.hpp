//csv_writer.hpp

#pragma once
#include<vector>
#include<string>
#include<sift/spike_detector.hpp>

namespace sift {
    void write_to_csv(const std::string output_path, std::vector<double>& data);
    void write_to_csv(const std::string output_path, std::vector<sift::SpikeData> spike_vector);
    void write_to_csv(const std::string output_path, std::vector<sift::DominantFrequency> spectral_drift_data);
}