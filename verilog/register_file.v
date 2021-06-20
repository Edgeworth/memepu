// Copyright 2019 E.
`include "common.v"
module register_file(
  input wire [1:0] REG_SEL,
  input wire [4:0] REG_SRC0,
  input wire [4:0] REG_SRC1,
  input wire [4:0] REG_SRC2,
  input wire [4:0] REG_SRC3,
  input wire [31:0] IN_DATA,
  input wire N_WE,
  input wire N_OE,
  input wire N_RST,
  output logic [31:0] OUT_DATA
);
  wire [4:0] reg_src;
  wire [2:0] unused_reg_src;
  buffer_mux4x8 reg_sel_mux(.A({3'b0, REG_SRC0}), .B({3'b0, REG_SRC1}), .C({3'b0, REG_SRC2}),
    .D({3'b0, REG_SRC3}), .SEL(REG_SEL), .N_RST(N_RST), .OUT({unused_reg_src, reg_src}));

  // TODO: change to specific sram chip.
  // 32 registers.
  sram5x32 registers(.ADDR(reg_src), .N_WE(N_WE), .N_OE(N_OE), .IN_DATA(IN_DATA), .N_RST(N_RST),
    .OUT_DATA(OUT_DATA));

  `ifdef FORMAL
  always_comb begin
    if (N_RST) begin
      `CONTRACT(N_WE || N_OE);  // Not write enable and output enable at the same time.
    end
    if (N_OE) begin
      case (REG_SEL)
        2'b00: begin
          assert (reg_src == REG_SRC0);
        end
        2'b01: begin
          assert (reg_src == REG_SRC1);
        end
        2'b10: begin
          assert (reg_src == REG_SRC2);
        end
        2'b11: begin
          assert (reg_src == REG_SRC3);
        end
      endcase
    end
  end
  `endif
endmodule
