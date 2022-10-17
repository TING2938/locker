cmake_minimum_required(VERSION 3.0.0)
project(CPMAddPackage_demo VERSION 0.1.0)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME fmt 
    URL "https://github.com/fmtlib/fmt/releases/download/8.1.1/fmt-8.1.1.zip"
)
CPMAddPackage(
    NAME spdlog 
    URL "https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.tar.gz"
    OPTIONS
        "SPDLOG_FMT_EXTERNAL_HO ON"
)
CPMAddPackage(
    NAME spdlog 
    URL "https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.tar.gz"
    OPTIONS
        "SPDLOG_FMT_EXTERNAL_HO ON"
)
add_executable(CPMAddPackage_demo main.cpp)
target_link_libraries(CPMAddPackage_demo fmt::fmt spdlog::spdlog)
