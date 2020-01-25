`include "common.v"
// Yosys doesn't support tri-state logic, so concentrate the build-specific logic here.
module buffer_mux4x8(
  input wire [7:0] A,
  input wire [7:0] B,
  input wire [7:0] C,
  input wire [7:0] D,
  input wire [1:0] SEL,
  input wire N_RST,
  output logic [7:0] OUT
);
  wire [7:0] out_a;
  wire [7:0] out_b;
  wire [7:0] out_c;
  wire [7:0] out_d;
  buffer8 mux_a(.IN(A), .OUT(out_a), .N_OE(reg_sel_decoded[0]));
  buffer8 mux_b(.IN(B), .OUT(out_b), .N_OE(reg_sel_decoded[1]));
  buffer8 mux_c(.IN(C), .OUT(out_c), .N_OE(reg_sel_decoded[2]));
  buffer8 mux_d(.IN(D), .OUT(out_d), .N_OE(reg_sel_decoded[3]));

  wire [3:0] unused_y2;
  wire [3:0] reg_sel_decoded;
  chip74139 decoder(.A1(SEL), .A2(0), .N_E1(0), .N_E2(1),
    .N_Y1(reg_sel_decoded), .N_Y2(unused_y2));

  `ifdef SCHEMATIC
  assign OUT = out_a;
  assign OUT = out_b;
  assign OUT = out_c;
  assign OUT = out_d;
  `else
  assign OUT = (SEL == 2'b00) ? out_a : (SEL == 2'b01) ? out_b : (SEL == 2'b10) ? out_c :
      (SEL == 2'b11) ? out_d : 0;
  `endif

  `ifdef FORMAL
  always_comb begin
    if (N_RST) begin
      case (SEL)
        2'b00: begin assert (OUT == A); end
        2'b01: begin assert (OUT == B); end
        2'b10: begin assert (OUT == C); end
        2'b11: begin assert (OUT == D); end
      endcase
    end
  end
  `else
  wire _unused_ok = {N_RST};
  `endif
endmodule
