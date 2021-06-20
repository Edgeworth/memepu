// Copyright 2019 E.
`include "common.v"

// OR
module chip7432(
  input wire [3:0] A,
  input wire [3:0] B,
  output logic [3:0] Y
);
  assign Y = A | B;

  `ifdef FORMAL
  always_comb begin
    assert (Y == (A | B));
  end
  `endif
endmodule
