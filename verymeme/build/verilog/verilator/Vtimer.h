// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtimer_H_
#define _Vtimer_H_

#include "verilated.h"

class Vtimer__Syms;

//----------

VL_MODULE(Vtimer) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_RST,0,0);
    VL_OUT(TIME,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count,3,0);
    VL_SIG8(timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count,3,0);
    VL_SIG16(timer__DOT__rco,8,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO,0,0);
    VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO,0,0);
    VL_SIG8(__Vclklast__TOP__CLK,0,0);
    VL_SIG8(__Vclklast__TOP__N_RST,0,0);
    VL_SIG16(__Vchglast__TOP__timer__DOT__rco,8,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtimer__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtimer);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtimer(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtimer();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtimer__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtimer__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtimer__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vtimer__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtimer__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtimer__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtimer__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtimer__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtimer__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
