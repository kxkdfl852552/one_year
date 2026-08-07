cmake_minimum_required(VERSION 3.10)

project(link_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(math_ops SHARED math_ops.cpp)

target_include_directories(math_ops PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app main.cpp)

target_link_libraries(app PRIVATE math_ops)

target_compile_options(math_ops PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_compile_options(app PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)