`include "common.v"

module sram(
  input wire [DEPTH-1:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire [WIDTH-1:0] IN_DATA,
  output wire [WIDTH-1:0] OUT_DATA
);
  parameter DEPTH = 12;
  parameter WIDTH = 8;
  parameter INITIAL = "alu_slice.hex";  // TODO remove.
  logic [WIDTH-1:0] mem [(1 << DEPTH)-1:0];

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:8'bZ;
  always_ff @(negedge N_WE) mem[ADDR] <= IN_DATA;

  `ifdef HEXFILE
  // TODO: Bootstrapping
  initial begin
    $readmemh(INITIAL, mem);
  end
  `endif

  `ifdef FORMAL
  // Consider any arbitrary address, and say that the value stored in the memory should be the
  // last one written to that address.
  (* anyconst *) wire [DEPTH-1:0] verify_addr;
  logic [WIDTH-1:0] verify_data;

  initial assume (verify_data == mem[verify_addr]);

  always_ff @(negedge N_WE) begin
    if (ADDR == verify_addr) verify_data <= IN_DATA;
  end

  always_comb begin
        `CONTRACT (N_OE || N_WE);
    assert (verify_data == mem[verify_addr]);
  end

  `ifdef HEXFILE
  logic [WIDTH-1:0] mem_cpy [(1 << DEPTH)-1:0];
  integer i;
  always_comb begin
        `CONTRACT (N_WE);
    $readmemh(INITIAL, mem_cpy);
    for (i = 0; i < (1 << DEPTH); i = i+1) assert (mem[i] == mem_cpy[i]);
  end
  `endif
  `endif
endmodule
