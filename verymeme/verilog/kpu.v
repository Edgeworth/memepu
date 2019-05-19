`include "common.v"
/* verilator lint_off UNUSED */  // TODO REMOVE
module kpu(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST
);
  // Bus.
  wire [31:0] bus;

  // Scratch registers - invisible to running code.
  wire [31:0] tmp0_val, tmp1_val;
  register32 tmp0(.CLK(CLK), .IN(bus), .N_OE(1), .OUT(tmp0_val));
  register32 tmp1(.CLK(CLK), .IN(bus), .N_OE(1), .OUT(tmp1_val));

  // Register file:
  wire [31:0] reg_out;
  wire reg_n_we, reg_n_oe;
  register_file regs(.REG_SEL(control_reg_sel), .REG_SRC0(op_reg_src0), .REG_SRC1(op_reg_src1),
    .REG_SRC2(control_reg_src), .IN_DATA(bus), .N_WE(reg_n_we), .N_OE(reg_n_oe), .OUT_DATA(reg_out));

  // Opcode word:
  // Outputs:
  wire [5:0] op;  // 6 bit opcode
  wire [4:0] op_reg_src0, op_reg_src1;
  wire [15:0] op_offset;
  register32 op_word(.CLK(CLK), .IN(bus), .N_OE(0), .OUT({op_offset, op_reg_src1, op_reg_src0, op}));

  // Control logic:
  // Outputs:
  wire [1:0] control_in_plane;
  wire [1:0] control_out_plane;
  wire [2:0] control_alu_plane;
  // Reg plane:
  wire [1:0] control_reg_sel;
  wire [4:0] control_reg_src;
  wire [17:0] unused_control;
  // TODO: change to specific sram chip
  sram#(.DEPTH(6), .WIDTH(32)) microcode(.ADDR({op}), .N_WE(boostrap_control_n_we),
    .N_OE(n_booted), .IN_DATA({bootstrap_data, 24'b0}),  // TODO(bootstrap): only feeding 8 bits in
    .OUT_DATA({control_in_plane, control_out_plane, control_alu_plane, control_reg_sel,
        control_reg_src, unused_control}));
  // TODO: Need to latch on N_CLK(?)

  // Timer:
  wire [31:0] time_out;
  timer timer(.CLK(CLK), .N_RST(N_RST), .TIME(time_out));

  // MLU:
  wire [31:0] mlu_out;
  wire [2:0] mlu_op = 1, mlu_flags_out;
  wire mlu_c_in = 1, mlu_n_oe = 1;  // TODO feed this value in.
  mlu mlu(.A(tmp0_val), .B(tmp1_val), .OP(mlu_op), .C_IN(mlu_c_in), .OUT(mlu_out),
    .Z(mlu_flags_out[0]), .C(mlu_flags_out[1]), .N(mlu_flags_out[2]),
    .BOOTSTRAP_DATA(bootstrap_data), .N_BOOTED(n_booted), .BOOTSTRAP_ADDR(bootstrap_addr),
    .BOOTSTRAP_MLU_SLICE_N_WE(bootstrap_mlu_slice_n_we),
    .BOOTSTRAP_MLU_LOOKAHEAD_N_WE(bootstrap_mlu_lookahead_n_we));

  // Shifter:
  wire [31:0] shifter_out;
  wire [1:0] shifter_op = 0;  // TODO feed this value in.
  wire shifter_n_oe = 0;  // TODO set this
  shifter shifter(.IN(tmp0_val), .SHFT(tmp1_val[4:0]), .LEFT(shifter_op[0]), .ARITH(shifter_op[1]),
    .OUT(shifter_out));

  // Bus mux:
  `ifdef SCHEMATIC
  assign bus = mlu_out;
  assign bus = shifter_out;
  assign bus = reg_out;
  `else
  assign bus = mlu_n_oe == 0 ? mlu_out : shifter_n_oe == 0 ? shifter_out :
    reg_n_oe == 0 ? reg_out : 32'bZ;
  `endif

  // Bootstrapping code:
  wire n_booted;
  wire [7:0] bootstrap_data;
  wire [16:0] bootstrap_addr;
  wire bootstrap_mlu_slice_n_we;
  wire bootstrap_mlu_lookahead_n_we;
  wire boostrap_control_n_we;
  `ifdef BOOTSTRAP
  // Read data from EEPROMs into SRAMs in physical version.
  // Requires bootstrapping: MLU slices, MLU lookahead, microcode
  bootstrapper bootstrapper(.TIME(time_out), .CLK(CLK), .N_CLK(N_CLK),
    .DATA(control_bootstrap_data), .N_BOOTED(n_booted), .ADDR(bootstrap_addr),
    .CONTROL_N_WE(boostrap_control_n_we), .MLU_SLICE_N_WE(bootstrap_mlu_slice_n_we),
    .MLU_LOOKAHEAD_N_WE(bootstrap_mlu_lookahead_n_we));
  `else
  // Otherwise, load from hex files.
  assign n_booted = 0;
  assign bootstrap_data = 0;
  assign bootstrap_addr = 0;
  assign bootstrap_mlu_slice_n_we = 1;
  assign bootstrap_mlu_lookahead_n_we = 1;
  assign boostrap_control_n_we = 1;
  `endif

  `ifdef FORMAL
  always_comb begin
    assert (8'b0+!mlu_n_oe+!shifter_n_oe+!reg_n_oe <= 1);  // No conflict on busses.
    // TODO: Assert stuff about boot process
  end
  `endif
endmodule
