cmake_minimum_required(VERSION 3.11)
project(pybind11_demo)

add_subdirectory(third_party/pybind11)

add_subdirectory(demo/cppCallPython)
add_subdirectory(demo/pythonCallCpp)