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
set(VERILATOR_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/verilator)

function(add_verilog_module VERILOG_MODULE)
    set(VERILOG_SOURCES ${VERILOG_MODULE} common.v)
    get_filename_component(MODULE_NAME ${VERILOG_MODULE} NAME_WE)
    set(VERILATOR_OUTPUTS ${VERILATOR_OUTPUTS} "V${MODULE_NAME}.cpp" "V${MODULE_NAME}.h"
            "V${MODULE_NAME}_common.cpp" "V${MODULE_NAME}_common.h"
            "V${MODULE_NAME}__Syms.cpp" "V${MODULE_NAME}__Syms.h")
    list(TRANSFORM VERILATOR_OUTPUTS PREPEND "${VERILATOR_OUTPUT_DIR}/")
    add_custom_command(OUTPUT ${VERILATOR_OUTPUTS}
            COMMAND verilator -Wall -CFLAGS "${CMAKE_CXX_FLAGS}" --cc ${VERILOG_SOURCES} -Mdir ${VERILATOR_OUTPUT_DIR}
            DEPENDS ${VERILOG_SOURCES}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Running verilator...")

    set(ALL_VERILATOR_OUTPUTS ${ALL_VERILATOR_OUTPUTS} ${VERILATOR_OUTPUTS} PARENT_SCOPE)
endfunction()

add_verilog_module(chip7400.v)
add_verilog_module(chip7404.v)
add_verilog_module(chip74299.v)

message(${ALL_VERILATOR_OUTPUTS})

add_library(memepu_verilator ${ALL_VERILATOR_OUTPUTS})
target_include_directories(memepu_verilator PUBLIC ${VERILATOR_INCLUDE_DIRS} ${VERILATOR_OUTPUT_DIR})
target_link_libraries(memepu_verilator PUBLIC verilator ${VERILATOR_LIBRARIES})
