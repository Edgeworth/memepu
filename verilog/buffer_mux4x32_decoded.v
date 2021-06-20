// Copyright 2019 E.
`include "common.v"
module buffer_mux4x32_decoded(
  input wire [31:0] A,
  input wire [31:0] B,
  input wire [31:0] C,
  input wire [31:0] D,
  input wire N_SEL_A,
  input wire N_SEL_B,
  input wire N_SEL_C,
  input wire N_SEL_D,
  output logic [31:0] OUT
);
  wire [31:0] out_a;
  wire [31:0] out_b;
  wire [31:0] out_c;
  wire [31:0] out_d;
  buffer32 mux_a(.IN(A), .OUT(out_a), .N_OE(N_SEL_A));
  buffer32 mux_b(.IN(B), .OUT(out_b), .N_OE(N_SEL_B));
  buffer32 mux_c(.IN(C), .OUT(out_c), .N_OE(N_SEL_C));
  buffer32 mux_d(.IN(D), .OUT(out_d), .N_OE(N_SEL_D));

  `ifdef SCHEMATIC
  assign OUT = out_a;
  assign OUT = out_b;
  assign OUT = out_c;
  assign OUT = out_d;
  `else
  assign OUT = !N_SEL_A ? out_a : !N_SEL_B ? out_b : !N_SEL_C ? out_c : !N_SEL_D ? out_d : 32'b0;
  `endif

  `ifdef FORMAL
  always_comb begin
    `CONTRACT (!N_SEL_A + !N_SEL_B + !N_SEL_C + !N_SEL_D == 1);  // Can't select more than one.
    if (!N_SEL_A) begin assert (OUT == A); end
    else if (!N_SEL_B) begin assert (OUT == B); end
    else if (!N_SEL_C) begin assert (OUT == C); end
    else if (!N_SEL_D) begin assert (OUT == D); end
  end
  `endif
endmodule
