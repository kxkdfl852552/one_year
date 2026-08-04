cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(memory_debug memory_debug.cpp)

target_compile_features(memory_debug PRIVATE cxx_std_17)
target_compile_options(memory_debug PRIVATE -Wall -O0 -g -D_GLIBCXX_DEBUG -fsanitize=address,undefined -fno-omit-frame-pointer)

target_link_options(memory_debug PRIVATE -fsanitize=address,undefined)

#-fsanitize=address,undefined 既要参与编译，也要参与链接。