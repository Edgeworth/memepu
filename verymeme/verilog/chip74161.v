`include "common.v"
// 74590 is ripple carry so it's slow.
// 74163 is synchronous reset, so don't use it.
module chip74161(
  input wire CLK,
  input wire N_CLR,  // Asynchronous reset.
  input wire ENP,  // Must be enabled to count.
  input wire ENT,  // Must be enabled to count.
  input wire [3:0] PRESET,
  input wire N_LOAD,  // Load from |PRESET|.
  output logic [3:0] Q,
  output logic RCO  // Ripple carry output. High when count reaches maximum and |ENT| is true.
);
  logic [3:0] count;

  // Allow for chaining.
  assign RCO = ENT && count == 4'hF ? 1:0;

  always_ff @(posedge CLK or negedge N_CLR) begin
    if (N_CLR == 0)
      count <= 0;
    else if (N_LOAD == 0) count <= PRESET;
    else if (ENP && ENT) count <= count+1;
  end

  assign Q = count;

  `ifdef FORMAL
  logic f_past;
  logic f_last_clk;
  logic f_last_n_clr;
  initial begin
    f_last_clk = 0;
    f_last_n_clr = 0;
    f_past = 0;
  end

  // Asynchronous reset should always make it zero.
  always_comb begin
    if (N_CLR == 0) assert (Q == 0);
    assert (RCO == (ENT && count == 4'hF));
  end

  // Assume something must change each global clock.
  always_ff @($global_clock) begin
    assume (f_last_clk != CLK || f_last_n_clr != N_CLR);
    f_last_clk <= CLK;
    f_last_n_clr <= N_CLR;
  end

  // If there was an asynchronous reset, can't rely on the values in the last clock cycle.
  always_ff @(posedge CLK or negedge N_CLR) begin
    if (N_CLR == 0) f_past <= N_CLR ? 1:0;
    else f_past <= 1;
  end

  always_ff @(posedge CLK) begin
    if (f_past && N_CLR != 0) begin
      if ($past(N_LOAD) == 0) assert (Q == $past(PRESET));  // Preset should work.
      else if ($past(ENP) && $past(ENT)) assert (Q == $past(Q)+4'b1);  // Increment should work.
      else assert ($stable(Q));  // Otherwise shouldn't change.
    end
  end
  `endif
endmodule
