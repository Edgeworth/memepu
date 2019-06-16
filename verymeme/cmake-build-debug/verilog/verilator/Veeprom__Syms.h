// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Veeprom__Syms_H_
#define _Veeprom__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Veeprom.h"

// SYMS CLASS
class Veeprom__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Veeprom*                       TOPp;
    
    // CREATORS
    Veeprom__Syms(Veeprom* topp, const char* namep);
    ~Veeprom__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
