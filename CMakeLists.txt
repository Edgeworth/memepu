cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -march=native -O3")
set(THREADS_PREFER_PTHREAD_FLAG ON)

# Fuzzing
if ("${USE_AFL}" STREQUAL "clang")
  message(STATUS "Using american fuzzy lop with clang")
  set(CMAKE_C_COMPILER "afl-clang-fast")
  set(CMAKE_CXX_COMPILER "afl-clang-fast++")
elseif (USE_AFL)
  message(STATUS "Using american fuzzy lop with gcc")
  set(CMAKE_C_COMPILER "afl-gcc")
  set(CMAKE_CXX_COMPILER "afl-g++")
endif ()

if (USE_AFL)
  message(STATUS "Using AFL hardening")
  set(ENV{AFL_HARDEN} 1)  # Set AFL_HARDEN variable
endif ()

# Use shared libraries for faster linking in Debug mode (except when using AFL).
if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND NOT USE_AFL)
  message(STATUS "Building using shared libraries")
  set(BUILD_SHARED_LIBS ON)
endif ()

project(verymeme)

# Add verilog SCHEMATIC configuration option.
option(VERILOG_SCHEMATIC "Build KPU with SCHEMATIC define enabled. Force enables HEXFILE" OFF)
# Add verilog HEXFILE configuration option.
option(VERILOG_HEXFILE "Build KPU with HEXFILE define enabled." OFF)

# Enable IPO if possible (and not a debug build, for build performance).
include(CheckIPOSupported)
check_ipo_supported(RESULT result OUTPUT output)
if (result AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Enabling IPO")
  cmake_policy(SET CMP0069 NEW)
  set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Skipping IPO for debug build")
else ()
  message(WARNING "IPO is not supported: ${output}")
endif ()

# Find required packages.
find_package(Boost REQUIRED program_options)
find_package(Verilator REQUIRED)
find_package(Yosys REQUIRED)
find_package(SFML COMPONENTS graphics window system REQUIRED)
find_package(Threads REQUIRED)
# Sanitizers via extra-cmake-modules.
find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_DIR})
include(ECMEnableSanitizers)

# Backtrace is slow so skip for AFL.
if (USE_AFL)
  message(STATUS "Skipping backtrace for AFL")
  add_definitions(-DBOOST_STACKTRACE_USE_NOOP)
else ()
  if (boost_stacktrace_backtrace_FOUND)
    add_definitions(-DBOOST_STACKTRACE_USE_BACKTRACE)
  else ()
    add_definitions(-DBOOST_STACKTRACE_USE_ADDR2LINE)
  endif ()
endif ()

include(CheckCCompilerFlag)
check_c_compiler_flag("-fuse-ld=gold" HAVE_GOLD)
check_c_compiler_flag("-fuse-ld=lld" HAVE_LLD)

if (HAVE_LLD AND NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND NOT USE_AFL)
  message(STATUS "Using lld linker")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=lld")
elseif (HAVE_GOLD)
  # Gold linker.
  message(STATUS "Using gold linker")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=gold")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=gold")
endif ()

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
set(VERYMEME_SOURCES
    src/verymeme/util.h
    src/verymeme/file.cpp src/verymeme/file.h
    src/verymeme/geom.cpp src/verymeme/geom.h
    src/verymeme/tokeniser.cpp src/verymeme/tokeniser.h
    src/verymeme/term.cpp src/verymeme/term.h
    src/verymeme/concurrent_queue.h src/verymeme/bimap.h
    src/verymeme/string_util.cpp src/verymeme/string_util.h
    src/verymeme/macros.cpp src/verymeme/macros.h)
set(MEMEASM_SOURCES src/memeasm/assembler.cpp src/memeasm/assembler.h)
set(MEMECAD_SOURCES
    src/memecad/parser.cpp src/memecad/parser.h
    src/memecad/types.cpp src/memecad/types.h
    src/memecad/mapper.cpp src/memecad/mapper.h
    src/memecad/yosys_module.cpp src/memecad/yosys_module.h
    src/memecad/util.cpp src/memecad/util.h
    src/memecad/schematic.cpp src/memecad/schematic.h)
set(MEMELANG_SOURCES
    src/memelang/constants.h
    src/memelang/tokeniser.cpp src/memelang/tokeniser.h
    src/memelang/parser.cpp src/memelang/parser.h
    src/memelang/file_contents.cpp src/memelang/file_contents.h
    src/memelang/ast.cpp src/memelang/ast.h
    src/memelang/expression.cpp src/memelang/expression.h
    src/memelang/exec.cpp src/memelang/exec.h
    src/memelang/vm.cpp src/memelang/vm.h
    src/memelang/scopes.cpp src/memelang/scopes.h
    src/memelang/type.cpp src/memelang/type.h)
set(MEMESIM_SOURCES
    src/memesim/simulator.cpp src/memesim/simulator.h
    src/memesim/cli.cpp src/memesim/cli.h
    src/memesim/display.cpp src/memesim/display.h)
set(MEMEWARE_SOURCES
    src/memeware/constants.h
    src/memeware/microcode.cpp src/memeware/microcode.h)
set(TEST_SOURCES
    src/tests/verilator_tests.cpp src/tests/memecad_tests.cpp
    src/tests/common_tests.cpp src/tests/memelang_tests.cpp)

# verymeme:
add_library(verymeme_library ${VERYMEME_SOURCES})
target_include_directories(verymeme_library PUBLIC ${Boost_INCLUDE_DIRS}
    ${VERILATOR_INCLUDE_DIRS} src)
target_link_directories(verymeme_library PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(verymeme_library PUBLIC ${CMAKE_DL_LIBS} ${Boost_LIBRARIES})

# memeasm:
add_library(memeasm_library ${MEMEASM_SOURCES})
target_link_libraries(memeasm_library PUBLIC verymeme_library)
add_executable(memeasm src/programs/memeasm.cpp)
target_link_libraries(memeasm PUBLIC memeasm_library)

# memecad:
add_library(memecad_library ${MEMECAD_SOURCES})
target_link_libraries(memecad_library PUBLIC verymeme_library)
target_compile_options(memecad_library PUBLIC ${YOSYS_OPTIONS})
target_link_options(memecad_library PUBLIC ${YOSYS_LDFLAGS})
target_link_libraries(memecad_library PUBLIC ${YOSYS_LIBRARIES})
add_executable(memecad src/programs/memecad.cpp)
target_link_libraries(memecad PUBLIC memecad_library)

# memelang:
add_library(memelang_library ${MEMELANG_SOURCES})
target_link_libraries(memelang_library PUBLIC verymeme_library)
add_executable(memelang src/programs/memelang.cpp)
target_link_libraries(memelang PUBLIC memelang_library)

# memesim:
add_library(memesim_library ${MEMESIM_SOURCES})
target_link_libraries(memesim_library PUBLIC verymeme_library memeasm_library)
target_include_directories(memesim_library PUBLIC ${SFML_INCLUDE_DIR} ${VERILATOR_INCLUDE_DIRS})
target_link_libraries(memesim_library PUBLIC Threads::Threads verilated_library
    ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
add_executable(memesim src/programs/memesim.cpp)
target_link_libraries(memesim PUBLIC memesim_library)

# memeware:
add_library(memeware_library ${MEMEWARE_SOURCES})
target_link_libraries(memeware_library PUBLIC verymeme_library)
target_include_directories(memeware_library PUBLIC ${VERILATOR_INCLUDE_DIRS})
target_link_libraries(memeware_library PUBLIC verilated_library)
add_executable(memeware src/programs/memeware.cpp)
target_link_libraries(memeware PUBLIC memeware_library)

# tests:
add_executable(tests ${TEST_SOURCES} src/programs/test_harness.cpp)
target_link_libraries(tests PUBLIC gtest gmock memeasm_library memecad_library
    memelang_library memesim_library memeware_library)
gtest_discover_tests(tests WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
