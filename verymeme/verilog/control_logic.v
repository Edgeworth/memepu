`include "common.v"
/* verilator lint_off UNUSED */  // TODO: Remove
module control_logic(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST,
  input wire [5:0] OPCODE,
  output logic [4:0] REG_SRC, // Control logic reg src.
  output logic [1:0] REG_SEL, // 0=>Opcode reg0, 1=>Opcode reg1, 2=>Control logic reg sel.
  output logic [3:0] ALU_PLANE,
  // In plane signals:
  output logic REG_N_IN_CLK,
  output logic TMP0_IN_CLK,
  output logic TMP1_IN_CLK,
  output logic OPWORD_IN_CLK,
  output logic OPCODE_IN_CLK,
  // Out plane signals:
  output logic REG_N_OUT,
  output logic TMP0_N_OUT,
  output logic TMP1_N_OUT,
  output logic MLU_N_OUT,
  output logic SHIFTER_N_OUT,
  output logic TIMER_N_OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  wire [2:0] unused_and;
  wire counter_combined_n_rst;
  chip7408 and_gate(.A({3'b0, microop_counter_n_rst}), .B({3'b0, N_RST}),
    .Y({unused_and, counter_combined_n_rst}));
  wire [4:0] microop_count /*verilator public*/;
  microop_counter counter(.CLK(CLK), .N_RST(counter_combined_n_rst), .COUNT(microop_count));

  // TODO: change to specific lut chip
  wire [31:0] microcode_val;
  lut#(.DEPTH(11), .WIDTH(32), .INITIAL("microcode.hex")) microcode(
    .ADDR({OPCODE, microop_count}), .OUT_DATA(microcode_val),
    .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA({BOOTSTRAP_DATA, 24'b0}));  // TODO(bootstrap): only feeding 8 bits in

  // In plane: NONE, REG, TMP0, TMP1
  wire [2:0] control_in_plane /*verilator public*/;
  // Out plane: NONE, REG, TMP0, TMP1, MLU, SHIFTER, TIMER
  wire [2:0] control_out_plane /*verilator public*/;
  // ALU plane:
  //   For MLU: 3 bits for op select, 1 bit for carry.
  //   For shifter: 2 bits for direction and arithmetic or not.
  // Misc plane: Micro-op counter reset
  wire control_misc_plane /*verilator public*/;
  wire [13:0] unused_control;
  // Latch on N_CLK - control signals change on falling clock, system stabilises, then read in
  // on rising clock.
  register32 microcode_latch(.CLK(N_CLK), .IN(microcode_val), .N_OE(0),
    .OUT({unused_control, control_misc_plane, control_in_plane, control_out_plane,
        ALU_PLANE, REG_SEL, REG_SRC}));

  // In plane decoder - enable on CLK to do pulse.
  wire unused_in_none;
  wire reg_in_clk;
  wire [1:0] unused_in_plane;
  chip74238 in_plane_decoder(.A(control_in_plane), .N_E1(0), .N_E2(0), .E3(CLK),
    .Y({unused_in_plane, OPCODE_IN_CLK, OPWORD_IN_CLK, TMP1_IN_CLK, TMP0_IN_CLK, reg_in_clk,
        unused_in_none}));

  // Inverter:
  wire [4:0] unused_inverter;
  chip7404 inverter(.A({5'b0, reg_in_clk}), .Y({unused_inverter, REG_N_IN_CLK}));

  // Out plane decoder:
  wire unused_out_none;
  wire unused_out_plane;
  chip74138 out_plane_decoder(.A(control_out_plane), .N_E1(0), .N_E2(0), .E3(1),
    .N_Y({unused_out_plane, TIMER_N_OUT, SHIFTER_N_OUT, MLU_N_OUT, TMP1_N_OUT,
        TMP0_N_OUT, REG_N_OUT, unused_out_none}));

  // Misc plane decoder
  // TODO(optimisation): Can reduce size? 2=>4 decoder (dual).
  wire unused_misc_none;
  wire [5:0] unused_misc_plane;
  wire microop_counter_n_rst;
  chip74138 misc_plane_decoder(.A({2'b0, control_misc_plane}), .N_E1(0), .N_E2(0), .E3(1),
    .N_Y({unused_misc_plane, microop_counter_n_rst, unused_misc_none}));

  `ifdef FORMAL
  // Contract that N_RST is deasserted after at least 2 falling edges.
  integer f_past_n_clk = 0;
  always_ff @(posedge N_CLK or negedge N_RST) begin
    if (!N_RST) f_past_n_clk <= 0;
    else f_past_n_clk = f_past_n_clk == 2 ? 2 : (f_past_n_clk + 1);
  end

  always_ff @($global_clock) begin
    // Only do these checks after coming out of a reset and having the first falling edge to set-up
    // state.
    if (f_past_n_clk == 2) begin
      assert ($past(REG_SEL) != 2'b11);  // Not a valid register selector option.
      // Don't try to do a left-arithmetic shift, it doesn't make sense.
      if ($past(SHIFTER_N_OUT)) assert ($past(ALU_PLANE[1:0]) != 2'b11);

      // Don't try to write and read to the same thing:
      assert ($past(REG_N_IN_CLK) || $past(REG_N_OUT));
      assert ($past(!TMP0_IN_CLK) || $past(TMP0_N_OUT));
      assert ($past(!TMP1_IN_CLK) || $past(TMP1_N_OUT));
    end
  end

  // TODO(testing): More testing.
  always_comb begin
    `CONTRACT(CLK != N_CLK);  // Must be opposites.

    // TODO(testing): Make sure subtract provides carry.

    `ifdef BOOTSTRAP
    if (!N_BOOTED) `CONTRACT(BOOTSTRAP_N_WE);  // Don't write after boot.
    `else
    `CONTRACT(BOOTSTRAP_N_WE);  // Don't write if we're not bootstrapping.
    `endif
  end
  `endif
endmodule
