`include "common.v"
module buffer_mux3x32(
  input wire [31:0] A,
  input wire [31:0] B,
  input wire [31:0] C,
  input wire [1:0] SEL,
  input wire N_RST,
  output logic [31:0] OUT
);
  wire [31:0] out_a;
  wire [31:0] out_b;
  wire [31:0] out_c;
  buffer32 mux_a(.IN(A), .OUT(out_a), .N_OE(reg_sel_decoded[0]));
  buffer32 mux_b(.IN(B), .OUT(out_b), .N_OE(reg_sel_decoded[1]));
  buffer32 mux_c(.IN(C), .OUT(out_c), .N_OE(reg_sel_decoded[2]));

  wire [3:0] unused_y2;
  wire unused_reg_sel;
  wire [2:0] reg_sel_decoded;
  chip74139 decoder(.A1(SEL), .A2(0), .N_E1(0), .N_E2(1),
    .N_Y1({unused_reg_sel, reg_sel_decoded}), .N_Y2(unused_y2));

  `ifdef SCHEMATIC
  assign OUT = out_a;
  assign OUT = out_b;
  assign OUT = out_c;
  `else
  assign OUT = SEL == 2'b00 ? out_a : (SEL == 2'b01 ? out_b : (SEL == 2'b10 ? out_c : 0));
  `endif

  `ifdef FORMAL
  always_comb begin
    if (N_RST) begin
      `CONTRACT(SEL != 2'b11);  // Only support 3 inputs.
      case (SEL)
        2'b00: begin assert (OUT == A); end
        2'b01: begin assert (OUT == B); end
        2'b10: begin assert (OUT == C); end
        2'b11: begin assert (0); end
      endcase
    end
  end
  `else
  wire _unused_ok = {N_RST};
  `endif
endmodule
