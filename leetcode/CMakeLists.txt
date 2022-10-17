cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

set(CXX_STANDARD 17)

include(FetchContent)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    tag_gtest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.tar.gz
)
FetchContent_MakeAvailable(tag_gtest)

# build target

file(GLOB LEETCODE_SRC_FILES *.cpp)
foreach(SRC_PATH ${LEETCODE_SRC_FILES})
    get_filename_component(_target ${SRC_PATH} NAME_WE)
    add_executable(${_target} ${SRC_PATH})
    target_link_libraries(${_target} gtest gtest_main)
endforeach()

