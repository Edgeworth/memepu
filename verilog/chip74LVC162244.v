// Copyright 2019 E.
`include "common.v"

// 74LVC162244 buffer.
module chip74LVC162244(
  input wire [15:0] IN,
  input wire N_OE,
  output logic [15:0] OUT
);
  assign OUT = N_OE == 0 ? IN:16'bZ;

  `ifdef FORMAL
  always_comb begin
    if (N_OE == 0)
      assert (OUT == IN);
  end
  `endif
endmodule
