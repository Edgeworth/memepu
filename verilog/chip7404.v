// Copyright 2019 E.
`include "common.v"

// NOT
module chip7404(
  input wire [5:0] A,
  output logic [5:0] Y
);
  assign Y = ~A;

  `ifdef FORMAL
  always_comb begin
    assert (Y == ~A);
  end
  `endif
endmodule
