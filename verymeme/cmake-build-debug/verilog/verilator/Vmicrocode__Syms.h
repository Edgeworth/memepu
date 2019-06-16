// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vmicrocode__Syms_H_
#define _Vmicrocode__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmicrocode.h"

// SYMS CLASS
class Vmicrocode__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmicrocode*                    TOPp;
    
    // CREATORS
    Vmicrocode__Syms(Vmicrocode* topp, const char* namep);
    ~Vmicrocode__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
