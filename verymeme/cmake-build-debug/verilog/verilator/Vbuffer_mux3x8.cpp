// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbuffer_mux3x8.h for the primary calling header

#include "Vbuffer_mux3x8.h"
#include "Vbuffer_mux3x8__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vbuffer_mux3x8) {
    Vbuffer_mux3x8__Syms* __restrict vlSymsp = __VlSymsp = new Vbuffer_mux3x8__Syms(this, name());
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbuffer_mux3x8::__Vconfigure(Vbuffer_mux3x8__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbuffer_mux3x8::~Vbuffer_mux3x8() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vbuffer_mux3x8::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbuffer_mux3x8::eval\n"); );
    Vbuffer_mux3x8__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vbuffer_mux3x8::_eval_initial_loop(Vbuffer_mux3x8__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vbuffer_mux3x8::_combo__TOP__1(Vbuffer_mux3x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_combo__TOP__1\n"); );
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT = (0xffU & ((0U == (IData)(vlTOPp->SEL))
			     ? ((((1U & ((IData)(1U) 
					 << (IData)(vlTOPp->SEL)))
				   ? (IData)(vlTOPp->A)
				   : 0U) & ((1U & ((IData)(1U) 
						   << (IData)(vlTOPp->SEL)))
					     ? 0xffU
					     : 0U)) 
				& ((1U & ((IData)(1U) 
					  << (IData)(vlTOPp->SEL)))
				    ? 0xffU : 0U)) : 
			    ((1U == (IData)(vlTOPp->SEL))
			      ? ((((2U & ((IData)(1U) 
					  << (IData)(vlTOPp->SEL)))
				    ? (IData)(vlTOPp->B)
				    : 0U) & ((2U & 
					      ((IData)(1U) 
					       << (IData)(vlTOPp->SEL)))
					      ? 0xffU
					      : 0U)) 
				 & ((2U & ((IData)(1U) 
					   << (IData)(vlTOPp->SEL)))
				     ? 0xffU : 0U))
			      : ((2U == (IData)(vlTOPp->SEL))
				  ? ((((4U & ((IData)(1U) 
					      << (IData)(vlTOPp->SEL)))
				        ? (IData)(vlTOPp->C)
				        : 0U) & ((4U 
						  & ((IData)(1U) 
						     << (IData)(vlTOPp->SEL)))
						  ? 0xffU
						  : 0U)) 
				     & ((4U & ((IData)(1U) 
					       << (IData)(vlTOPp->SEL)))
					 ? 0xffU : 0U))
				  : 0U))));
}

void Vbuffer_mux3x8::_eval(Vbuffer_mux3x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_eval\n"); );
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vbuffer_mux3x8::_eval_initial(Vbuffer_mux3x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_eval_initial\n"); );
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbuffer_mux3x8::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::final\n"); );
    // Variables
    Vbuffer_mux3x8__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbuffer_mux3x8::_eval_settle(Vbuffer_mux3x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_eval_settle\n"); );
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vbuffer_mux3x8::_change_request(Vbuffer_mux3x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_change_request\n"); );
    Vbuffer_mux3x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbuffer_mux3x8::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((SEL & 0xfcU))) {
	Verilated::overWidthError("SEL");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vbuffer_mux3x8::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer_mux3x8::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(8);
    B = VL_RAND_RESET_I(8);
    C = VL_RAND_RESET_I(8);
    SEL = VL_RAND_RESET_I(2);
    N_RST = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(8);
}
