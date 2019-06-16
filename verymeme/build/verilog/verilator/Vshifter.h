// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vshifter_H_
#define _Vshifter_H_

#include "verilated.h"

class Vshifter__Syms;

//----------

VL_MODULE(Vshifter) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(SHFT,4,0);
    VL_IN8(LEFT,0,0);
    VL_IN8(ARITH,0,0);
    VL_IN8(N_RST,0,0);
    VL_IN(IN,31,0);
    VL_OUT(OUT,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG(shifter__DOT__pre_reverse,31,0);
    VL_SIG(shifter__DOT__stage[5],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(shifter__DOT____Vcellinp__notter__A,5,0);
    VL_SIG8(shifter__DOT____Vcellout__ander__Y,3,0);
    VL_SIG(shifter__DOT____Vcellinp__pre_reverse_mux__B,31,0);
    VL_SIG(shifter__DOT____Vcellinp__shift_left_mux0__A,31,0);
    VL_SIG(shifter__DOT____Vcellinp__shift_left_mux1__A,31,0);
    VL_SIG(shifter__DOT____Vcellinp__shift_left_mux2__A,31,0);
    VL_SIG(shifter__DOT____Vcellinp__shift_left_mux3__A,31,0);
    VL_SIG(shifter__DOT____Vcellinp__shift_left_mux4__A,31,0);
    VL_SIG(shifter__DOT____Vcellinp__post_reverse_mux__B,31,0);
    VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3,31,0);
    VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2,31,0);
    VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3,31,0);
    VL_SIG(__Vchglast__TOP__shifter__DOT__stage[5],31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vshifter__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vshifter);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vshifter(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vshifter();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vshifter__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vshifter__Syms* symsp, bool first);
  private:
    static QData _change_request(Vshifter__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vshifter__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vshifter__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vshifter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vshifter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
