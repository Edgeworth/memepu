// Copyright 2019 E.
`include "common.v"
module buffer32(
  input wire [31:0] IN,
  input wire N_OE,
  output logic [31:0] OUT
);
  buffer16 buf_lo(.IN(IN[15:0]), .OUT(OUT[15:0]), .N_OE(N_OE));
  buffer16 buf_hi(.IN(IN[31:16]), .OUT(OUT[31:16]), .N_OE(N_OE));

  `ifdef FORMAL
  always_comb begin
    if (!N_OE) assert (OUT == IN);
  end
  `endif
endmodule
