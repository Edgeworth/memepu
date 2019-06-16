// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vmmu__Syms_H_
#define _Vmmu__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmmu.h"
#include "Vmmu_mmu.h"
#include "Vmmu_sram__Da_W20.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vmmu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmmu*                          TOPp;
    Vmmu_mmu                       TOP__mmu;
    Vmmu_sram__Da_W20              TOP__mmu__ram;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_mmu__ram;
    
    // CREATORS
    Vmmu__Syms(Vmmu* topp, const char* namep);
    ~Vmmu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
