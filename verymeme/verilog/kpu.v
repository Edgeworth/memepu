`include "common.v"
/* verilator lint_off UNUSED */  // TODO REMOVE
module kpu(
  input wire CLK,
//  input wire N_CLK,
  input wire N_RST
);
  wire [31:0] bus;
  // Scratch registers - invisible to running code.
  register32 tmp0(.CLK(CLK), .IN(bus), .N_OE(0), .OUT(bus));

  // Timer:
  wire [31:0] time32;
  timer timer(.CLK(CLK), .N_RST(N_RST), .TIME(time32));

  // MLU:
endmodule
