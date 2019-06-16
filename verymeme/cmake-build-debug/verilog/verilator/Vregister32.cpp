// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister32.h for the primary calling header

#include "Vregister32.h"
#include "Vregister32__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vregister32) {
    Vregister32__Syms* __restrict vlSymsp = __VlSymsp = new Vregister32__Syms(this, name());
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vregister32::__Vconfigure(Vregister32__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vregister32::~Vregister32() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vregister32::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister32::eval\n"); );
    Vregister32__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vregister32::_eval_initial_loop(Vregister32__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vregister32::_sequent__TOP__1(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_sequent__TOP__1\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlTOPp->register32__DOT__high16__DOT__high8 = (0xffU 
						   & (vlTOPp->IN 
						      >> 0x18U));
    // ALWAYS at chip7416374.v:19
    vlTOPp->register32__DOT__high16__DOT__low8 = (0xffU 
						  & (vlTOPp->IN 
						     >> 0x10U));
    // ALWAYS at chip7416374.v:20
    vlTOPp->register32__DOT__low16__DOT__high8 = (0xffU 
						  & (vlTOPp->IN 
						     >> 8U));
    // ALWAYS at chip7416374.v:19
    vlTOPp->register32__DOT__low16__DOT__low8 = (0xffU 
						 & vlTOPp->IN);
}

void Vregister32::_settle__TOP__2(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_settle__TOP__2\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->register32__DOT__OUT__out__out4 = ((0xffff00ffU 
						& vlTOPp->register32__DOT__OUT__out__out4) 
					       | ((((IData)(vlTOPp->N_OE)
						     ? 0U
						     : (IData)(vlTOPp->register32__DOT__low16__DOT__high8)) 
						   & ((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU)) 
						  << 8U));
    vlTOPp->register32__DOT__OUT__out__out5 = ((0xffffff00U 
						& vlTOPp->register32__DOT__OUT__out__out5) 
					       | (((IData)(vlTOPp->N_OE)
						    ? 0U
						    : (IData)(vlTOPp->register32__DOT__low16__DOT__low8)) 
						  & ((IData)(vlTOPp->N_OE)
						      ? 0U
						      : 0xffU)));
    vlTOPp->register32__DOT__OUT__out__out6 = ((0xffffffU 
						& vlTOPp->register32__DOT__OUT__out__out6) 
					       | ((((IData)(vlTOPp->N_OE)
						     ? 0U
						     : (IData)(vlTOPp->register32__DOT__high16__DOT__high8)) 
						   & ((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU)) 
						  << 0x18U));
    vlTOPp->register32__DOT__OUT__out__out7 = ((0xff00ffffU 
						& vlTOPp->register32__DOT__OUT__out__out7) 
					       | ((((IData)(vlTOPp->N_OE)
						     ? 0U
						     : (IData)(vlTOPp->register32__DOT__high16__DOT__low8)) 
						   & ((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU)) 
						  << 0x10U));
    vlTOPp->OUT = (((((vlTOPp->register32__DOT__OUT__out__out4 
		       & (((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffU) << 8U)) | (vlTOPp->register32__DOT__OUT__out__out5 
						& ((IData)(vlTOPp->N_OE)
						    ? 0U
						    : 0xffU))) 
		     | (vlTOPp->register32__DOT__OUT__out__out6 
			& (((IData)(vlTOPp->N_OE) ? 0U
			     : 0xffU) << 0x18U))) | 
		    (vlTOPp->register32__DOT__OUT__out__out7 
		     & (((IData)(vlTOPp->N_OE) ? 0U
			  : 0xffU) << 0x10U))) & ((
						   ((((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU) 
						     << 8U) 
						    | ((IData)(vlTOPp->N_OE)
						        ? 0U
						        : 0xffU)) 
						   | (((IData)(vlTOPp->N_OE)
						        ? 0U
						        : 0xffU) 
						      << 0x18U)) 
						  | (((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU) 
						     << 0x10U)));
}

VL_INLINE_OPT void Vregister32::_combo__TOP__3(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_combo__TOP__3\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->register32__DOT__OUT__out__out6 = ((0xffffffU 
						& vlTOPp->register32__DOT__OUT__out__out6) 
					       | ((((IData)(vlTOPp->N_OE)
						     ? 0U
						     : (IData)(vlTOPp->register32__DOT__high16__DOT__high8)) 
						   & ((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU)) 
						  << 0x18U));
    vlTOPp->register32__DOT__OUT__out__out7 = ((0xff00ffffU 
						& vlTOPp->register32__DOT__OUT__out__out7) 
					       | ((((IData)(vlTOPp->N_OE)
						     ? 0U
						     : (IData)(vlTOPp->register32__DOT__high16__DOT__low8)) 
						   & ((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU)) 
						  << 0x10U));
    vlTOPp->register32__DOT__OUT__out__out4 = ((0xffff00ffU 
						& vlTOPp->register32__DOT__OUT__out__out4) 
					       | ((((IData)(vlTOPp->N_OE)
						     ? 0U
						     : (IData)(vlTOPp->register32__DOT__low16__DOT__high8)) 
						   & ((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU)) 
						  << 8U));
    vlTOPp->register32__DOT__OUT__out__out5 = ((0xffffff00U 
						& vlTOPp->register32__DOT__OUT__out__out5) 
					       | (((IData)(vlTOPp->N_OE)
						    ? 0U
						    : (IData)(vlTOPp->register32__DOT__low16__DOT__low8)) 
						  & ((IData)(vlTOPp->N_OE)
						      ? 0U
						      : 0xffU)));
    vlTOPp->OUT = (((((vlTOPp->register32__DOT__OUT__out__out4 
		       & (((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffU) << 8U)) | (vlTOPp->register32__DOT__OUT__out__out5 
						& ((IData)(vlTOPp->N_OE)
						    ? 0U
						    : 0xffU))) 
		     | (vlTOPp->register32__DOT__OUT__out__out6 
			& (((IData)(vlTOPp->N_OE) ? 0U
			     : 0xffU) << 0x18U))) | 
		    (vlTOPp->register32__DOT__OUT__out__out7 
		     & (((IData)(vlTOPp->N_OE) ? 0U
			  : 0xffU) << 0x10U))) & ((
						   ((((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU) 
						     << 8U) 
						    | ((IData)(vlTOPp->N_OE)
						        ? 0U
						        : 0xffU)) 
						   | (((IData)(vlTOPp->N_OE)
						        ? 0U
						        : 0xffU) 
						      << 0x18U)) 
						  | (((IData)(vlTOPp->N_OE)
						       ? 0U
						       : 0xffU) 
						     << 0x10U)));
}

void Vregister32::_eval(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_eval\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void Vregister32::_eval_initial(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_eval_initial\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void Vregister32::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::final\n"); );
    // Variables
    Vregister32__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vregister32::_eval_settle(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_eval_settle\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vregister32::_change_request(Vregister32__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_change_request\n"); );
    Vregister32* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregister32::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
}
#endif // VL_DEBUG

void Vregister32::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister32::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    IN = VL_RAND_RESET_I(32);
    N_OE = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(32);
    register32__DOT__OUT__out__out4 = VL_RAND_RESET_I(32);
    register32__DOT__OUT__out__out5 = VL_RAND_RESET_I(32);
    register32__DOT__OUT__out__out6 = VL_RAND_RESET_I(32);
    register32__DOT__OUT__out__out7 = VL_RAND_RESET_I(32);
    register32__DOT__low16__DOT__low8 = VL_RAND_RESET_I(8);
    register32__DOT__low16__DOT__high8 = VL_RAND_RESET_I(8);
    register32__DOT__high16__DOT__low8 = VL_RAND_RESET_I(8);
    register32__DOT__high16__DOT__high8 = VL_RAND_RESET_I(8);
}
