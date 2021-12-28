
# Building it
file(GLOB TOTAL_SRC_FILES *.cpp)

foreach(SRC_PATH ${TOTAL_SRC_FILES})
    get_filename_component(_target ${SRC_PATH} NAME_WE)
    add_executable(${_target} ${SRC_PATH})
endforeach()

