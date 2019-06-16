// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vchip74107_H_
#define _Vchip74107_H_

#include "verilated.h"

class Vchip74107__Syms;

//----------

VL_MODULE(Vchip74107) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(J,1,0);
    VL_IN8(K,1,0);
    VL_IN8(N_CP,1,0);
    VL_IN8(N_R,1,0);
    VL_OUT8(Q,1,0);
    VL_OUT8(N_Q,1,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(chip74107__DOT__genblk1__BRA__0__KET____DOT__data,0,0);
    VL_SIG8(chip74107__DOT__genblk1__BRA__1__KET____DOT__data,0,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1,0,0);
    VL_SIG8(chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2,0,0);
    VL_SIG8(chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1,0,0);
    VL_SIG8(chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2,0,0);
    VL_SIG8(__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1,0,0);
    VL_SIG8(__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2,0,0);
    VL_SIG8(__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1,0,0);
    VL_SIG8(__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2,0,0);
    static VL_ST_SIG8(__Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[128],0,0);
    static VL_ST_SIG8(__Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[128],0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vchip74107__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vchip74107);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vchip74107(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vchip74107();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vchip74107__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vchip74107__Syms* symsp, bool first);
  private:
    static QData _change_request(Vchip74107__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vchip74107__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vchip74107__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vchip74107__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vchip74107__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vchip74107__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vchip74107__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vchip74107__Syms* __restrict vlSymsp);
    static void _settle__TOP__6(Vchip74107__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
