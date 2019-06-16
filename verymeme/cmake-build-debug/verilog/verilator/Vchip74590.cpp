// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74590.h for the primary calling header

#include "Vchip74590.h"
#include "Vchip74590__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip74590) {
    Vchip74590__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74590__Syms(this, name());
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74590::__Vconfigure(Vchip74590__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74590::~Vchip74590() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74590::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74590::eval\n"); );
    Vchip74590__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74590::_eval_initial_loop(Vchip74590__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip74590::_sequent__TOP__1(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_sequent__TOP__1\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74590.v:13
    vlTOPp->chip74590__DOT__count = (0xffU & ((IData)(vlTOPp->N_MRC)
					       ? ((IData)(1U) 
						  + (IData)(vlTOPp->chip74590__DOT__count))
					       : 0U));
    vlTOPp->N_RCO = (1U & ((0xffU == (IData)(vlTOPp->chip74590__DOT__count))
			    ? 0U : 1U));
}

void Vchip74590::_settle__TOP__2(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_settle__TOP__2\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->N_RCO = (1U & ((0xffU == (IData)(vlTOPp->chip74590__DOT__count))
			    ? 0U : 1U));
    vlTOPp->Q_OUT = ((((IData)(vlTOPp->N_OE) ? 0U : (IData)(vlTOPp->chip74590__DOT__count)) 
		      & ((IData)(vlTOPp->N_OE) ? 0U
			  : 0xffU)) & ((IData)(vlTOPp->N_OE)
				        ? 0U : 0xffU));
}

VL_INLINE_OPT void Vchip74590::_combo__TOP__3(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_combo__TOP__3\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q_OUT = ((((IData)(vlTOPp->N_OE) ? 0U : (IData)(vlTOPp->chip74590__DOT__count)) 
		      & ((IData)(vlTOPp->N_OE) ? 0U
			  : 0xffU)) & ((IData)(vlTOPp->N_OE)
				        ? 0U : 0xffU));
}

void Vchip74590::_eval(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_eval\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CPC) & (~ (IData)(vlTOPp->__Vclklast__TOP__CPC))) 
	 | ((~ (IData)(vlTOPp->N_MRC)) & (IData)(vlTOPp->__Vclklast__TOP__N_MRC)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CPC = vlTOPp->CPC;
    vlTOPp->__Vclklast__TOP__N_MRC = vlTOPp->N_MRC;
}

void Vchip74590::_eval_initial(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_eval_initial\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CPC = vlTOPp->CPC;
    vlTOPp->__Vclklast__TOP__N_MRC = vlTOPp->N_MRC;
}

void Vchip74590::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::final\n"); );
    // Variables
    Vchip74590__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74590::_eval_settle(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_eval_settle\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vchip74590::_change_request(Vchip74590__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_change_request\n"); );
    Vchip74590* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74590::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((N_MRC & 0xfeU))) {
	Verilated::overWidthError("N_MRC");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
    if (VL_UNLIKELY((CPC & 0xfeU))) {
	Verilated::overWidthError("CPC");}
}
#endif // VL_DEBUG

void Vchip74590::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74590::_ctor_var_reset\n"); );
    // Body
    N_MRC = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    CPC = VL_RAND_RESET_I(1);
    N_RCO = VL_RAND_RESET_I(1);
    Q_OUT = VL_RAND_RESET_I(8);
    chip74590__DOT__count = VL_RAND_RESET_I(8);
}
