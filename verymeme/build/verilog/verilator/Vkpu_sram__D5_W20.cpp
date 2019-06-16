// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkpu.h for the primary calling header

#include "Vkpu_sram__D5_W20.h"
#include "Vkpu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vkpu_sram__D5_W20) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vkpu_sram__D5_W20::__Vconfigure(Vkpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vkpu_sram__D5_W20::~Vkpu_sram__D5_W20() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vkpu_sram__D5_W20::_sequent__TOP__kpu__regs__registers__1(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vkpu_sram__D5_W20::_sequent__TOP__kpu__regs__registers__1\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__mem__v0,4,0);
    VL_SIG(__Vdlyvval__mem__v0,31,0);
    // Body
    // ALWAYS at sram.v:16
    __Vdlyvval__mem__v0 = vlSymsp->TOP__kpu.bus;
    __Vdlyvdim0__mem__v0 = (0x1fU & (IData)(vlSymsp->TOP__kpu__regs.__Vcellout__reg_sel_mux__OUT));
    // ALWAYSPOST at sram.v:16
    vlSymsp->TOP__kpu__regs__registers.mem[__Vdlyvdim0__mem__v0] 
	= __Vdlyvval__mem__v0;
}

void Vkpu_sram__D5_W20::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vkpu_sram__D5_W20::_ctor_var_reset\n"); );
    // Body
    __PVT__ADDR = VL_RAND_RESET_I(5);
    __PVT__N_WE = VL_RAND_RESET_I(1);
    __PVT__N_OE = VL_RAND_RESET_I(1);
    __PVT__IN_DATA = VL_RAND_RESET_I(32);
    __PVT__N_RST = VL_RAND_RESET_I(1);
    __PVT__OUT_DATA = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    OUT_DATA__out = VL_RAND_RESET_I(32);
    OUT_DATA__en = VL_RAND_RESET_I(32);
}
