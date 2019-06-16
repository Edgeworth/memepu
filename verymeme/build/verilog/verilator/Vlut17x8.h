// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vlut17x8_H_
#define _Vlut17x8_H_

#include "verilated.h"

class Vlut17x8__Syms;

//----------

VL_MODULE(Vlut17x8) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(N_WE,0,0);
    VL_IN8(N_OE,0,0);
    VL_IN8(IN_DATA,7,0);
    VL_OUT8(OUT_DATA,7,0);
    VL_IN(ADDR,16,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(lut17x8__DOT__mem[131072],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__N_WE,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vlut17x8__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vlut17x8);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vlut17x8(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vlut17x8();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vlut17x8__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vlut17x8__Syms* symsp, bool first);
  private:
    static QData _change_request(Vlut17x8__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vlut17x8__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vlut17x8__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vlut17x8__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vlut17x8__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vlut17x8__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vlut17x8__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
