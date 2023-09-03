cmake_minimum_required(VERSION 3.21.0)
project(cuda_demo VERSION 0.1.0 LANGUAGES CXX CUDA)

add_executable(device_info device_info.cu)

add_subdirectory(kernel)

add_executable(main main.cpp)
target_link_libraries(main cu_func)

