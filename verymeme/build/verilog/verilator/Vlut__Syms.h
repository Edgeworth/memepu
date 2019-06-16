// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vlut__Syms_H_
#define _Vlut__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vlut.h"
#include "Vlut_lut.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vlut__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vlut*                          TOPp;
    Vlut_lut                       TOP__lut;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_lut;
    
    // CREATORS
    Vlut__Syms(Vlut* topp, const char* namep);
    ~Vlut__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
