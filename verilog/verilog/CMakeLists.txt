find_package(Verilator REQUIRED)

# Build verilator module
find_path(VERILATOR_PATH verilated.h
        PATH_SUFFIXES verilator/include
        HINTS ${VERILATOR_INCLUDE_DIRS})

if ("${VERILATOR_PATH}" STREQUAL "VERILATOR_PATH-NOTFOUND")
    message(FATAL_ERROR "cannot find verilator")
endif ()

set(VERILATOR_SOURCES verilated.cpp verilated.h verilated_save.cpp verilated_save.h)
list(TRANSFORM VERILATOR_SOURCES PREPEND ${VERILATOR_PATH}/)
add_library(verilator ${VERILATOR_SOURCES})

# Run verilator on verilog files.
set(VERILOG_SOURCES chips.v test.v)
set(VERILATOR_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/verilator)
set(VERILATOR_OUTPUTS
        Vchips_chips.cpp Vchips_chips.h
        Vchips.cpp Vchips.h
        Vchips__Syms.cpp Vchips__Syms.h)
list(TRANSFORM VERILATOR_OUTPUTS PREPEND "${VERILATOR_OUTPUT_DIR}/")

add_custom_command(OUTPUT ${VERILATOR_OUTPUTS}
        COMMAND verilator -Wall -CFLAGS "${CMAKE_CXX_FLAGS}" --cc ${VERILOG_SOURCES} -Mdir ${VERILATOR_OUTPUT_DIR}
        DEPENDS ${VERILOG_SOURCES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Running verilator...")

add_library(memepu_verilator ${VERILATOR_OUTPUTS})
target_include_directories(memepu_verilator PUBLIC ${VERILATOR_INCLUDE_DIRS})
target_link_libraries(memepu_verilator PUBLIC verilator ${VERILATOR_LIBRARIES})
