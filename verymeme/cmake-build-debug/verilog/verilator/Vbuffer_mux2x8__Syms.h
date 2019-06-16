// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vbuffer_mux2x8__Syms_H_
#define _Vbuffer_mux2x8__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vbuffer_mux2x8.h"

// SYMS CLASS
class Vbuffer_mux2x8__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vbuffer_mux2x8*                TOPp;
    
    // CREATORS
    Vbuffer_mux2x8__Syms(Vbuffer_mux2x8* topp, const char* namep);
    ~Vbuffer_mux2x8__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
