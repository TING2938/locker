
file(GLOB LEETCODE_SRC_FILES *.cpp)
foreach(SRC_PATH ${LEETCODE_SRC_FILES})
    get_filename_component(_target ${SRC_PATH} NAME_WE)
    add_executable(${_target} ${SRC_PATH})
    target_link_libraries(${_target} gtest gtest_main)
endforeach()

