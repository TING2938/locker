project(cmake_test)

cmake_minimum_required(VERSION 3.14)

set(genv "hello world, $<$<CONFIG:DEBUG>:mk>")

message("${genv}")

add_executable(main main.cpp)
target_compile_definitions(main PRIVATE genv="${genv}")