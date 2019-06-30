`include "common.v"
module mmu(
  input wire [31:0] ADDR,
  input wire N_WE,
  input wire N_OE,
  input wire N_RST,
  input wire [31:0] IN,
  output logic [31:0] OUT
);
  // Decide based on 17th bit
  wire [4:0] unused_inverter;
  wire n_a16;
  chip7404 inverter(.A({5'b0, ADDR[16]}), .Y({unused_inverter, n_a16}));
  chip7432 orer(.A({N_WE, N_WE, N_OE, N_OE}), .B({ADDR[16], n_a16, ADDR[16], n_a16}),
    .Y({ram_n_we, vga_n_we, ram_n_oe, vga_n_oe}));

  wire ram_n_we;
  wire ram_n_oe;
  wire ram_val;
  sram#(.DEPTH(14), .WIDTH(32), .INITIAL("boot.hex")) ram(.ADDR(ADDR[15:2]), .N_WE(ram_n_we),
    .N_OE(ram_n_oe), .IN_DATA(IN), .N_RST(N_RST), .OUT_DATA(ram_val));

  wire vga_n_we;
  wire vga_n_oe;
  wire vga_val;
  vga vga(.ADDR({ADDR[15:2]}), .N_WE(vga_n_we), .N_OE(vga_n_oe), .N_RST(N_RST), .IN(IN), .OUT(vga_val));

  wire _unused_ok = &{ADDR}; // TODO REMOVE.

  `ifdef SCHEMATIC
  assign OUT = ram_val;
  assign OUT = vga_val;
  `else
  assign OUT = ADDR[16] ? vga_val : ram_val;
  `endif


  `ifdef FORMAL
  always_comb begin
    if (N_RST) `CONTRACT(N_WE || N_OE);
    assert(ram_n_we || vga_n_we);  // Only try to use one device at a time.
    assert(ram_n_oe || vga_n_oe);
//    `CONTRACT(ADDR[1:0] == 2'b0);  // No unaligned accesses.
  end
  `endif
endmodule
