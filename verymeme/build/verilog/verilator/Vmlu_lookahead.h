// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmlu_lookahead_H_
#define _Vmlu_lookahead_H_

#include "verilated.h"

class Vmlu_lookahead__Syms;

//----------

VL_MODULE(Vmlu_lookahead) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_OUT8(CARRYS,7,0);
    VL_IN8(BOOTSTRAP_DATA,7,0);
    VL_IN8(N_BOOTED,0,0);
    VL_IN8(BOOTSTRAP_N_WE,0,0);
    VL_IN(ADDR,16,0);
    VL_IN(BOOTSTRAP_ADDR,16,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(mlu_lookahead__DOT__prev_carry,0,0);
    VL_SIG8(mlu_lookahead__DOT__carry,0,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmlu_lookahead__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmlu_lookahead);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmlu_lookahead(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmlu_lookahead();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmlu_lookahead__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmlu_lookahead__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmlu_lookahead__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vmlu_lookahead__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmlu_lookahead__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmlu_lookahead__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmlu_lookahead__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
