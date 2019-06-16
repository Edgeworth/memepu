// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vbuffer32__Syms_H_
#define _Vbuffer32__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vbuffer32.h"

// SYMS CLASS
class Vbuffer32__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vbuffer32*                     TOPp;
    
    // CREATORS
    Vbuffer32__Syms(Vbuffer32* topp, const char* namep);
    ~Vbuffer32__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
