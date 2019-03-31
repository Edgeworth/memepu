`include "common.v"

module alu(
  input wire [31:0] IN,
  input wire [4:0] SHFT,
  output logic [31:0] OUT
);
  wire [7:0] slice_p, slice_g, slice_z, unused_slice;
  wire [8:0] carrys;

  assign carrys[0] = C_IN;
  assign C = carrys[8];
  assign N = OUT[31];

  generate
    genvar i;
    for (i = 0; i < 8; i = i+1) begin
      alu_slice slice(.A(A[i*4+3:i*4]), .B(B[i*4+3:i*4]), .OP(OP),
        .C_IN(carrys[i]),
        .OUT({unused_slice[i], slice_z[i], slice_g[i], slice_p[i], OUT[i*4+3:i*4]}));
    end
  endgenerate

  `ifdef FORMAL
  always_comb begin
    assert (OUT == (IN << SHFT));
  end
  `endif
endmodule
