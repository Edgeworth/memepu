find_package(Verilator REQUIRED)

# Find verilator
find_path(VERILATOR_PATH verilated.h
    PATH_SUFFIXES verilator/include
    HINTS ${VERILATOR_INCLUDE_DIRS})

if ("${VERILATOR_PATH}" STREQUAL "VERILATOR_PATH-NOTFOUND")
  message(FATAL_ERROR "cannot find verilator")
endif ()

# Run verilator on verilog files.
set(VERILATOR_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/verilator)
file(GLOB VERILOG_MODULES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.v)
list(REMOVE_ITEM VERILOG_MODULES common.v workaround.v)  # Remove non-top level modules

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

# Add verilator library.
set(VERILATOR_COMMON_SOURCES verilated.cpp verilated.h verilated_save.cpp verilated_save.h)
list(TRANSFORM VERILATOR_COMMON_SOURCES PREPEND ${VERILATOR_PATH}/)
add_library(verilated_library ${VERILATOR_COMMON_SOURCES} ${ALL_VERILATOR_OUTPUTS})
target_include_directories(verilated_library PUBLIC ${VERILATOR_INCLUDE_DIRS} ${VERILATOR_OUTPUT_DIR})
