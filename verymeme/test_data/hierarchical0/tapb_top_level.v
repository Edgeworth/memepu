module tapb_top_level(
  input wire [3:0] LOW_B
);
  logic [7:0] out;
  two_a_plus_b tapb(.A(8'd42), .B({4'b1010, LOW_B}), .OUT(out));
endmodule
