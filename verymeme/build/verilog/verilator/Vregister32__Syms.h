// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vregister32__Syms_H_
#define _Vregister32__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vregister32.h"

// SYMS CLASS
class Vregister32__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vregister32*                   TOPp;
    
    // CREATORS
    Vregister32__Syms(Vregister32* topp, const char* namep);
    ~Vregister32__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
