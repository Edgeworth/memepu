// Copyright 2019 E.
`include "common.v"
// Shift register.
module chip74299(
  input wire [1:0] S,
  input wire [1:0] N_OE,
  input wire N_MR,
  input wire DSR,
  input wire DSL,
  input wire CP,
  inout wire [7:0] IO,
  output logic Q0,
  output logic Q7
);
  logic [7:0] shift_reg;

  // Expose shift reg MSB and LSB for chaining.
  assign Q0 = shift_reg[0];
  assign Q7 = shift_reg[7];
  assign IO = N_OE == 0 ? shift_reg:8'bZ;

  always_ff @(posedge CP or negedge N_MR) begin
    if (N_MR == 0)
      shift_reg <= 0;
    else begin
      case (S)
        2'b11:  // Parallel load
            shift_reg <= IO;
        2'b01: begin  // Shift right (left from MSB is leftmost (datasheet) perspective)
          shift_reg <= shift_reg << 1;
          shift_reg[0] <= DSL;
        end
        2'b10: begin  // Shift left (right from MSB is leftmost (datasheet) perspective)
          shift_reg <= shift_reg >> 1;
          shift_reg[7] <= DSR;
        end
        2'b00:;  // Hold
      endcase
    end
  end

  // TODO(improvement) finish
  `ifdef FORMAL
  always_comb begin
    assert (Q0 == shift_reg[0]);
    assert (Q7 == shift_reg[7]);

    if (N_MR == 0) begin
      assert (IO == 0);
    end
  end
  always_ff @(posedge CP) begin
    if (N_MR != 0) begin
      if (N_OE == 0 && S == 2'b11) assert (shift_reg == IO);
    end
  end
  `endif

endmodule
