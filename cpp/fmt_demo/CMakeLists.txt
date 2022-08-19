cmake_minimum_required(VERSION 3.0.0)
project(spdlog_demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
    cpptools
    GIT_REPOSITORY https://github.com/ting2938/cpptools.git
    GIT_TAG master
)
FetchContent_MakeAvailable(cpptools)

add_executable(fmt_demo fmt_example.cpp)
target_link_libraries(fmt_demo PRIVATE fmt::fmt-header-only)