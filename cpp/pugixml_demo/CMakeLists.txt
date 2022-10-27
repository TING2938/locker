cmake_minimum_required(VERSION 3.0.0)
project(pugixml_demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
    pugixml
    URL https://github.com/zeux/pugixml/releases/download/v1.12.1/pugixml-1.12.1.tar.gz
)
FetchContent_MakeAvailable(pugixml)

add_executable(pugixml_demo example.cpp)
target_link_libraries(pugixml_demo pugixml)
