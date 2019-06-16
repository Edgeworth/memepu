// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip7486__Syms_H_
#define _Vchip7486__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip7486.h"

// SYMS CLASS
class Vchip7486__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip7486*                     TOPp;
    
    // CREATORS
    Vchip7486__Syms(Vchip7486* topp, const char* namep);
    ~Vchip7486__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
