// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vchip74LVC162244_H_
#define _Vchip74LVC162244_H_

#include "verilated.h"

class Vchip74LVC162244__Syms;

//----------

VL_MODULE(Vchip74LVC162244) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(N_OE,0,0);
    VL_IN16(IN,15,0);
    VL_OUT16(OUT,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vchip74LVC162244__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vchip74LVC162244);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vchip74LVC162244(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vchip74LVC162244();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vchip74LVC162244__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vchip74LVC162244__Syms* symsp, bool first);
  private:
    static QData _change_request(Vchip74LVC162244__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vchip74LVC162244__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vchip74LVC162244__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vchip74LVC162244__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vchip74LVC162244__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
