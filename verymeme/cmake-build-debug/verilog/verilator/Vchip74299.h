// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vchip74299_H_
#define _Vchip74299_H_

#include "verilated.h"

class Vchip74299__Syms;

//----------

VL_MODULE(Vchip74299) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(N_MR,0,0);
    VL_IN8(CP,0,0);
    VL_IN8(S,1,0);
    VL_IN8(N_OE,1,0);
    VL_IN8(DSR,0,0);
    VL_IN8(DSL,0,0);
    VL_INOUT8(IO,7,0);
    VL_OUT8(Q0,0,0);
    VL_OUT8(Q7,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(chip74299__DOT__shift_reg,7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__CP,0,0);
    VL_SIG8(__Vclklast__TOP__N_MR,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vchip74299__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vchip74299);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vchip74299(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vchip74299();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vchip74299__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vchip74299__Syms* symsp, bool first);
  private:
    static QData _change_request(Vchip74299__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vchip74299__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vchip74299__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vchip74299__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vchip74299__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vchip74299__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vchip74299__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
