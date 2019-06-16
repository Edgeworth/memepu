// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74299.h for the primary calling header

#include "Vchip74299.h"
#include "Vchip74299__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip74299) {
    Vchip74299__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74299__Syms(this, name());
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74299::__Vconfigure(Vchip74299__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74299::~Vchip74299() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74299::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74299::eval\n"); );
    Vchip74299__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74299::_eval_initial_loop(Vchip74299__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip74299::_sequent__TOP__1(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_sequent__TOP__1\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__chip74299__DOT__shift_reg,7,0);
    // Body
    __Vdly__chip74299__DOT__shift_reg = vlTOPp->chip74299__DOT__shift_reg;
    // ALWAYS at chip74299.v:21
    if (vlTOPp->N_MR) {
	if ((2U & (IData)(vlTOPp->S))) {
	    if ((1U & (IData)(vlTOPp->S))) {
		__Vdly__chip74299__DOT__shift_reg = vlTOPp->IO;
	    } else {
		__Vdly__chip74299__DOT__shift_reg = 
		    (0xffU & ((IData)(vlTOPp->chip74299__DOT__shift_reg) 
			      >> 1U));
		__Vdly__chip74299__DOT__shift_reg = 
		    ((0x7fU & (IData)(__Vdly__chip74299__DOT__shift_reg)) 
		     | ((IData)(vlTOPp->DSR) << 7U));
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->S))) {
		__Vdly__chip74299__DOT__shift_reg = 
		    (0xffU & ((IData)(vlTOPp->chip74299__DOT__shift_reg) 
			      << 1U));
		__Vdly__chip74299__DOT__shift_reg = 
		    ((0xfeU & (IData)(__Vdly__chip74299__DOT__shift_reg)) 
		     | (IData)(vlTOPp->DSL));
	    }
	}
    } else {
	__Vdly__chip74299__DOT__shift_reg = 0U;
    }
    vlTOPp->chip74299__DOT__shift_reg = __Vdly__chip74299__DOT__shift_reg;
    vlTOPp->Q0 = (1U & (IData)(vlTOPp->chip74299__DOT__shift_reg));
    vlTOPp->Q7 = (1U & ((IData)(vlTOPp->chip74299__DOT__shift_reg) 
			>> 7U));
}

void Vchip74299::_settle__TOP__2(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_settle__TOP__2\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q0 = (1U & (IData)(vlTOPp->chip74299__DOT__shift_reg));
    vlTOPp->Q7 = (1U & ((IData)(vlTOPp->chip74299__DOT__shift_reg) 
			>> 7U));
    vlTOPp->IO = ((((0U == (IData)(vlTOPp->N_OE)) ? (IData)(vlTOPp->chip74299__DOT__shift_reg)
		     : 0U) & ((0U == (IData)(vlTOPp->N_OE))
			       ? 0xffU : 0U)) & ((0U 
						  == (IData)(vlTOPp->N_OE))
						  ? 0xffU
						  : 0U));
}

VL_INLINE_OPT void Vchip74299::_combo__TOP__3(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_combo__TOP__3\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->IO = ((((0U == (IData)(vlTOPp->N_OE)) ? (IData)(vlTOPp->chip74299__DOT__shift_reg)
		     : 0U) & ((0U == (IData)(vlTOPp->N_OE))
			       ? 0xffU : 0U)) & ((0U 
						  == (IData)(vlTOPp->N_OE))
						  ? 0xffU
						  : 0U));
}

void Vchip74299::_eval(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_eval\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CP) & (~ (IData)(vlTOPp->__Vclklast__TOP__CP))) 
	 | ((~ (IData)(vlTOPp->N_MR)) & (IData)(vlTOPp->__Vclklast__TOP__N_MR)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CP = vlTOPp->CP;
    vlTOPp->__Vclklast__TOP__N_MR = vlTOPp->N_MR;
}

void Vchip74299::_eval_initial(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_eval_initial\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CP = vlTOPp->CP;
    vlTOPp->__Vclklast__TOP__N_MR = vlTOPp->N_MR;
}

void Vchip74299::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::final\n"); );
    // Variables
    Vchip74299__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74299::_eval_settle(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_eval_settle\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vchip74299::_change_request(Vchip74299__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_change_request\n"); );
    Vchip74299* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74299::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((S & 0xfcU))) {
	Verilated::overWidthError("S");}
    if (VL_UNLIKELY((N_OE & 0xfcU))) {
	Verilated::overWidthError("N_OE");}
    if (VL_UNLIKELY((N_MR & 0xfeU))) {
	Verilated::overWidthError("N_MR");}
    if (VL_UNLIKELY((DSR & 0xfeU))) {
	Verilated::overWidthError("DSR");}
    if (VL_UNLIKELY((DSL & 0xfeU))) {
	Verilated::overWidthError("DSL");}
    if (VL_UNLIKELY((CP & 0xfeU))) {
	Verilated::overWidthError("CP");}
}
#endif // VL_DEBUG

void Vchip74299::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74299::_ctor_var_reset\n"); );
    // Body
    S = VL_RAND_RESET_I(2);
    N_OE = VL_RAND_RESET_I(2);
    N_MR = VL_RAND_RESET_I(1);
    DSR = VL_RAND_RESET_I(1);
    DSL = VL_RAND_RESET_I(1);
    CP = VL_RAND_RESET_I(1);
    IO = VL_RAND_RESET_I(8);
    Q0 = VL_RAND_RESET_I(1);
    Q7 = VL_RAND_RESET_I(1);
    chip74299__DOT__shift_reg = VL_RAND_RESET_I(8);
}
