// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlut.h for the primary calling header

#include "Vlut.h"
#include "Vlut__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vlut) {
    Vlut__Syms* __restrict vlSymsp = __VlSymsp = new Vlut__Syms(this, name());
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(lut, Vlut_lut);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlut::__Vconfigure(Vlut__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vlut::~Vlut() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vlut::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlut::eval\n"); );
    Vlut__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vlut::_eval_initial_loop(Vlut__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vlut::_settle__TOP__1(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_settle__TOP__1\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT_DATA = ((((IData)(vlTOPp->N_OE) ? 0U
			   : vlSymsp->TOP__lut.mem[vlTOPp->ADDR]) 
			 & ((IData)(vlTOPp->N_OE) ? 0U
			     : 0xffU)) & ((IData)(vlTOPp->N_OE)
					   ? 0U : 0xffU));
}

void Vlut::_eval(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_eval\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->N_WE)) & (IData)(vlTOPp->__Vclklast__TOP__N_WE))) {
	vlSymsp->TOP__lut._sequent__TOP__lut__2(vlSymsp);
    }
    vlTOPp->_settle__TOP__1(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vlut::_eval_initial(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_eval_initial\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__lut._initial__TOP__lut__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vlut::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::final\n"); );
    // Variables
    Vlut__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlut::_eval_settle(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_eval_settle\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vlut::_change_request(Vlut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_change_request\n"); );
    Vlut* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlut::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xfcU))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((N_WE & 0xfeU))) {
	Verilated::overWidthError("N_WE");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
}
#endif // VL_DEBUG

void Vlut::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(2);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    IN_DATA = VL_RAND_RESET_I(8);
    OUT_DATA = VL_RAND_RESET_I(8);
}
