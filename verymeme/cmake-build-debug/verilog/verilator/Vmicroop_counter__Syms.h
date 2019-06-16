// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vmicroop_counter__Syms_H_
#define _Vmicroop_counter__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmicroop_counter.h"

// SYMS CLASS
class Vmicroop_counter__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmicroop_counter*              TOPp;
    
    // CREATORS
    Vmicroop_counter__Syms(Vmicroop_counter* topp, const char* namep);
    ~Vmicroop_counter__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
