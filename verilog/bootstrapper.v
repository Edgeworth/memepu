// Copyright 2019 E.
`include "common.v"
/* verilator lint_off UNUSED */  // TODO REMOVE
/* verilator lint_off UNDRIVEN */  // TODO REMOVE
module bootstrapper(
  input wire [31:0] TIME,
  input wire CLK,
  input wire N_CLK,
  output logic [7:0] DATA,
  output logic [16:0] ADDR,
  output logic N_BOOTED,
  output logic CONTROL_N_WE,
  output logic MLU_SLICE_N_WE,
  output logic MLU_LOOKAHEAD_N_WE
);
  // TODO: Need to use 2 bits to decide which write enable lines to enable.
  // TODO: Use 2=>4 decoder, one of the signals is latch booted, goes to JK flipflop.
  // TODO: Or put write enable lines in EEPROM.
  // TODO: This doesn't work, need to latch.
  // TODO: Need to be careful about CLK and not CLK. EEPROM needs to have data ready before doing.
  // TODO: Can put write enable lines inside eeprom?
//  assign N_BOOTED = !TIME[17];  // TODO: Use chip for this negate.
  // TODO: assign addr.
//  eeprom bootstrap_eeprom(.ADDR({TIME[16:0]}), .N_OE(N_BOOTED), .OUT_DATA(DATA));

  `ifdef FORMAL
  always_comb begin
    if (N_BOOTED) begin

    end else begin
//      assert (CONTROL_N_WE == 1'b1);
    end
  end
  `endif
endmodule
