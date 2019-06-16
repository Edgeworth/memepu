// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vkpu_H_
#define _Vkpu_H_

#include "verilated.h"
#include "Vkpu__Dpi.h"

class Vkpu__Syms;
class Vkpu_kpu;

//----------

VL_MODULE(Vkpu) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vkpu_kpu*          	kpu;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_CLK,0,0);
    VL_IN8(N_RST_ASYNC,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__VinpClk__TOP__kpu__n_rst,0,0);
    VL_SIG8(__VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst,0,0);
    VL_SIG8(__Vclklast__TOP__CLK,0,0);
    VL_SIG8(__Vclklast__TOP__N_RST_ASYNC,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__kpu__n_rst,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst,0,0);
    VL_SIG8(__Vclklast__TOP__N_CLK,0,0);
    VL_SIG8(__Vclklast__TOP__kpu__control____PVT__opcode_in_clk,0,0);
    VL_SIG8(__Vclklast__TOP__kpu____PVT__control_opword_in_clk,0,0);
    VL_SIG8(__Vclklast__TOP__kpu____PVT__control_tmp1_in_clk,0,0);
    VL_SIG8(__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk,0,0);
    VL_SIG8(__Vclklast__TOP__kpu__regs__registers____PVT__N_WE,0,0);
    VL_SIG8(__Vclklast__TOP__kpu__mmu__ram____PVT__N_WE,0,0);
    VL_SIG8(__Vchglast__TOP__kpu__n_rst,0,0);
    VL_SIG8(__Vchglast__TOP__kpu__control__counter_combined_n_rst,0,0);
    VL_SIG16(__Vchglast__TOP__kpu__timer__DOT__rco,8,0);
    VL_SIG(__Vchglast__TOP__kpu__mlu__DOT____Vcellinp__lookahead__ADDR,16,0);
    VL_SIG(__Vchglast__TOP__kpu__shifter__DOT__stage[5],31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vkpu__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vkpu(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vkpu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vkpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vkpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vkpu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vkpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
