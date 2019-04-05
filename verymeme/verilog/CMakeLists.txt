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
set(VERILOG_MODULES buffer_mux.v  chip74LVC162244.v chip7400.v chip7404.v chip7408.v chip7432.v
    chip7486.v chip74161.v chip74299.v chip7416374.v kpu.v mlu.v mlu_lookahead.v
    mlu_slice.v register32.v shifter.v sram.v sram17x8.v timer.v)

function(add_verilog_module VERILOG_MODULE)
  set(VERILOG_MODULE_SOURCES ${VERILOG_MODULE})
  get_filename_component(MODULE_NAME ${VERILOG_MODULE} NAME_WE)
  set(VERILATOR_OUTPUTS ${VERILATOR_OUTPUTS} "V${MODULE_NAME}.cpp" "V${MODULE_NAME}.h"
      "V${MODULE_NAME}__Syms.cpp" "V${MODULE_NAME}__Syms.h")
  list(TRANSFORM VERILATOR_OUTPUTS PREPEND "${VERILATOR_OUTPUT_DIR}/")
  add_custom_command(OUTPUT ${VERILATOR_OUTPUTS}
      COMMAND verilator --report-unoptflat -Wall -CFLAGS "${CMAKE_CXX_FLAGS}"
      --cc ${VERILOG_MODULE_SOURCES} -Mdir ${VERILATOR_OUTPUT_DIR}
      DEPENDS ${VERILOG_MODULES} common.v
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Running verilator for ${VERILOG_MODULE}")

  set(ALL_VERILATOR_OUTPUTS ${ALL_VERILATOR_OUTPUTS} ${VERILATOR_OUTPUTS} PARENT_SCOPE)
endfunction()

foreach (VERILOG_MODULE ${VERILOG_MODULES})
  add_verilog_module(${VERILOG_MODULE})
endforeach ()

add_library(verymeme_verilated ${ALL_VERILATOR_OUTPUTS})
target_include_directories(verymeme_verilated PUBLIC ${VERILATOR_INCLUDE_DIRS} ${VERILATOR_OUTPUT_DIR})
target_link_libraries(verymeme_verilated PUBLIC verilator)
