`include "common.v"

module register_file(
  input wire [4:0] REG,
  input wire [31:0] IN_DATA,
  input wire N_WE,
  input wire N_OE,
  output logic [31:0] OUT_DATA
);
  // TODO: change to specific sram chip
  // 32 registers.
//  sram#(.DEPTH(5), .WIDTH(32)) registers(.ADDR(REG), .N_WE(N_WE), .N_OE(N_OE),
//    .IN_DATA(IN_DATA), .OUT_DATA(OUT_DATA));

  `ifdef FORMAL
  `endif
endmodule
