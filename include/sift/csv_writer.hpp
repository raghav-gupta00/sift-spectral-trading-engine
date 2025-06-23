//csv_writer.hpp

#pragma once
#include<vector>
#include<string>

namespace sift {
    void save_csv(const std::string output_path, std::vector<double>& data);
}