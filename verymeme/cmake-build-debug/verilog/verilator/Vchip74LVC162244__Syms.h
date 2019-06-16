// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vchip74LVC162244__Syms_H_
#define _Vchip74LVC162244__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vchip74LVC162244.h"

// SYMS CLASS
class Vchip74LVC162244__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vchip74LVC162244*              TOPp;
    
    // CREATORS
    Vchip74LVC162244__Syms(Vchip74LVC162244* topp, const char* namep);
    ~Vchip74LVC162244__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
