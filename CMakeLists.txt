cmake_minimum_required(VERSION 3.10)
project(sift)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp)

#to include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(sift ${SOURCES})

# Link FFTW manually
target_link_libraries(sift fftw3)
