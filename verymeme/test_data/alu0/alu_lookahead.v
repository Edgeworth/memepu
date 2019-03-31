module alu_lookahead(
  input wire C_IN,
  input wire [7:0] P,
  input wire [7:0] G,
  output logic [7:0] CARRYS
);
  wire [7:0] unused = 0;
  sram17x8 lookahead_mem(.ADDR({C_IN, G, P}), .N_WE(1), .N_OE(0),
      .IN_DATA(unused), .OUT_DATA(CARRYS));
endmodule
