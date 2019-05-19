`include "common.v"
/* verilator lint_off UNOPTFLAT */
module mlu_lookahead(
  input wire C_IN,
  input wire [7:0] P,
  input wire [7:0] G,
  output logic [7:0] CARRYS,
  // BOOTSTRAPPING flags:
  input wire [16:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);

  `ifdef SCHEMATIC
  // TODO(bootstrapping): Use BOOTSTRAP_ADDR.
  sram17x8#(.INITIAL("mlu_lookahead.hex")) lookahead_mem(
    .ADDR({C_IN, G, P}), .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA(BOOTSTRAP_DATA), .OUT_DATA(CARRYS));
  `else
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
  wire _unused_ok = &{BOOTSTRAP_ADDR, BOOTSTRAP_DATA, N_BOOTED, BOOTSTRAP_N_WE};
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
