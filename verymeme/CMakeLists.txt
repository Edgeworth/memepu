cmake_minimum_required(VERSION 3.12)
project(verymeme)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3")

# Set-up icecc if it exists
find_program(ICECC icecc)
if (ICECC)
  foreach (LANG C CXX)
    message(STATUS "Using icecc for ${LANG}")
    set(CMAKE_${LANG}_COMPILER_LAUNCHER ${ICECC})
  endforeach ()
endif ()

#add_definitions(-DVL_DEBUG)

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
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build EXCLUDE_FROM_ALL)

# Build the rest.
include(GoogleTest)

find_package(Boost REQUIRED program_options stacktrace_backtrace)
find_package(Verilator REQUIRED)
add_subdirectory(verilog)

add_library(verymeme_library
    src/common.cpp include/common.h
    src/test_printer.cpp include/test_printer.h
    src/kicad_parser.cpp include/kicad_parser.h)
add_executable(tests src/tests/tests.cpp src/programs/test_harness.cpp)
add_executable(memecad src/programs/memecad.cpp)
add_executable(generate_firmware src/programs/generate_firmware.cpp)

target_include_directories(verymeme_library PUBLIC
    ${VERILATOR_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} include)
target_link_directories(verymeme_library PUBLIC ${Boost_LIBRARY_DIRS})

target_link_libraries(verymeme_library PUBLIC ${Boost_LIBRARIES} gtest verymeme_verilated)
target_link_libraries(tests PRIVATE verymeme_library)
target_link_libraries(memecad PRIVATE verymeme_library)
target_link_libraries(generate_firmware PRIVATE verymeme_library)

# gtest_discover_tests is slow for a large number of tests, so it's not used here.
