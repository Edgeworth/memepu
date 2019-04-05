`include "common.v"
/* verilator lint_off UNOPTFLAT */
module timer(
  input wire CLK,
  input wire N_RST,
  output logic [31:0] TIME
);
  generate
    genvar i;
    wire [8:0] rco;
    wire unused_rco;
    assign rco[0] = 1'b1;
    assign unused_rco = rco[8];
    for (i = 0; i < 8; i = i+1) begin
      chip74161 counter(.CLK(CLK), .N_CLR(N_RST), .ENP(1'b1), .ENT(rco[i]), .PRESET(4'b0),
        .N_LOAD(1'b1), .Q(TIME[i*4+3:i*4]), .RCO(rco[i+1]));
    end
  endgenerate

  `ifdef FORMAL
  logic f_past;
  logic f_last_clk;
  initial begin
    f_last_clk = 0;
    f_past = 0;
  end

  // Asynchronous reset should always make it zero.
  always_comb begin
    if (N_RST == 0) assert (TIME == 0);
  end

  // Assume something must change each global clock.
  always_ff @($global_clock) begin
    assume (f_last_clk != CLK);
    f_last_clk <= CLK;
  end

  // If there was an asynchronous reset, can't rely on the values in the last clock cycle.
  always_ff @(posedge CLK or negedge N_RST) begin
    if (N_RST == 0) f_past <= N_RST ? 1:0;
    else f_past <= 1;
  end

  always_ff @(posedge CLK) begin
    if (f_past && N_RST != 0) begin
      assert (TIME == $past(TIME)+4'b1);  // Increment should work.
    end
  end
  `endif
endmodule
