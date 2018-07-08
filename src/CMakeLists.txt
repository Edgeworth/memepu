# cmake_minimum_required(VERSION <specify CMake version here>)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp control.cpp led.cpp control.h led.h common.h control_constants.h common.cpp)
