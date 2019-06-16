// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip7432__Syms_H_
#define _Vchip7432__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip7432.h"

// SYMS CLASS
class Vchip7432__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip7432*                     TOPp;
    
    // CREATORS
    Vchip7432__Syms(Vchip7432* topp, const char* namep);
    ~Vchip7432__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
