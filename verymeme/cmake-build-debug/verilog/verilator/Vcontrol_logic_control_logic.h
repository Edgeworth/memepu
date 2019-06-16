// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontrol_logic.h for the primary calling header

#ifndef _Vcontrol_logic_control_logic_H_
#define _Vcontrol_logic_control_logic_H_

#include "verilated.h"
#include "Vcontrol_logic__Dpi.h"

class Vcontrol_logic__Syms;

//----------

VL_MODULE(Vcontrol_logic_control_logic) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_CLK,0,0);
    VL_IN8(N_RST,0,0);
    VL_IN8(BUS,7,0);
    VL_IN8(OPWORD,5,0);
    VL_IN8(CTRL_DATA,5,0);
    VL_IN8(REG_SEL,1,0);
    VL_IN8(MLU_PLANE,3,0);
    VL_IN8(SHIFTER_PLANE,1,0);
    VL_OUT8(REG_N_IN_CLK,0,0);
    VL_OUT8(TMP0_IN_CLK,0,0);
    VL_OUT8(TMP1_IN_CLK,0,0);
    VL_OUT8(MMU_N_IN_CLK,0,0);
    VL_OUT8(OPWORD_IN_CLK,0,0);
    VL_OUT8(REG_N_OUT,0,0);
    VL_OUT8(TMP0_N_OUT,0,0);
    VL_OUT8(TMP1_N_OUT,0,0);
    VL_OUT8(MMU_N_OUT,0,0);
    VL_OUT8(MLU_N_OUT,0,0);
    VL_OUT8(SHIFTER_N_OUT,0,0);
    VL_OUT8(TIMER_N_OUT,0,0);
    VL_OUT8(CTRL_DATA_N_OUT,0,0);
    VL_IN8(BOOTSTRAP_DATA,7,0);
    VL_IN8(N_BOOTED,0,0);
    VL_IN8(BOOTSTRAP_N_WE,0,0);
    VL_OUT8(CTRL_DATA__out,5,0);
    VL_OUT8(CTRL_DATA__en,5,0);
    VL_OUT8(REG_SEL__out,1,0);
    VL_OUT8(REG_SEL__en,1,0);
    VL_OUT8(MLU_PLANE__out,3,0);
    VL_OUT8(MLU_PLANE__en,3,0);
    VL_OUT8(SHIFTER_PLANE__out,1,0);
    VL_OUT8(SHIFTER_PLANE__en,1,0);
    VL_IN16(BOOTSTRAP_ADDR,11,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG8(__PVT__counter_combined_n_rst,0,0);
    VL_SIG8(__PVT__opcode_in_clk,0,0);
    VL_SIG8(microop_count,4,0);
    VL_SIG8(opcode,5,0);
    VL_SIG8(control_in_plane,2,0);
    VL_SIG8(control_out_plane,3,0);
    VL_SIG8(control_misc_plane,0,0);
    VL_SIG8(control_opcode_sel,0,0);
    VL_SIG8(__PVT__counter__DOT__counter__DOT__count,7,0);
    VL_SIG8(__PVT__opcode_reg__DOT__value,7,0);
    VL_SIG8(__PVT__microcode_latch__DOT__low16__DOT__low8,7,0);
    VL_SIG8(__PVT__microcode_latch__DOT__low16__DOT__high8,7,0);
    VL_SIG8(__PVT__microcode_latch__DOT__high16__DOT__low8,7,0);
    VL_SIG8(__PVT__microcode_latch__DOT__high16__DOT__high8,7,0);
    VL_SIG(__PVT__microcode_val,31,0);
    
    // LOCAL VARIABLES
    // Begin mtask footprint  all: 
    VL_SIG8(__Vcellinp__inverter__A,5,0);
    VL_SIG8(__Vcellout__in_plane_decoder__Y,7,0);
    VL_SIG16(__Vcellinp__microcode__ADDR,10,0);
    VL_SIG(__Vcelloutt__microcode_latch__OUT__out,31,0);
    VL_SIG(microcode_latch__DOT__OUT__out__out4,31,0);
    VL_SIG(microcode_latch__DOT__OUT__out__out5,31,0);
    VL_SIG(microcode_latch__DOT__OUT__out__out6,31,0);
    VL_SIG(microcode_latch__DOT__OUT__out__out7,31,0);
    
    // INTERNAL VARIABLES
  private:
    Vcontrol_logic__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcontrol_logic_control_logic);  ///< Copying not allowed
  public:
    Vcontrol_logic_control_logic(const char* name="TOP");
    ~Vcontrol_logic_control_logic();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vcontrol_logic__Syms* symsp, bool first);
    static void _combo__TOP__control_logic__5(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _combo__TOP__control_logic__9(Vcontrol_logic__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__control_logic__1(Vcontrol_logic__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__control_logic__8(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _sequent__TOP__control_logic__2(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _sequent__TOP__control_logic__3(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _sequent__TOP__control_logic__6(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _sequent__TOP__control_logic__7(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _settle__TOP__control_logic__4(Vcontrol_logic__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
