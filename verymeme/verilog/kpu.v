`include "common.v"
module kpu(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST
);
  // Timer:
  wire [31:0] time32;
  timer timer(.CLK(CLK), .N_RST(N_RST), .TIME(time32));

  // ALU:
endmodule
