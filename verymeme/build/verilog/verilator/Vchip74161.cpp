// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74161.h for the primary calling header

#include "Vchip74161.h"
#include "Vchip74161__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip74161) {
    Vchip74161__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74161__Syms(this, name());
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74161::__Vconfigure(Vchip74161__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74161::~Vchip74161() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74161::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74161::eval\n"); );
    Vchip74161__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74161::_eval_initial_loop(Vchip74161__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip74161::_sequent__TOP__1(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_sequent__TOP__1\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_CLR) {
	if (vlTOPp->N_LOAD) {
	    if (((IData)(vlTOPp->ENP) & (IData)(vlTOPp->ENT))) {
		vlTOPp->chip74161__DOT__count = (0xfU 
						 & ((IData)(1U) 
						    + (IData)(vlTOPp->chip74161__DOT__count)));
	    }
	} else {
	    vlTOPp->chip74161__DOT__count = vlTOPp->PRESET;
	}
    } else {
	vlTOPp->chip74161__DOT__count = 0U;
    }
    vlTOPp->Q = vlTOPp->chip74161__DOT__count;
}

void Vchip74161::_settle__TOP__2(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_settle__TOP__2\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q = vlTOPp->chip74161__DOT__count;
    vlTOPp->RCO = (1U & (((IData)(vlTOPp->ENT) & (0xfU 
						  == (IData)(vlTOPp->chip74161__DOT__count)))
			  ? 1U : 0U));
}

VL_INLINE_OPT void Vchip74161::_combo__TOP__3(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_combo__TOP__3\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->RCO = (1U & (((IData)(vlTOPp->ENT) & (0xfU 
						  == (IData)(vlTOPp->chip74161__DOT__count)))
			  ? 1U : 0U));
}

void Vchip74161::_eval(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_eval\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	 | ((~ (IData)(vlTOPp->N_CLR)) & (IData)(vlTOPp->__Vclklast__TOP__N_CLR)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_CLR = vlTOPp->N_CLR;
}

void Vchip74161::_eval_initial(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_eval_initial\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_CLR = vlTOPp->N_CLR;
}

void Vchip74161::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::final\n"); );
    // Variables
    Vchip74161__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74161::_eval_settle(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_eval_settle\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vchip74161::_change_request(Vchip74161__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_change_request\n"); );
    Vchip74161* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74161::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_CLR & 0xfeU))) {
	Verilated::overWidthError("N_CLR");}
    if (VL_UNLIKELY((ENP & 0xfeU))) {
	Verilated::overWidthError("ENP");}
    if (VL_UNLIKELY((ENT & 0xfeU))) {
	Verilated::overWidthError("ENT");}
    if (VL_UNLIKELY((PRESET & 0xf0U))) {
	Verilated::overWidthError("PRESET");}
    if (VL_UNLIKELY((N_LOAD & 0xfeU))) {
	Verilated::overWidthError("N_LOAD");}
}
#endif // VL_DEBUG

void Vchip74161::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74161::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    N_CLR = VL_RAND_RESET_I(1);
    ENP = VL_RAND_RESET_I(1);
    ENT = VL_RAND_RESET_I(1);
    PRESET = VL_RAND_RESET_I(4);
    N_LOAD = VL_RAND_RESET_I(1);
    Q = VL_RAND_RESET_I(4);
    RCO = VL_RAND_RESET_I(1);
    chip74161__DOT__count = VL_RAND_RESET_I(4);
}
