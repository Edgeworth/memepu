`include "common.v"
module eeprom(
  input wire [DEPTH-1:0] ADDR,
  input wire N_OE,
  output wire [WIDTH-1:0] OUT_DATA
);
  parameter DEPTH = 17;
  parameter WIDTH = 8;
  parameter INITIAL = "mlu_slice.hex";  // TODO remove.
  logic [WIDTH-1:0] mem [(1 << DEPTH)-1:0];

  assign OUT_DATA = N_OE == 0 ? mem[ADDR]:8'bZ;

  initial begin
    $readmemh(INITIAL, mem);
  end

  `ifdef FORMAL
  always_comb begin
    if (N_BOOTED) begin
    end else begin
      assert (CONTROL_N_WE == 1'b1);
    end
  end
  `endif
endmodule
