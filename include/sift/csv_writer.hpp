//csv_writer.hpp

#pragma once
#include<vector>
#include<string>
#include<sift/spike_detector.hpp>

namespace sift {
    void save_csv(const std::string output_path, std::vector<double>& data);
    void save_csv(const std::string output_path, std::vector<sift::SpikeData> spike_vector);
}