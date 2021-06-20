// Copyright 2019 E.
`include "common.v"

module sram5x32(
  input wire [4:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire [31:0] IN_DATA,
  input wire N_RST,
  output logic [31:0] OUT_DATA
);
  logic [31:0] mem [(1 << 5)-1:0] /*verilator public*/;

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:32'bZ;
  always_ff @(negedge N_WE) mem[ADDR] <= IN_DATA;

  `ifdef FORMAL
  // Consider any arbitrary address, and say that the value stored in the memory should be the
  // last one written to that address.
  (* anyconst *) wire [4:0] f_verify_addr;
  logic [31:0] f_verify_data;

  initial assume (f_verify_data == mem[f_verify_addr]);

  always_ff @(negedge N_WE) begin
    if (ADDR == f_verify_addr) f_verify_data <= IN_DATA;
  end

  always_comb begin
    if (N_RST) `CONTRACT (N_OE || N_WE);
    assert (f_verify_data == mem[f_verify_addr]);
  end
  `else
  wire _unused_ok = {N_RST};
  `endif
endmodule
