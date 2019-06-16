// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vchip74238_H_
#define _Vchip74238_H_

#include "verilated.h"

class Vchip74238__Syms;

//----------

VL_MODULE(Vchip74238) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(A,2,0);
    VL_IN8(N_E1,0,0);
    VL_IN8(N_E2,0,0);
    VL_IN8(E3,0,0);
    VL_OUT8(Y,7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vchip74238__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vchip74238);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vchip74238(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vchip74238();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vchip74238__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vchip74238__Syms* symsp, bool first);
  private:
    static QData _change_request(Vchip74238__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vchip74238__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vchip74238__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vchip74238__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vchip74238__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
