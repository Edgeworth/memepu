// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister_file.h for the primary calling header

#ifndef _Vregister_file_register_file_H_
#define _Vregister_file_register_file_H_

#include "verilated.h"
#include "Vregister_file__Dpi.h"

class Vregister_file__Syms;
class Vregister_file_sram__D5_W20;

//----------

VL_MODULE(Vregister_file_register_file) {
  public:
    // CELLS
    Vregister_file_sram__D5_W20*	registers;
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(REG_SEL,1,0);
    VL_IN8(REG_SRC0,4,0);
    VL_IN8(REG_SRC1,4,0);
    VL_IN8(REG_SRC2,4,0);
    VL_IN8(N_WE,0,0);
    VL_IN8(N_OE,0,0);
    VL_IN8(N_RST,0,0);
    VL_IN(IN_DATA,31,0);
    VL_IN(OUT_DATA,31,0);
    VL_OUT(OUT_DATA__out,31,0);
    VL_OUT(OUT_DATA__en,31,0);
    
    // LOCAL SIGNALS
    
    // LOCAL VARIABLES
    // Begin mtask footprint  all: 
    VL_SIG8(__Vcellout__reg_sel_mux__OUT,7,0);
    
    // INTERNAL VARIABLES
  private:
    Vregister_file__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister_file_register_file);  ///< Copying not allowed
  public:
    Vregister_file_register_file(const char* name="TOP");
    ~Vregister_file_register_file();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vregister_file__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _settle__TOP__register_file__1(Vregister_file__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
