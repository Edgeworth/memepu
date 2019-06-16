// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip74154__Syms_H_
#define _Vchip74154__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip74154.h"

// SYMS CLASS
class Vchip74154__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip74154*                    TOPp;
    
    // CREATORS
    Vchip74154__Syms(Vchip74154* topp, const char* namep);
    ~Vchip74154__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
