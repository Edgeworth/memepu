`include "common.v"

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
