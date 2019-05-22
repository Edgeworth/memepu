`include "common.v"
// 3->8 Decoder, non-inverting outputs.
module chip74238(
  input wire [2:0] A,
  input wire N_E1,  // Enable input or not. (all high if not enabled).
  input wire N_E2,
  input wire E3,
  output logic [7:0] Y
);
  assign Y = !N_E1 && !N_E2 && E3 ? ~(8'b1 << A) : 0;

  `ifdef FORMAL
  always_comb begin
    if (!N_E1 && !N_E2 && E3) begin
      case (A)
        3'b000: begin assert (Y == 1); end
        3'b001: begin assert (Y == 2); end
        3'b010: begin assert (Y == 4); end
        3'b011: begin assert (Y == 8); end
        3'b100: begin assert (Y == 16); end
        3'b101: begin assert (Y == 32); end
        3'b110: begin assert (Y == 64); end
        3'b111: begin assert (Y == 128); end
      endcase
    end else begin
      assert (Y == 0);
    end
  end
  `endif
endmodule
