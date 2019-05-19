`include "common.v"
/* verilator lint_off UNUSED */  // TODO: Remove
module control_logic(
  input wire [5:0] OPCODE,
  input wire CLK,
  input wire N_CLK,
  output wire [1:0] REG_SEL, // 0=>Opcode reg0, 1=>Opcode reg1, 2=>Control logic reg sel.
  output wire [4:0] REG_SRC, // Control logic reg src.
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  // Control logic:
  // Outputs:
  // In plane: NONE, REG
  wire [1:0] control_in_plane;
  // Out plane: NONE, REG
  wire [1:0] control_out_plane;
  // ALU plane:
  wire [2:0] control_alu_plane;
  wire [17:0] unused_control;
  // TODO: change to specific sram chip
  sram#(.DEPTH(6), .WIDTH(32)) microcode(.ADDR({OPCODE}), .N_WE(BOOTSTRAP_N_WE),
    .N_OE(N_BOOTED), .IN_DATA({BOOTSTRAP_DATA, 24'b0}),  // TODO(bootstrap): only feeding 8 bits in
    .OUT_DATA({control_in_plane, control_out_plane, control_alu_plane, REG_SEL,
        REG_SRC, unused_control}));
  // TODO: Need to latch on N_CLK(?)

  `ifdef FORMAL
  always_comb begin
    if (!N_BOOTED) `CONTRACT(BOOTSTRAP_N_WE);  // Don't write after boot.
  end
  `endif
endmodule
