`include "common.v"
/* verilator lint_off UNOPTFLAT */
module alu(
  input wire [31:0] A,
  input wire [31:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  output /*u*/ wire [31:0] OUT,
  output /*u*/ wire Z,
  output /*u*/ wire C,
  output /*u*/ wire N
);
  wire [7:0] tmp = 0;  // TODO bootstrapping
  wire [7:0] slice_p, slice_g, slice_z, slice_unused;
  wire [8:0] carrys;

  assign carrys[0] = C_IN;
  assign C = carrys[8];
  assign N = OUT[31];

  generate
    genvar i;
    for (i = 0; i < 8; i = i+1) begin
      alu_slice slice(.A(A[i*4+3:i*4]), .B(B[i*4+3:i*4]), .OP(OP), .C_IN(carrys[i]),
        .OUT({slice_unused[i], slice_z[i], slice_g[i], slice_p[i], OUT[i*4+3:i*4]}));
    end
  endgenerate
  sram#(.DEPTH(17), .WIDTH(8), .INITIAL("alu_lookahead.hex")) lookahead_mem(
    .ADDR({C_IN, slice_g, slice_p}), .N_WE(1), .N_OE(0), .IN_DATA(tmp), .OUT_DATA(carrys[8:1]));

  wire [3:0] z_level0;
  wire [1:0] z_level1;
  wire z_unused;
  chip7408 and_level0(.A(slice_z[3:0]), .B(slice_z[7:4]), .Y(z_level0));
  chip7408 and_level1(.A({1'b0, z_level1[0], z_level0[1:0]}),
    .B({1'b0, z_level1[1], z_level0[3:2]}), .Y({z_unused, Z, z_level1[1:0]}));

  `ifdef FORMAL
  always_comb begin
    case (OP)
      common::ALU_ADD: assert (OUT == A+B+{31'b0, C_IN});
      common::ALU_SUB: assert (OUT == (A-B));
      common::ALU_AND: assert (OUT == (A & B));
      common::ALU_OR: assert (OUT == (A | B));
      common::ALU_XOR: assert (OUT == (A ^ B));
      common::ALU_NOT: assert (OUT == ~A);
      common::ALU_NOP0: assert (OUT == 0);
      common::ALU_NOP1: assert (OUT == 0);
      default: assert (0);
    endcase
    assert (Z == (OUT == 0));
  end
  `endif
endmodule
