// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vsram__Syms_H_
#define _Vsram__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vsram.h"
#include "Vsram_sram.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vsram__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vsram*                         TOPp;
    Vsram_sram                     TOP__sram;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_sram;
    
    // CREATORS
    Vsram__Syms(Vsram* topp, const char* namep);
    ~Vsram__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
