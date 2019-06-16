// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vmlu_slice__Syms_H_
#define _Vmlu_slice__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmlu_slice.h"

// SYMS CLASS
class Vmlu_slice__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmlu_slice*                    TOPp;
    
    // CREATORS
    Vmlu_slice__Syms(Vmlu_slice* topp, const char* namep);
    ~Vmlu_slice__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
