`include "common.v"
// TODO(improvement): Also define models for CLK, RST.
module kpu(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST_ASYNC,
  output wire [31:0] BUS
);
  // Bus.
  wire [31:0] bus /*verilator public*/;
  assign BUS = bus;

  // Synchronously deassert reset on 2nd falling edge.
  wire n_rst /*verilator public*/;
  // 0 when N_RST_ASYNC is low. Back to 1 upon deasserting N_RST_ASYNC and negedge of CLK.
  wire n_rst_first_edge;
  wire [1:0] unused_n_q;
  chip74107 jkflip(.J({n_rst_first_edge, 1'b1}), .K(0), .N_CP({CLK, CLK}),
    .N_R({N_RST_ASYNC, N_RST_ASYNC}), .Q({n_rst, n_rst_first_edge}), .N_Q(unused_n_q));

  // Timer:
  wire [31:0] timer_val /*verilator public*/, timer_out;
  timer timer(.CLK(CLK), .N_RST(n_rst), .TIME(timer_val));
  buffer32 timer_buf(.IN(timer_val), .OUT(timer_out), .N_OE(control_timer_n_out));

  // MLU:
  wire [31:0] mlu_val /*verilator public*/, mlu_out;
  wire mlu_zero;
  wire mlu_carry;
  wire mlu_negative;
  mlu mlu(.A(tmp0_val), .B(tmp1_val), .OP(control_mlu_plane[2:0]), .C_IN(control_mlu_plane[3]),
    .N_RST(n_rst), .OUT(mlu_val), .Z(mlu_zero), .C(mlu_carry), .N(mlu_negative),
    .BOOTSTRAP_DATA(bootstrap_data), .N_BOOTED(n_booted), .BOOTSTRAP_ADDR(bootstrap_addr),
    .BOOTSTRAP_MLU_SLICE_N_WE(bootstrap_mlu_slice_n_we),
    .BOOTSTRAP_MLU_LOOKAHEAD_N_WE(bootstrap_mlu_lookahead_n_we));
  // TODO(optimisation): maybe can remove buffer by pushing output enable signals down to mlu slices.
  buffer32 mlu_buf(.IN(mlu_val), .OUT(mlu_out), .N_OE(control_mlu_n_out));

  // Shifter:
  wire [31:0] shifter_val, shifter_out;
  shifter shifter(.IN(tmp0_val), .SHFT(tmp1_val[4:0]), .SEL(control_shifter_plane),
    .ARITH(control_shifter_arith), .N_RST(n_rst), .OUT(shifter_val));
  buffer32 shifter_buf(.IN(shifter_val), .OUT(shifter_out), .N_OE(control_shifter_n_out));

  // MMU:
  wire [31:0] mmu_out;
  mmu mmu(.ADDR(tmp0_val), .N_WE(control_mmu_n_in_clk),
    .N_OE(control_mmu_n_out), .N_RST(n_rst), .IN(bus), .OUT(mmu_out));

  // Scratch registers - invisible to running code.
  wire [31:0] tmp0_val /*verilator public*/, tmp0_out;
  wire [31:0] tmp1_val /*verilator public*/, tmp1_out;
  register32 tmp0(.CLK(control_tmp0_in_clk), .IN(bus), .N_OE(0), .OUT(tmp0_val));
  buffer32 tmp0_buf(.IN(tmp0_val), .OUT(tmp0_out), .N_OE(control_tmp0_n_out));
  register32 tmp1(.CLK(control_tmp1_in_clk), .IN(bus), .N_OE(0), .OUT(tmp1_val));
  buffer32 tmp1_buf(.IN(tmp1_val), .OUT(tmp1_out), .N_OE(control_tmp1_n_out));

  // Register file:
  wire [31:0] reg_out;
  register_file regs(.REG_SEL(control_reg_sel), .REG_SRC0(opword_reg_src0),
    .REG_SRC1(opword_reg_src1), .REG_SRC2(opword_reg_src2),
    .REG_SRC3(control_ctrl_data[4:0]), .IN_DATA(bus), .N_WE(control_reg_n_in_clk),
    .N_OE(control_reg_n_out), .N_RST(n_rst), .OUT_DATA(reg_out));

  // Opcode word:
  // Outputs:
  wire [5:0] opword_opcode /*verilator public*/;  // 6 bit opcode
  wire [25:0] opword_bits /*verilator public*/;
  wire [4:0] opword_reg_src0 = opword_bits[4:0];
  wire [4:0] opword_reg_src1 = opword_bits[9:5];
  wire [4:0] opword_reg_src2 = opword_bits[14:10];

  // Opword bit mux
  wire [15:0] opword_immediate_out;
  buffer16 opword_immediate_buf(.IN(opword_bits[25:10]), .OUT(opword_immediate_out),
    .N_OE(control_opword_immediate_n_out));

  // Opword:
  register32 opword(.CLK(control_opword_in_clk), .IN(bus), .N_OE(0),
    .OUT({opword_bits, opword_opcode}));

  // Control logic:
  wire [7:0] control_ctrl_data;
  wire [1:0] control_reg_sel;
  wire [3:0] control_mlu_plane;
  wire [1:0] control_shifter_plane;
  wire control_shifter_arith;
  // In plane:
  wire control_reg_n_in_clk;
  wire control_tmp0_in_clk;
  wire control_tmp1_in_clk;
  wire control_mmu_n_in_clk;
  wire control_opword_in_clk;
  // Out plane
  wire control_reg_n_out;
  wire control_tmp0_n_out;
  wire control_tmp1_n_out;
  wire control_mmu_n_out;
  wire control_mlu_n_out;
  wire control_shifter_n_out;
  wire control_timer_n_out;
  wire control_ctrl_data_n_out;
  wire control_opword_immediate_n_out;
  control_logic control(.CLK(CLK), .N_CLK(N_CLK), .N_RST(n_rst),
    .BUS(bus[7:0]),
    .OPWORD_OPCODE(opword_opcode),
    .MLU_ZERO(mlu_zero), .MLU_CARRY(mlu_carry), .MLU_NEGATIVE(mlu_negative),
    .CTRL_DATA(control_ctrl_data),
    .REG_SEL(control_reg_sel),
    .MLU_PLANE(control_mlu_plane),
    .SHIFTER_PLANE(control_shifter_plane),
    .SHIFTER_ARITH(control_shifter_arith),
    .REG_N_IN_CLK(control_reg_n_in_clk),
    .TMP0_IN_CLK(control_tmp0_in_clk),
    .TMP1_IN_CLK(control_tmp1_in_clk),
    .MMU_N_IN_CLK(control_mmu_n_in_clk),
    .OPWORD_IN_CLK(control_opword_in_clk),
    .REG_N_OUT(control_reg_n_out),
    .TMP0_N_OUT(control_tmp0_n_out),
    .TMP1_N_OUT(control_tmp1_n_out),
    .MMU_N_OUT(control_mmu_n_out),
    .MLU_N_OUT(control_mlu_n_out),
    .SHIFTER_N_OUT(control_shifter_n_out),
    .TIMER_N_OUT(control_timer_n_out),
    .CTRL_DATA_N_OUT(control_ctrl_data_n_out),
    .OPWORD_IMMEDIATE_N_OUT(control_opword_immediate_n_out),
    .BOOTSTRAP_DATA(bootstrap_data), .N_BOOTED(n_booted), .BOOTSTRAP_ADDR(bootstrap_addr[11:0]),
    .BOOTSTRAP_N_WE(bootstrap_control_n_we));

  // Bus mux:
  `ifdef SCHEMATIC
  assign bus = reg_out;
  assign bus = tmp0_out;
  assign bus = tmp1_out;
  assign bus = mlu_out;
  assign bus = shifter_out;
  assign bus = timer_out;
  assign bus = mmu_out;
  assign bus[7:0] = control_ctrl_data;
  assign bus[15:0] = opword_immediate_out;
  `else
  assign bus = !control_reg_n_out ? reg_out : !control_tmp0_n_out ? tmp0_out :
    !control_tmp1_n_out ? tmp1_out : !control_mlu_n_out ? mlu_out : !control_shifter_n_out ?
    shifter_out : !control_timer_n_out ? timer_out : !control_mmu_n_out ? mmu_out :
    !control_ctrl_data_n_out ? {24'b0, control_ctrl_data} : !control_opword_immediate_n_out ?
    {16'b0, opword_immediate_out} : 32'b0;
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
  // Assume starting state is reset. Turning on is undefined so need to reset anyway.
  initial assume (!N_RST_ASYNC);

  always_comb begin
    `CONTRACT(CLK != N_CLK);  // Must be opposites.
    // No conflict on busses.
    assert (8'b0+!control_reg_n_out+!control_tmp0_n_out+!control_tmp1_n_out+!control_mlu_n_out+
        !control_shifter_n_out+!control_timer_n_out+!control_mmu_n_out+!control_ctrl_data_n_out+
        !control_opword_immediate_n_out<= 1);
    // TODO(bootstrapping): Assert stuff about boot process
  end

  always_ff @($global_clock) begin
    // Force CLK or RST to change every time, so induction passes.
    assume (CLK != $past(CLK) || n_rst != $past(n_rst));
  end
  `endif
endmodule
