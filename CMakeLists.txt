cmake_minimum_required(VERSION 3.14)
project(SIFT)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(include)

# Add source files
set(SOURCES
    src/main.cpp
    src/csv_reader.cpp
    src/csv_writer.cpp
    src/fft.cpp
)

# Create the executable
add_executable(sift ${SOURCES})
