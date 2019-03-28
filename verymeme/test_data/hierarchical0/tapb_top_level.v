module tapb_top_level();
  logic [7:0] unused_out;
  logic [3:0] high_b;

  assign high_b = 4'b1010;

  two_a_plus_b tapb(.A(8'd42), .B({high_b, 4'b1010}), .OUT(unused_out));
endmodule
