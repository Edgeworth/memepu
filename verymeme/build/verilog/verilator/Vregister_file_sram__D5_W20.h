// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vregister_file.h for the primary calling header

#ifndef _Vregister_file_sram__D5_W20_H_
#define _Vregister_file_sram__D5_W20_H_

#include "verilated.h"
#include "Vregister_file__Dpi.h"

class Vregister_file__Syms;

//----------

VL_MODULE(Vregister_file_sram__D5_W20) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__N_WE,0,0);
    VL_IN8(__PVT__ADDR,4,0);
    VL_IN8(__PVT__N_OE,0,0);
    VL_IN8(__PVT__N_RST,0,0);
    VL_IN(__PVT__IN_DATA,31,0);
    VL_IN(__PVT__OUT_DATA,31,0);
    VL_OUT(OUT_DATA__out,31,0);
    VL_OUT(OUT_DATA__en,31,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG(mem[32],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vregister_file__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister_file_sram__D5_W20);  ///< Copying not allowed
  public:
    Vregister_file_sram__D5_W20(const char* name="TOP");
    ~Vregister_file_sram__D5_W20();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vregister_file__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__register_file__registers__1(Vregister_file__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
