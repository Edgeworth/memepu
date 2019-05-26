`include "common.v"
module mmu(
  input wire [9:0] ADDR,  // TODO: For now a small amount of memory, 1 KiB.
  output logic [31:0] OUT
);
  assign OUT = {22'b0, ADDR};

  `ifdef FORMAL
  `endif
endmodule
