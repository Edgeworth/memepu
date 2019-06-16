`include "common.v"
module microcode(
  input wire [10:0] ADDR,
  output logic [31:0] OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  `ifdef HEXFILE
  // TODO: change to specific lut chip
  lut#(.DEPTH(11), .WIDTH(32), .INITIAL("microcode.hex")) microcode(
    .ADDR(ADDR), .OUT_DATA(OUT),
    .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA({BOOTSTRAP_DATA, 24'b0}));  // TODO(bootstrap): only feeding 8 bits in
  `else
  // These assignments must be kept up to date with control_logic.v.
  wire [5:0] opcode = ADDR[10:5];
  wire [4:0] microop_count = ADDR[4:0];
  logic [5:0] ctrl_data;
  logic [1:0] reg_sel; // 0=>Opcode reg0, 1=>Opcode reg1, 2=>Control logic reg sel.
  logic [3:0] out_plane; // Out plane: NONE, REG, TMP0, TMP1, MMU, MLU, SHIFTER, TIMER, CTRL_DATA
  logic [2:0] in_plane; // In plane: NONE, REG, TMP0, TMP1, MMU, OPWORD, OPCODE
  logic misc_plane; // Misc plane: Micro-op counter reset
  // Could merge these, but it's confusing, makes routing harder, and causes more switching.
  logic [3:0] mlu_plane;  // 3 bits for op select, 1 bit for carry.
  logic [1:0] shifter_plane; // 2 bits for direction and arithmetic or not.
  logic opcode_sel;  // 1 bit for deciding between reading from opword reg or bus. 0 is opword.

  assign OUT[5:0] = ctrl_data;
  assign OUT[7:6] = reg_sel;
  assign OUT[11:8] = out_plane;
  assign OUT[14:12] = in_plane;
  assign OUT[15] = misc_plane;
  assign OUT[19:16] = mlu_plane;
  assign OUT[21:20] = shifter_plane;
  assign OUT[22] = opcode_sel;
  assign OUT[31:23] = 0;

  // r31 is program counter.

  localparam OP_RESET = 0;
  localparam OP_FETCH = 1;
  // [Opcode 6][rD 5][rS 5][Offset 16]
  localparam OP_LW = 2;  // LW rD, [rS + Offset sign ext] - load 32-bit

  localparam REG_SEL_CONTROL = 2;

  localparam OUT_NONE = 0;
  localparam OUT_REG = 1;
  localparam OUT_MMU = 4;
  localparam OUT_TIMER = 7;
  localparam OUT_CTRL_DATA = 8;

  localparam IN_REG = 1;
  localparam IN_TMP0 = 2;
  localparam IN_TMP1 = 3;
  localparam IN_OPWORD = 5;
  localparam IN_OPCODE = 6;

  localparam MISC_RESET_MICROOP_COUNTER = 1;

  localparam OPCODE_SEL_OPCODE_FROM_BUS = 1;

  localparam REG_PC = 31;

  `define ZERO_ALL() {ctrl_data, reg_sel, out_plane, in_plane, misc_plane, mlu_plane, shifter_plane, opcode_sel} = 0

  always_comb begin
    case (opcode)
      OP_RESET: begin
        case (microop_count)
          0: begin  // Set program counter to zero.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_NONE;
            in_plane = IN_REG;
            {misc_plane, mlu_plane, shifter_plane, opcode_sel} = 0;
          end
          1: begin // Set opcode to fetch and reset micro-op counter.
            ctrl_data = OP_FETCH;
            out_plane = OUT_CTRL_DATA;
            in_plane = IN_OPCODE;
            misc_plane = MISC_RESET_MICROOP_COUNTER;
            opcode_sel = OPCODE_SEL_OPCODE_FROM_BUS;
            {reg_sel, mlu_plane, shifter_plane} = 0;
          end
          default: `ZERO_ALL();
        endcase
      end
      OP_FETCH: begin
        case (microop_count)
          0: begin  // Copy the program counter into TMP0 to access memory.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
            {misc_plane, mlu_plane, shifter_plane, opcode_sel} = 0;
          end
          1: begin // Read MMU data onto opword.
            out_plane = OUT_MMU;
            in_plane = IN_OPWORD;
            {ctrl_data, reg_sel, misc_plane, mlu_plane, shifter_plane, opcode_sel} = 0;
          end
          2: begin // Write 1 into TMP1 for incrementing the program counter. TODO(optimization): Faster increment.
            ctrl_data = 1;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_REG;
            in_plane = IN_TMP1;
            {misc_plane, mlu_plane, shifter_plane, opcode_sel} = 0;
          end
          default: `ZERO_ALL();
        endcase
      end
      default: `ZERO_ALL();
    endcase
  end
  `endif

  `ifndef BOOTSTRAP
  // Mark bootstrap signals as okay to not be used if not using bootstrapping.
  wire _unused_ok = &{BOOTSTRAP_ADDR, BOOTSTRAP_DATA, N_BOOTED, BOOTSTRAP_N_WE};
  `endif

  `ifdef FORMAL
  `endif
endmodule
