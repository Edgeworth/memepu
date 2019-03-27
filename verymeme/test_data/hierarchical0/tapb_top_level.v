module tapb_top_level(
  input wire [3:0] LOW_B
);
  logic [7:0] out;
  logic [3:0] HIGH_B;

  assign HIGH_B = 4'b1010;

  two_a_plus_b tapb(.A(8'd42), .B({HIGH_B, LOW_B}), .OUT(out));
endmodule
