cmake_minimum_required(VERSION 3.11)
project(EigenDemo)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    cpptools
    GIT_REPOSITORY https://github.com/ting2938/cpptools.git
    GIT_TAG master
)
FetchContent_MakeAvailable(cpptools)

CT_USE_EIGEN()

add_executable(demo demo.cpp)
target_link_libraries(demo Eigen3::Eigen)
