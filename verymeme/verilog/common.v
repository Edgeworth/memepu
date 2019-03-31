`ifndef COMMON_INCLUDED
`define COMMON_INCLUDED
package common;
  // Must explicitly specify net types:
  `default_nettype none
  // Load hex files into SRAMs using readmemh. This makes formal verification very slow, so
  // disabling this will instead use in-verilog implementations.
  // This should be defined for generating schematics.
  `define HEXFILE

  // TODO: yosys bug, does not support enums: https://github.com/YosysHQ/yosys/issues/248
  localparam ALU_ADD = 0;
  localparam ALU_SUB = 1;
  localparam ALU_AND = 2;
  localparam ALU_OR = 3;
  localparam ALU_XOR = 4;
  localparam ALU_NOT = 5;
  localparam ALU_NOP0 = 6;  // TODO sign extend
  localparam ALU_NOP1 = 7;
endpackage
`endif
