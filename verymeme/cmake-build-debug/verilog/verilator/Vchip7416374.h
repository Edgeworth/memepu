// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vchip7416374_H_
#define _Vchip7416374_H_

#include "verilated.h"

class Vchip7416374__Syms;

//----------

VL_MODULE(Vchip7416374) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK1,0,0);
    VL_IN8(CLK2,0,0);
    VL_IN8(D1,7,0);
    VL_IN8(D2,7,0);
    VL_IN8(N_OE1,0,0);
    VL_IN8(N_OE2,0,0);
    VL_OUT8(Q1,7,0);
    VL_OUT8(Q2,7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(chip7416374__DOT__low8,7,0);
    VL_SIG8(chip7416374__DOT__high8,7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__CLK1,0,0);
    VL_SIG8(__Vclklast__TOP__CLK2,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vchip7416374__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vchip7416374);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vchip7416374(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vchip7416374();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vchip7416374__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vchip7416374__Syms* symsp, bool first);
  private:
    static QData _change_request(Vchip7416374__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vchip7416374__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vchip7416374__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vchip7416374__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vchip7416374__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vchip7416374__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vchip7416374__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
