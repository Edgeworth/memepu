cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3")
set(THREADS_PREFER_PTHREAD_FLAG ON)

project(verymeme)

# Find required packages.
find_package(Boost REQUIRED program_options stacktrace_backtrace)
find_package(Verilator REQUIRED)
find_package(Yosys REQUIRED)
find_package(SFML COMPONENTS graphics window system REQUIRED)
find_package(Threads REQUIRED)
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
set(VERYMEME_SOURCES
    src/verymeme/common.cpp include/verymeme/common.h
    src/verymeme/file.cpp include/verymeme/file.h
    src/verymeme/geom.cpp include/verymeme/geom.h
    src/verymeme/tokenizer.cpp include/verymeme/tokenizer.h
    src/verymeme/term.cpp include/verymeme/term.h)
set(MEMECAD_SOURCES ${VERYMEME_SOURCES}
    src/memecad/parser.cpp include/memecad/parser.h
    src/memecad/types.cpp include/memecad/types.h
    src/memecad/mapper.cpp include/memecad/mapper.h
    src/memecad/yosys_module.cpp include/memecad/yosys_module.h
    src/memecad/util.cpp include/memecad/util.h
    src/memecad/schematic.cpp include/memecad/schematic.h)
set(MEMEROUTE_SOURCES ${VERYMEME_SOURCES}
    src/memeroute/parser.cpp include/memeroute/parser.h
    src/memeroute/types.cpp include/memeroute/types.h
    src/memeroute/render_shapes.cpp include/memeroute/render_shapes.h
    src/memeroute/renderer.cpp include/memeroute/renderer.h
    src/memeroute/router.cpp include/memeroute/router.h
    src/memeroute/router_worker.cpp include/memeroute/router_worker.h)
set(MEMEWARE_SOURCES ${VERYMEME_SOURCES}
    include/memeware/constants.h
    src/memeware/microcode.cpp include/memeware/microcode.h)
set(MEMEASM_SOURCES ${VERYMEME_SOURCES}
    src/memeasm/assembler.cpp include/memeasm/assembler.h)
set(MEMESIM_SOURCES ${VERYMEME_SOURCES} ${MEMEASM_SOURCES}
    src/memesim/simulator.cpp include/memesim/simulator.h
    src/memesim/cli.cpp include/memesim/cli.h
    src/memesim/display.cpp include/memesim/display.h)
set(MEMELANG_SOURCES ${VERYMEME_SOURCES}
    src/memelang/tokeniser.cpp include/memelang/tokeniser.h
    src/memelang/parser.cpp include/memelang/parser.h
    src/memelang/file_contents.cpp include/memelang/file_contents.h
    include/memelang/types.h)
set(TEST_SOURCES ${VERYMEME_SOURCES} ${MEMECAD_SOURCES} ${MEMEROUTE_SOURCES} ${MEMEWARE_SOURCES}
    ${MEMEASM_SOURCES} ${MEMESIM_SOURCES} ${MEMELANG_SOURCES}
    src/tests/verilator_tests.cpp src/tests/memecad_tests.cpp
    src/tests/common_tests.cpp src/tests/memeroute_tests.cpp src/tests/memelang_tests.cpp)

# memeasm:
add_executable(memeasm ${MEMEASM_SOURCES} src/programs/memeasm.cpp)
target_include_directories(memeasm PUBLIC ${Boost_INCLUDE_DIRS} include)
target_link_directories(memeasm PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(memeasm PUBLIC ${Boost_LIBRARIES})

# memeware:
add_executable(memeware ${MEMEWARE_SOURCES} src/programs/memeware.cpp)
target_include_directories(memeware PUBLIC ${Boost_INCLUDE_DIRS} ${VERILATOR_INCLUDE_DIRS} include)
target_link_directories(memeware PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(memeware PUBLIC verilated_library ${Boost_LIBRARIES})

# memecad:
add_executable(memecad ${MEMECAD_SOURCES} src/programs/memecad.cpp)
target_include_directories(memecad PUBLIC ${Boost_INCLUDE_DIRS} include)
target_link_directories(memecad PUBLIC ${Boost_LIBRARY_DIRS})
target_compile_options(memecad PUBLIC ${YOSYS_OPTIONS})
target_link_options(memecad PUBLIC ${YOSYS_LDFLAGS})
target_link_libraries(memecad PUBLIC ${YOSYS_LIBRARIES} ${Boost_LIBRARIES})

# memeroute:
add_executable(memeroute ${MEMEROUTE_SOURCES} src/programs/memeroute.cpp)
target_include_directories(memeroute PUBLIC ${SFML_INCLUDE_DIR} ${Boost_INCLUDE_DIRS} include)
target_link_directories(memeroute PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(memeroute PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${Boost_LIBRARIES}
    Threads::Threads)

# memesim:
add_executable(memesim ${MEMESIM_SOURCES} src/programs/memesim.cpp)
target_include_directories(memesim PUBLIC ${SFML_INCLUDE_DIR} ${VERILATOR_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS} include)
target_link_directories(memesim PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(memesim PUBLIC verilated_library ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
    ${Boost_LIBRARIES} Threads::Threads)

# memelang:
add_executable(memelang ${MEMELANG_SOURCES} src/programs/memelang.cpp)
target_include_directories(memelang PUBLIC ${Boost_INCLUDE_DIRS} include)
target_link_directories(memelang PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(memelang PUBLIC ${Boost_LIBRARIES})

# tests:
add_executable(tests ${TEST_SOURCES} src/programs/test_harness.cpp)
target_include_directories(tests PUBLIC ${SFML_INCLUDE_DIR} ${VERILATOR_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS} include)
target_link_directories(tests PUBLIC ${YOSYS_OPTIONS} ${Boost_LIBRARY_DIRS})
target_compile_options(tests PUBLIC ${YOSYS_OPTIONS})
target_link_options(tests PUBLIC ${YOSYS_LDFLAGS})
target_link_libraries(tests PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${YOSYS_LIBRARIES}
    gtest verilated_library ${Boost_LIBRARIES} Threads::Threads)
gtest_discover_tests(tests WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
