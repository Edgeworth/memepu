`include "common.v"
// 8-bit register with asynchronous clear.
module chip74273(
  input wire [7:0] D,
  input wire N_MR,
  input wire CP,
  output logic [7:0] Q
);
  logic [7:0] value;

  assign Q = value;

  // Make sure async reset works on startup for verilator.
  `ifdef verilator
  initial begin
    if (!N_MR) value = 0;
  end
  `endif

  always_ff @(posedge CP or negedge N_MR) begin
    if (!N_MR) value <= 0;
    else value <= D;
  end

  `ifdef FORMAL
  integer f_past;
  initial f_past = 0;

  // If there was an asynchronous reset, can't rely on the values in the last clock cycle.
  always_ff @($global_clock) begin
    if (!N_MR) f_past <= 0;
    else f_past <= 1;

    if (N_MR && f_past && $rose(CP)) assert (Q == $past(D));
  end

  always_comb begin
    assert (value == Q);
    if (!N_MR) assert (Q == 0);
  end
  `endif
endmodule
