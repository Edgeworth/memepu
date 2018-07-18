cmake_minimum_required(VERSION 3.10)
project(memepu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_library(memepu_utils
    src/asm.cpp
    include/asm.h
    src/common.cpp
    include/common.h
    src/control.cpp
    include/control.h
    include/control_constants.h
    src/led.cpp
    include/led.h
)
add_executable(eeprom src/programs/eeprom.cpp)
add_executable(assembler src/programs/assembler.cpp)
add_executable(run_test src/programs/test.cpp)

target_link_libraries(eeprom memepu_utils)
target_link_libraries(assembler memepu_utils)
target_link_libraries(run_test memepu_utils)

target_include_directories(memepu_utils PUBLIC include)
