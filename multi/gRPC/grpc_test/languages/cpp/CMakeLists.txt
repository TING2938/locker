project(grpc-cmake-example)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "-O3 -std=c++17 ${CMAKE_CXX_FLAGS}")

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

set(PROTO_SRC_DIR ${PROJECT_SOURCE_DIR}/mySum)
include_directories(${PROTO_SRC_DIR})

file(GLOB PROTO_SRC_FILE ${PROTO_SRC_DIR}/*.cc)

add_library(grpc_protoc ${PROTO_SRC_FILE})

# Building it
foreach(_target server client)
    add_executable(${_target} ${CMAKE_CURRENT_SOURCE_DIR}/${_target}.cpp)
    target_link_libraries(${_target}
        grpc_protoc
        gRPC::grpc++_reflection
        protobuf::libprotobuf)
endforeach()
