// Copyright 2019 E.
`include "common.v"
module buffer16(
  input wire [15:0] IN,
  input wire N_OE,
  output logic [15:0] OUT
);
  chip74LVC162244 buffer(.IN(IN), .OUT(OUT), .N_OE(N_OE));

  `ifdef FORMAL
  always_comb begin
    if (!N_OE) assert (OUT == IN);
  end
  `endif
endmodule
