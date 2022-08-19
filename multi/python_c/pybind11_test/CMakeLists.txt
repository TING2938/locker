cmake_minimum_required(VERSION 3.11)
project(pybind11_demo)

include(FetchContent)
FetchContent_Declare(
    cpptools
    GIT_REPOSITORY https://github.com/ting2938/cpptools.git
    GIT_TAG master
)
FetchContent_MakeAvailable(cpptools)

CT_USE_PYBIND11()

add_subdirectory(demo/cppCallPython)
add_subdirectory(demo/pythonCallCpp)