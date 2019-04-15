cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3")

project(verymeme)

# Find required packages.
find_package(Boost REQUIRED program_options stacktrace_backtrace)
find_package(Verilator REQUIRED)
find_package(Yosys REQUIRED)
find_package(SFML COMPONENTS graphics window system REQUIRED)
# Sanitizers via extra-cmake-modules.
find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_DIR})
include(ECMEnableSanitizers)

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
include(GoogleTest)

# Verilator debug option.
#add_definitions(-DVL_DEBUG)

# Build verilog files using verilator.
add_subdirectory(verilog)

# Add libraries.
add_library(verymeme_library
    src/verymeme/common.cpp include/verymeme/common.h
    include/verymeme/firmware_constants.h
    src/verymeme/parser.cpp include/verymeme/parser.h)
add_library(memecad_library
    src/memecad/parser.cpp include/memecad/parser.h
    src/memecad/types.cpp include/memecad/types.h
    src/memecad/mapper.cpp include/memecad/mapper.h
    src/memecad/yosys_module.cpp include/memecad/yosys_module.h
    src/memecad/util.cpp include/memecad/util.h
    src/memecad/schematic.cpp include/memecad/schematic.h)
add_library(memeroute_library
    src/memeroute/parser.cpp include/memeroute/parser.h
    src/memeroute/types.cpp include/memeroute/types.h src/memeroute/render_shapes.cpp include/memeroute/render_shapes.h)

# Add executables
add_executable(memecad src/programs/memecad.cpp)
add_executable(generate_firmware src/programs/generate_firmware.cpp)
add_executable(tests src/tests/verilator_tests.cpp
    src/programs/test_harness.cpp src/tests/memecad_tests.cpp src/tests/common_tests.cpp)
add_executable(memeroute src/programs/memeroute.cpp src/programs/memeroute.cpp)

# Verymeme library configuration:
target_include_directories(verymeme_library PUBLIC
    ${VERILATOR_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} include)
target_link_directories(verymeme_library PUBLIC ${Boost_LIBRARY_DIRS})
# -fPIC since it's used in a shared library.
set_property(TARGET verymeme_library PROPERTY POSITION_INDEPENDENT_CODE ON)

# Memecad library configuration:
target_compile_options(memecad_library PUBLIC ${YOSYS_OPTIONS})
target_link_options(memecad_library PUBLIC ${YOSYS_LDFLAGS})

# Memeroute library configuration:
target_include_directories(memeroute_library PUBLIC ${SFML_INCLUDE_DIR})

# Link libraries.
target_link_libraries(verymeme_library PUBLIC ${Boost_LIBRARIES})
target_link_libraries(memecad_library PUBLIC ${YOSYS_LIBRARIES} verymeme_library)
target_link_libraries(memeroute_library PUBLIC verymeme_library ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Link executables.
target_link_libraries(tests PRIVATE gtest verymeme_library memecad_library verilated_library)
target_link_libraries(generate_firmware PRIVATE verymeme_library)
target_link_libraries(memecad PRIVATE memecad_library)
target_link_libraries(memeroute PRIVATE memeroute_library)

gtest_discover_tests(tests WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
