`include "common.v"

module alu_slice(
  input wire [3:0] A,
  input wire [3:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  output /*u*/ wire [7:0] OUT
);
  localparam MAX_MEM = 1 << 12;

  wire [7:0] tmp = 0;

  sram#(.DEPTH(12), .WIDTH(8), .INITIAL("alu_slice.hex")) slice_mem(
    .ADDR({OP, C_IN, B, A}), .N_WE(1), .N_OE(0), .IN_DATA(tmp), .OUT_DATA(OUT));

  `ifdef FORMAL
  logic [3:0] sum = A+B+{3'b0, C_IN};
  wire [3:0] out = OUT[3:0];
  wire prop = OUT[4];
  wire gen = OUT[5];
  wire zero = OUT[6];

  always_comb begin
    case (OP)
      common::ALU_ADD: begin
        assert (out == sum);
        assert (prop == (A+B == 4'hF));
        assert (gen == ({1'b0, A}+{1'b0, B} > 5'hF));
      end
      common::ALU_SUB: begin
        if (C_IN) assert (out == (A-B));
        else assert (out == A-B-4'b1);
        assert (prop == (A+(~B) == 4'hF));
        assert (gen == ({1'b0, A}+{1'b0, ~B} > 5'hF));
      end
      common::ALU_AND: assert (out == (A & B));
      common::ALU_OR: assert (out == (A | B));
      common::ALU_XOR: assert (out == (A ^ B));
      common::ALU_NOT: assert (out == ~A);
      common::ALU_NOP0: assert (out == 0);
      common::ALU_NOP1: assert (out == 0);
      default: assert (0);
    endcase
    assert (zero == (out == 0));
  end
  `endif
endmodule
