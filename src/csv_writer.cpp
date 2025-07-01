//csv_writer.cpp
//utility to write output to a csv file from a input vector

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sift/spike_detector.hpp>

namespace sift {
    void write_to_csv(const std::string output_path, std::vector<double>& data){
        std::ofstream out_file(output_path);

        for(int i=0; i<data.size();i++){
            out_file<<i<<","<<data[i]<<"\n";
        }

        std::cout<<"Output write successfull"<<std::endl;

        out_file.close();
        return;
    }

    void write_to_csv(const std::string output_path, std::vector<sift::SpikeData> spike_vector){
      std::ofstream out_file(output_path);

      out_file<<"bins"<<","<<"cycle_length"<<","<<"magnitude"<<"\n";

      for(int i = 0; i < spike_vector.size(); i++){
        out_file<<spike_vector[i].bin<<","<<spike_vector[i].cycle_length<<","<<spike_vector[i].magnitude<<"\n";
      }

      std::cout<<"Output write successfull"<<std::endl;

      out_file.close();
      return;
    }

    void write_to_csv(const std::string output_path, std::vector<sift::DominantFrequency> spectral_drift_data){
      std::ofstream out_file(output_path);

      out_file<<"window_start"<<","<<"bin"<<","<<"magnitude"<<","<<"cycle_length"<<"\n";

      for(int i = 0; i < spectral_drift_data.size(); i++){
        out_file<<spectral_drift_data[i].window_start<<","<<spectral_drift_data[i].bin<<","<<spectral_drift_data[i].magnitude<<","<<spectral_drift_data[i].cycle_length<<"\n";
      }

      std::cout<<"Output write successfull"<<std::endl;

      out_file.close();
      return;
    }
}