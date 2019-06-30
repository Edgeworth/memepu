`include "common.v"
/* verilator lint_off UNOPTFLAT */
module shifter(
  input wire [31:0] IN,
  input wire [4:0] SHFT,
  input wire [1:0] SEL,  // LEFT SHIFT, RIGHT SHIFT, SIGNEXT8, SIGNEXT16
  input wire ARITH,  // Arithmetic shift or not.
  input wire N_RST,
  output logic [31:0] OUT
);
  wire [4:0] n_shft;
  wire right_shift;
  chip7404 inverter0(.A({n_right_shift, SHFT}), .Y({right_shift, n_shft}));

  wire [3:0] unused_y2;
  wire n_left_shift;
  wire n_right_shift;
  wire n_signext8;
  wire n_signext16;
  chip74139 decoder(.A1(SEL), .A2(0), .N_E1(0), .N_E2(1),
    .N_Y1({n_signext16, n_signext8, n_right_shift, n_left_shift}), .N_Y2(unused_y2));

  // Collect shift-in bit from |IN| not |pre_reversed| to avoid stacking gate delays.
  wire shift_in;
  wire [2:0] unused_and;
  chip7408 ander(.A({3'b0, ARITH}), .B({3'b0, IN[31]}), .Y({unused_and, shift_in}));

  wire [31:0] pre_step;
  wire [31:0] pre_reversed = {IN[0], IN[1], IN[2], IN[3], IN[4], IN[5], IN[6], IN[7], IN[8], IN[9],
      IN[10], IN[11], IN[12], IN[13], IN[14], IN[15], IN[16], IN[17], IN[18], IN[19], IN[20],
      IN[21], IN[22], IN[23], IN[24], IN[25], IN[26], IN[27], IN[28], IN[29], IN[30], IN[31]};
  wire [31:0] pre_signext8 = {{24{IN[7]}}, IN[7:0]};
  wire [31:0] pre_signext16 = {{16{IN[15]}}, IN[15:0]};
  buffer_mux4x32_decoded pre_step_mux(.A(IN), .B(pre_reversed), .C(pre_signext8), .D(pre_signext16),
    .N_SEL_A(n_left_shift), .N_SEL_B(n_right_shift), .N_SEL_C(n_signext8), .N_SEL_D(n_signext16),
    .OUT(pre_step));

  // Left-shift hardware.
  wire [31:0] stage[5];
  // Shift 1.
  buffer_mux2x32 shift_left_mux0(.A({pre_step[30:0], shift_in}), .B(pre_step),
    .OUT(stage[0]), .SEL_A(SHFT[0]), .N_SEL_A(n_shft[0]));

  // Shift 2.
  buffer_mux2x32 shift_left_mux1(.A({stage[0][29:0], {2{shift_in}}}), .B(stage[0]),
    .OUT(stage[1]), .SEL_A(SHFT[1]), .N_SEL_A(n_shft[1]));
  // Shift 4
  buffer_mux2x32 shift_left_mux2(.A({stage[1][27:0], {4{shift_in}}}), .B(stage[1]),
    .OUT(stage[2]), .SEL_A(SHFT[2]), .N_SEL_A(n_shft[2]));
  // Shift 8
  buffer_mux2x32 shift_left_mux3(.A({stage[2][23:0], {8{shift_in}}}), .B(stage[2]),
    .OUT(stage[3]), .SEL_A(SHFT[3]), .N_SEL_A(n_shft[3]));
  // Shift 16
  buffer_mux2x32 shift_left_mux4(.A({stage[3][15:0], {16{shift_in}}}), .B(stage[3]),
    .OUT(stage[4]), .SEL_A(SHFT[4]), .N_SEL_A(n_shft[4]));

  // Undo the reverses for right shift.
  buffer_mux2x32 post_reverse_mux(.A(stage[4]), .B({stage[4] [0], stage[4] [1], stage[4] [2],
      stage[4] [3], stage[4] [4], stage[4] [5], stage[4] [6], stage[4] [7], stage[4] [8], stage[4] [9],
      stage[4] [10], stage[4] [11], stage[4] [12], stage[4] [13], stage[4] [14], stage[4] [15],
      stage[4] [16], stage[4] [17], stage[4] [18], stage[4] [19], stage[4] [20], stage[4] [21],
      stage[4] [22], stage[4] [23], stage[4] [24], stage[4] [25], stage[4] [26], stage[4] [27],
      stage[4] [28], stage[4] [29], stage[4] [30], stage[4] [31]}),
    .OUT(OUT), .SEL_A(n_right_shift), .N_SEL_A(right_shift));

  `ifdef FORMAL
  always_comb begin
    if (N_RST) begin
      `CONTRACT (n_left_shift || !ARITH);  // Left arithmetic shift does not make sense.
      `CONTRACT (n_signext8 || n_signext16);  // Can't sign extend 8 bit and 16 bit at the same time.
      // If sign extending, can't also reverse bits (right shift).
      `CONTRACT ((n_signext8 && n_signext16) || !n_left_shift);
      // If sign extending, can't also shift.
      `CONTRACT ((n_signext8 && n_signext16) || (SHFT == 5'b0));
      // Should rotate left.
      if (!n_left_shift) assert (OUT == (IN << SHFT));
      else if (!n_right_shift && ARITH) assert ($signed(OUT) == ($signed(IN) >>> SHFT));
      else if (!n_signext8) assert (OUT == ({{24{IN[7]}}, IN[7:0]}));
      else if (!n_signext16) assert (OUT == ({{16{IN[15]}}, IN[15:0]}));
      else assert (OUT == (IN >> SHFT));
    end
  end
  `else
  wire _unused_ok = &{N_RST};
  `endif
endmodule
