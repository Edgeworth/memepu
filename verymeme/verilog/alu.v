`include "common.v"
/* verilator lint_off UNOPTFLAT */
module alu(
  input wire [31:0] A,
  input wire [31:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  output logic [31:0] OUT,
  output logic Z,
  output logic C,
  output logic N
);
  wire [7:0] tmp = 0;  // TODO bootstrapping
  wire [7:0] slice_p, slice_g, slice_z, slice_unused;
  wire [7:0] carrys;

  assign C = carrys[7];
  assign N = OUT[31];

  generate
    genvar i;
    for (i = 0; i < 8; i = i+1) begin
      alu_slice slice(.A(A[i*4+3:i*4]), .B(B[i*4+3:i*4]), .OP(OP),
        .C_IN(i == 0 ? C_IN:carrys[i-1]),
        .OUT({slice_unused[i], slice_z[i], slice_g[i], slice_p[i], OUT[i*4+3:i*4]}));
    end
  endgenerate

  // TODO make own file and move this in + non-hexfile implementation.
  sram#(.DEPTH(17), .WIDTH(8), .INITIAL("alu_lookahead.hex")) lookahead_mem(
    .ADDR({C_IN, slice_g, slice_p}), .N_WE(1), .N_OE(0), .IN_DATA(tmp), .OUT_DATA(carrys));

  wire [3:0] z_level0;
  wire [1:0] z_level1;
  wire z_unused;
  chip7408 and_level0(.A(slice_z[3:0]), .B(slice_z[7:4]), .Y(z_level0));
  chip7408 and_level1(.A({1'b0, z_level1[0], z_level0[1:0]}),
    .B({1'b0, z_level1[1], z_level0[3:2]}), .Y({z_unused, Z, z_level1[1:0]}));

  `ifdef FORMAL
  always_comb begin
    case (OP)
      common::ALU_ADD: begin assert (OUT == A+B+{31'b0, C_IN}); end
      common::ALU_SUB: begin
        // Implementation must set carry when doing subtraction.
        `CONTRACT (C_IN == 1'b1);
        assert (OUT == (A-B));
      end
      common::ALU_AND: begin assert (OUT == (A & B)); end
      common::ALU_OR: begin assert (OUT == (A | B)); end
      common::ALU_XOR: begin assert (OUT == (A ^ B)); end
      common::ALU_NOT: begin assert (OUT == ~A); end
      common::ALU_NOP0: begin assert (OUT == 0); end
      common::ALU_NOP1: begin assert (OUT == 0); end
      default: begin assert (0); end
    endcase
    assert (Z == (OUT == 0));
  end
  `endif
endmodule
