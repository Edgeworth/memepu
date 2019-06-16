// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsram.h for the primary calling header

#include "Vsram_sram.h"
#include "Vsram__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsram_sram) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vsram_sram::__Vconfigure(Vsram__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsram_sram::~Vsram_sram() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vsram_sram::_sequent__TOP__sram__1(Vsram__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vsram_sram::_sequent__TOP__sram__1\n"); );
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__mem__v0,1,0);
    VL_SIG8(__Vdlyvval__mem__v0,7,0);
    // Body
    // ALWAYS at sram.v:16
    __Vdlyvval__mem__v0 = vlTOPp->IN_DATA;
    __Vdlyvdim0__mem__v0 = vlTOPp->ADDR;
    // ALWAYSPOST at sram.v:16
    vlSymsp->TOP__sram.mem[__Vdlyvdim0__mem__v0] = __Vdlyvval__mem__v0;
}

void Vsram_sram::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vsram_sram::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(2);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    IN_DATA = VL_RAND_RESET_I(8);
    N_RST = VL_RAND_RESET_I(1);
    OUT_DATA = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    OUT_DATA__out = VL_RAND_RESET_I(8);
    OUT_DATA__en = VL_RAND_RESET_I(8);
}
