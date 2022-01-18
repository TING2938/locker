project(torch_test)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

set(torch_build_prefix /home/yeting/study/ML/pytorch/build)
include_directories(${torch_build_prefix}/lib.linux-x86_64-3.8/torch/include/torch/csrc/api/include)
include_directories(${torch_build_prefix}/lib.linux-x86_64-3.8/torch/include)
link_directories(${torch_build_prefix}/lib)

set(LINK_OBJS c10 torch torch_cpu)

# Building it
add_executable(main main.cpp)
target_link_libraries(main ${LINK_OBJS})

