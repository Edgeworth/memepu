// Copyright 2019 E.
`include "common.v"
module buffer8(
  input wire [7:0] IN,
  input wire N_OE,
  output logic [7:0] OUT
);
  chip74245 buffer(.IN(IN), .OUT(OUT), .N_OE(N_OE));

  `ifdef FORMAL
  always_comb begin
    if (!N_OE) assert (OUT == IN);
  end
  `endif
endmodule
