module two_a_plus_b(
  input wire [7:0] A,
  input wire [7:0] B,
  output wire [7:0] OUT,
);
  logic [7:0] two_a;

  full_adder two_a_adder(.A(A), .B(A), .C_IN(1'b0), .Y(two_a), .C_OUT());
  full_adder plus_b_adder(.A(two_a), .B(B), .C_IN(1'b0), .Y(OUT), .C_OUT());
endmodule
