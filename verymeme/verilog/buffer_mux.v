`include "common.v"
// Yosys doesn't support tri-state logic, so concentrate the build-specific logic here.
module buffer_mux(
  input wire [15:0] A,
  input wire [15:0] B,
  input wire SEL_A,
  input wire N_SEL_A,
  output logic [15:0] OUT
);
  wire [15:0] out_a;
  wire [15:0] out_b;
  chip74LVC162244 mux_a(.IN(A), .OUT(out_a), .N_OE(N_SEL_A));
  chip74LVC162244 mux_b(.IN(B), .OUT(out_b), .N_OE(SEL_A));

  `ifdef SCHEMATIC
  assign OUT = out_a;
  assign OUT = out_b;
  `else
  assign OUT = SEL_A ? out_a : out_b;
  `endif

  `ifdef FORMAL
  always_comb begin
    `CONTRACT (SEL_A ^ N_SEL_A);  // N_SEL must be opposite of SEL.
    if (SEL_A) assert (OUT == A);
    else assert (OUT == B);
  end
  `endif
endmodule
