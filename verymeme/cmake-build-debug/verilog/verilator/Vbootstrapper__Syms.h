// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vbootstrapper__Syms_H_
#define _Vbootstrapper__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vbootstrapper.h"

// SYMS CLASS
class Vbootstrapper__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vbootstrapper*                 TOPp;
    
    // CREATORS
    Vbootstrapper__Syms(Vbootstrapper* topp, const char* namep);
    ~Vbootstrapper__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
