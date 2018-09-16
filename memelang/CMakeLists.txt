cmake_minimum_required(VERSION 3.10)
project(memelang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -pedantic -Wconversion -Wno-sign-conversion \
  -Wno-sign-compare -Wfloat-equal -Wformat-security -pedantic")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -fno-omit-frame-pointer -march=native -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3")

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
add_definitions(${LLVM_DEFINITIONS})

add_library(memelang_library
        src/tokeniser.cpp include/tokeniser.h src/common.cpp include/common.h src/parser.cpp
        include/parser.h include/file_contents.h src/file_contents.cpp src/compile.cpp include/compile.h src/llvm.cpp include/llvm.h include/types.h)
add_executable(compiler src/programs/compiler.cpp)

llvm_map_components_to_libnames(LLVM_LIBS support core irreader X86)
target_link_libraries(memelang_library ${LLVM_LIBS})
target_link_libraries(compiler memelang_library)
target_include_directories(memelang_library PUBLIC include)
target_include_directories(memelang_library SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})

