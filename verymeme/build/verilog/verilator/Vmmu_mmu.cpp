// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmmu.h for the primary calling header

#include "Vmmu_mmu.h"
#include "Vmmu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmmu_mmu) {
    VL_CELL(ram, Vmmu_sram__Da_W20);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vmmu_mmu::__Vconfigure(Vmmu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmmu_mmu::~Vmmu_mmu() {
}

//--------------------
// Internal Methods

void Vmmu_mmu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vmmu_mmu::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(32);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    IN = VL_RAND_RESET_I(32);
    OUT = VL_RAND_RESET_I(32);
    OUT__out = VL_RAND_RESET_I(32);
    OUT__en = VL_RAND_RESET_I(32);
}
