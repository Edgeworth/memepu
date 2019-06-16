// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip7416374__Syms_H_
#define _Vchip7416374__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip7416374.h"

// SYMS CLASS
class Vchip7416374__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip7416374*                  TOPp;
    
    // CREATORS
    Vchip7416374__Syms(Vchip7416374* topp, const char* namep);
    ~Vchip7416374__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
