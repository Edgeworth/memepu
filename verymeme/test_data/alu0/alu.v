module alu(
);
  wire [31:0] A = 0;
  wire [31:0] B = 0;
  wire [2:0] OP = 0;
  wire C_IN = 0;
  logic [31:0] unused_OUT;
  logic unused_Z;
  logic unused_C;
  logic unused_N;

  wire [7:0] slice_p, slice_g, slice_z, unused_slice;
  wire [8:0] carrys;

  assign carrys[0] = C_IN;
  assign unused_C = carrys[8];
  assign unused_N = unused_OUT[31];

  generate
    genvar i;
    for (i = 0; i < 8; i = i+1) begin
      alu_slice slice(.A(A[i*4+3:i*4]), .B(B[i*4+3:i*4]), .OP(OP),
        .C_IN(carrys[i]),
        .OUT({unused_slice[i], slice_z[i], slice_g[i], slice_p[i], unused_OUT[i*4+3:i*4]}));
    end
  endgenerate
  alu_lookahead lookahead(.C_IN(C_IN), .P(slice_p), .G(slice_g), .CARRYS(carrys[8:1]));

  wire [3:0] z_level0;
  wire [1:0] z_level1;
  wire unused_z;
  chip7408 and_level0(.A(slice_z[3:0]), .B(slice_z[7:4]), .Y(z_level0));
  chip7408 and_level1(.A({1'b0, z_level1[0], z_level0[1:0]}),
    .B({1'b0, z_level1[1], z_level0[3:2]}), .Y({unused_z, unused_Z, z_level1[1:0]}));
endmodule
