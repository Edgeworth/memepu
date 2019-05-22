`include "common.v"
module chip74590(
  input wire N_MRC,  // Async reset
  input wire N_OE,
  input wire CPC,  // Counter clock input
  input wire CPR,  // Register clock input
  input wire [7:0] Q_IN,
  output logic N_RCO,  // Ripple carry output.
  output logic [7:0] Q_OUT
);
  logic [7:0] count;
  assign Q_OUT = !N_OE ? count:8'bZ;
  assign N_RCO = count == 8'hFF ? 0 : 1;

  always_ff @(posedge CPR or posedge CPC or negedge N_MRC) begin
    if (!N_MRC) count <= 0;
    else if (CPR) count <= Q_IN;
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
      if ($past(CPR) && $past(CPR) != $past(CPR, 2)) assert ($past(count) == $past(Q_IN));
      if ($past(CPC) && $past(CPC) != $past(CPC, 2)) begin
        assert ($past(count) == $past(count, 2) + 8'b1);
      end
    end
  end

  always_comb begin
    if (!N_MRC) assert (Q_OUT == 0); // Asynchronous reset should always make it zero.
    assert (N_RCO == (count != 8'hFF));  // RCO is 1 when count isn't at edge.
  end

  always_comb begin
    // As a compromise to deal with multiple asynchronous signals (although they are really
    // synchronous), don't let CPR and CPC both be true at the same time, so we can distinguish them
    // on posedge.
    `CONTRACT(!(CPR && CPC));
    if (!N_OE) assert (Q_OUT == count);
  end
  `endif
endmodule
