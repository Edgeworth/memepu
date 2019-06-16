// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbuffer_mux2x32.h for the primary calling header

#include "Vbuffer_mux2x32.h"
#include "Vbuffer_mux2x32__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vbuffer_mux2x32) {
    Vbuffer_mux2x32__Syms* __restrict vlSymsp = __VlSymsp = new Vbuffer_mux2x32__Syms(this, name());
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbuffer_mux2x32::__Vconfigure(Vbuffer_mux2x32__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbuffer_mux2x32::~Vbuffer_mux2x32() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vbuffer_mux2x32::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbuffer_mux2x32::eval\n"); );
    Vbuffer_mux2x32__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vbuffer_mux2x32::_eval_initial_loop(Vbuffer_mux2x32__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vbuffer_mux2x32::_combo__TOP__1(Vbuffer_mux2x32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_combo__TOP__1\n"); );
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((IData)(vlTOPp->N_SEL_A) ? 0U : vlTOPp->A) 
	      & ((IData)(vlTOPp->N_SEL_A) ? 0U : 0xffffU)));
    vlTOPp->buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((IData)(vlTOPp->N_SEL_A) ? 0U : (vlTOPp->A 
						 >> 0x10U)) 
	       & ((IData)(vlTOPp->N_SEL_A) ? 0U : 0xffffU)) 
	      << 0x10U));
    vlTOPp->buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((IData)(vlTOPp->SEL_A) ? 0U : vlTOPp->B) 
	      & ((IData)(vlTOPp->SEL_A) ? 0U : 0xffffU)));
    vlTOPp->buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((IData)(vlTOPp->SEL_A) ? 0U : (vlTOPp->B 
					       >> 0x10U)) 
	       & ((IData)(vlTOPp->SEL_A) ? 0U : 0xffffU)) 
	      << 0x10U));
    vlTOPp->OUT = ((IData)(vlTOPp->SEL_A) ? (((vlTOPp->buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out2 
					       & ((IData)(vlTOPp->N_SEL_A)
						   ? 0U
						   : 0xffffU)) 
					      | (vlTOPp->buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out3 
						 & (((IData)(vlTOPp->N_SEL_A)
						      ? 0U
						      : 0xffffU) 
						    << 0x10U))) 
					     & (((IData)(vlTOPp->N_SEL_A)
						  ? 0U
						  : 0xffffU) 
						| (((IData)(vlTOPp->N_SEL_A)
						     ? 0U
						     : 0xffffU) 
						   << 0x10U)))
		    : (((vlTOPp->buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out2 
			 & ((IData)(vlTOPp->SEL_A) ? 0U
			     : 0xffffU)) | (vlTOPp->buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out3 
					    & (((IData)(vlTOPp->SEL_A)
						 ? 0U
						 : 0xffffU) 
					       << 0x10U))) 
		       & (((IData)(vlTOPp->SEL_A) ? 0U
			    : 0xffffU) | (((IData)(vlTOPp->SEL_A)
					    ? 0U : 0xffffU) 
					  << 0x10U))));
}

void Vbuffer_mux2x32::_eval(Vbuffer_mux2x32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_eval\n"); );
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vbuffer_mux2x32::_eval_initial(Vbuffer_mux2x32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_eval_initial\n"); );
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbuffer_mux2x32::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::final\n"); );
    // Variables
    Vbuffer_mux2x32__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbuffer_mux2x32::_eval_settle(Vbuffer_mux2x32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_eval_settle\n"); );
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vbuffer_mux2x32::_change_request(Vbuffer_mux2x32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_change_request\n"); );
    Vbuffer_mux2x32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbuffer_mux2x32::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((SEL_A & 0xfeU))) {
	Verilated::overWidthError("SEL_A");}
    if (VL_UNLIKELY((N_SEL_A & 0xfeU))) {
	Verilated::overWidthError("N_SEL_A");}
}
#endif // VL_DEBUG

void Vbuffer_mux2x32::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux2x32::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(32);
    B = VL_RAND_RESET_I(32);
    SEL_A = VL_RAND_RESET_I(1);
    N_SEL_A = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(32);
    buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    buffer_mux2x32__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    buffer_mux2x32__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
}
