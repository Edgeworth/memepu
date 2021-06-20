// Copyright 2019 E.
`include "common.v"

// D-flipflop, positive edge trigger (async preset not implemented).
module chip7474(
  input wire [1:0] D,
  input wire [1:0] CP,
  input wire [1:0] N_R,
  output logic [1:0] Q,
  output logic [1:0] N_Q
);
  generate
    genvar i;
    for (i = 0; i < 2; i = i+1) begin
      logic data;

      assign Q[i] = data;
      assign N_Q[i] = ~data;

      // Make sure async reset works on startup for verilator.
      `ifdef verilator
      initial begin
      if (!N_R[i]) data = 0;
      end
      `endif

      always_ff @(posedge CP[i] or negedge N_R[i]) begin
        if (!N_R[i]) data <= 0;
        else data <= D[i];
      end

      `ifdef FORMAL
      integer f_past;
      initial f_past = 0;

      always_ff @($global_clock) begin
        if (!N_R[i]) f_past <= 0;
        else f_past <= 1;

        if (f_past && N_R[i] && $rose(CP[i]))
          assert (data == $past(D[i]));
      end

      always_comb begin
        assert (Q[i] != N_Q[i]);
        if (!N_R[i]) assert (!Q[i] && N_Q[i]);
      end
      `endif
    end
  endgenerate
endmodule
