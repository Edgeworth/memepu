// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vtimer__Syms_H_
#define _Vtimer__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vtimer.h"

// SYMS CLASS
class Vtimer__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtimer*                        TOPp;
    
    // CREATORS
    Vtimer__Syms(Vtimer* topp, const char* namep);
    ~Vtimer__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
