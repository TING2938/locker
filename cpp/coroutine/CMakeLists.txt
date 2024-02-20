cmake_minimum_required(VERSION 3.12)
project(coroutine_demo VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(coroutine_demo main.cpp)
