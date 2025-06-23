#include<iostream>
#include<vector>
#include<string>
#include<fstream>

namespace sift {
    void save_csv(const std::string output_path, std::vector<double>& data){
        std::ofstream out_file(output_path);

        for(int i=0; i<data.size();i++){
            out_file<<i<<","<<data[i]<<"\n";
        }

        std::cout<<"Output write successfull"<<std::endl;

        out_file.close();
        return;
    }
}