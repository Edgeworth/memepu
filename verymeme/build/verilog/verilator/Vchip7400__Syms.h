// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip7400__Syms_H_
#define _Vchip7400__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip7400.h"

// SYMS CLASS
class Vchip7400__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip7400*                     TOPp;
    
    // CREATORS
    Vchip7400__Syms(Vchip7400* topp, const char* namep);
    ~Vchip7400__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
