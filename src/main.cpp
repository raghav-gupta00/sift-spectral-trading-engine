//main.cpp

#include <iostream>
#include <sift/csv_reader.hpp>
#include <sift/csv_writer.hpp>
#include <sift/fft.hpp>


int main(){
    std::vector<double> price_list = sift::read_csv("../data/nvda_data.csv", 1);

    std::vector<double> returns_list;
    
    for(int i = 1; i < price_list.size(); i++){
      returns_list.push_back(price_list[i] - price_list[i-1]);
    }

    std::vector<double> spectrum = sift::fft_wrapper(returns_list);

    sift::save_csv("../data_output/output_data.csv", spectrum);
}