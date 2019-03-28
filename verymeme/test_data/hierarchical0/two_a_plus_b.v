module two_a_plus_b(
  input wire [7:0] A,
  input wire [7:0] B,
  output logic [7:0] OUT,
);
  logic [7:0] two_a;
  logic unused_carry0;
  logic unused_carry1;

  full_adder two_a_adder(.A(A), .B(A), .C_IN(0), .Y(two_a), .C_OUT(unused_carry0));
  full_adder plus_b_adder(.A(two_a), .B(B), .C_IN(0), .Y(OUT), .C_OUT(unused_carry1));
endmodule
