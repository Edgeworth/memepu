// Copyright 2019 E.
`include "common.v"

module lut12x8(
  input wire [11:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire [7:0] IN_DATA,
  output logic [7:0] OUT_DATA
);
  parameter INITIAL = "mlu_slice.hex";
  logic [7:0] mem [(1 << 12)-1:0];

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:8'bZ;
  always_ff @(negedge N_WE) mem[ADDR] <= IN_DATA;

  // Load initial data if not bootstrapping.
  `ifndef BOOTSTRAP
  initial begin
    $readmemh(INITIAL, mem);
  end
  `endif

  `ifdef FORMAL
  // Consider any arbitrary address, and say that the value stored in the memory should be the
  // last one written to that address.
  (* anyconst *) wire [11:0] f_verify_addr;
  logic [7:0] f_verify_data;

  initial assume (f_verify_data == mem[f_verify_addr]);

  always_ff @(negedge N_WE) begin
    if (ADDR == f_verify_addr) f_verify_data <= IN_DATA;
  end

  always_comb begin
    `CONTRACT (N_OE || N_WE);
    assert (f_verify_data == mem[f_verify_addr]);
  end

  // Assume data doesn't change if not bootstrapping and there is an initial file specified.
  `ifndef BOOTSTRAP
  logic [7:0] f_mem [(1 << 12)-1:0];
  integer f_i;
  always_comb begin
    `CONTRACT (N_WE);
    $readmemh(INITIAL, f_mem);
    for (f_i = 0; f_i < (1 << 12); f_i = f_i+1) assert (mem[f_i] == f_mem[f_i]);
  end
  `endif
  `endif
endmodule
