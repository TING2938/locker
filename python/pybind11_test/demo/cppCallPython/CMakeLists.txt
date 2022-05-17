
add_executable(cppCallPython demo.cpp)
target_link_libraries(cppCallPython pybind11::embed)