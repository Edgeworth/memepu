// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmmu.h for the primary calling header

#ifndef _Vmmu_mmu_H_
#define _Vmmu_mmu_H_

#include "verilated.h"
#include "Vmmu__Dpi.h"

class Vmmu__Syms;
class Vmmu_sram__Da_W20;

//----------

VL_MODULE(Vmmu_mmu) {
  public:
    // CELLS
    Vmmu_sram__Da_W20* 	ram;
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(N_WE,0,0);
    VL_IN8(N_OE,0,0);
    VL_IN8(N_RST,0,0);
    VL_IN(ADDR,31,0);
    VL_IN(IN,31,0);
    VL_IN(OUT,31,0);
    VL_OUT(OUT__out,31,0);
    VL_OUT(OUT__en,31,0);
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vmmu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmmu_mmu);  ///< Copying not allowed
  public:
    Vmmu_mmu(const char* name="TOP");
    ~Vmmu_mmu();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vmmu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
