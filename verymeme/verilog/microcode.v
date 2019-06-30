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
  logic [8*20:0] mnemonic /*verilator public*/;

  `ifdef HEXFILEA // TODO undo
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
  logic [3:0] out_plane;
  logic [2:0] in_plane;
  logic misc_plane; // Misc plane: Micro-op counter reset
  // Could merge these, but it's confusing, makes routing harder, and causes more switching.
  logic [2:0] mlu_op;  // 3 bits for op select
  logic mlu_carry; // 1 bit for carry.
  logic [1:0] shifter_plane;  // See common::SHIFTER_*
  logic shifter_arith;
  logic opcode_sel;  // 1 bit for deciding between reading from opword reg or bus. 0 is opword.

  assign OUT[5:0] = ctrl_data;
  assign OUT[7:6] = reg_sel;
  assign OUT[11:8] = out_plane;
  assign OUT[14:12] = in_plane;
  assign OUT[15] = misc_plane;
  assign OUT[18:16] = mlu_op;
  assign OUT[19] = mlu_carry;
  assign OUT[23:20] = shifter_plane;
  assign OUT[24] = opcode_sel;
  assign OUT[31:25] = 0;

  localparam OP_RESET=0;
  localparam OP_FETCH=1;
  // [Opcode 6][rD 5][unused 5][immediate 16]
  localparam OP_LHU=2;  // LHU rD, I - rD = signext(I) - load unsigned 16 bits

  // [Opcode 6][rD 5][rS 5][immediate 16]
  localparam OP_SW=5;  // SW [rD + signext(I)], rS - store 32-bit
  localparam OP_ADDU=3; // ADDU rD,rS,I - rD = rS + zeroext(I)

  // [Opcode 6][rD 5][rA 5][rB 5][unused 11]
  localparam OP_ADD3=4;  // ADD rD,rA,rB - rD = rA + rB
  localparam OP_OR3=6;  // OR rD,rS,I - rD = rS | zeroext(I)

  localparam REG_SEL_OPWORD0=0;
  localparam REG_SEL_OPWORD1=1;
  localparam REG_SEL_OPWORD2=2;
  localparam REG_SEL_CONTROL=3;

  localparam OUT_NONE=0;
  localparam OUT_REG=1;
  localparam OUT_TMP0=2;
  localparam OUT_TMP1=3;
  localparam OUT_MMU=4;
  localparam OUT_MLU=5;
  localparam OUT_SHIFTER=6;
  localparam OUT_TIMER=7;
  localparam OUT_CTRL_DATA=8;
  localparam OUT_OPWORD_IMMEDIATE=9;

  localparam IN_REG=1;
  localparam IN_TMP0=2;
  localparam IN_TMP1=3;
  localparam IN_MMU=4;
  localparam IN_OPWORD=5;
  localparam IN_OPCODE=6;

  localparam MISC_RESET_MICROOP_COUNTER=1;

  localparam OPCODE_SEL_OPCODE_FROM_OPWORD=0;
  localparam OPCODE_SEL_OPCODE_FROM_BUS=1;

  localparam REG_PC=31; // r31 is program counter.

  `define SET_MNEMONIC(s) `ifdef verilator mnemonic = $size(mnemonic)'(s); `endif
  // Set opcode to fetch and reset micro-op counter.
  `define GO_FETCH() \
      begin ctrl_data = OP_FETCH; \
      out_plane = OUT_CTRL_DATA; \
      in_plane = IN_OPCODE; \
      misc_plane = MISC_RESET_MICROOP_COUNTER; \
      opcode_sel = OPCODE_SEL_OPCODE_FROM_BUS; end
  always_comb begin
    {ctrl_data, reg_sel, out_plane, in_plane, misc_plane, mlu_op, mlu_carry, shifter_plane, shifter_arith, opcode_sel} = 0;
    `SET_MNEMONIC("")
    case (opcode)
      OP_RESET: begin
      `SET_MNEMONIC("rst")
        // TODO: maybe can build model of assembler instructions by outputting a string e.g. JMP $a and probing it in memeware.
        case (microop_count)
          0: begin  // Set program counter to zero.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_NONE;
            in_plane = IN_REG;
          end
          1: `GO_FETCH()
        endcase
      end
      OP_FETCH: begin
      `SET_MNEMONIC("nop")
      case (microop_count)
        0: begin  // Copy the program counter into TMP0 to access memory.
          ctrl_data = REG_PC;
          reg_sel = REG_SEL_CONTROL;
          out_plane = OUT_REG;
          in_plane = IN_TMP0;
        end
        1: begin // Read MMU data onto opword.
          out_plane = OUT_MMU;
          in_plane = IN_OPWORD;
        end
        2: begin // Write 4 into TMP1 for incrementing the program counter. TODO(optimization): Faster increment.
          ctrl_data = 4;
          reg_sel = REG_SEL_CONTROL;
          out_plane = OUT_CTRL_DATA;
          in_plane = IN_TMP1;
        end
        3: begin // Increment the program counter.
          ctrl_data = REG_PC;
          reg_sel = REG_SEL_CONTROL;
          out_plane = OUT_MLU;
          in_plane = IN_REG;
          mlu_op = common::MLU_ADD;
        end
        4: begin // Copy the opword opcode to the opcode reg, and reset the microop counter.
          in_plane = IN_OPCODE;
          misc_plane = MISC_RESET_MICROOP_COUNTER;
          opcode_sel = OPCODE_SEL_OPCODE_FROM_OPWORD;
        end
      endcase
      end
      OP_LHU: begin
      `SET_MNEMONIC("lhu r%d,%x")
      case (microop_count)
        0: begin  // Write the opword 16 bits into the given register.
          reg_sel = REG_SEL_OPWORD0;
          out_plane = OUT_OPWORD_IMMEDIATE;
          in_plane = IN_REG;
        end
        1: `GO_FETCH()
      endcase
      end
      OP_SW: begin  // TODO: use offset
      `SET_MNEMONIC("sw r%d,r%d,%x")
      case (microop_count)
        0: begin  // Write first register (dst) into tmp0.
          reg_sel = REG_SEL_OPWORD0;
          out_plane = OUT_REG;
          in_plane = IN_TMP0;
        end
        1: begin  // Write second register value into memory.
          reg_sel = REG_SEL_OPWORD1;
          out_plane = OUT_REG;
          in_plane = IN_MMU;
        end
        2: `GO_FETCH()
      endcase
      end
      OP_ADDU: begin
      `SET_MNEMONIC("addu r%d,r%d,%x")
      case (microop_count)
        0: begin  // Write second reg into tmp0.
          reg_sel = REG_SEL_OPWORD1;
          out_plane = OUT_REG;
          in_plane = IN_TMP0;
        end
        1: begin  // Write immediate value into tmp1.
          out_plane = OUT_OPWORD_IMMEDIATE;
          in_plane = IN_TMP1;
        end
        2: begin  // Write add result into first reg.
          reg_sel = REG_SEL_OPWORD0;
          out_plane = OUT_MLU;
          in_plane = IN_REG;
          mlu_op = common::MLU_ADD;
        end
        3: `GO_FETCH()
      endcase
      end
      OP_ADD3: begin
      `SET_MNEMONIC("add r%d,r%d,r%d")
      case (microop_count)
        0: begin  // Write second reg into tmp0.
          reg_sel = REG_SEL_OPWORD1;
          out_plane = OUT_REG;
          in_plane = IN_TMP0;
        end
        1: begin  // Write third reg into tmp1.
          reg_sel = REG_SEL_OPWORD2;
          out_plane = OUT_REG;
          in_plane = IN_TMP1;
        end
        2: begin  // Write add result into first reg.
          reg_sel = REG_SEL_OPWORD0;
          out_plane = OUT_MLU;
          in_plane = IN_REG;
          mlu_op = common::MLU_ADD;
        end
        3: `GO_FETCH()
      endcase
      end
      OP_OR3: begin
      `SET_MNEMONIC("or r%d,r%d,r%d")
      case (microop_count)
        0: begin  // Write second reg into tmp0.
          reg_sel = REG_SEL_OPWORD1;
          out_plane = OUT_REG;
          in_plane = IN_TMP0;
        end
        1: begin  // Write third reg into tmp1.
          reg_sel = REG_SEL_OPWORD2;
          out_plane = OUT_REG;
          in_plane = IN_TMP1;
        end
        2: begin  // Write add result into first reg.
          reg_sel = REG_SEL_OPWORD0;
          out_plane = OUT_MLU;
          in_plane = IN_REG;
          mlu_op = common::MLU_OR;
        end
        3: `GO_FETCH()
      endcase
      end
    endcase
  end
  `endif

  `ifndef BOOTSTRAP
  // Mark bootstrap signals as okay to not be used if not using bootstrapping.
  wire _unused_ok = & {BOOTSTRAP_ADDR, BOOTSTRAP_DATA, N_BOOTED, BOOTSTRAP_N_WE};
  `endif

  `ifdef FORMAL
  `endif
endmodule
