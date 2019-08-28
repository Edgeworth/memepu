`include "common.v"
module microcode(
  input wire [11:0] ADDR,
  output logic [31:0] OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  logic [8*20:0] mnemonic /*verilator public*/;
  logic imm_relative /*verilator public*/;

  `ifdef HEXFILEA
  // TODO: change to specific lut chip
  lut#(.DEPTH(12), .WIDTH(32), .INITIAL("microcode.hex")) microcode(
    .ADDR(ADDR), .OUT_DATA(OUT),
    .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA({BOOTSTRAP_DATA, 24'b0}));  // TODO(bootstrap): only feeding 8 bits in
  `else
  // These assignments must be kept up to date with control_logic.v.
  wire cond_var = ADDR[11];
  wire [5:0] opcode = ADDR[10:5];
  wire [4:0] microop_count = ADDR[4:0];
  logic [7:0] ctrl_data;
  logic [1:0] reg_sel; // 0=>Opcode reg0, 1=>Opcode reg1, 2=>Control logic reg sel.
  logic [3:0] out_plane;
  logic [2:0] in_plane;
  logic [1:0] misc_plane;
  // Could merge these, but it's confusing, makes routing harder, and causes more switching.
  logic [2:0] mlu_op;  // 3 bits for op select
  logic mlu_carry; // 1 bit for carry.
  logic [1:0] shifter_plane;  // See common::SHIFTER_*
  logic shifter_arith;
  logic opcode_sel;  // 1 bit for deciding between reading from opword reg or bus. 0 is opword.
  logic [1:0] cond_var_sel;

  assign OUT[7:0] = ctrl_data;
  assign OUT[9:8] = reg_sel;
  assign OUT[13:10] = out_plane;
  assign OUT[16:14] = in_plane;
  assign OUT[18:17] = misc_plane;
  assign OUT[21:19] = mlu_op;
  assign OUT[22] = mlu_carry;
  assign OUT[24:23] = shifter_plane;
  assign OUT[25] = shifter_arith;
  assign OUT[26] = opcode_sel;
  assign OUT[28:27] = cond_var_sel;
  assign OUT[31:29] = 0;

  localparam OP_RESET=0;
  localparam OP_FETCH=1;
  localparam OP_INT=16;
  localparam OP_SETI=17;
  localparam OP_CLRI=18;
  // [Opcode 6][rD 5][unused 5][immediate 16]
  localparam OP_LH=7;  // LH rD, I - rD = I - load signed 16 bits
  localparam OP_LHU=2;  // LHU rD, I - rD = signext(I) - load unsigned 16 bits

  // [Opcode 6][rD 5][rS 5][immediate 16]
  localparam OP_SW=5;  // SW [rD + signext(I)], rS - store 32-bit
  localparam OP_ADDU=3; // ADDU rD,rS,I - rD = rS + zeroext(I)
  localparam OP_BEQ=8;  // BEQ rA,rB,I - if rA == rB: r31 = r31 + signext(I)
  localparam OP_LW=9;  // LW rD, [rS + signext(I)] - load 32-bit
  localparam OP_SLL=10;  // SLL rD,rS,I - rD = rS << (I & 0x1F)
  localparam OP_BNE=11;  // BNE rA,rB,I - if rA != rB: r31 = r31 + signext(I)
  localparam OP_AND=12;  // AND rD,rS,I - rD = rS & zeroext(I)
  localparam OP_SRL=14;  // SRL rD,rS,I - rD = rS >> (I & 0x1F)

  // [Opcode 6][rD 5][rA 5][rB 5][unused 11]
  localparam OP_ADD3=4;  // ADD rD,rA,rB - rD = rA + rB
  localparam OP_OR3=6;  // OR rD,rA,rB - rD = rA | rB
  localparam OP_XOR3=13;  // XOR rD,rA,rB - rD = rA ^ rB
  localparam OP_SLL3=15;  // SLL rD,rA,rB - rD = rA << (rB & 0x1F)

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
  localparam MISC_SET_INTERRUPTS=2;

  localparam OPCODE_SEL_OPCODE_FROM_OPWORD=0;
  localparam OPCODE_SEL_OPCODE_FROM_BUS=1;

  // Selects which condition we look at on the next cycle.
  localparam COND_SEL_MLU_ZERO=0;
  localparam COND_SEL_MLU_CARRY=1;
  localparam COND_SEL_MLU_NEGATIVE=2;
  localparam COND_SEL_INTERRUPT=3;

  localparam REG_PC=31; // r31 is program counter.

  // TODO: Can change to 4 bit microop counter?

  `define SET_MNEMONIC(s) `ifdef verilator mnemonic = $size(mnemonic)'(s); `endif
  // Set opcode to fetch and reset micro-op counter.
  `define GO_FETCH() \
      begin ctrl_data = OP_FETCH; \
      out_plane = OUT_CTRL_DATA; \
      in_plane = IN_OPCODE; \
      misc_plane = MISC_RESET_MICROOP_COUNTER; \
      opcode_sel = OPCODE_SEL_OPCODE_FROM_BUS; end
  always_comb begin
    {ctrl_data, reg_sel, out_plane, in_plane, misc_plane, mlu_op, mlu_carry, shifter_plane,
    shifter_arith, opcode_sel, cond_var_sel} = 0;
    `SET_MNEMONIC("")
    imm_relative = 1'b0;
    case (opcode)
      OP_RESET: begin
        `SET_MNEMONIC("rst")
        case (microop_count)
          0: begin
            ctrl_data = 1;
            out_plane = OUT_CTRL_DATA;
            in_plane = IN_TMP0;
          end
          1: begin  // Set program counter to 1.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_TMP0;
            in_plane = IN_REG;
          end
          2: `GO_FETCH()
        endcase
      end
      OP_FETCH: begin
        `SET_MNEMONIC("nop")
        // TODO: Can optimise a bunch of stuff with a separate address bus and data bus +
        // dual ported ram for registers. => maybe then can implement multiplication?
        case (microop_count)
          0: begin  // Check interrupts + copy the program counter into TMP0 to access memory.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
            cond_var_sel = COND_SEL_INTERRUPT;
          end
          1: begin // Read MMU data onto opword or change to INT instruction.
            if (cond_var) begin
              ctrl_data = OP_INT;
              out_plane = OUT_CTRL_DATA;
              in_plane = IN_OPCODE;
              misc_plane = MISC_RESET_MICROOP_COUNTER;
              opcode_sel = OPCODE_SEL_OPCODE_FROM_BUS;
            end else begin
              out_plane = OUT_MMU;
              in_plane = IN_OPWORD;
            end
          end
          2: begin // Write 1 into TMP1 for incrementing the program counter. // TODO: optimise with specific increment instruction.
            ctrl_data = 1;
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
      OP_INT: begin
        `SET_MNEMONIC("int")
        case (microop_count)
          0: begin  // Read interrupt vector.
            ctrl_data = 0;
            out_plane = OUT_CTRL_DATA;
            in_plane = IN_TMP0;
            misc_plane = MISC_SET_INTERRUPTS;  // Disable interrupts (uses 0 ctrl_data).
          end
          1: begin  // Read interrupt vector into program counter.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_MMU;
            in_plane = IN_REG;
          end
          2: `GO_FETCH()
        endcase
      end
      OP_SETI: begin
        `SET_MNEMONIC("seti")
        case (microop_count)
          0: begin  // Enable interrupts
            ctrl_data = 1;
            misc_plane = MISC_SET_INTERRUPTS;
          end
          1: `GO_FETCH()
        endcase
      end
      OP_CLRI: begin
        `SET_MNEMONIC("clri")
        case (microop_count)
          0: begin  // Disable interrupts
            ctrl_data = 0;
            misc_plane = MISC_SET_INTERRUPTS;
          end
          1: `GO_FETCH()
        endcase
      end
      OP_LH: begin
        `SET_MNEMONIC("lh r%1%,%4$x")
        case (microop_count)
          0: begin  // Write the opword 16 bits into tmp0.
            out_plane = OUT_OPWORD_IMMEDIATE;
            in_plane = IN_TMP0;
          end
          1: begin  // Make sure to not shift
            out_plane = OUT_NONE;
            in_plane = IN_TMP1;
          end
          2: begin  // Sign extend and write into the destination register.
            reg_sel = REG_SEL_OPWORD0;
            out_plane = OUT_SHIFTER;
            shifter_plane = common::SHIFTER_SIGNEXT16;
            in_plane = IN_REG;
          end
          3: `GO_FETCH()
        endcase
      end
      OP_LHU: begin
        `SET_MNEMONIC("lhu r%1%,%4$x")
        case (microop_count)
          0: begin  // Write the opword 16 bits into the given register.
            reg_sel = REG_SEL_OPWORD0;
            out_plane = OUT_OPWORD_IMMEDIATE;
            in_plane = IN_REG;
          end
          1: `GO_FETCH()
        endcase
      end
      OP_SW: begin
        `SET_MNEMONIC("sw [r%1%,%4$x],r%2%")
        case (microop_count)
          0: begin  // Load offset into TMP0.
            out_plane = OUT_OPWORD_IMMEDIATE;
            in_plane = IN_TMP0;
          end
          1: begin  // Load 0 into TMP1.
            ctrl_data = 0;
            out_plane = OUT_CTRL_DATA;
            in_plane = IN_TMP1;
          end
          2: begin  // Sign extend and write into tmp1
            out_plane = OUT_SHIFTER;
            in_plane = IN_TMP1;
            shifter_plane = common::SHIFTER_SIGNEXT16;
          end
          3: begin  // Write first register (dst) into tmp0.
            reg_sel = REG_SEL_OPWORD0;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
          end
          4: begin  // Add offset.
            out_plane = OUT_MLU;
            in_plane = IN_TMP0;
            mlu_op = common::MLU_ADD;
          end
          5: begin  // Write second register value into memory.
            reg_sel = REG_SEL_OPWORD1;
            out_plane = OUT_REG;
            in_plane = IN_MMU;
          end
          6: `GO_FETCH()
        endcase
      end
      OP_ADDU: begin
        `SET_MNEMONIC("addu r%1%,r%2%,%4$x")
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
      OP_AND: begin
        `SET_MNEMONIC("and r%1%,r%2%,%4$x")
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
            mlu_op = common::MLU_AND;
          end
          3: `GO_FETCH()
        endcase
      end
      OP_BEQ: begin
        `SET_MNEMONIC("beq r%1%,r%2%,%4$x")
        imm_relative = 1'b1;
        case (microop_count)
          0: begin  // Load first register into TMP0
            reg_sel = REG_SEL_OPWORD0;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
          end
          1: begin  // Load second register into TMP1
            reg_sel = REG_SEL_OPWORD1;
            out_plane = OUT_REG;
            in_plane = IN_TMP1;
          end
          2: begin  // Subtract and observe the ZERO flag on the next microop.
            mlu_op = common::MLU_SUB;
            mlu_carry = 1;
            cond_var_sel = COND_SEL_MLU_ZERO;
          end
          3: begin
            if (cond_var) begin  // If it was zero, load offset into tmp0 for sign extend.
              out_plane = OUT_OPWORD_IMMEDIATE;
              in_plane = IN_TMP0;
            end else `GO_FETCH()  // Skip if it wasn't zero.
          end
          4: begin  // Set shift amount to zero. TODO: Remove this func to optimise?
            out_plane = OUT_NONE;
            in_plane = IN_TMP1;
          end
          5: begin  // Sign extend and write to TMP1.
            shifter_plane = common::SHIFTER_SIGNEXT16;
            out_plane = OUT_SHIFTER;
            in_plane = IN_TMP1;
          end
          6: begin  // Load PC into tmp0.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
          end
          7: begin  // Add offset and write back to program counter.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_MLU;
            in_plane = IN_REG;
            mlu_op = common::MLU_ADD;
          end
          8: `GO_FETCH()
        endcase
      end
      OP_BNE: begin
        `SET_MNEMONIC("bne r%1%,r%2%,%4$x")
        imm_relative = 1'b1;
        case (microop_count)
          0: begin  // Load first register into TMP0
            reg_sel = REG_SEL_OPWORD0;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
          end
          1: begin  // Load second register into TMP1
            reg_sel = REG_SEL_OPWORD1;
            out_plane = OUT_REG;
            in_plane = IN_TMP1;
          end
          2: begin  // Subtract and observe the ZERO flag on the next microop.
            mlu_op = common::MLU_SUB;
            mlu_carry = 1;
            cond_var_sel = COND_SEL_MLU_ZERO;
          end
          3: begin
            if (!cond_var) begin  // If it was not zero, load offset into tmp0 for sign extend.
              out_plane = OUT_OPWORD_IMMEDIATE;
              in_plane = IN_TMP0;
            end else `GO_FETCH()  // Skip if it wasn't zero.
          end
          4: begin  // Set shift amount to zero. TODO: Remove this func to optimise?
            out_plane = OUT_NONE;
            in_plane = IN_TMP1;
          end
          5: begin  // Sign extend and write to TMP1.
            shifter_plane = common::SHIFTER_SIGNEXT16;
            out_plane = OUT_SHIFTER;
            in_plane = IN_TMP1;
          end
          6: begin  // Load PC into tmp0.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
          end
          7: begin  // Add offset and write back to program counter.
            ctrl_data = REG_PC;
            reg_sel = REG_SEL_CONTROL;
            out_plane = OUT_MLU;
            in_plane = IN_REG;
            mlu_op = common::MLU_ADD;
          end
          8: `GO_FETCH()
        endcase
      end
      OP_ADD3: begin
        `SET_MNEMONIC("add r%1%,r%2%,r%3%")
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
        `SET_MNEMONIC("or r%1%,r%2%,r%3%")
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
      OP_XOR3: begin
        `SET_MNEMONIC("xor r%1%,r%2%,r%3%")
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
            mlu_op = common::MLU_XOR;
          end
          3: `GO_FETCH()
        endcase
      end
      OP_SLL3: begin
        `SET_MNEMONIC("sll r%1%,r%2%,r%3%")
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
            out_plane = OUT_SHIFTER;
            in_plane = IN_REG;
            shifter_plane = common::SHIFTER_LEFT;
          end
          3: `GO_FETCH()
        endcase
      end
      OP_LW: begin
        `SET_MNEMONIC("lw r%1%,[r%2%,%4$x]")
        case (microop_count)
          0: begin  // Load offset into TMP0.
            out_plane = OUT_OPWORD_IMMEDIATE;
            in_plane = IN_TMP0;
          end
          1: begin  // Load 0 into TMP1.
            ctrl_data = 0;
            out_plane = OUT_CTRL_DATA;
            in_plane = IN_TMP1;
          end
          2: begin  // Sign extend and write into tmp1
            out_plane = OUT_SHIFTER;
            in_plane = IN_TMP1;
            shifter_plane = common::SHIFTER_SIGNEXT16;
          end
          3: begin  // Write second register (src) into tmp0.
            reg_sel = REG_SEL_OPWORD1;
            out_plane = OUT_REG;
            in_plane = IN_TMP0;
          end
          4: begin  // Add offset.
            out_plane = OUT_MLU;
            in_plane = IN_TMP0;
            mlu_op = common::MLU_ADD;
          end
          5: begin  // Read the value from memory into the first (dst) register.
            reg_sel = REG_SEL_OPWORD0;
            out_plane = OUT_MMU;
            in_plane = IN_REG;
          end
          6: `GO_FETCH()
        endcase
      end
      OP_SLL: begin
        `SET_MNEMONIC("sll r%1%,r%2%,%4$x")
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
            out_plane = OUT_SHIFTER;
            in_plane = IN_REG;
            shifter_plane = common::SHIFTER_LEFT;
          end
          3: `GO_FETCH()
        endcase
      end
      OP_SRL: begin
        `SET_MNEMONIC("srl r%1%,r%2%,%4$x")
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
            out_plane = OUT_SHIFTER;
            in_plane = IN_REG;
            shifter_plane = common::SHIFTER_RIGHT;
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
