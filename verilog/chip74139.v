// Copyright 2019 E.
`include "common.v"
// Dual 2->4 line decoder, inverting outputs.
module chip74139(
  input wire [1:0] A1,
  input wire [1:0] A2,
  input wire N_E1,  // Enable input or not. (all high if not enabled).
  input wire N_E2,
  output logic [3:0] N_Y1,
  output logic [3:0] N_Y2
);
  assign N_Y1 = N_E1 ? 4'b1111:~(4'b1 << A1);
  assign N_Y2 = N_E2 ? 4'b1111:~(4'b1 << A2);

  `ifdef FORMAL
  always_comb begin
    if (!N_E1) begin
      case (A1)
        2'b00: begin assert (N_Y1 == 4'b1110); end
        2'b01: begin assert (N_Y1 == 4'b1101); end
        2'b10: begin assert (N_Y1 == 4'b1011); end
        2'b11: begin assert (N_Y1 == 4'b0111); end
      endcase
    end else begin
      assert (N_Y1 == 4'b1111);
    end
    if (!N_E2) begin
      case (A2)
        2'b00: begin assert (N_Y2 == 4'b1110); end
        2'b01: begin assert (N_Y2 == 4'b1101); end
        2'b10: begin assert (N_Y2 == 4'b1011); end
        2'b11: begin assert (N_Y2 == 4'b0111); end
      endcase
    end else begin
      assert (N_Y2 == 4'b1111);
    end
  end
  `endif
endmodule
