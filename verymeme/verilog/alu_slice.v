`include "common.v"
module alu_slice(
  input wire [3:0] A,
  input wire [3:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  output logic [7:0] OUT
);

  `ifdef HEXFILE
  wire [7:0] unused = 0;
  sram#(.DEPTH(12), .WIDTH(8), .INITIAL("alu_slice.hex")) slice_mem(
    .ADDR({OP, C_IN, B, A}), .N_WE(1), .N_OE(0), .IN_DATA(unused), .OUT_DATA(OUT));
  `else
  logic [3:0] out_low;
  logic prop;
  logic gen;

  always_comb begin
    prop = 0;
    gen = 0;
    case (OP)
      common::ALU_ADD: begin
        out_low = A+B+{3'b0, C_IN};
        prop = (A+B == 4'hF);
        gen = ({1'b0, A}+{1'b0, B} > 5'hF);
      end
      common::ALU_SUB: begin
        out_low = A+(~B)+{3'b0, C_IN};
        prop = (A+(~B) == 4'hF);
        gen = ({1'b0, A}+{1'b0, ~B} > 5'hF);
      end
      common::ALU_AND: out_low = A & B;
      common::ALU_OR: out_low = A | B;
      common::ALU_XOR: out_low = A ^ B;
      common::ALU_NOT: out_low = ~A;
      common::ALU_NOP0: out_low = 0;
      common::ALU_NOP1: out_low = 0;
    endcase
    OUT = {1'b0, out_low == 0, gen, prop, out_low};
  end
  `endif

  `ifdef FORMAL
  logic [3:0] f_sum = A+B+{3'b0, C_IN};
  wire [3:0] f_out = OUT[3:0];
  wire f_prop = OUT[4];
  wire f_gen = OUT[5];
  wire f_zero = OUT[6];

  always_comb begin
    case (OP)
      common::ALU_ADD: begin
        assert (f_out == f_sum);
        assert (f_prop == (A+B == 4'hF));
        assert (f_gen == ({1'b0, A}+{1'b0, B} > 5'hF));
      end
      common::ALU_SUB: begin
        // C_IN must be 1 for the first slice. After that, it depends.
        assert (f_out == A+(~B)+{3'b0, C_IN});
        assert (f_prop == (A+(~B) == 4'hF));
        assert (f_gen == ({1'b0, A}+{1'b0, ~B} > 5'hF));
      end
      // TODO: yosys bug means need begin/end here
      common::ALU_AND: begin assert (f_out == (A & B)); end
      common::ALU_OR: begin assert (f_out == (A | B)); end
      common::ALU_XOR: begin assert (f_out == (A ^ B)); end
      common::ALU_NOT: begin assert (f_out == ~A); end
      common::ALU_NOP0: begin assert (f_out == 0); end
      common::ALU_NOP1: begin assert (f_out == 0); end
      default: begin assert (0); end
    endcase
    assert (f_zero == (f_out == 0));
  end
  `endif
endmodule
