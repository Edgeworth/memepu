`include "common.v"
// Yosys doesn't support tri-state logic, so concentrate the build-specific logic here.
module buffer_mux3x8(
  input wire [7:0] A,
  input wire [7:0] B,
  input wire [7:0] C,
  input wire [1:0] SEL,
  output logic [7:0] OUT
);
  wire [7:0] out_a;
  wire [7:0] out_b;
  wire [7:0] out_c;
  chip74245 mux_a(.IN(A), .OUT(out_a), .N_OE(reg_sel_decoded[0]));
  chip74245 mux_b(.IN(B), .OUT(out_b), .N_OE(reg_sel_decoded[1]));
  chip74245 mux_c(.IN(C), .OUT(out_c), .N_OE(reg_sel_decoded[2]));

  wire [3:0] unused_y2;
  wire [3:0] reg_sel_decoded;
  chip74139 decoder(.A1(SEL), .A2(0), .N_E1(0), .N_E2(1), .N_Y1(reg_sel_decoded), .N_Y2(unused_y2));

  `ifdef SCHEMATIC
  assign OUT = out_a;
  assign OUT = out_b;
  assign OUT = out_c;
  `else
  assign OUT = SEL == 2'b00 ? out_a : (SEL == 2'b01 ? out_b : (SEL == 2'b10 ? out_c : 0));
  `endif

  `ifdef FORMAL
  always_comb begin
   `CONTRACT (SEL != 2'b11);  // Only support 3 inputs.
    case (SEL)
      2'b00: begin assert (OUT == A); end
      2'b01: begin assert (OUT == B); end
      2'b10: begin assert (OUT == C); end
    endcase
  end
  `endif
endmodule
