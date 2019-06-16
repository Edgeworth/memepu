// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74273.h for the primary calling header

#include "Vchip74273.h"
#include "Vchip74273__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip74273) {
    Vchip74273__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74273__Syms(this, name());
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74273::__Vconfigure(Vchip74273__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74273::~Vchip74273() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74273::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74273::eval\n"); );
    Vchip74273__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74273::_eval_initial_loop(Vchip74273__Syms* __restrict vlSymsp) {
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

void Vchip74273::_initial__TOP__1(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_initial__TOP__1\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at chip74273.v:16
    if ((1U & (~ (IData)(vlTOPp->N_MR)))) {
	vlTOPp->chip74273__DOT__value = 0U;
    }
}

VL_INLINE_OPT void Vchip74273::_sequent__TOP__2(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_sequent__TOP__2\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74273.v:21
    vlTOPp->chip74273__DOT__value = ((IData)(vlTOPp->N_MR)
				      ? (IData)(vlTOPp->D)
				      : 0U);
    vlTOPp->Q = vlTOPp->chip74273__DOT__value;
}

void Vchip74273::_settle__TOP__3(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_settle__TOP__3\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q = vlTOPp->chip74273__DOT__value;
}

void Vchip74273::_eval(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_eval\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CP) & (~ (IData)(vlTOPp->__Vclklast__TOP__CP))) 
	 | ((~ (IData)(vlTOPp->N_MR)) & (IData)(vlTOPp->__Vclklast__TOP__N_MR)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CP = vlTOPp->CP;
    vlTOPp->__Vclklast__TOP__N_MR = vlTOPp->N_MR;
}

void Vchip74273::_eval_initial(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_eval_initial\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CP = vlTOPp->CP;
    vlTOPp->__Vclklast__TOP__N_MR = vlTOPp->N_MR;
}

void Vchip74273::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::final\n"); );
    // Variables
    Vchip74273__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74273::_eval_settle(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_eval_settle\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vchip74273::_change_request(Vchip74273__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_change_request\n"); );
    Vchip74273* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74273::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((N_MR & 0xfeU))) {
	Verilated::overWidthError("N_MR");}
    if (VL_UNLIKELY((CP & 0xfeU))) {
	Verilated::overWidthError("CP");}
}
#endif // VL_DEBUG

void Vchip74273::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74273::_ctor_var_reset\n"); );
    // Body
    D = VL_RAND_RESET_I(8);
    N_MR = VL_RAND_RESET_I(1);
    CP = VL_RAND_RESET_I(1);
    Q = VL_RAND_RESET_I(8);
    chip74273__DOT__value = VL_RAND_RESET_I(8);
}
