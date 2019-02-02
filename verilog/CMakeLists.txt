cmake_minimum_required(VERSION 3.12)
project(memepu_verilog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)


# Download and unpack googletest at configure time
configure_file(cmake/DownloadGTest.cmake googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# Build the rest.
include(GoogleTest)

find_package(Verilator REQUIRED)
add_subdirectory(verilog)

add_library(memepu_verilog_utils src/common.cpp include/common.h)
add_executable(main src/programs/main.cpp)
add_executable(tests src/programs/tests.cpp)

target_include_directories(memepu_verilog_utils PUBLIC ${VERILATOR_INCLUDE_DIRS} include)

target_link_libraries(memepu_verilog_utils PUBLIC gtest memepu_verilator)
target_link_libraries(main PRIVATE memepu_verilog_utils)
target_link_libraries(tests PRIVATE memepu_verilog_utils)

gtest_discover_tests(tests)
