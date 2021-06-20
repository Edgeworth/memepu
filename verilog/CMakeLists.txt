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

foreach (VERILOG_MODULE ${VERILOG_MODULES})
  # Make CMake watch these for changes.
  set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
      "${CMAKE_CURRENT_SOURCE_DIR}/${VERILOG_MODULE}")
endforeach ()

list(REMOVE_ITEM VERILOG_MODULES common.v workaround.v)  # Remove non-top level modules

function(add_verilog_module VERILOG_MODULE)
  set(VERILOG_MODULE_SOURCES ${VERILOG_MODULE})
  get_filename_component(MODULE_NAME ${VERILOG_MODULE} NAME_WE)

  set(VERILATOR_DEFINES "")
  if (${VERILOG_SCHEMATIC})
    # Weird spacing because of verilator argument parsing.
    set(VERILATOR_DEFINES "${VERILATOR_DEFINES}-DSCHEMATIC ")
  endif ()
  if (${VERILOG_HEXFILE})
    set(VERILATOR_DEFINES "${VERILATOR_DEFINES}-DHEXFILE ")
  endif ()
    message("Running verilator for ${VERILOG_MODULE}. Defines: ${VERILATOR_DEFINES}")
  # Options: Enable assertions.
  execute_process(
      COMMAND verilator --report-unoptflat --assert -Wall -Wno-fatal -O3 --no-threads
      ${VERILATOR_DEFINES} -CFLAGS "${CMAKE_CXX_FLAGS}" --cc ${VERILOG_MODULE_SOURCES}
      -Mdir ${VERILATOR_OUTPUT_DIR} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE retcode)
  if (NOT ${retcode} STREQUAL "0")
    message(FATAL_ERROR "Verilator failed")
  endif ()

  # Rewrite outputs with everything we got.
  file(GLOB VERILATOR_OUTPUT_H "${VERILATOR_OUTPUT_DIR}/V${MODULE_NAME}*.h")
  file(GLOB VERILATOR_OUTPUT_CPP "${VERILATOR_OUTPUT_DIR}/V${MODULE_NAME}*.cpp")
  set(VERILATOR_OUTPUTS ${VERILATOR_OUTPUT_H} ${VERILATOR_OUTPUT_CPP})

  set(ALL_VERILATOR_OUTPUTS ${ALL_VERILATOR_OUTPUTS} ${VERILATOR_OUTPUTS} PARENT_SCOPE)
endfunction()

foreach (VERILOG_MODULE ${VERILOG_MODULES})
  add_verilog_module(${VERILOG_MODULE})
endforeach ()

# Add verilator library.
set(VERILATOR_COMMON_SOURCES verilated.cpp verilated.h verilated_save.cpp verilated_save.h)
list(TRANSFORM VERILATOR_COMMON_SOURCES PREPEND ${VERILATOR_PATH}/)
add_library(verilated_library ${VERILATOR_COMMON_SOURCES} ${ALL_VERILATOR_OUTPUTS})
target_include_directories(verilated_library SYSTEM PUBLIC ${VERILATOR_INCLUDE_DIRS} ${VERILATOR_OUTPUT_DIR})
target_compile_options(verilated_library PRIVATE -w)
