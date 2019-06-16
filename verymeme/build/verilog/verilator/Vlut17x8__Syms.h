// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vlut17x8__Syms_H_
#define _Vlut17x8__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vlut17x8.h"

// SYMS CLASS
class Vlut17x8__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vlut17x8*                      TOPp;
    
    // CREATORS
    Vlut17x8__Syms(Vlut17x8* topp, const char* namep);
    ~Vlut17x8__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
