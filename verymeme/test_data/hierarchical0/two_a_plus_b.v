module two_a_plus_b(
  input wire [7:0] A,
  input wire [7:0] B,
  output wire [7:0] OUT,
);
  logic [7:0] two_a;
  // TODO: Implement unused.
  logic plus_a_carry;
  logic plus_b_carry;

  full_adder two_a_adder(.A(A), .B(A), .C_IN(0), .Y(two_a), .C_OUT(plus_a_carry));
  full_adder plus_b_adder(.A(two_a), .B(B), .C_IN(0), .Y(OUT), .C_OUT(plus_b_carry));
endmodule
