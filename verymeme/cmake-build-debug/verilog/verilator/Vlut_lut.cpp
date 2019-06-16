// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlut.h for the primary calling header

#include "Vlut_lut.h"
#include "Vlut__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vlut_lut) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vlut_lut::__Vconfigure(Vlut__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vlut_lut::~Vlut_lut() {
}

//--------------------
// Internal Methods

void Vlut_lut::_initial__TOP__lut__1(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vlut_lut::_initial__TOP__lut__1\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIGW(__Vtemp1,95,0,3);
    // Body
    // INITIAL at lut.v:20
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x726d616cU;
    __Vtemp1[2U] = 0x666fU;
    VL_READMEM_W(true,8,4, 0,3, __Vtemp1, vlSymsp->TOP__lut.mem
		 ,0,~0);
}

VL_INLINE_OPT void Vlut_lut::_sequent__TOP__lut__2(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vlut_lut::_sequent__TOP__lut__2\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__mem__v0,1,0);
    VL_SIG8(__Vdlyvval__mem__v0,7,0);
    // Body
    // ALWAYS at lut.v:16
    __Vdlyvval__mem__v0 = vlTOPp->IN_DATA;
    __Vdlyvdim0__mem__v0 = vlTOPp->ADDR;
    // ALWAYSPOST at lut.v:16
    vlSymsp->TOP__lut.mem[__Vdlyvdim0__mem__v0] = __Vdlyvval__mem__v0;
}

void Vlut_lut::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vlut_lut::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(2);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    IN_DATA = VL_RAND_RESET_I(8);
    OUT_DATA = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
    OUT_DATA__out = VL_RAND_RESET_I(8);
    OUT_DATA__en = VL_RAND_RESET_I(8);
}
