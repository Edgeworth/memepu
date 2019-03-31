`include "common.v"

// 74LVC162244 buffer.
module chip7400(
  input wire [15:0] IN,
  input wire [15:0] OUT,
);
  assign Y = ~(A & B);

  `ifdef FORMAL
  always_comb begin
    assert (Y == ~(A & B));
  end
  `endif
endmodule
