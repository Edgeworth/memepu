cmake_minimum_required(VERSION 3.12)
project(verymeme)

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

add_library(verymeme_library src/common.cpp include/common.h)
add_executable(tests src/programs/tests.cpp)

target_include_directories(verymeme_library PUBLIC ${VERILATOR_INCLUDE_DIRS} include)

target_link_libraries(verymeme_library PUBLIC gtest verymeme_verilated)
target_link_libraries(tests PRIVATE verymeme_library)

# gtest_discover_tests is slow for a large number of tests, so it's not used here.
