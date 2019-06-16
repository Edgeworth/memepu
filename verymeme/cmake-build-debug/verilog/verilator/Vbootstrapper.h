// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vbootstrapper_H_
#define _Vbootstrapper_H_

#include "verilated.h"

class Vbootstrapper__Syms;

//----------

VL_MODULE(Vbootstrapper) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_CLK,0,0);
    VL_OUT8(DATA,7,0);
    VL_OUT8(N_BOOTED,0,0);
    VL_OUT8(CONTROL_N_WE,0,0);
    VL_OUT8(MLU_SLICE_N_WE,0,0);
    VL_OUT8(MLU_LOOKAHEAD_N_WE,0,0);
    VL_IN(TIME,31,0);
    VL_OUT(ADDR,16,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vbootstrapper__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbootstrapper);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vbootstrapper(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vbootstrapper();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vbootstrapper__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vbootstrapper__Syms* symsp, bool first);
  private:
    static QData _change_request(Vbootstrapper__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vbootstrapper__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vbootstrapper__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vbootstrapper__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vbootstrapper__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
