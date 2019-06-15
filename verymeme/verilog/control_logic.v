`include "common.v"
module control_logic(
  input wire CLK,
  input wire N_CLK,
  input wire N_RST,
  input wire [5:0] OPWORD_OPCODE,
  // Grouped signals
  output logic [5:0] CTRL_DATA,
  output logic [1:0] REG_SEL,
  output logic [3:0] MISC2_PLANE,
  // Decoded in plane signals:
  output logic REG_N_IN_CLK,
  output logic TMP0_IN_CLK,
  output logic TMP1_IN_CLK,
  output logic MMU_N_IN_CLK,
  output logic OPWORD_IN_CLK,
  // Decoded out plane signals:
  output logic REG_N_OUT,
  output logic TMP0_N_OUT,
  output logic TMP1_N_OUT,
  output logic MMU_N_OUT,
  output logic MLU_N_OUT,
  output logic SHIFTER_N_OUT,
  output logic TIMER_N_OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);
  // Inverter:
  wire [2:0] unused_inverter;
  chip7404 inverter(.A({3'b0, MISC2_PLANE[0], mmu_in_clk, reg_in_clk}),
    .Y({unused_inverter, n_opcode_sel, MMU_N_IN_CLK, REG_N_IN_CLK}));

  // Ander:
  wire [2:0] unused_and;
  wire counter_combined_n_rst;
  chip7408 and_gate(.A({3'b0, microop_counter_n_rst}), .B({3'b0, N_RST}),
    .Y({unused_and, counter_combined_n_rst}));

  // Microop counter:
  wire [4:0] microop_count /*verilator public*/;
  microop_counter counter(.CLK(CLK), .N_RST(counter_combined_n_rst), .COUNT(microop_count));

  // Opcode mux:
  wire [1:0] unused_opcode_mux_val;
  wire [5:0] opcode_mux_val;
  wire n_opcode_sel;
  buffer_mux2x8 opcode_mux(.A({2'b0, CTRL_DATA}), .B({2'b0, OPWORD_OPCODE}),
    .SEL_A(MISC2_PLANE[0]), .N_SEL_A(n_opcode_sel), .OUT({unused_opcode_mux_val, opcode_mux_val}));

  // Opcode storage:
  // TODO(idea): Can have control logic write into this to do micro-op functions.
  wire [1:0] unused_opcode;
  wire [5:0] opcode /*verilator public*/;
  chip74273 opcode_reg(.D({2'b0, opcode_mux_val}), .N_MR(N_RST), .CP(opcode_in_clk),
    .Q({unused_opcode, opcode}));

  // Microcode:
  wire [31:0] microcode_val;
  microcode microcode(.ADDR({opcode, microop_count}), .OUT(microcode_val),
    .BOOTSTRAP_ADDR(BOOTSTRAP_ADDR), .BOOTSTRAP_DATA(BOOTSTRAP_DATA),
    .N_BOOTED(N_BOOTED), .BOOTSTRAP_N_WE(BOOTSTRAP_N_WE));

  wire [2:0] control_in_plane /*verilator public*/;
  wire [2:0] control_out_plane /*verilator public*/;
  wire control_misc_plane /*verilator public*/;
  wire [12:0] unused_control;
  // Latch on N_CLK - control signals change on falling clock, system stabilises, then read in
  // on rising clock.
  register32 microcode_latch(.CLK(N_CLK), .IN(microcode_val), .N_OE(0),
    .OUT({unused_control, MISC2_PLANE, control_misc_plane, control_in_plane,
          control_out_plane, REG_SEL, CTRL_DATA}));

  // In plane decoder - enable on CLK to do pulse.
  wire unused_in_none;
  wire reg_in_clk;
  wire mmu_in_clk;
  wire opcode_in_clk;
  wire unused_in_plane;
  chip74238 in_plane_decoder(.A(control_in_plane), .N_E1(0), .N_E2(0), .E3(CLK),
    .Y({unused_in_plane, opcode_in_clk, OPWORD_IN_CLK, mmu_in_clk, TMP1_IN_CLK, TMP0_IN_CLK,
        reg_in_clk, unused_in_none}));

  // Out plane decoder:
  wire unused_out_none;
  chip74138 out_plane_decoder(.A(control_out_plane), .N_E1(0), .N_E2(0), .E3(1),
    .N_Y({TIMER_N_OUT, SHIFTER_N_OUT, MLU_N_OUT, MMU_N_OUT, TMP1_N_OUT,
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
  integer f_past_n_clk;
  initial f_past_n_clk = 0;
  always_ff @(posedge N_CLK or negedge N_RST) begin
    if (!N_RST) f_past_n_clk <= 0;
    else f_past_n_clk <= f_past_n_clk == 2 ? 2:(f_past_n_clk+1);
  end

  always_ff @($global_clock) begin
    // Force CLK or RST to change every time, so induction passes.
    assume (CLK != $past(CLK) || N_RST != $past(N_RST));

    // Only do these checks after coming out of a reset and having the first falling edge to set-up
    // state.
    if ($past(f_past_n_clk) == 2 && f_past_n_clk == 2 && N_RST) begin
      assert ($past(REG_SEL) != 2'b11);  // Not a valid register selector option.
      // Don't try to do a left-arithmetic shift, it doesn't make sense.
      if ($past(!SHIFTER_N_OUT)) assert ($past(MISC2_PLANE[1:0]) != 2'b11);

      // Don't try to write and read to the same thing:
      assert ($past(REG_N_IN_CLK) || $past(REG_N_OUT));
      assert ($past(!TMP0_IN_CLK) || $past(TMP0_N_OUT));
      assert ($past(!TMP1_IN_CLK) || $past(TMP1_N_OUT));
      assert ($past(MMU_N_IN_CLK) || $past(MMU_N_OUT));
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
