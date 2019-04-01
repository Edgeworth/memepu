`include "common.v"
/* verilator lint_off UNOPTFLAT */
module alu_lookahead(
  input wire C_IN,
  input wire [7:0] P,
  input wire [7:0] G,
  output logic [7:0] CARRYS
);

  `ifdef SCHEMATIC
  wire [7:0] unused = 0;
  sram17x8#(.INITIAL("alu_lookahead.hex")) lookahead_mem(
    .ADDR({C_IN, G, P}), .N_WE(1), .N_OE(0), .IN_DATA(unused), .OUT_DATA(CARRYS));
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
