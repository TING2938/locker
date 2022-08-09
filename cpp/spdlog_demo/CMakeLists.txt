cmake_minimum_required(VERSION 3.0.0)
project(spdlog_demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(third_party/spdlog)

add_executable(spdlog_demo example.cpp)
target_link_libraries(spdlog_demo PRIVATE spdlog::spdlog_header_only)

add_executable(fmt_demo fmt_example.cpp)
target_link_libraries(fmt_demo PRIVATE spdlog::spdlog_header_only)
