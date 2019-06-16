// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlut.h for the primary calling header

#ifndef _Vlut_lut_H_
#define _Vlut_lut_H_

#include "verilated.h"
#include "Vlut__Dpi.h"

class Vlut__Syms;

//----------

VL_MODULE(Vlut_lut) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(N_WE,0,0);
    VL_IN8(ADDR,1,0);
    VL_IN8(N_OE,0,0);
    VL_IN8(IN_DATA,7,0);
    VL_IN8(OUT_DATA,7,0);
    VL_OUT8(OUT_DATA__out,7,0);
    VL_OUT8(OUT_DATA__en,7,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG8(mem[4],7,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vlut__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vlut_lut);  ///< Copying not allowed
  public:
    Vlut_lut(const char* name="TOP");
    ~Vlut_lut();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vlut__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__lut__1(Vlut__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__lut__2(Vlut__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
