`include "common.v"

module microop_counter(
  input wire N_CLK,
  output logic [3:0] COUNT
);
  assign Y = ~(A & B);

  `ifdef FORMAL
  always_comb begin
    assert (Y == ~(A & B));
  end
  `endif
endmodule
