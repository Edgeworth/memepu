`include "common.v"

module register32(
  input wire CLK,
  input wire [31:0] IN,
  input wire N_OE,
  output logic [31:0] OUT
);
  chip7416374 low16(.D1(IN[7:0]), .D2(IN[15:8]), .CLK1(CLK), .CLK2(CLK),
    .N_OE1(N_OE), .N_OE2(N_OE), .Q1(OUT[7:0]), .Q2(OUT[15:8]));
  chip7416374 high16(.D1(IN[23:16]), .D2(IN[31:24]), .CLK1(CLK), .CLK2(CLK),
    .N_OE1(N_OE), .N_OE2(N_OE), .Q1(OUT[23:16]), .Q2(OUT[31:24]));

  `ifdef FORMAL
  `endif
endmodule
