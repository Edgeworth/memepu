// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmicrocode_H_
#define _Vmicrocode_H_

#include "verilated.h"

class Vmicrocode__Syms;

//----------

VL_MODULE(Vmicrocode) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(BOOTSTRAP_DATA,7,0);
    VL_IN8(N_BOOTED,0,0);
    VL_IN8(BOOTSTRAP_N_WE,0,0);
    VL_IN16(ADDR,10,0);
    VL_IN16(BOOTSTRAP_ADDR,11,0);
    VL_OUT(OUT,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmicrocode__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmicrocode);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmicrocode(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmicrocode();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmicrocode__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmicrocode__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmicrocode__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vmicrocode__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmicrocode__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmicrocode__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmicrocode__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__1(Vmicrocode__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
