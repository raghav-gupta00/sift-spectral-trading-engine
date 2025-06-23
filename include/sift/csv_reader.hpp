//csv_header.cpp

# pragma once
#include <vector>
#include <string>

namespace sift {
    std::vector<double> read_csv(const std::string data_path, int col_index);
}
