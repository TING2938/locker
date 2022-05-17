cmake_minimum_required(VERSION 3.11)
project(learnPybind11)

add_subdirectory(pybind11)

add_subdirectory(demo/cppCallPython)
add_subdirectory(demo/pythonCallCpp)