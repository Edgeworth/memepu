module test(
  input logic clk,
  input logic A,
  input logic B,
  output logic AND
);

always @(posedge clk) begin
  AND <= A & B;
end

endmodule
