# Copyright(c) 2019 spdlog authors Distributed under the MIT License (http://opensource.org/licenses/MIT)

cmake_minimum_required(VERSION 3.10)
project(spdlog_examples CXX)

add_subdirectory(third_party/spdlog)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------

add_executable(example_header_only example.cpp)
target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)

