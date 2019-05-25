`include "common.v"
/* verilator lint_off UNUSED */  // TODO: Remove
module kpu(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST
);
  // Bus.
  wire [31:0] bus /*verilator public*/;

  // Timer:
  wire [31:0] time_out;
  timer timer(.CLK(CLK), .N_RST(N_RST), .TIME(time_out));

  // MLU:
  wire [31:0] mlu_val /*verilator public*/, mlu_out;
  wire [2:0] mlu_flags_out;
  mlu mlu(.A(tmp0_val), .B(tmp1_val), .OP(control_alu_plane[2:0]), .C_IN(control_alu_plane[3]),
    .OUT(mlu_val), .Z(mlu_flags_out[0]), .C(mlu_flags_out[1]), .N(mlu_flags_out[2]),
    .BOOTSTRAP_DATA(bootstrap_data), .N_BOOTED(n_booted), .BOOTSTRAP_ADDR(bootstrap_addr),
    .BOOTSTRAP_MLU_SLICE_N_WE(bootstrap_mlu_slice_n_we),
    .BOOTSTRAP_MLU_LOOKAHEAD_N_WE(bootstrap_mlu_lookahead_n_we));
  // TODO(optimisation): maybe can remove buffer by pushing output enable signals down to mlu slices.
  buffer32 mlu_buf(.IN(mlu_val), .OUT(mlu_out), .N_OE(control_mlu_n_out));

  // Shifter:
  wire [31:0] shifter_val, shifter_out;
  shifter shifter(.IN(tmp0_val), .SHFT(tmp1_val[4:0]), .LEFT(control_alu_plane[0]),
    .ARITH(control_alu_plane[1]), .OUT(shifter_val));
  buffer32 shifter_buf(.IN(shifter_val), .OUT(shifter_out), .N_OE(control_shifter_n_out));

  // Scratch registers - invisible to running code.
  wire [31:0] tmp0_val, tmp0_out;
  wire [31:0] tmp1_val, tmp1_out;
  register32 tmp0(.CLK(control_tmp0_in_clk), .IN(bus), .N_OE(0), .OUT(tmp0_val));
  buffer32 tmp0_buf(.IN(tmp0_val), .OUT(tmp0_out), .N_OE(control_tmp0_n_out));
  register32 tmp1(.CLK(control_tmp1_in_clk), .IN(bus), .N_OE(0), .OUT(tmp1_val));
  buffer32 tmp1_buf(.IN(tmp1_val), .OUT(tmp1_out), .N_OE(control_tmp1_n_out));

  // Register file:
  wire [31:0] reg_out;
  register_file regs(.REG_SEL(control_reg_sel), .REG_SRC0(op_reg_src0), .REG_SRC1(op_reg_src1),
    .REG_SRC2(control_reg_src), .IN_DATA(bus), .N_WE(control_reg_n_in_clk), .N_OE(control_reg_n_out),
    .OUT_DATA(reg_out));

  // Opcode word:
  // Outputs:
  wire [5:0] opword_opcode;  // 6 bit opcode
  wire [4:0] op_reg_src0, op_reg_src1;
  wire [15:0] op_offset;
  register32 opword(.CLK(control_opword_in_clk), .IN(bus), .N_OE(0), .OUT({op_offset, op_reg_src1, op_reg_src0, opword_opcode}));
  // TODO(idea): Can have control logic write into this to do micro-op functions.
  wire [1:0] unused_opcode;
  wire [5:0] opcode /*verilator public*/;
  chip74273 opcode_reg(.D({2'b0, opword_opcode}), .N_MR(N_RST), .CP(control_opcode_in_clk),
    .Q({unused_opcode, opcode}));

  // Control logic:
  wire [1:0] control_reg_sel;
  wire [4:0] control_reg_src;
  // In plane:
  wire control_reg_n_in_clk;
  wire control_tmp0_in_clk;
  wire control_tmp1_in_clk;
  wire control_opword_in_clk;
  wire control_opcode_in_clk;
  // Out plane
  wire control_reg_n_out;
  wire control_tmp0_n_out;
  wire control_tmp1_n_out;
  wire control_mlu_n_out;
  wire control_shifter_n_out;
  // ALU plane:
  wire [3:0] control_alu_plane;
  control_logic control(.CLK(CLK), .N_CLK(N_CLK), .N_RST(N_RST), .OPCODE(opcode),
    .REG_SEL(control_reg_sel), .REG_SRC(control_reg_src), .ALU_PLANE(control_alu_plane),
    .REG_N_IN_CLK(control_reg_n_in_clk),
    .TMP0_IN_CLK(control_tmp0_in_clk),
    .TMP1_IN_CLK(control_tmp1_in_clk),
    .OPWORD_IN_CLK(control_opword_in_clk),
    .OPCODE_IN_CLK(control_opcode_in_clk),
    .REG_N_OUT(control_reg_n_out), .TMP0_N_OUT(control_tmp0_n_out),
    .TMP1_N_OUT(control_tmp1_n_out), .MLU_N_OUT(control_mlu_n_out),
    .SHIFTER_N_OUT(control_shifter_n_out),
    .BOOTSTRAP_DATA(bootstrap_data), .N_BOOTED(n_booted), .BOOTSTRAP_ADDR(bootstrap_addr[11:0]),
    .BOOTSTRAP_N_WE(bootstrap_control_n_we));

  // Bus mux:
  `ifdef SCHEMATIC
  assign bus = reg_out;
  assign bus = tmp0_out;
  assign bus = tmp1_out;
  assign bus = mlu_out;
  assign bus = shifter_out;
  `else
  assign bus = !control_reg_n_out ? reg_out : !control_tmp0_n_out ? tmp0_out :
    !control_tmp1_n_out ? tmp1_out : !control_mlu_n_out ? mlu_out : !control_shifter_n_out ?
    shifter_out : 32'bZ;
  `endif

  // Bootstrapping code:
  wire n_booted;
  wire [7:0] bootstrap_data;
  wire [16:0] bootstrap_addr;
  wire bootstrap_mlu_slice_n_we;
  wire bootstrap_mlu_lookahead_n_we;
  wire bootstrap_control_n_we;
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
  assign bootstrap_control_n_we = 1;
  `endif

  `ifdef FORMAL
  always_comb begin
    // TODO: Need to update this.
    assert (8'b0+!control_reg_n_out+!control_tmp0_n_out+!control_tmp1_n_out+!control_mlu_n_out +
      !control_shifter_n_out <= 1);  // No conflict on busses.
    // TODO: Assert stuff about boot process
  end
  `endif
endmodule
