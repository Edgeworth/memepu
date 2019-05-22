`include "common.v"
// 3->8 Decoder, inverting outputs.
module chip74138(
  input wire [2:0] A,
  input wire N_E1,  // Enable input or not. (all high if not enabled).
  input wire N_E2,
  input wire E3,
  output logic [7:0] N_Y
);
  assign N_Y = !N_E1 && !N_E2 && E3 ? ~(8'b1 << A) : 8'hFF;

  `ifdef FORMAL
  always_comb begin
    if (!N_E1 && !N_E2 && E3) begin
      case (A)
        3'b000: begin assert (N_Y == 8'b11111110); end
        3'b001: begin assert (N_Y == 8'b11111101); end
        3'b010: begin assert (N_Y == 8'b11111011); end
        3'b011: begin assert (N_Y == 8'b11110111); end
        3'b100: begin assert (N_Y == 8'b11101111); end
        3'b101: begin assert (N_Y == 8'b11011111); end
        3'b110: begin assert (N_Y == 8'b10111111); end
        3'b111: begin assert (N_Y == 8'b01111111); end
      endcase
    end else begin
      assert (N_Y == 8'hFF);
    end
  end
  `endif
endmodule
