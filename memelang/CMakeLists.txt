cmake_minimum_required(VERSION 3.12)
project(memelang)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wno-sign-compare")

add_library(memelang_library
        src/tokeniser.cpp include/tokeniser.h src/common.cpp include/common.h src/parser.cpp
        include/parser.h include/file_contents.h src/file_contents.cpp src/compile.cpp include/compile.h)

add_executable(compiler src/programs/compiler.cpp)
target_link_libraries(compiler memelang_library)
target_include_directories(memelang_library PUBLIC include)

