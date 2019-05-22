`include "common.v"

module microop_counter(
  input wire CLK,
  input wire N_RST,
  output logic [4:0] COUNT
);
  wire unused_rco;
  wire [2:0] unused_count;
  chip74590 counter(.N_MRC(N_RST), .N_OE(1), .CPC(CLK), .N_RCO(unused_rco),
    .Q_OUT({unused_count, COUNT}));

  `ifdef FORMAL
  `endif
endmodule
