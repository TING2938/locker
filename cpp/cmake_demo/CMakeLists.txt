project(cmake_test)

cmake_minimum_required(VERSION 3.14)

set(genv "hello world, $<$<CONFIG:DEBUG>:mk>")

message("${genv}")

# add -DCMAKE_PREFIX_PATH=/path/to/func2 for Func path
find_package(Func CONFIG REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main Func::Func)

target_compile_definitions(main PRIVATE genv="${genv}")
