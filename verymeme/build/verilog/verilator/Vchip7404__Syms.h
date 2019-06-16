// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip7404__Syms_H_
#define _Vchip7404__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip7404.h"

// SYMS CLASS
class Vchip7404__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip7404*                     TOPp;
    
    // CREATORS
    Vchip7404__Syms(Vchip7404* topp, const char* namep);
    ~Vchip7404__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
