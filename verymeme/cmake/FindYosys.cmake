# YOSYS_FOUND - System has Yosys
# YOSYS_LIBRARIES - The libraries needed to use Yosys
# YOSYS_OPTIONS - Compiler switches required for using Yosys

include(FindPackageHandleStandardArgs)

find_path(YOSYS_CONFIG_PATH yosys-config)
if (NOT "${YOSYS_CONFIG_PATH}" STREQUAL "YOSYS_CONFIG_PATH-NOTFOUND")
  execute_process(COMMAND yosys-config --cxxflags OUTPUT_VARIABLE
      YOSYS_OPTIONS OUTPUT_STRIP_TRAILING_WHITESPACE)
  execute_process(COMMAND yosys-config --ldflags OUTPUT_VARIABLE
      YOSYS_LDFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
  execute_process(COMMAND yosys-config --ldlibs OUTPUT_VARIABLE
      YOSYS_LIBRARIES OUTPUT_STRIP_TRAILING_WHITESPACE)
endif ()

find_package_handle_standard_args(Yosys DEFAULT_MSG
    YOSYS_OPTIONS YOSYS_LDFLAGS YOSYS_LIBRARIES)

separate_arguments(YOSYS_OPTIONS)
separate_arguments(YOSYS_LDFLAGS)
separate_arguments(YOSYS_LIBRARIES)