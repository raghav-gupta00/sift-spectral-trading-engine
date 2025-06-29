//fft.cpp
//wrapper function for fftw3 r2c operation

#include<iostream>
#include<vector>
#include<fftw3.h>
#include<cmath>
#include<cstddef>

namespace sift {

  std::vector<double> zero_pad_to_pow2(std::vector<double>& signal){
    size_t N = signal.size();
    size_t next_pow2 = 1;

    while(next_pow2 < N) next_pow2 *= 2;

    std::vector<double> padded = signal;
    padded.resize(next_pow2, 0.0);
    return padded;
  }


  std::vector<double> fft_wrapper(std::vector<double>& signal){

    std::vector<double> padded_signal= sift::zero_pad_to_pow2(signal); 

    int N = padded_signal.size();

    double* in = fftw_alloc_real(N);
    fftw_complex* out = fftw_alloc_complex(N);

    for(int i=0 ; i< N; i++){
      in[i] = padded_signal[i];
    }

    fftw_plan plan = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    fftw_execute(plan);

    std::vector<double> spectrum;

    int out_len = N/2 + 1;

    for(int i=0; i< out_len; i++){
      double re = out[i][0];
      double im = out[i][1];

      spectrum.push_back(std:: sqrt(re * re + im * im));
    }

    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);

    return spectrum;
  }
}