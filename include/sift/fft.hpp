//fft.hpp

#pragma once
#include <vector>
#include <span>

namespace sift {
  std::vector<double> fft_wrapper(std::span<const double> signal);
}