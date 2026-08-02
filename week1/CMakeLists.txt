cmake_minimum_required(VERSION 3.16)
project(cpp_week1 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) #把所有可执行程序输出到 build/bin 目录下。
function(add_week1_exe target_name source_file)
    add_executable(${target_name} ${source_file})
    target_compile_features(${target_name} PRIVATE cxx_std_17) #给某个 target 指定需要的编译特性；如果这个特性需要额外编译参数
    target_compile_options(${target_name} PRIVATE
        -Wall
        -Wextra
        -g
    )  #给指定 target 添加编译时使用的 options，这个 target 必须已经通过 add_executable() 或 add_library() 创建
endfunction()

add_week1_exe(pointer_ref_test      day1/pointer_ref_test.cpp)
add_week1_exe(virtual_test          day2/virtual_test.cpp)
add_week1_exe(smart_ptr_demo        day3/smart_ptr_demo.cpp)
add_week1_exe(tensor                day4/tensor.cpp)
add_week1_exe(atomic_demo           day6/atomic_demo.cpp)
add_week1_exe(condition_variable    day6/condition_variable.cpp)


find_package(Threads REQUIRED)

target_link_libraries(atomic_demo PRIVATE Threads::Threads)
target_link_libraries(condition_variable PRIVATE Threads::Threads)