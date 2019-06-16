// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkpu.h for the primary calling header

#ifndef _Vkpu_mmu_H_
#define _Vkpu_mmu_H_

#include "verilated.h"
#include "Vkpu__Dpi.h"

class Vkpu__Syms;
class Vkpu_sram__Da_W20;

//----------

VL_MODULE(Vkpu_mmu) {
  public:
    // CELLS
    Vkpu_sram__Da_W20* 	ram;
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__N_WE,0,0);
    VL_IN8(__PVT__N_OE,0,0);
    VL_IN8(__PVT__N_RST,0,0);
    VL_IN(__PVT__ADDR,31,0);
    VL_IN(__PVT__IN,31,0);
    VL_IN(__PVT__OUT,31,0);
    VL_OUT(OUT__out,31,0);
    VL_OUT(OUT__en,31,0);
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vkpu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkpu_mmu);  ///< Copying not allowed
  public:
    Vkpu_mmu(const char* name="TOP");
    ~Vkpu_mmu();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vkpu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _settle__TOP__kpu__mmu__1(Vkpu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
