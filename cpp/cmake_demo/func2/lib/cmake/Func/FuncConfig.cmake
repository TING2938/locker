
set(FUNC_ROOT_DIR /home/yeting/work/locker/cpp/cmake_demo/func2)

add_library(Func INTERFACE)
add_library(Func::Func ALIAS Func)

target_include_directories(Func INTERFACE ${FUNC_ROOT_DIR}/include)
target_link_libraries(Func INTERFACE ${FUNC_ROOT_DIR}/lib/libfunc.so)