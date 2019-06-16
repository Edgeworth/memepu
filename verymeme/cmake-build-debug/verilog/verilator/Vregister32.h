// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vregister32_H_
#define _Vregister32_H_

#include "verilated.h"

class Vregister32__Syms;

//----------

VL_MODULE(Vregister32) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_OE,0,0);
    VL_IN(IN,31,0);
    VL_OUT(OUT,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(register32__DOT__low16__DOT__low8,7,0);
    VL_SIG8(register32__DOT__low16__DOT__high8,7,0);
    VL_SIG8(register32__DOT__high16__DOT__low8,7,0);
    VL_SIG8(register32__DOT__high16__DOT__high8,7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__CLK,0,0);
    VL_SIG(register32__DOT__OUT__out__out4,31,0);
    VL_SIG(register32__DOT__OUT__out__out5,31,0);
    VL_SIG(register32__DOT__OUT__out__out6,31,0);
    VL_SIG(register32__DOT__OUT__out__out7,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vregister32__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister32);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vregister32(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vregister32();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vregister32__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vregister32__Syms* symsp, bool first);
  private:
    static QData _change_request(Vregister32__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vregister32__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vregister32__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vregister32__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vregister32__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vregister32__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vregister32__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
