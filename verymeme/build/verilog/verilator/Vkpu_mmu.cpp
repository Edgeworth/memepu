// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkpu.h for the primary calling header

#include "Vkpu_mmu.h"
#include "Vkpu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vkpu_mmu) {
    VL_CELL(ram, Vkpu_sram__Da_W20);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vkpu_mmu::__Vconfigure(Vkpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vkpu_mmu::~Vkpu_mmu() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vkpu_mmu::_settle__TOP__kpu__mmu__1(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_mmu::_settle__TOP__kpu__mmu__1\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__mmu__ram.__PVT__N_WE = (1U & 
					       (~ ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A) 
						   >> 1U)));
}

void Vkpu_mmu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_mmu::_ctor_var_reset\n"); );
    // Body
    __PVT__ADDR = VL_RAND_RESET_I(32);
    __PVT__N_WE = VL_RAND_RESET_I(1);
    __PVT__N_OE = VL_RAND_RESET_I(1);
    __PVT__N_RST = VL_RAND_RESET_I(1);
    __PVT__IN = VL_RAND_RESET_I(32);
    __PVT__OUT = VL_RAND_RESET_I(32);
    OUT__out = VL_RAND_RESET_I(32);
    OUT__en = VL_RAND_RESET_I(32);
}
