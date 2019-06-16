// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmlu_slice.h for the primary calling header

#include "Vmlu_slice.h"
#include "Vmlu_slice__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmlu_slice) {
    Vmlu_slice__Syms* __restrict vlSymsp = __VlSymsp = new Vmlu_slice__Syms(this, name());
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmlu_slice::__Vconfigure(Vmlu_slice__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmlu_slice::~Vmlu_slice() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmlu_slice::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmlu_slice::eval\n"); );
    Vmlu_slice__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmlu_slice::_eval_initial_loop(Vmlu_slice__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vmlu_slice::_combo__TOP__1(Vmlu_slice__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_combo__TOP__1\n"); );
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu_slice__DOT__prop = 0U;
    vlTOPp->mlu_slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->ADDR) >> 8U)))) 
	   | (5U == (7U & ((IData)(vlTOPp->ADDR) >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->ADDR) >> 8U)))) 
	 | (7U == (7U & ((IData)(vlTOPp->ADDR) >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->ADDR) >> 8U)))) {
	    vlTOPp->mlu_slice__DOT__out_low = (0xfU 
					       & (((IData)(vlTOPp->ADDR) 
						   + 
						   ((IData)(vlTOPp->ADDR) 
						    >> 4U)) 
						  + 
						  (1U 
						   & ((IData)(vlTOPp->ADDR) 
						      >> 0xbU))));
	    vlTOPp->mlu_slice__DOT__prop = (0xfU == 
					    (0xfU & 
					     ((IData)(vlTOPp->ADDR) 
					      + ((IData)(vlTOPp->ADDR) 
						 >> 4U))));
	    vlTOPp->mlu_slice__DOT__gen = (0xfU < (0x1fU 
						   & ((0xfU 
						       & (IData)(vlTOPp->ADDR)) 
						      + 
						      (0xfU 
						       & ((IData)(vlTOPp->ADDR) 
							  >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu_slice__DOT__out_low = (0xfU 
						   & (((IData)(vlTOPp->ADDR) 
						       + 
						       (~ 
							((IData)(vlTOPp->ADDR) 
							 >> 4U))) 
						      + 
						      (1U 
						       & ((IData)(vlTOPp->ADDR) 
							  >> 0xbU))));
		vlTOPp->mlu_slice__DOT__prop = (0xfU 
						== 
						(0xfU 
						 & ((IData)(vlTOPp->ADDR) 
						    + 
						    (~ 
						     ((IData)(vlTOPp->ADDR) 
						      >> 4U)))));
		vlTOPp->mlu_slice__DOT__gen = (0xfU 
					       < (0x1fU 
						  & ((0xfU 
						      & (IData)(vlTOPp->ADDR)) 
						     + 
						     (0xfU 
						      & (~ 
							 ((IData)(vlTOPp->ADDR) 
							  >> 4U))))));
	    } else {
		vlTOPp->mlu_slice__DOT__out_low = (0xfU 
						   & ((2U 
						       == 
						       (7U 
							& ((IData)(vlTOPp->ADDR) 
							   >> 8U)))
						       ? 
						      ((IData)(vlTOPp->ADDR) 
						       & ((IData)(vlTOPp->ADDR) 
							  >> 4U))
						       : 
						      ((3U 
							== 
							(7U 
							 & ((IData)(vlTOPp->ADDR) 
							    >> 8U)))
						        ? 
						       ((IData)(vlTOPp->ADDR) 
							| ((IData)(vlTOPp->ADDR) 
							   >> 4U))
						        : 
						       ((4U 
							 == 
							 (7U 
							  & ((IData)(vlTOPp->ADDR) 
							     >> 8U)))
							 ? 
							((IData)(vlTOPp->ADDR) 
							 ^ 
							 ((IData)(vlTOPp->ADDR) 
							  >> 4U))
							 : 
							((5U 
							  == 
							  (7U 
							   & ((IData)(vlTOPp->ADDR) 
							      >> 8U)))
							  ? 
							 (~ (IData)(vlTOPp->ADDR))
							  : 0U)))));
	    }
	}
    }
    vlTOPp->OUT = (((0U == (IData)(vlTOPp->mlu_slice__DOT__out_low)) 
		    << 6U) | (((IData)(vlTOPp->mlu_slice__DOT__gen) 
			       << 5U) | (((IData)(vlTOPp->mlu_slice__DOT__prop) 
					  << 4U) | (IData)(vlTOPp->mlu_slice__DOT__out_low))));
}

void Vmlu_slice::_eval(Vmlu_slice__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_eval\n"); );
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vmlu_slice::_eval_initial(Vmlu_slice__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_eval_initial\n"); );
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmlu_slice::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::final\n"); );
    // Variables
    Vmlu_slice__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmlu_slice::_eval_settle(Vmlu_slice__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_eval_settle\n"); );
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vmlu_slice::_change_request(Vmlu_slice__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_change_request\n"); );
    Vmlu_slice* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmlu_slice::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xf000U))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((BOOTSTRAP_ADDR & 0xf000U))) {
	Verilated::overWidthError("BOOTSTRAP_ADDR");}
    if (VL_UNLIKELY((N_BOOTED & 0xfeU))) {
	Verilated::overWidthError("N_BOOTED");}
    if (VL_UNLIKELY((BOOTSTRAP_N_WE & 0xfeU))) {
	Verilated::overWidthError("BOOTSTRAP_N_WE");}
}
#endif // VL_DEBUG

void Vmlu_slice::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_slice::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(12);
    OUT = VL_RAND_RESET_I(8);
    BOOTSTRAP_ADDR = VL_RAND_RESET_I(12);
    BOOTSTRAP_DATA = VL_RAND_RESET_I(8);
    N_BOOTED = VL_RAND_RESET_I(1);
    BOOTSTRAP_N_WE = VL_RAND_RESET_I(1);
    mlu_slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu_slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu_slice__DOT__gen = VL_RAND_RESET_I(1);
}
