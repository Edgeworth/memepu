cmake_minimum_required(VERSION 3.12)
project(memelang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_library(memelang_library
        src/tokeniser.cpp
        include/tokeniser.h
        src/common.cpp
        include/common.h
)

add_executable(compiler src/programs/compiler.cpp)
target_link_libraries(compiler memelang_library)
target_include_directories(memelang_library PUBLIC include)

