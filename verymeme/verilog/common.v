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
  // This line is modified by a sed expression by the build system so be careful.
// `define HEXFILE
  // Defines whether or not to use bootstrapping for srams. TODO: Finish implementing.
//  `define BOOTSTRAP

  // Schematics must use LUTs, so enable HEXFILE.
  `ifdef SCHEMATIC
  // `define HEXFILE
  `endif

  // TODO: yosys bug, does not support enums: https://github.com/YosysHQ/yosys/issues/248
  localparam MLU_ADD = 0;
  localparam MLU_SUB = 1;
  localparam MLU_AND = 2;
  localparam MLU_OR = 3;
  localparam MLU_XOR = 4;
  localparam MLU_NOT = 5;
  localparam MLU_ANOT = 6;  // AND_NOT; Used for masking out bits.
  localparam MLU_NOP1 = 7; // TODO: Zero and ones - if can't guarantee weakly pulled zero on bus?

  localparam SHIFTER_LEFT = 0;
  localparam SHIFTER_RIGHT = 1;
  localparam SHIFTER_SIGNEXT8 = 2;
  localparam SHIFTER_SIGNEXT16 = 3;
endpackage
`endif
