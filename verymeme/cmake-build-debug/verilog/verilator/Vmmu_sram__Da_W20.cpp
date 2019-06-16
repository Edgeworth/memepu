// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmmu.h for the primary calling header

#include "Vmmu_sram__Da_W20.h"
#include "Vmmu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmmu_sram__Da_W20) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vmmu_sram__Da_W20::__Vconfigure(Vmmu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmmu_sram__Da_W20::~Vmmu_sram__Da_W20() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vmmu_sram__Da_W20::_sequent__TOP__mmu__ram__1(Vmmu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vmmu_sram__Da_W20::_sequent__TOP__mmu__ram__1\n"); );
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG16(__Vdlyvdim0__mem__v0,9,0);
    VL_SIG(__Vdlyvval__mem__v0,31,0);
    // Body
    // ALWAYS at sram.v:16
    __Vdlyvval__mem__v0 = vlTOPp->IN;
    __Vdlyvdim0__mem__v0 = (0x3ffU & vlTOPp->ADDR);
    // ALWAYSPOST at sram.v:16
    vlSymsp->TOP__mmu__ram.mem[__Vdlyvdim0__mem__v0] 
	= __Vdlyvval__mem__v0;
}

void Vmmu_sram__Da_W20::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vmmu_sram__Da_W20::_ctor_var_reset\n"); );
    // Body
    __PVT__ADDR = VL_RAND_RESET_I(10);
    __PVT__N_WE = VL_RAND_RESET_I(1);
    __PVT__N_OE = VL_RAND_RESET_I(1);
    __PVT__IN_DATA = VL_RAND_RESET_I(32);
    __PVT__N_RST = VL_RAND_RESET_I(1);
    __PVT__OUT_DATA = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    OUT_DATA__out = VL_RAND_RESET_I(32);
    OUT_DATA__en = VL_RAND_RESET_I(32);
}
