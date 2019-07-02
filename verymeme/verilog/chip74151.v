`include "common.v"
// 8->1 line selector/multiplexor.
module chip74151(
  input wire [7:0] I,  // Data values
  input wire N_E,  // Enable
  input wire [2:0] S,
  output logic Y,
  output logic N_Y
);
  assign Y = N_E ? 1'b0:I[S];
  assign N_Y = N_E ? 1'b1:!I[S];

  `ifdef FORMAL
  always_comb begin
    if (N_E) assert (Y == 1'b0 && N_Y == 1'b1);
    else begin
      case (S)
        3'b000: begin assert (Y == I[0] && N_Y == !I[0]); end
        3'b001: begin assert (Y == I[1] && N_Y == !I[1]); end
        3'b010: begin assert (Y == I[2] && N_Y == !I[2]); end
        3'b011: begin assert (Y == I[3] && N_Y == !I[3]); end
        3'b100: begin assert (Y == I[4] && N_Y == !I[4]); end
        3'b101: begin assert (Y == I[5] && N_Y == !I[5]); end
        3'b110: begin assert (Y == I[6] && N_Y == !I[6]); end
        3'b111: begin assert (Y == I[7] && N_Y == !I[7]); end
      endcase
    end
  end
  `endif
endmodule
