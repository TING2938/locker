cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(FetchContent_demo)

include(FetchContent)

set(FMT_URL "https://github.com/fmtlib/fmt/releases/download/8.1.1/fmt-8.1.1.zip" CACHE STRING "")
FetchContent_Declare(fmt URL ${FMT_URL})
FetchContent_MakeAvailable(fmt)

set(SPDLOG_URL "https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.tar.gz" CACHE STRING "")
set(SPDLOG_FMT_EXTERNAL_HO ON CACHE BOOL "")
FetchContent_Declare(spdlog URL ${SPDLOG_URL})
FetchContent_MakeAvailable(spdlog)

add_executable(FetchContent_demo main.cpp)
target_link_libraries(FetchContent_demo fmt::fmt spdlog::spdlog)
