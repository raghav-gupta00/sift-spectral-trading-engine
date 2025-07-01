//main.cpp

#include <iostream>
#include <sift/csv_reader.hpp>
#include <sift/csv_writer.hpp>
#include <sift/fft.hpp>
#include <sift/spike_detector.hpp>
#include <sift/analyse_spectral_drift.hpp>

int main(){
    std::vector<double> price_list = sift::read_csv("../data/nvda_data.csv", 1);

    std::vector<double> returns_list;
    
    for(int i = 1; i < price_list.size(); i++){
      returns_list.push_back(price_list[i] - price_list[i-1]);
    }

    std::vector<sift::DominantFrequency> spectral_drift_data = sift::analyse_spectral_drift(returns_list, 64, 32);

    sift::write_to_csv("../data_output/spectral_drift_data.csv", spectral_drift_data);
}