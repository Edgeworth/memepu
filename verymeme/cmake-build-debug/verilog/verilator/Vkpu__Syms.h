// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vkpu__Syms_H_
#define _Vkpu__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vkpu.h"
#include "Vkpu_kpu.h"
#include "Vkpu_mmu.h"
#include "Vkpu_register_file.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_sram__D5_W20.h"
#include "Vkpu_sram__Da_W20.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vkpu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vkpu*                          TOPp;
    Vkpu_kpu                       TOP__kpu;
    Vkpu_control_logic             TOP__kpu__control;
    Vkpu_mmu                       TOP__kpu__mmu;
    Vkpu_sram__Da_W20              TOP__kpu__mmu__ram;
    Vkpu_register_file             TOP__kpu__regs;
    Vkpu_sram__D5_W20              TOP__kpu__regs__registers;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_kpu;
    VerilatedScope __Vscope_kpu__control;
    VerilatedScope __Vscope_kpu__mmu__ram;
    VerilatedScope __Vscope_kpu__regs__registers;
    
    // CREATORS
    Vkpu__Syms(Vkpu* topp, const char* namep);
    ~Vkpu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
