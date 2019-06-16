// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmlu_H_
#define _Vmlu_H_

#include "verilated.h"

class Vmlu__Syms;

//----------

VL_MODULE(Vmlu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(OP,2,0);
    VL_IN8(C_IN,0,0);
    VL_IN8(N_RST,0,0);
    VL_OUT8(Z,0,0);
    VL_OUT8(C,0,0);
    VL_OUT8(N,0,0);
    VL_IN8(BOOTSTRAP_DATA,7,0);
    VL_IN8(N_BOOTED,0,0);
    VL_IN8(BOOTSTRAP_MLU_SLICE_N_WE,0,0);
    VL_IN8(BOOTSTRAP_MLU_LOOKAHEAD_N_WE,0,0);
    VL_IN(A,31,0);
    VL_IN(B,31,0);
    VL_OUT(OUT,31,0);
    VL_IN(BOOTSTRAP_ADDR,16,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(mlu__DOT__slice_p,7,0);
    VL_SIG8(mlu__DOT__slice_g,7,0);
    VL_SIG8(mlu__DOT__slice_z,7,0);
    VL_SIG8(mlu__DOT__z_level0,3,0);
    VL_SIG8(mlu__DOT__lookahead__DOT__prev_carry,0,0);
    VL_SIG8(mlu__DOT__lookahead__DOT__carry,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low,3,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop,0,0);
    VL_SIG8(mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen,0,0);
    VL_SIG16(mlu__DOT__carrys,8,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(mlu__DOT____Vcellout__lookahead__CARRYS,7,0);
    VL_SIG8(mlu__DOT____Vcellout__and_level1__Y,3,0);
    VL_SIG8(mlu__DOT____Vcellinp__and_level1__B,3,0);
    VL_SIG8(mlu__DOT____Vcellinp__and_level1__A,3,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT,7,0);
    VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT,7,0);
    VL_SIG8(__Vchglast__TOP__mlu__DOT____Vcellout__and_level1__Y,3,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR,11,0);
    VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR,11,0);
    VL_SIG(mlu__DOT____Vcellinp__lookahead__ADDR,16,0);
    VL_SIG(__Vchglast__TOP__mlu__DOT____Vcellinp__lookahead__ADDR,16,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmlu__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmlu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmlu(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmlu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmlu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmlu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmlu__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vmlu__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmlu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmlu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmlu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
