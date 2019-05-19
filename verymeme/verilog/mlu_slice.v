`include "common.v"
module mlu_slice(
  input wire [3:0] A,
  input wire [3:0] B,
  input wire [2:0] OP,
  input wire C_IN,
  output logic [7:0] OUT,
  // Bootstrapping signals:
  input wire [11:0] BOOTSTRAP_ADDR,
  input wire [7:0] BOOTSTRAP_DATA,
  input wire N_BOOTED,
  input wire BOOTSTRAP_N_WE
);

  `ifdef SCHEMATIC
  wire [7:0] unused = 0;
  // TODO(bootstrapping): Use BOOTSTRAP_ADDR.
  sram#(.DEPTH(12), .WIDTH(8), .INITIAL("mlu_slice.hex")) slice_mem(
    .ADDR({OP, C_IN, B, A}), .N_WE(BOOTSTRAP_N_WE), .N_OE(N_BOOTED),
    .IN_DATA(BOOTSTRAP_DATA), .OUT_DATA(OUT));
  `else
  logic [3:0] out_low;
  logic prop;
  logic gen;

  always_comb begin
    prop = 0;
    gen = 0;
    case (OP)
      common::MLU_ADD: begin
        out_low = A+B+{3'b0, C_IN};
        prop = (A+B == 4'hF);
        gen = ({1'b0, A}+{1'b0, B} > 5'hF);
      end
      common::MLU_SUB: begin
        out_low = A+(~B)+{3'b0, C_IN};
        prop = (A+(~B) == 4'hF);
        gen = ({1'b0, A}+{1'b0, ~B} > 5'hF);
      end
      common::MLU_AND: out_low = A & B;
      common::MLU_OR: out_low = A | B;
      common::MLU_XOR: out_low = A ^ B;
      common::MLU_NOT: out_low = ~A;
      common::MLU_NOP0: out_low = 0;
      common::MLU_NOP1: out_low = 0;
    endcase
    OUT = {1'b0, out_low == 0, gen, prop, out_low};
  end
  `endif

  `ifndef BOOTSTRAP
  // Mark bootstrap signals as okay to not be used if not using bootstrapping.
  wire _unused_ok = &{BOOTSTRAP_ADDR, BOOTSTRAP_DATA, N_BOOTED, BOOTSTRAP_N_WE};
  `endif

  `ifdef FORMAL
  logic [3:0] f_sum = A+B+{3'b0, C_IN};
  wire [3:0] f_out = OUT[3:0];
  wire f_prop = OUT[4];
  wire f_gen = OUT[5];
  wire f_zero = OUT[6];

  always_comb begin
    case (OP)
      common::MLU_ADD: begin
        assert (f_out == f_sum);
        assert (f_prop == (A+B == 4'hF));
        assert (f_gen == ({1'b0, A}+{1'b0, B} > 5'hF));
      end
      common::MLU_SUB: begin
        // C_IN must be 1 for the first slice. After that, it depends.
        assert (f_out == A+(~B)+{3'b0, C_IN});
        assert (f_prop == (A+(~B) == 4'hF));
        assert (f_gen == ({1'b0, A}+{1'b0, ~B} > 5'hF));
      end
      // TODO: yosys bug means need begin/end here
      common::MLU_AND: begin assert (f_out == (A & B)); end
      common::MLU_OR: begin assert (f_out == (A | B)); end
      common::MLU_XOR: begin assert (f_out == (A ^ B)); end
      common::MLU_NOT: begin assert (f_out == ~A); end
      common::MLU_NOP0: begin assert (f_out == 0); end
      common::MLU_NOP1: begin assert (f_out == 0); end
      default: begin assert (0); end
    endcase
    assert (f_zero == (f_out == 0));
  end
  `endif
endmodule
