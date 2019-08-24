`include "common.v"
module vga(
  input wire [13:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire N_RST,
  input wire [31:0] IN,
  output logic [31:0] OUT
);
  // TODO(improvement): Output vga signals.
  // Need to run at twice speed to allow reading and writing at the same time.
  sram#(.DEPTH(14), .WIDTH(32)) vram0(.ADDR(ADDR), .N_WE(N_WE),
    .N_OE(N_OE), .IN_DATA(IN), .N_RST(N_RST), .OUT_DATA(OUT));

  `ifdef FORMAL
  always_comb begin
    if (N_RST) `CONTRACT(N_WE || N_OE);
  end
  `endif
endmodule
