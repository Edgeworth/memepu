// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkpu.h for the primary calling header

#ifndef _Vkpu_register_file_H_
#define _Vkpu_register_file_H_

#include "verilated.h"
#include "Vkpu__Dpi.h"

class Vkpu__Syms;
class Vkpu_sram__D5_W20;

//----------

VL_MODULE(Vkpu_register_file) {
  public:
    // CELLS
    Vkpu_sram__D5_W20* 	registers;
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__REG_SEL,1,0);
    VL_IN8(__PVT__REG_SRC0,4,0);
    VL_IN8(__PVT__REG_SRC1,4,0);
    VL_IN8(__PVT__REG_SRC2,4,0);
    VL_IN8(__PVT__N_WE,0,0);
    VL_IN8(__PVT__N_OE,0,0);
    VL_IN8(__PVT__N_RST,0,0);
    VL_IN(__PVT__IN_DATA,31,0);
    VL_IN(__PVT__OUT_DATA,31,0);
    VL_OUT(OUT_DATA__out,31,0);
    VL_OUT(OUT_DATA__en,31,0);
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    // Begin mtask footprint  all: 
    VL_SIG8(__Vcellout__reg_sel_mux__OUT,7,0);
    
    // INTERNAL VARIABLES
  private:
    Vkpu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkpu_register_file);  ///< Copying not allowed
  public:
    Vkpu_register_file(const char* name="TOP");
    ~Vkpu_register_file();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vkpu__Syms* symsp, bool first);
    static void _combo__TOP__kpu__regs__2(Vkpu__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _multiclk__TOP__kpu__regs__3(Vkpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__kpu__regs__1(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
