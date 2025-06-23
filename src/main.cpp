//main.cpp

#include <iostream>
#include <sift/csv_reader.hpp>
#include <sift/csv_writer.hpp>

int main(){
    std::vector<double> price_list = sift::read_csv("../data/sample_data.csv", 1);
    sift::save_csv("../data_output/output_data.csv", price_list);
}