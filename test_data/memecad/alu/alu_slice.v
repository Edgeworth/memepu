// Copyright 2019 E.
module alu_slice(
  input wire [3:0] A,
  input wire [3:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  output logic [7:0] OUT
);
  wire [7:0] unused = 0;
  sram slice_mem(.ADDR({OP, C_IN, B, A}), .N_WE(1), .N_OE(0), .IN_DATA(unused), .OUT_DATA(OUT));
endmodule
