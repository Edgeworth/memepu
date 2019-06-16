// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmmu.h for the primary calling header

#ifndef _Vmmu_sram__Da_W20_H_
#define _Vmmu_sram__Da_W20_H_

#include "verilated.h"
#include "Vmmu__Dpi.h"

class Vmmu__Syms;

//----------

VL_MODULE(Vmmu_sram__Da_W20) {
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
    Vmmu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmmu_sram__Da_W20);  ///< Copying not allowed
  public:
    Vmmu_sram__Da_W20(const char* name="TOP");
    ~Vmmu_sram__Da_W20();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vmmu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__mmu__ram__1(Vmmu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
