`include "common.v"
/* verilator lint_off UNUSED */  // TODO: Remove
module control_logic(
  input wire [5:0] OPCODE,
  input wire CLK,
  input wire N_CLK,
  output wire [1:0] REG_SEL, // 0=>Opcode reg0, 1=>Opcode reg1, 2=>Control logic reg sel.
  output wire [4:0] REG_SRC, // Control logic reg src.
  // In plane signals:
  output wire CONTROL_REG_N_IN,
  output wire CONTROL_TMP0_N_IN,
  output wire CONTROL_TMP1_N_IN,
  // Out plane signals:
  output wire CONTROL_REG_N_OUT,
  output wire CONTROL_TMP0_N_OUT,
  output wire CONTROL_TMP1_N_OUT,
  output wire CONTROL_MLU_N_OUT,
  output wire CONTROL_SHIFTER_N_OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  // Outputs:
  // In plane: NONE, REG, TMP0, TMP1
  wire [2:0] control_in_plane;
  // Out plane: NONE, REG, TMP0, TMP1, MLU, SHIFTER
  wire [2:0] control_out_plane;
  // ALU plane:
  wire [2:0] control_alu_plane;
  wire [15:0] unused_control;
  // TODO: change to specific sram chip
  sram#(.DEPTH(6), .WIDTH(32), .INITIAL("microcode.hex")) microcode(.ADDR({OPCODE}),
    .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA({BOOTSTRAP_DATA, 24'b0}),  // TODO(bootstrap): only feeding 8 bits in
    .OUT_DATA({control_in_plane, control_out_plane, control_alu_plane, REG_SEL,
        REG_SRC, unused_control}));
  // TODO: Need to latch on N_CLK(?)

  // In plane decoder (inverting outputs):
  wire unused_in_none;
  wire [3:0] unused_in_plane;
  chip74138 in_plane_decoder(.A(control_in_plane), .N_E1(0), .N_E2(0), .E3(1),
    .N_Y({unused_in_plane, CONTROL_TMP1_N_IN, CONTROL_TMP0_N_IN, CONTROL_REG_N_IN, unused_in_none}));

  // Out plane decoder:
  wire unused_out_none;
  wire [1:0] unused_out_plane;
  chip74138 out_plane_decoder(.A(control_out_plane), .N_E1(0), .N_E2(0), .E3(1),
    .N_Y({unused_out_plane, CONTROL_SHIFTER_N_OUT, CONTROL_MLU_N_OUT, CONTROL_TMP1_N_OUT,
        CONTROL_TMP0_N_OUT, CONTROL_REG_N_OUT, unused_out_none}));

  `ifdef FORMAL
  // TODO: More testing.
  always_comb begin
    // TODO: Create microcode, until then some basic asserts:
    assert (REG_SEL != 2'b11);

    // Don't try to write and read to the same thing:
    assert (CONTROL_REG_N_IN || CONTROL_REG_N_OUT);
    assert (CONTROL_TMP0_N_IN || CONTROL_TMP0_N_OUT);
    assert (CONTROL_TMP1_N_IN || CONTROL_TMP1_N_OUT);

    if (!N_BOOTED) `CONTRACT(BOOTSTRAP_N_WE);  // Don't write after boot.
  end
  `endif
endmodule
