cmake_minimum_required(VERSION 3.10)
project(cmake_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)  #设置C++17标准
set(CMAKE_CXX_STANDARD_REQUIRED on)  #必须找到C++17

find_package(Threads REQUIRED)

add_executable(cmake_lab main.cpp worker.cpp)

target_compile_features(cmake_lab PRIVATE cxx_std_17)

target_compile_options(cmake_lab PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(cmake_lab PRIVATE Threads::Threads)

message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")