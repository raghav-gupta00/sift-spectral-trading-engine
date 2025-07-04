// csv_reader.cpp
// utility to read data from a csv file into a vector

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace sift {

    // Reads a single column (e.g., price) as double
    std::vector<double> read_csv(const std::string data_path, int col_index) {
        std::ifstream csv_file(data_path);
        std::vector<double> prices;

        if (!csv_file.is_open()) {
            std::cerr << "Error accessing csv file" << std::endl;
            return prices;
        }

        std::string line;
        std::getline(csv_file, line);  // Skip header

        while (std::getline(csv_file, line)) {
            std::stringstream ss(line);
            std::string token;

            int col = 0;
            while (std::getline(ss, token, ',')) {
                if (col == col_index) {
                    try {
                        prices.push_back(std::stod(token));
                    } catch (...) {
                        std::cerr << "Error parsing token: " << token << std::endl;
                    }
                }
                col++;
            }
        }

        std::cout << "Loaded:\t" << prices.size() << " prices" << std::endl;
        return prices;
    }

    // Reads (time, price) as pair<string, double>
    std::vector<std::pair<std::string, double>> read_csv(const std::string data_path, int time_index, int price_index) {
        std::ifstream csv_file(data_path);
        std::vector<std::pair<std::string, double>> time_price;

        if (!csv_file.is_open()) {
            std::cerr << "Error accessing csv file" << std::endl;
            return time_price;
        }

        std::string line;
        std::getline(csv_file, line);  // Skip header

        while (std::getline(csv_file, line)) {
            std::stringstream ss(line);
            std::string token;
            std::string time = "";
            double price = 0.0;
            int col = 0;

            while (std::getline(ss, token, ',')) {
                if (col == time_index) {
                    time = token;
                }
                if (col == price_index) {
                    try {
                        price = std::stod(token);
                    } catch (...) {
                        std::cerr << "Error parsing token as price: " << token << std::endl;
                        price = 0.0;
                    }
                }
                col++;
            }

            time_price.emplace_back(time, price);
        }

        std::cout << "Loaded:\t" << time_price.size() << " time-price pairs" << std::endl;
        return time_price;
    }
}
