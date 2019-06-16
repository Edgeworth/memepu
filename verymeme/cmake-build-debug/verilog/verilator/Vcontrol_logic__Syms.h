// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vcontrol_logic__Syms_H_
#define _Vcontrol_logic__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vcontrol_logic.h"
#include "Vcontrol_logic_control_logic.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vcontrol_logic__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vcontrol_logic*                TOPp;
    Vcontrol_logic_control_logic   TOP__control_logic;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_control_logic;
    
    // CREATORS
    Vcontrol_logic__Syms(Vcontrol_logic* topp, const char* namep);
    ~Vcontrol_logic__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
