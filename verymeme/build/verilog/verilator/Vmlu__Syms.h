// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vmlu__Syms_H_
#define _Vmlu__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmlu.h"

// SYMS CLASS
class Vmlu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmlu*                          TOPp;
    
    // CREATORS
    Vmlu__Syms(Vmlu* topp, const char* namep);
    ~Vmlu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
