// Copyright 2019 E.
`include "common.v"
/* verilator lint_off UNOPTFLAT */
module mlu_lookahead(
  input wire [16:0] ADDR,
  output logic [7:0] CARRYS,
  // Bootstrapping signals:
  input wire [16:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  `ifdef HEXFILE
  // TODO(bootstrapping): Use BOOTSTRAP_ADDR.
  lut17x8#(.INITIAL("mlu_lookahead.hex")) lookahead_mem(
    .ADDR(ADDR), .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA(BOOTSTRAP_DATA), .OUT_DATA(CARRYS));
  `else
  wire C_IN = ADDR[0];
  wire [7:0] P = ADDR[8:1];
  wire [7:0] G = ADDR[16:9];

  logic prev_carry, carry;
  integer i;
  always_comb begin
    prev_carry = C_IN;
    for (i = 0; i < 8; i = i+1) begin
      carry = (prev_carry && P[i]) || G[i];
      CARRYS[i] = carry;
      prev_carry = carry;
    end
  end
  `endif

  `ifndef BOOTSTRAP
  // Mark bootstrap signals as okay to not be used if not using bootstrapping.
  wire [26:0] _unused_ok = {BOOTSTRAP_ADDR, BOOTSTRAP_DATA, N_BOOTED, BOOTSTRAP_N_WE};
  `endif

  `ifdef FORMAL
  logic f_prev_carry, f_carry;
  integer f_i;
  always_comb begin
    f_prev_carry = C_IN;
    for (f_i = 0; f_i < 8; f_i = f_i+1) begin
      f_carry = (f_prev_carry && P[f_i]) || G[f_i];
      assert (CARRYS[f_i] == f_carry);
      f_prev_carry = f_carry;
    end
  end
  `endif
endmodule
