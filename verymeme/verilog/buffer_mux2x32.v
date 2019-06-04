`include "common.v"
module buffer_mux2x32(
  input wire [31:0] A,
  input wire [31:0] B,
  input wire SEL_A,
  input wire N_SEL_A,
  output logic [31:0] OUT
);
  wire [31:0] out_a;
  wire [31:0] out_b;
  buffer32 mux_a(.IN(A), .OUT(out_a), .N_OE(N_SEL_A));
  buffer32 mux_b(.IN(B), .OUT(out_b), .N_OE(SEL_A));

  `ifdef SCHEMATIC
  assign OUT = out_a;
  assign OUT = out_b;
  `else
  assign OUT = SEL_A ? out_a : out_b;
  `endif

  `ifdef FORMAL
  always_comb begin
    `CONTRACT (SEL_A ^ N_SEL_A);  // N_SEL must be opposite of SEL.
    if (SEL_A) begin assert (OUT == A); end
    else begin assert (OUT == B); end
  end
  `endif
endmodule
