cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(crash crash.cpp)
target_compile_features(crash PRIVATE cxx_std_17)
target_compile_options(crash PRIVATE -Wall -Wextra -Wpedantic -O0 -g -D_GLIBCXX_DEBUG)