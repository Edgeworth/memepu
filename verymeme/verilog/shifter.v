`include "common.v"
/* verilator lint_off UNUSED */
module shifter(
  input wire [31:0] IN,
  input wire [4:0] SHFT,
  output logic [31:0] OUT
);
  wire [15:0] stage0_out;
  wire [4:0] not_shft;
  wire unused_not_shft;

  chip7404 shft_not(.A({1'b0, SHFT}), .Y({unused_not_shft, not_shft}));

  buffer_mux stage0_mux_lo(.A(IN[15:0]), .B({IN[14:0], IN[15]}), .OUT(stage0_out),
    .SEL_A(not_shft[0]), .N_SEL_A(SHFT[0]));

  assign OUT[15:0] = stage0_out[15:0];
  assign OUT[31:16] = IN[31:16];

  `ifdef FORMAL
  always_comb begin
    assert (OUT[15:0] == (IN[15:0] << SHFT[0]) | (SHFT[0] & IN[15]));
  end
  `endif
endmodule
