`include "common.v"

module chip7416374(
  input wire [7:0] D1,
  input wire [7:0] D2,
  input wire CLK1,
  input wire CLK2,
  input wire N_OE1,
  input wire N_OE2,
  output logic [7:0] Q1,
  output logic [7:0] Q2
);
  logic [7:0] low8;
  logic [7:0] high8;

  assign Q1 = N_OE1 == 0 ? low8:8'bZ;
  assign Q2 = N_OE2 == 0 ? high8:8'bZ;

  always_ff @(posedge CLK1) low8 <= D1;
  always_ff @(posedge CLK2) high8 <= D2;

  `ifdef FORMAL
  always_comb begin
    if (N_OE1 == 0) assert (Q1 == low8);
    if (N_OE2 == 0) assert (Q2 == high8);
  end
  always_ff @(posedge CLK1) assert (low8 == $past(D1));
  always_ff @(posedge CLK2) assert (high8 == $past(D2));
  `endif
endmodule
