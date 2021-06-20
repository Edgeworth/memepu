// Copyright 2019 E.
module full_adder(
  input wire [7:0] A,
  input wire [7:0] B,
  input wire C_IN,
  output logic [7:0] Y,
  output logic C_OUT
);
  logic [7:0] A_XOR_B;
  logic [7:0] A_AND_B;
  logic [7:0] C_AND_AB;
  logic [7:0] C;

  assign C_OUT = C[7];

  chip7486 xor0_low(
    .A(A[3:0]),
    .B(B[3:0]),
    .Y(A_XOR_B[3:0])
  );
  chip7486 xor0_high(
    .A(A[7:4]),
    .B(B[7:4]),
    .Y(A_XOR_B[7:4])
  );

  chip7486 xor1_low(
    .A(A_XOR_B[3:0]),
    .B({C[2:0], C_IN}),
    .Y(Y[3:0])
  );
  chip7486 xor1_high(
    .A(A_XOR_B[7:4]),
    .B(C[6:3]),
    .Y(Y[7:4])
  );

  chip7408 and0_low(
    .A(A[3:0]),
    .B(B[3:0]),
    .Y(A_AND_B[3:0])
  );
  chip7408 and0_high(
    .A(A[7:4]),
    .B(B[7:4]),
    .Y(A_AND_B[7:4])
  );

  chip7408 and1_low(
    .A(A_XOR_B[3:0]),
    .B({C[2:0], C_IN}),
    .Y(C_AND_AB[3:0])
  );
  chip7408 and1_high(
    .A(A_XOR_B[7:4]),
    .B(C[6:3]),
    .Y(C_AND_AB[7:4])
  );

  chip7432 or0_low(
    .A(A_AND_B[3:0]),
    .B(C_AND_AB[3:0]),
    .Y(C[3:0])
  );
  chip7432 or0_high(
    .A(A_AND_B[7:4]),
    .B(C_AND_AB[7:4]),
    .Y(C[7:4])
  );
endmodule
