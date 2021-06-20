// Copyright 2019 E.
module chip7408(
  input wire [3:0] A,
  input wire [3:0] B,
  output logic [3:0] Y
);
  assign Y = A & B;
endmodule
