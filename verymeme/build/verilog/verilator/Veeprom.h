// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Veeprom_H_
#define _Veeprom_H_

#include "verilated.h"

class Veeprom__Syms;

//----------

VL_MODULE(Veeprom) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(ADDR,1,0);
    VL_IN8(N_OE,0,0);
    VL_OUT8(OUT_DATA,7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(eeprom__DOT__mem[4],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Veeprom__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Veeprom);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Veeprom(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Veeprom();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Veeprom__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Veeprom__Syms* symsp, bool first);
  private:
    static QData _change_request(Veeprom__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Veeprom__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Veeprom__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Veeprom__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Veeprom__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Veeprom__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
