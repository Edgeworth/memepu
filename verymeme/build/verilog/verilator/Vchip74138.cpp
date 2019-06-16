// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74138.h for the primary calling header

#include "Vchip74138.h"
#include "Vchip74138__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip74138) {
    Vchip74138__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74138__Syms(this, name());
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74138::__Vconfigure(Vchip74138__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74138::~Vchip74138() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74138::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74138::eval\n"); );
    Vchip74138__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74138::_eval_initial_loop(Vchip74138__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip74138::_combo__TOP__1(Vchip74138__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_combo__TOP__1\n"); );
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->N_Y = (0xffU & ((((~ (IData)(vlTOPp->N_E1)) 
			      & (~ (IData)(vlTOPp->N_E2))) 
			     & (IData)(vlTOPp->E3))
			     ? (~ ((IData)(1U) << (IData)(vlTOPp->A)))
			     : 0xffU));
}

void Vchip74138::_eval(Vchip74138__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_eval\n"); );
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vchip74138::_eval_initial(Vchip74138__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_eval_initial\n"); );
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74138::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::final\n"); );
    // Variables
    Vchip74138__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74138::_eval_settle(Vchip74138__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_eval_settle\n"); );
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vchip74138::_change_request(Vchip74138__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_change_request\n"); );
    Vchip74138* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74138::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((A & 0xf8U))) {
	Verilated::overWidthError("A");}
    if (VL_UNLIKELY((N_E1 & 0xfeU))) {
	Verilated::overWidthError("N_E1");}
    if (VL_UNLIKELY((N_E2 & 0xfeU))) {
	Verilated::overWidthError("N_E2");}
    if (VL_UNLIKELY((E3 & 0xfeU))) {
	Verilated::overWidthError("E3");}
}
#endif // VL_DEBUG

void Vchip74138::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74138::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(3);
    N_E1 = VL_RAND_RESET_I(1);
    N_E2 = VL_RAND_RESET_I(1);
    E3 = VL_RAND_RESET_I(1);
    N_Y = VL_RAND_RESET_I(8);
}
