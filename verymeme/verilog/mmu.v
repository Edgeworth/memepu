`include "common.v"
module mmu(
  input wire [31:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire N_RST,
  input wire [31:0] IN,
  output logic [31:0] OUT
);
  sram#(.DEPTH(10), .WIDTH(32), .INITIAL("boot.hex")) ram(.ADDR(ADDR[9:0]), .N_WE(N_WE),
    .N_OE(N_OE), .IN_DATA(IN), .N_RST(N_RST), .OUT_DATA(OUT));

  wire _unused_ok = &{ADDR[31:10]}; // TODO REMOVE.

  `ifdef FORMAL
  always_comb begin
    if (N_RST) `CONTRACT(N_WE || N_OE);
  end
  `endif
endmodule
