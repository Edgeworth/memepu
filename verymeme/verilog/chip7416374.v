`include "common.v"

module chip7416374(
  input wire [7:0] D1,
  input wire [7:0] D2,
  input /*u*/ wire CLK1,
  input /*u*/ wire CLK2,
  input /*u*/ wire N_OE1,
  input /*u*/ wire N_OE2,
  output /*u*/ wire [7:0] Q1,
  output /*u*/ wire [7:0] Q2
);
  logic [7:0] low;
  logic [7:0] high;

  assign Q1 = N_OE1 == 0 ? low:8'bZ;
  assign Q2 = N_OE2 == 0 ? high:8'bZ;

  always_ff @(posedge CLK1) low <= D1;
  always_ff @(posedge CLK2) high <= D2;

  `ifdef FORMAL
  always_comb begin
    if (N_OE1 == 0) assert (Q1 == low);
    if (N_OE2 == 0) assert (Q2 == high);
  end
  always_ff @(posedge CLK1) assert (low == $past(D1));
  always_ff @(posedge CLK2) assert (high == $past(D2));
  `endif
endmodule
