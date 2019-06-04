`include "common.v"
/* verilator lint_off UNOPTFLAT */
module mlu(
  input wire [31:0] A,
  input wire [31:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  input wire N_RST,
  output logic [31:0] OUT,
  output logic Z,
  output logic C,
  output logic N,
  // Bootstrapping flags:
  input wire [7:0] BOOTSTRAP_DATA,
  input wire [16:0] BOOTSTRAP_ADDR,
  input wire N_BOOTED,
  input wire BOOTSTRAP_MLU_SLICE_N_WE,
  input wire BOOTSTRAP_MLU_LOOKAHEAD_N_WE
);
  wire [7:0] slice_p, slice_g, slice_z, unused_slice;
  wire [8:0] carrys;

  assign carrys[0] = C_IN;
  assign C = carrys[8];
  assign N = OUT[31];

  generate
    genvar i;
    for (i = 0; i < 8; i = i+1) begin
      mlu_slice slice(.A(A[i*4+3:i*4]), .B(B[i*4+3:i*4]), .OP(OP), .C_IN(carrys[i]),
        .OUT({unused_slice[i], slice_z[i], slice_g[i], slice_p[i], OUT[i*4+3:i*4]}),
        .BOOTSTRAP_ADDR(BOOTSTRAP_ADDR[11:0]), .BOOTSTRAP_DATA(BOOTSTRAP_DATA),
        .BOOTSTRAP_N_WE(BOOTSTRAP_MLU_SLICE_N_WE), .N_BOOTED(N_BOOTED));
    end
  endgenerate
  mlu_lookahead lookahead(.C_IN(C_IN), .P(slice_p), .G(slice_g), .CARRYS(carrys[8:1]),
    .BOOTSTRAP_ADDR(BOOTSTRAP_ADDR), .BOOTSTRAP_DATA(BOOTSTRAP_DATA), .N_BOOTED(N_BOOTED),
    .BOOTSTRAP_N_WE(BOOTSTRAP_MLU_LOOKAHEAD_N_WE));

  wire [3:0] z_level0;
  wire [1:0] z_level1;
  wire unused_z;
  chip7408 and_level0(.A(slice_z[3:0]), .B(slice_z[7:4]), .Y(z_level0));
  chip7408 and_level1(.A({1'b0, z_level1[0], z_level0[1:0]}),
    .B({1'b0, z_level1[1], z_level0[3:2]}), .Y({unused_z, Z, z_level1[1:0]}));

  `ifdef FORMAL
  always_comb begin
    if (N_RST) begin
      case (OP)
        common::MLU_ADD: begin assert (OUT == A+B+{31'b0, C_IN}); end
        common::MLU_SUB: begin
          // Implementation must set carry when doing subtraction.
          `CONTRACT (C_IN == 1'b1);
          assert (OUT == (A-B));
        end
        common::MLU_AND: begin assert (OUT == (A & B)); end
        common::MLU_OR: begin assert (OUT == (A | B)); end
        common::MLU_XOR: begin assert (OUT == (A ^ B)); end
        common::MLU_NOT: begin assert (OUT == ~A); end
        common::MLU_NOP0: begin assert (OUT == 0); end
        common::MLU_NOP1: begin assert (OUT == 0); end
        default: begin assert (0); end
      endcase
      assert (Z == (OUT == 0));
    end
  end
  `else
  wire _unused_ok = &{N_RST};
  `endif
endmodule
