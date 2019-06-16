// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vregister_file__Syms_H_
#define _Vregister_file__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vregister_file.h"
#include "Vregister_file_register_file.h"
#include "Vregister_file_sram__D5_W20.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vregister_file__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vregister_file*                TOPp;
    Vregister_file_register_file   TOP__register_file;
    Vregister_file_sram__D5_W20    TOP__register_file__registers;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_register_file__registers;
    
    // CREATORS
    Vregister_file__Syms(Vregister_file* topp, const char* namep);
    ~Vregister_file__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
