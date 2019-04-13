`include "common.v"
/* verilator lint_off UNUSED */  // TODO REMOVE
module kpu(
  input wire CLK,
//  input wire N_CLK,
  input wire N_RST
);
/*  // Bus.
  wire [31:0] bus;

  // Scratch registers - invisible to running code.
  wire [31:0] tmp0_val, tmp1_val;
  register32 tmp0(.CLK(CLK), .IN(bus), .N_OE(1), .OUT(tmp0_val));
  register32 tmp1(.CLK(CLK), .IN(bus), .N_OE(1), .OUT(tmp1_val));

  // Register file:
  wire [31:0] reg_out;
  wire [4:0] reg_sel;  // TODO: need to mux between reg0sel, reg1sel, and microcode. Use 74245 ?
  wire reg_n_we, reg_n_oe;
  register_file regs(.REG(reg_sel), .IN_DATA(bus), .N_WE(reg_n_we), .N_OE(reg_n_oe),
    .OUT_DATA(reg_out));

  // Opcode word:
  wire [5:0] op;  // 6 bit opcode
  wire [4:0] op_reg0_sel, op_reg1_sel;
  wire [15:0] op_offset;
  register32 op_word(.CLK(), .IN(), .N_OE(0), .OUT({op_offset, op_reg1_sel, op_reg0_sel, op}));

  // Microcode:
  // TODO: change to specific sram chip
  sram#(.DEPTH(12), .WIDTH(32)) microcode(.ADDR(), .N_WE(1), .N_OE(0),
    .IN_DATA(),
    .OUT_DATA());

  // Timer:
  wire [31:0] time_out;
  timer timer(.CLK(CLK), .N_RST(N_RST), .TIME(time_out));

  // MLU:
  wire [31:0] mlu_out;
  wire [2:0] mlu_op = 1, mlu_flags_out;
  wire mlu_c_in = 1, mlu_n_oe = 1;  // TODO feed this value in.
  mlu mlu(.A(tmp0_val), .B(tmp1_val), .OP(mlu_op), .C_IN(mlu_c_in), .OUT(mlu_out),
    .Z(mlu_flags_out[0]), .C(mlu_flags_out[1]), .N(mlu_flags_out[2]));

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

  `ifdef FORMAL
  always_comb begin
    assert (8'b0+mlu_n_oe+shifter_n_oe+reg_n_oe <= 1);  // No conflict on busses.
  end
  `endif*/
endmodule
