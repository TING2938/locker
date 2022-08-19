cmake_minimum_required(VERSION 3.0.0)
project(json_demo VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
    cpptools
    GIT_REPOSITORY https://github.com/ting2938/cpptools.git 
    GIT_TAG  master
)
FetchContent_MakeAvailable(cpptools)

CT_USE_JSON()

add_executable(json_demo main.cpp)
target_link_libraries(json_demo cpptools::json)
