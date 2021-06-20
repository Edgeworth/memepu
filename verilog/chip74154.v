`include "common.v"
// 4->16 Decoder, inverting outputs.
module chip74154(
  input wire [3:0] A,
  input wire N_E1,  // Enable input or not. (all high if not enabled).
  input wire N_E2,
  output logic [15:0] N_Y
);
  assign N_Y = !N_E1 && !N_E2 ? ~(16'b1 << A):16'hFFFF;

  `ifdef FORMAL
  always_comb begin
    if (!N_E1 && !N_E2) begin
      case (A)
        4'b0000: begin assert (N_Y == 16'b1111111111111110); end
        4'b0001: begin assert (N_Y == 16'b1111111111111101); end
        4'b0010: begin assert (N_Y == 16'b1111111111111011); end
        4'b0011: begin assert (N_Y == 16'b1111111111110111); end
        4'b0100: begin assert (N_Y == 16'b1111111111101111); end
        4'b0101: begin assert (N_Y == 16'b1111111111011111); end
        4'b0110: begin assert (N_Y == 16'b1111111110111111); end
        4'b0111: begin assert (N_Y == 16'b1111111101111111); end
        4'b1000: begin assert (N_Y == 16'b1111111011111111); end
        4'b1001: begin assert (N_Y == 16'b1111110111111111); end
        4'b1010: begin assert (N_Y == 16'b1111101111111111); end
        4'b1011: begin assert (N_Y == 16'b1111011111111111); end
        4'b1100: begin assert (N_Y == 16'b1110111111111111); end
        4'b1101: begin assert (N_Y == 16'b1101111111111111); end
        4'b1110: begin assert (N_Y == 16'b1011111111111111); end
        4'b1111: begin assert (N_Y == 16'b0111111111111111); end
      endcase
    end else begin
      assert (N_Y == 16'hFFFF);
    end
  end
  `endif
endmodule
