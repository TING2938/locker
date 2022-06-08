cmake_minimum_required(VERSION 3.0.0)
project(json_demo VERSION 0.1.0)


add_subdirectory(third_party/json)

add_executable(json_demo main.cpp)
target_link_libraries(json_demo nlohmann_json::nlohmann_json)
