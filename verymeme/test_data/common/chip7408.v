module chip7408(
  input wire [3:0] A,
  input wire [3:0] B,
  output wire [3:0] Y
);
  assign Y = A & B;
endmodule
