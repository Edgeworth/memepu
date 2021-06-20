// Copyright 2019 E.
module sram(
  input wire [11:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire [7:0] IN_DATA,
  output logic [7:0] OUT_DATA
);
  assign OUT_DATA = 0;
endmodule
