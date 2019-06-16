// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmmu_H_
#define _Vmmu_H_

#include "verilated.h"
#include "Vmmu__Dpi.h"

class Vmmu__Syms;
class Vmmu_mmu;

//----------

VL_MODULE(Vmmu) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vmmu_mmu*          	mmu;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(N_WE,0,0);
    VL_IN8(N_OE,0,0);
    VL_IN8(N_RST,0,0);
    VL_IN(ADDR,31,0);
    VL_IN(IN,31,0);
    VL_OUT(OUT,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__N_WE,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmmu__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmmu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmmu(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmmu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmmu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmmu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmmu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmmu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmmu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmmu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__1(Vmmu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
