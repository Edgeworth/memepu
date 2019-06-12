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
  logic [4:0] reg_src;
  logic [1:0] reg_sel;
  logic [3:0] alu_plane;
  logic [2:0] out_plane;
  logic [2:0] in_plane;
  logic misc_plane;

  assign OUT[4:0] = reg_src;
  assign OUT[6:5] = reg_sel;
  assign OUT[10:7] = alu_plane;
  assign OUT[13:11] = out_plane;
  assign OUT[16:14] = in_plane;
  assign OUT[17] = misc_plane;
  assign OUT[31:18] = 0;

  localparam OP_RESET = 0;

  localparam REG_SEL_CONTROL = 2;

  localparam OUT_TIMER = 6;

  localparam IN_REG = 1;

  localparam MISC_RESET_MICROOP_COUNTER = 1;
  always_comb begin
    case (opcode)
      OP_RESET: begin
        if (microop_count == 5'b11111) begin
          misc_plane = MISC_RESET_MICROOP_COUNTER;
          {reg_src, reg_sel, alu_plane, out_plane, in_plane} = 0;
        end else begin
          reg_src = microop_count;
          reg_sel = REG_SEL_CONTROL;
          out_plane = OUT_TIMER;
          in_plane = IN_REG;
          {alu_plane, misc_plane} = 0;
        end
      end
      default: {reg_src, reg_sel, alu_plane, out_plane, in_plane, misc_plane} = 0;
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
