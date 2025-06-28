//csv_reader.cpp
//utility to read data from a csv file into a vector

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

namespace sift{
    std::vector<double> read_csv(const std::string data_path, int col_index){

        std::ifstream csv_file(data_path);
        std::vector<double> prices;

        if(!csv_file.is_open()){
           std::cerr<<"Error accessing csv file"<<std::endl;
           return prices;
        }

        std::string line;

        std::getline(csv_file, line);

        while(std::getline(csv_file, line)){
            std::stringstream ss(line);
            std::string token;

            int col{0};
            double price{0.0};

            while(std::getline(ss, token, ',')){
                if(col == col_index){
                    try{
                        price = std::stod(token);
                        prices.push_back(price);
                    }catch(...){
                        std::cerr<<"Error parsing token:"<<token<<std::endl;
                    }
                }
                col++;
            }
        }

        std::cout<<"Loaded:\t"<<prices.size()<<"prices"<<std::endl;
        return prices;

    }
}