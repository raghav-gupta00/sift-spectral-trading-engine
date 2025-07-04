//main.cpp

#include <iostream>
#include <sift/csv_reader.hpp>
#include <sift/csv_writer.hpp>
#include <sift/fft.hpp>
#include <sift/spike_detector.hpp>
#include <sift/analyse_spectral_drift.hpp>
#include <sift/generate_trade_signals.hpp>
#include <sift/map_signal_to_time_series.hpp>

int main(){
    std::vector<double> price_list = sift::read_csv("../data/nvda_data.csv", 1);

    std::vector<double> returns_list;
    
    for(int i = 1; i < price_list.size(); i++){
      returns_list.push_back(price_list[i] - price_list[i-1]);
    }

    std::vector<sift::DominantFrequency> spectral_drift_data = sift::analyse_spectral_drift(returns_list, 64, 32);

    std::vector<sift::TradeSignals> trade_signal = sift::generate_trade_signals(spectral_drift_data, "none");
    
    std::vector<sift::TimeSeriesSignal> mapped_signal = sift::map_signal_to_time_series(trade_signal);

    sift::write_to_csv("../data_output/trade_signal.csv",mapped_signal);
    
    return 0;
}