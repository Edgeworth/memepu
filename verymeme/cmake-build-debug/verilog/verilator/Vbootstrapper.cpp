// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbootstrapper.h for the primary calling header

#include "Vbootstrapper.h"
#include "Vbootstrapper__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vbootstrapper) {
    Vbootstrapper__Syms* __restrict vlSymsp = __VlSymsp = new Vbootstrapper__Syms(this, name());
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbootstrapper::__Vconfigure(Vbootstrapper__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbootstrapper::~Vbootstrapper() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vbootstrapper::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbootstrapper::eval\n"); );
    Vbootstrapper__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vbootstrapper::_eval_initial_loop(Vbootstrapper__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vbootstrapper::_combo__TOP__1(Vbootstrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_combo__TOP__1\n"); );
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->N_BOOTED = (1U & (~ (vlTOPp->TIME >> 0x11U)));
}

void Vbootstrapper::_eval(Vbootstrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_eval\n"); );
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vbootstrapper::_eval_initial(Vbootstrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_eval_initial\n"); );
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbootstrapper::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::final\n"); );
    // Variables
    Vbootstrapper__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbootstrapper::_eval_settle(Vbootstrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_eval_settle\n"); );
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vbootstrapper::_change_request(Vbootstrapper__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_change_request\n"); );
    Vbootstrapper* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbootstrapper::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_CLK & 0xfeU))) {
	Verilated::overWidthError("N_CLK");}
}
#endif // VL_DEBUG

void Vbootstrapper::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbootstrapper::_ctor_var_reset\n"); );
    // Body
    TIME = VL_RAND_RESET_I(32);
    CLK = VL_RAND_RESET_I(1);
    N_CLK = VL_RAND_RESET_I(1);
    DATA = VL_RAND_RESET_I(8);
    ADDR = VL_RAND_RESET_I(17);
    N_BOOTED = VL_RAND_RESET_I(1);
    CONTROL_N_WE = VL_RAND_RESET_I(1);
    MLU_SLICE_N_WE = VL_RAND_RESET_I(1);
    MLU_LOOKAHEAD_N_WE = VL_RAND_RESET_I(1);
}
