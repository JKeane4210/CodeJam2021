cmake_minimum_required(VERSION 3.17)
project(CodeJam2021)

set(CMAKE_CXX_STANDARD 14)

add_executable(CodeJam2021 main.cpp)
add_executable(Test Qualifiers/testingWorks.cpp)
add_executable(Reversort Qualifiers/Reversort.cpp)
add_executable(MoonsAndUmbrellas Qualifiers/MoonsAndUmbrellas.cpp)
add_executable(ReversortEngineering Qualifiers/ReversortEngineering.cpp)
add_executable(MedianSort Qualifiers/MedianSort.cpp)
add_executable(PartAMedianSort Qualifiers/partAMedianSort.cpp)