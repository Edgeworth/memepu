// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vshifter__Syms_H_
#define _Vshifter__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vshifter.h"

// SYMS CLASS
class Vshifter__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vshifter*                      TOPp;
    
    // CREATORS
    Vshifter__Syms(Vshifter* topp, const char* namep);
    ~Vshifter__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
