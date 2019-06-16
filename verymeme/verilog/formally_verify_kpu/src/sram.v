`include "common.v"

module sram(
  input wire [DEPTH-1:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire [WIDTH-1:0] IN_DATA,
  input wire N_RST,
  output logic [WIDTH-1:0] OUT_DATA
);
  parameter DEPTH = 2;
  parameter WIDTH = 8;
  logic [WIDTH-1:0] mem [(1 << DEPTH)-1:0] /*verilator public*/;

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:{WIDTH{1'bZ}};
  always_ff @(negedge N_WE) mem[ADDR] <= IN_DATA;

  `ifdef FORMAL
  // Consider any arbitrary address, and say that the value stored in the memory should be the
  // last one written to that address.
  (* anyconst *) wire [DEPTH-1:0] f_verify_addr;
  logic [WIDTH-1:0] f_verify_data;

  initial assume (f_verify_data == mem[f_verify_addr]);

  always_ff @(negedge N_WE) begin
    if (ADDR == f_verify_addr) f_verify_data <= IN_DATA;
  end

  always_comb begin
    if (N_RST) `CONTRACT (N_OE || N_WE);
    assert (f_verify_data == mem[f_verify_addr]);
  end
  `else
  wire _unused_ok = &{N_RST};
  `endif
endmodule
