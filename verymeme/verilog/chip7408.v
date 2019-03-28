`include "common.v"

module chip7408(
  input wire [3:0] A,
  input wire [3:0] B,
  output logic [3:0] Y
);
  assign Y = A & B;

  `ifdef FORMAL
  always_comb begin
    assert (Y == (A & B));
  end
  `endif
endmodule
