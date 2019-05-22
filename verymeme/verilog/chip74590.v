`include "common.v"
module chip74590(
  input wire N_MRC,  // Async reset
  input wire N_OE,
  input wire CPC,  // Counter clock input
  output logic N_RCO,  // Ripple carry output.
  output logic [7:0] Q_OUT
);
  logic [7:0] count;
  assign Q_OUT = !N_OE ? count:8'bZ;
  assign N_RCO = count == 8'hFF ? 0 : 1;

  always_ff @(posedge CPC or negedge N_MRC) begin
    if (!N_MRC) count <= 0;
    else count <= count + 8'b1;
  end

  `ifdef FORMAL
  integer f_past = 0;

  // If there was an asynchronous reset, can't rely on the values in the last clock cycle.
  always_ff @($global_clock) begin
    if (!N_MRC) f_past <= 0;
    else f_past <= f_past == 2 ? 2 : (f_past + 1);

    if (f_past >= 2 && N_MRC) begin
      // If there was a positive edge to load the register, check it loaded properly.
      if ($past(CPC) && $past(CPC) != $past(CPC, 2)) begin
        assert ($past(count) == $past(count, 2) + 8'b1);
      end
    end
  end

  always_comb begin
    if (!N_OE) assert (Q_OUT == count);
    if (!N_MRC) assert (Q_OUT == 0); // Asynchronous reset should always make it zero.
    assert (N_RCO == (count != 8'hFF));  // RCO is 1 when count isn't at edge.
  end
  `endif
endmodule
