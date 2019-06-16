// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmicroop_counter_H_
#define _Vmicroop_counter_H_

#include "verilated.h"

class Vmicroop_counter__Syms;

//----------

VL_MODULE(Vmicroop_counter) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_RST,0,0);
    VL_OUT8(COUNT,4,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(microop_counter__DOT__counter__DOT__count,7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__CLK,0,0);
    VL_SIG8(__Vclklast__TOP__N_RST,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmicroop_counter__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmicroop_counter);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmicroop_counter(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmicroop_counter();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmicroop_counter__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmicroop_counter__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmicroop_counter__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmicroop_counter__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmicroop_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmicroop_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vmicroop_counter__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vmicroop_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
