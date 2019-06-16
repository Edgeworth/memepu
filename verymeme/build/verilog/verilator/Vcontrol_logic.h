// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vcontrol_logic_H_
#define _Vcontrol_logic_H_

#include "verilated.h"
#include "Vcontrol_logic__Dpi.h"

class Vcontrol_logic__Syms;
class Vcontrol_logic_control_logic;

//----------

VL_MODULE(Vcontrol_logic) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vcontrol_logic_control_logic*	control_logic;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_CLK,0,0);
    VL_IN8(N_RST,0,0);
    VL_IN8(BUS,7,0);
    VL_IN8(OPWORD,5,0);
    VL_OUT8(CTRL_DATA,5,0);
    VL_OUT8(REG_SEL,1,0);
    VL_OUT8(MLU_PLANE,3,0);
    VL_OUT8(SHIFTER_PLANE,1,0);
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
    VL_IN16(BOOTSTRAP_ADDR,11,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__VinpClk__TOP__control_logic____PVT__counter_combined_n_rst,0,0);
    VL_SIG8(__Vclklast__TOP__CLK,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__control_logic____PVT__counter_combined_n_rst,0,0);
    VL_SIG8(__Vclklast__TOP__N_CLK,0,0);
    VL_SIG8(__Vclklast__TOP__N_RST,0,0);
    VL_SIG8(__Vclklast__TOP__control_logic____PVT__opcode_in_clk,0,0);
    VL_SIG8(__Vchglast__TOP__control_logic__counter_combined_n_rst,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcontrol_logic__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcontrol_logic);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcontrol_logic(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcontrol_logic();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcontrol_logic__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcontrol_logic__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcontrol_logic__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(Vcontrol_logic__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcontrol_logic__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vcontrol_logic__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcontrol_logic__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vcontrol_logic__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vcontrol_logic__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
