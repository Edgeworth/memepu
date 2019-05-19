`include "common.v"
/* verilator lint_off UNOPTFLAT */
module shifter(
  input wire [31:0] IN,
  input wire [4:0] SHFT,
  input wire LEFT,  // True for left shift.
  input wire ARITH,  // True for arithmetic shift.
  output logic [31:0] OUT
);
  wire [4:0] not_shft;
  wire not_left;
  chip7404 notter(.A({LEFT, SHFT}), .Y({not_left, not_shft}));

  // Collect shift-in bit from |IN| not |pre_reverse| to avoid stacking gate delays.
  wire shift_in;
  wire [2:0] unused_and;
  chip7408 ander(.A({3'b0, ARITH}), .B({3'b0, IN[31]}), .Y({unused_and, shift_in}));

  // Do reverses for right shift.
  wire [31:0] pre_reverse;
  buffer_mux2x32 pre_reverse_mux(.A(IN), .B({IN[0], IN[1], IN[2], IN[3], IN[4], IN[5], IN[6],
    IN[7], IN[8], IN[9], IN[10], IN[11], IN[12], IN[13], IN[14], IN[15], IN[16], IN[17], IN[18],
    IN[19], IN[20], IN[21], IN[22], IN[23], IN[24], IN[25], IN[26], IN[27], IN[28], IN[29], IN[30],
    IN[31]}), .OUT(pre_reverse), .SEL_A(LEFT), .N_SEL_A(not_left));

  // Left-shift hardware.
  wire [31:0] stage[5];
  // Shift 1.
  buffer_mux2x32 shift_left_mux0(.A({pre_reverse[30:0], shift_in}), .B(pre_reverse),
    .OUT(stage[0]), .SEL_A(SHFT[0]), .N_SEL_A(not_shft[0]));

  // Shift 2.
  buffer_mux2x32 shift_left_mux1(.A({stage[0][29:0], {2{shift_in}}}), .B(stage[0]),
    .OUT(stage[1]), .SEL_A(SHFT[1]), .N_SEL_A(not_shft[1]));
  // Shift 4
  buffer_mux2x32 shift_left_mux2(.A({stage[1][27:0], {4{shift_in}}}), .B(stage[1]),
    .OUT(stage[2]), .SEL_A(SHFT[2]), .N_SEL_A(not_shft[2]));
  // Shift 8
  buffer_mux2x32 shift_left_mux3(.A({stage[2][23:0], {8{shift_in}}}), .B(stage[2]),
    .OUT(stage[3]), .SEL_A(SHFT[3]), .N_SEL_A(not_shft[3]));
  // Shift 16
  buffer_mux2x32 shift_left_mux4(.A({stage[3][15:0], {16{shift_in}}}), .B(stage[3]),
    .OUT(stage[4]), .SEL_A(SHFT[4]), .N_SEL_A(not_shft[4]));

  // Undo the reverses for right shift.
  buffer_mux2x32 post_reverse_mux(.A(stage[4]), .B({stage[4][0], stage[4][1], stage[4][2],
    stage[4][3], stage[4][4], stage[4][5], stage[4][6], stage[4][7], stage[4][8], stage[4][9],
    stage[4][10], stage[4][11], stage[4][12], stage[4][13], stage[4][14], stage[4][15],
    stage[4][16], stage[4][17], stage[4][18], stage[4][19], stage[4][20], stage[4][21],
    stage[4][22], stage[4][23], stage[4][24], stage[4][25], stage[4][26], stage[4][27],
    stage[4][28], stage[4][29], stage[4][30], stage[4][31]}),
    .OUT(OUT), .SEL_A(LEFT), .N_SEL_A(not_left));

  `ifdef FORMAL
  always_comb begin
    `CONTRACT (!(LEFT && ARITH));  // Left arithmetic shift does not make sense.
    // Should rotate left.
    if (LEFT) assert (OUT == (IN << SHFT));
    else if (ARITH) assert ($signed(OUT) == ($signed(IN) >>> SHFT));
    else assert (OUT == (IN >> SHFT));
  end
  `endif
endmodule
