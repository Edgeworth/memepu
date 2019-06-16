// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkpu.h for the primary calling header

#ifndef _Vkpu_sram__Da_W20_H_
#define _Vkpu_sram__Da_W20_H_

#include "verilated.h"
#include "Vkpu__Dpi.h"

class Vkpu__Syms;

//----------

VL_MODULE(Vkpu_sram__Da_W20) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__N_WE,0,0);
    VL_IN8(__PVT__N_OE,0,0);
    VL_IN8(__PVT__N_RST,0,0);
    VL_IN16(__PVT__ADDR,9,0);
    VL_IN(__PVT__IN_DATA,31,0);
    VL_IN(__PVT__OUT_DATA,31,0);
    VL_OUT(OUT_DATA__out,31,0);
    VL_OUT(OUT_DATA__en,31,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG(mem[1024],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vkpu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkpu_sram__Da_W20);  ///< Copying not allowed
  public:
    Vkpu_sram__Da_W20(const char* name="TOP");
    ~Vkpu_sram__Da_W20();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vkpu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__kpu__mmu__ram__1(Vkpu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
