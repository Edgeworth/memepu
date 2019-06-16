// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip7416374.h for the primary calling header

#include "Vchip7416374.h"
#include "Vchip7416374__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip7416374) {
    Vchip7416374__Syms* __restrict vlSymsp = __VlSymsp = new Vchip7416374__Syms(this, name());
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip7416374::__Vconfigure(Vchip7416374__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip7416374::~Vchip7416374() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip7416374::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip7416374::eval\n"); );
    Vchip7416374__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip7416374::_eval_initial_loop(Vchip7416374__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip7416374::_sequent__TOP__1(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_sequent__TOP__1\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:19
    vlTOPp->chip7416374__DOT__low8 = vlTOPp->D1;
}

VL_INLINE_OPT void Vchip7416374::_sequent__TOP__2(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_sequent__TOP__2\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlTOPp->chip7416374__DOT__high8 = vlTOPp->D2;
}

VL_INLINE_OPT void Vchip7416374::_settle__TOP__3(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_settle__TOP__3\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q1 = ((((IData)(vlTOPp->N_OE1) ? 0U : (IData)(vlTOPp->chip7416374__DOT__low8)) 
		   & ((IData)(vlTOPp->N_OE1) ? 0U : 0xffU)) 
		  & ((IData)(vlTOPp->N_OE1) ? 0U : 0xffU));
    vlTOPp->Q2 = ((((IData)(vlTOPp->N_OE2) ? 0U : (IData)(vlTOPp->chip7416374__DOT__high8)) 
		   & ((IData)(vlTOPp->N_OE2) ? 0U : 0xffU)) 
		  & ((IData)(vlTOPp->N_OE2) ? 0U : 0xffU));
}

void Vchip7416374::_eval(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_eval\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK1) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK1)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->CLK2) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK2)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_settle__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK1 = vlTOPp->CLK1;
    vlTOPp->__Vclklast__TOP__CLK2 = vlTOPp->CLK2;
}

void Vchip7416374::_eval_initial(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_eval_initial\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLK1 = vlTOPp->CLK1;
    vlTOPp->__Vclklast__TOP__CLK2 = vlTOPp->CLK2;
}

void Vchip7416374::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::final\n"); );
    // Variables
    Vchip7416374__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip7416374::_eval_settle(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_eval_settle\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vchip7416374::_change_request(Vchip7416374__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_change_request\n"); );
    Vchip7416374* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip7416374::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK1 & 0xfeU))) {
	Verilated::overWidthError("CLK1");}
    if (VL_UNLIKELY((CLK2 & 0xfeU))) {
	Verilated::overWidthError("CLK2");}
    if (VL_UNLIKELY((N_OE1 & 0xfeU))) {
	Verilated::overWidthError("N_OE1");}
    if (VL_UNLIKELY((N_OE2 & 0xfeU))) {
	Verilated::overWidthError("N_OE2");}
}
#endif // VL_DEBUG

void Vchip7416374::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7416374::_ctor_var_reset\n"); );
    // Body
    D1 = VL_RAND_RESET_I(8);
    D2 = VL_RAND_RESET_I(8);
    CLK1 = VL_RAND_RESET_I(1);
    CLK2 = VL_RAND_RESET_I(1);
    N_OE1 = VL_RAND_RESET_I(1);
    N_OE2 = VL_RAND_RESET_I(1);
    Q1 = VL_RAND_RESET_I(8);
    Q2 = VL_RAND_RESET_I(8);
    chip7416374__DOT__low8 = VL_RAND_RESET_I(8);
    chip7416374__DOT__high8 = VL_RAND_RESET_I(8);
}
