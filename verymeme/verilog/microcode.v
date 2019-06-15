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
  logic [2:0] out_plane; // Out plane: NONE, REG, TMP0, TMP1, MMU, MLU, SHIFTER, TIMER
  logic [2:0] in_plane; // In plane: NONE, REG, TMP0, TMP1, MMU, OPWORD, OPCODE
  logic misc_plane; // Misc plane: Micro-op counter reset
  // MISC2 plane:
  //   For MLU: 3 bits for op select, 1 bit for carry.
  //   For shifter: 2 bits for direction and arithmetic or not.
  //   For opcode reg: 1 bit for deciding between reading from opword reg or CTRL_DATA. 0 is opword.
  logic [3:0] misc2_plane;

  assign OUT[5:0] = ctrl_data;
  assign OUT[7:6] = reg_sel;
  assign OUT[10:8] = out_plane;
  assign OUT[13:11] = in_plane;
  assign OUT[14] = misc_plane;
  assign OUT[18:15] = misc2_plane;
  assign OUT[31:19] = 0;

  // r31 is program counter.

  localparam OP_RESET = 0;
  localparam OP_FETCH = 1;
  // [Opcode 6][rD 5][rS 5][Offset 16]
  localparam OP_LW = 2;  // LW rD, [rS + Offset sign ext] - load 32-bit

  localparam REG_SEL_CONTROL = 2;

  localparam OUT_NONE = 0;
  localparam OUT_TIMER = 6;

  localparam IN_REG = 1;
  localparam IN_OPCODE = 6;

  localparam MISC_RESET_MICROOP_COUNTER = 1;
  always_comb begin
    case (opcode)
      OP_RESET: begin
        case (microop_count)
          0: begin  // Set program counter to zero.
            ctrl_data = 0;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_NONE;
            in_plane = IN_REG;
            {misc_plane, misc2_plane} = 0;
          end
          1: begin // Set opcode to fetch and reset micro-op counter.
            // TODO: need to be able to set opcode? use reg src val?
          end
        endcase
        if (microop_count == 5'b11111) begin
          misc_plane = MISC_RESET_MICROOP_COUNTER;
          {ctrl_data, reg_sel, out_plane, in_plane, misc2_plane} = 0;
        end else begin
          ctrl_data = {1'b0, microop_count};
          reg_sel = REG_SEL_CONTROL;
          out_plane = OUT_TIMER;
          in_plane = IN_REG;
          {misc_plane, misc2_plane} = 0;
        end
      end
//      OP_FETCH: begin
//
//      end
      default: {ctrl_data, reg_sel, out_plane, in_plane, misc_plane, misc2_plane} = 0;
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
