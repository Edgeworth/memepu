// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip7486.h for the primary calling header

#include "Vchip7486.h"
#include "Vchip7486__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip7486) {
    Vchip7486__Syms* __restrict vlSymsp = __VlSymsp = new Vchip7486__Syms(this, name());
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip7486::__Vconfigure(Vchip7486__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip7486::~Vchip7486() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip7486::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip7486::eval\n"); );
    Vchip7486__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip7486::_eval_initial_loop(Vchip7486__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip7486::_combo__TOP__1(Vchip7486__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_combo__TOP__1\n"); );
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Y = ((IData)(vlTOPp->A) ^ (IData)(vlTOPp->B));
}

void Vchip7486::_eval(Vchip7486__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_eval\n"); );
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vchip7486::_eval_initial(Vchip7486__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_eval_initial\n"); );
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip7486::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::final\n"); );
    // Variables
    Vchip7486__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip7486::_eval_settle(Vchip7486__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_eval_settle\n"); );
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vchip7486::_change_request(Vchip7486__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_change_request\n"); );
    Vchip7486* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip7486::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((A & 0xf0U))) {
	Verilated::overWidthError("A");}
    if (VL_UNLIKELY((B & 0xf0U))) {
	Verilated::overWidthError("B");}
}
#endif // VL_DEBUG

void Vchip7486::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7486::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(4);
    B = VL_RAND_RESET_I(4);
    Y = VL_RAND_RESET_I(4);
}
