// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip7404.h for the primary calling header

#include "Vchip7404.h"
#include "Vchip7404__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip7404) {
    Vchip7404__Syms* __restrict vlSymsp = __VlSymsp = new Vchip7404__Syms(this, name());
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip7404::__Vconfigure(Vchip7404__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip7404::~Vchip7404() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip7404::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip7404::eval\n"); );
    Vchip7404__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip7404::_eval_initial_loop(Vchip7404__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip7404::_combo__TOP__1(Vchip7404__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_combo__TOP__1\n"); );
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Y = (0x3fU & (~ (IData)(vlTOPp->A)));
}

void Vchip7404::_eval(Vchip7404__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_eval\n"); );
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vchip7404::_eval_initial(Vchip7404__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_eval_initial\n"); );
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip7404::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::final\n"); );
    // Variables
    Vchip7404__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip7404::_eval_settle(Vchip7404__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_eval_settle\n"); );
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vchip7404::_change_request(Vchip7404__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_change_request\n"); );
    Vchip7404* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip7404::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((A & 0xc0U))) {
	Verilated::overWidthError("A");}
}
#endif // VL_DEBUG

void Vchip7404::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip7404::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(6);
    Y = VL_RAND_RESET_I(6);
}
