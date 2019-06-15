`ifndef COMMON_INCLUDED
`define COMMON_INCLUDED
package common;
  // Must explicitly specify net types:
  `default_nettype none
  // This should be defined for generating schematics. This will enable schematic specific features
  // e.g. tri-state logic muxes.
//  `define SCHEMATIC
  // This enables hex files for look up tables. Using hex files makes formal
  // verification very slow, so disabling this will instead use in-verilog implementations.
  // Hexfiles are generated from probing in-verilog implementation behaviour using verilator.
// `define HEXFILE
  // Defines whether or not to use bootstrapping for srams. TODO: Finish implementing.
//  `define BOOTSTRAP

  // TODO: yosys bug, does not support enums: https://github.com/YosysHQ/yosys/issues/248
  localparam MLU_ADD = 0;
  localparam MLU_SUB = 1;
  localparam MLU_AND = 2;
  localparam MLU_OR = 3;
  localparam MLU_XOR = 4;
  localparam MLU_NOT = 5;
  localparam MLU_NOP0 = 6;  // TODO sign extend
  localparam MLU_NOP1 = 7;
endpackage
`endif
