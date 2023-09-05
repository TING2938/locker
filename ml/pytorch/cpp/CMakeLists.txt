cmake_minimum_required(VERSION 3.0)
project(torch_test LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)

# -DCMAKE_PREFIX_PATH=/path/to/python3/dist-packages/torch
find_package(Python REQUIRED COMPONENTS Development)
find_package(Torch REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main ${TORCH_LIBRARIES})

