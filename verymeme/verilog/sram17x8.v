`include "common.v"

module sram17x8(
  input wire [16:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire [7:0] IN_DATA,
  output logic [7:0] OUT_DATA
);
  parameter INITIAL = "mlu_lookahead.hex";  // TODO remove.
  logic [7:0] mem [(1 << 17)-1:0];

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:8'bZ;
  always_ff @(negedge N_WE) mem[ADDR] <= IN_DATA;

  `ifdef SCHEMATIC
  // TODO: Bootstrapping
  initial begin
    $readmemh(INITIAL, mem);
  end
  `endif

  `ifdef FORMAL
  `ifdef SCHEMATIC
  logic [7:0] f_mem [(1 << 17)-1:0];
  integer f_i;
  always_comb begin
    `CONTRACT (N_WE);
    $readmemh(INITIAL, f_mem);
    for (f_i = 0; f_i < (1 << 17); f_i = f_i+1) assert (mem[f_i] == f_mem[f_i]);
  end
  `endif
  `endif
endmodule
