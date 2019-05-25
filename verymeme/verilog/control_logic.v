`include "common.v"
/* verilator lint_off UNUSED */  // TODO: Remove
module control_logic(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST,
  input wire [5:0] OPCODE,
  output logic [1:0] REG_SEL, // 0=>Opcode reg0, 1=>Opcode reg1, 2=>Control logic reg sel.
  output logic [4:0] REG_SRC, // Control logic reg src.
  output logic [3:0] ALU_PLANE,
  // In plane signals:
  output logic REG_N_IN_CLK,
  output logic TMP0_IN_CLK,
  output logic TMP1_IN_CLK,
  output logic OPWORD_IN_CLK,
  output logic OPCODE_IN_CLK,
  // Out plane signals:
  output logic REG_N_OUT,
  output logic TMP0_N_OUT,
  output logic TMP1_N_OUT,
  output logic MLU_N_OUT,
  output logic SHIFTER_N_OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  // TODO: Micro-op counter:
  wire [4:0] microop_count;
  microop_counter counter(.CLK(CLK), .N_RST(N_RST), .COUNT(microop_count));

  // Outputs:
  // In plane: NONE, REG, TMP0, TMP1
  wire [2:0] control_in_plane;
  // Out plane: NONE, REG, TMP0, TMP1, MLU, SHIFTER
  wire [2:0] control_out_plane;
  // ALU plane:
  //   For MLU: 3 bits for op select, 1 bit for carry.
  //   For shifter: 2 bits for direction and arithmetic or not.
  wire [14:0] unused_control;
  // TODO: change to specific sram chip
  sram#(.DEPTH(11), .WIDTH(32), .INITIAL("microcode.hex")) microcode(.ADDR({OPCODE, microop_count}),
    .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA({BOOTSTRAP_DATA, 24'b0}),  // TODO(bootstrap): only feeding 8 bits in
    .OUT_DATA({control_in_plane, control_out_plane, ALU_PLANE, REG_SEL, REG_SRC, unused_control}));
  // TODO: Need to latch on N_CLK(?)

  // In plane decoder - enable on CLK to do pulse.
  wire unused_in_none;
  wire reg_in_clk;
  wire [1:0] unused_in_plane;
  chip74238 in_plane_decoder(.A(control_in_plane), .N_E1(0), .N_E2(0), .E3(CLK),
    .Y({unused_in_plane, OPCODE_IN_CLK, OPWORD_IN_CLK, TMP1_IN_CLK, TMP0_IN_CLK, reg_in_clk,
        unused_in_none}));

  // Inverter:
  wire [4:0] unused_inverter;
  chip7404 inverter(.A({5'b0, reg_in_clk}), .Y({unused_inverter, REG_N_IN_CLK}));

  // Out plane decoder:
  wire unused_out_none;
  wire [1:0] unused_out_plane;
  chip74138 out_plane_decoder(.A(control_out_plane), .N_E1(0), .N_E2(0), .E3(1),
    .N_Y({unused_out_plane, SHIFTER_N_OUT, MLU_N_OUT, TMP1_N_OUT,
        TMP0_N_OUT, REG_N_OUT, unused_out_none}));

  `ifdef FORMAL
  // TODO: More testing.
  always_comb begin
    assert (REG_SEL != 2'b11);  // Not a valid register selector option.

    // Don't try to write and read to the same thing:
    assert (!REG_IN_CLK || REG_N_OUT);
    assert (!TMP0_IN_CLK || TMP0_N_OUT);
    assert (!TMP1_IN_CLK || TMP1_N_OUT);

    // Don't try to do a left-arithmetic shift, it doesn't make sense.
    if (SHIFTER_N_OUT) assert (ALU_PLANE[1:0] != 2'b11);

    // TODO: Make sure subtract provides carry.

    `ifdef BOOTSTRAP
    if (!N_BOOTED) `CONTRACT(BOOTSTRAP_N_WE);  // Don't write after boot.
    `else
    `CONTRACT(BOOTSTRAP_N_WE);  // Don't write if we're not bootstrapping.
    `endif
  end
  `endif
endmodule
