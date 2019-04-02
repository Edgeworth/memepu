`include "common.v"
/* verilator lint_off UNOPTFLAT */
module shifter(
  input wire [31:0] IN,
  input wire [4:0] SHFT,
  output logic [31:0] OUT
);
  wire [4:0] not_shft;
  wire unused_not_shft;
  chip7404 shft_not(.A({1'b0, SHFT}), .Y({unused_not_shft, not_shft}));

  wire [31:0] stages[6];
  assign stages[0] = IN;
  generate
    genvar i;
    for (i = 0; i < 5; i = i+1) begin
      buffer_mux shift_mux_low(.A(stages[i][15:0]), .B(stages[i][15:0]),
        .OUT(stages[i+1][15:0]), .SEL_A(not_shft[i]), .N_SEL_A(SHFT[i]));
      buffer_mux shift_mux_high(.A(stages[i][31:16]), .B(stages[i][31:16]),
        .OUT(stages[i+1][31:16]), .SEL_A(not_shft[i]), .N_SEL_A(SHFT[i]));
    end
  endgenerate

  assign OUT = stages[5];

  `ifdef FORMAL
  always_comb begin
    // Should rotate left.
//    assert (OUT == (IN << SHFT) | (IN >> (32 - SHFT)));
    assert (OUT == IN);
  end
  `endif
endmodule
