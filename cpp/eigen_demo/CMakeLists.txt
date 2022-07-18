cmake_minimum_required(VERSION 3.11)
project(EigenDemo)

set(CMAKE_CXX_STANDARD 11)

set(EIGEN_BUILD_DOC OFF CACHE BOOL "")
set(BUILD_TESTING OFF CACHE BOOL "")
set(EIGEN_BUILD_PKGCONFIG OFF CACHE BOOL "")
add_subdirectory(third_party/eigen)

add_executable(demo demo.cpp)
target_link_libraries(demo Eigen3::Eigen)
