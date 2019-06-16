// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsram.h for the primary calling header

#ifndef _Vsram_sram_H_
#define _Vsram_sram_H_

#include "verilated.h"
#include "Vsram__Dpi.h"

class Vsram__Syms;

//----------

VL_MODULE(Vsram_sram) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(N_WE,0,0);
    VL_IN8(ADDR,1,0);
    VL_IN8(N_OE,0,0);
    VL_IN8(IN_DATA,7,0);
    VL_IN8(N_RST,0,0);
    VL_IN8(OUT_DATA,7,0);
    VL_OUT8(OUT_DATA__out,7,0);
    VL_OUT8(OUT_DATA__en,7,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG8(mem[4],7,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vsram__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsram_sram);  ///< Copying not allowed
  public:
    Vsram_sram(const char* name="TOP");
    ~Vsram_sram();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vsram__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__sram__1(Vsram__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
