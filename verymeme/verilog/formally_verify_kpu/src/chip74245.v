`include "common.v"
module chip74245(
  input wire [7:0] IN,
  input wire N_OE,
  output logic [7:0] OUT
);
  // Direction signal for 74245:
  //   If 0, B => A. If 1, A => B. Normally want 1, this implementation only suports 1.
  //   Here map A => IN, B => OUT.
  assign OUT = N_OE == 0 ? IN:8'bZ;

  `ifdef FORMAL
  always_comb begin
    if (N_OE == 0)
      assert (IN == OUT);
  end
  `endif
endmodule
