// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbuffer32.h for the primary calling header

#include "Vbuffer32.h"
#include "Vbuffer32__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vbuffer32) {
    Vbuffer32__Syms* __restrict vlSymsp = __VlSymsp = new Vbuffer32__Syms(this, name());
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbuffer32::__Vconfigure(Vbuffer32__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbuffer32::~Vbuffer32() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vbuffer32::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbuffer32::eval\n"); );
    Vbuffer32__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vbuffer32::_eval_initial_loop(Vbuffer32__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vbuffer32::_combo__TOP__1(Vbuffer32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_combo__TOP__1\n"); );
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->buffer32__DOT__OUT__out__out2 = ((0xffff0000U 
					      & vlTOPp->buffer32__DOT__OUT__out__out2) 
					     | (((IData)(vlTOPp->N_OE)
						  ? 0U
						  : vlTOPp->IN) 
						& ((IData)(vlTOPp->N_OE)
						    ? 0U
						    : 0xffffU)));
    vlTOPp->buffer32__DOT__OUT__out__out3 = ((0xffffU 
					      & vlTOPp->buffer32__DOT__OUT__out__out3) 
					     | ((((IData)(vlTOPp->N_OE)
						   ? 0U
						   : 
						  (vlTOPp->IN 
						   >> 0x10U)) 
						 & ((IData)(vlTOPp->N_OE)
						     ? 0U
						     : 0xffffU)) 
						<< 0x10U));
    vlTOPp->OUT = (((vlTOPp->buffer32__DOT__OUT__out__out2 
		     & ((IData)(vlTOPp->N_OE) ? 0U : 0xffffU)) 
		    | (vlTOPp->buffer32__DOT__OUT__out__out3 
		       & (((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffffU) << 0x10U))) 
		   & (((IData)(vlTOPp->N_OE) ? 0U : 0xffffU) 
		      | (((IData)(vlTOPp->N_OE) ? 0U
			   : 0xffffU) << 0x10U)));
}

void Vbuffer32::_eval(Vbuffer32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_eval\n"); );
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vbuffer32::_eval_initial(Vbuffer32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_eval_initial\n"); );
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbuffer32::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::final\n"); );
    // Variables
    Vbuffer32__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbuffer32::_eval_settle(Vbuffer32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_eval_settle\n"); );
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vbuffer32::_change_request(Vbuffer32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_change_request\n"); );
    Vbuffer32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbuffer32::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
}
#endif // VL_DEBUG

void Vbuffer32::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbuffer32::_ctor_var_reset\n"); );
    // Body
    IN = VL_RAND_RESET_I(32);
    N_OE = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(32);
    buffer32__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    buffer32__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
}
