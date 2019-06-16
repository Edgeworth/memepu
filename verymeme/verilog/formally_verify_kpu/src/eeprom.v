`include "common.v"
module eeprom(
  input wire [DEPTH-1:0] ADDR,
  input wire N_OE,
  output logic [WIDTH-1:0] OUT_DATA
);
  parameter DEPTH = 2;
  parameter WIDTH = 8;
  parameter INITIAL = "formal.hex";
  logic [WIDTH-1:0] mem [(1 << DEPTH)-1:0];

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:8'bZ;

  initial begin
    $readmemh(INITIAL, mem);
  end

  `ifdef FORMAL
  logic [WIDTH-1:0] f_mem [(1 << DEPTH)-1:0];
  integer f_i;
  always_comb begin
    $readmemh(INITIAL, f_mem);
    for (f_i = 0; f_i < (1 << DEPTH); f_i = f_i+1) assert (mem[f_i] == f_mem[f_i]);
    if (!N_OE) assert (OUT_DATA == f_mem[ADDR]);
  end
  `endif
endmodule
