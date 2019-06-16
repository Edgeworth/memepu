// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmicrocode.h for the primary calling header

#include "Vmicrocode.h"
#include "Vmicrocode__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmicrocode) {
    Vmicrocode__Syms* __restrict vlSymsp = __VlSymsp = new Vmicrocode__Syms(this, name());
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmicrocode::__Vconfigure(Vmicrocode__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmicrocode::~Vmicrocode() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmicrocode::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmicrocode::eval\n"); );
    Vmicrocode__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmicrocode::_eval_initial_loop(Vmicrocode__Syms* __restrict vlSymsp) {
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

void Vmicrocode::_settle__TOP__1(Vmicrocode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_settle__TOP__1\n"); );
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT = (0xfff0ffffU & vlTOPp->OUT);
    vlTOPp->OUT = (0xffcfffffU & vlTOPp->OUT);
    vlTOPp->OUT = (0x7fffffU & vlTOPp->OUT);
    vlTOPp->OUT = ((0xffffffc0U & vlTOPp->OUT) | ((0U 
						   == 
						   (0x3fU 
						    & ((IData)(vlTOPp->ADDR) 
						       >> 5U)))
						   ? 
						  ((0U 
						    == 
						    (0x1fU 
						     & (IData)(vlTOPp->ADDR)))
						    ? 0x1fU
						    : 
						   ((1U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 1U
						     : 0U))
						   : 
						  ((1U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 0x1fU
						     : 
						    ((1U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 0U
						      : 
						     ((2U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 1U
						       : 0U)))
						    : 0U)));
    vlTOPp->OUT = ((0xffffff3fU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 2U
						     : 0U)
						    : 
						   ((1U 
						     == 
						     (0x3fU 
						      & ((IData)(vlTOPp->ADDR) 
							 >> 5U)))
						     ? 
						    ((0U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 2U
						      : 
						     ((1U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 0U
						       : 
						      ((2U 
							== 
							(0x1fU 
							 & (IData)(vlTOPp->ADDR)))
						        ? 2U
						        : 0U)))
						     : 0U)) 
						  << 6U));
    vlTOPp->OUT = ((0xfffff0ffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 0U
						     : 
						    ((1U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 8U
						      : 0U))
						    : 
						   ((1U 
						     == 
						     (0x3fU 
						      & ((IData)(vlTOPp->ADDR) 
							 >> 5U)))
						     ? 
						    ((0U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 1U
						      : 
						     ((1U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 4U
						       : 
						      ((2U 
							== 
							(0x1fU 
							 & (IData)(vlTOPp->ADDR)))
						        ? 1U
						        : 0U)))
						     : 0U)) 
						  << 8U));
    vlTOPp->OUT = ((0xffff8fffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 1U
						     : 
						    ((1U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 6U
						      : 0U))
						    : 
						   ((1U 
						     == 
						     (0x3fU 
						      & ((IData)(vlTOPp->ADDR) 
							 >> 5U)))
						     ? 
						    ((0U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 2U
						      : 
						     ((1U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 5U
						       : 
						      ((2U 
							== 
							(0x1fU 
							 & (IData)(vlTOPp->ADDR)))
						        ? 3U
						        : 0U)))
						     : 0U)) 
						  << 0xcU));
    vlTOPp->OUT = ((0xffff7fffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U))) 
						   & ((0U 
						       != 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR))) 
						      & (1U 
							 == 
							 (0x1fU 
							  & (IData)(vlTOPp->ADDR))))) 
						  << 0xfU));
    vlTOPp->OUT = ((0xffbfffffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U))) 
						   & ((0U 
						       != 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR))) 
						      & (1U 
							 == 
							 (0x1fU 
							  & (IData)(vlTOPp->ADDR))))) 
						  << 0x16U));
}

VL_INLINE_OPT void Vmicrocode::_combo__TOP__2(Vmicrocode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_combo__TOP__2\n"); );
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT = ((0xffffffc0U & vlTOPp->OUT) | ((0U 
						   == 
						   (0x3fU 
						    & ((IData)(vlTOPp->ADDR) 
						       >> 5U)))
						   ? 
						  ((0U 
						    == 
						    (0x1fU 
						     & (IData)(vlTOPp->ADDR)))
						    ? 0x1fU
						    : 
						   ((1U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 1U
						     : 0U))
						   : 
						  ((1U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 0x1fU
						     : 
						    ((1U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 0U
						      : 
						     ((2U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 1U
						       : 0U)))
						    : 0U)));
    vlTOPp->OUT = ((0xffffff3fU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 2U
						     : 0U)
						    : 
						   ((1U 
						     == 
						     (0x3fU 
						      & ((IData)(vlTOPp->ADDR) 
							 >> 5U)))
						     ? 
						    ((0U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 2U
						      : 
						     ((1U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 0U
						       : 
						      ((2U 
							== 
							(0x1fU 
							 & (IData)(vlTOPp->ADDR)))
						        ? 2U
						        : 0U)))
						     : 0U)) 
						  << 6U));
    vlTOPp->OUT = ((0xfffff0ffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 0U
						     : 
						    ((1U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 8U
						      : 0U))
						    : 
						   ((1U 
						     == 
						     (0x3fU 
						      & ((IData)(vlTOPp->ADDR) 
							 >> 5U)))
						     ? 
						    ((0U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 1U
						      : 
						     ((1U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 4U
						       : 
						      ((2U 
							== 
							(0x1fU 
							 & (IData)(vlTOPp->ADDR)))
						        ? 1U
						        : 0U)))
						     : 0U)) 
						  << 8U));
    vlTOPp->OUT = ((0xffff8fffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U)))
						    ? 
						   ((0U 
						     == 
						     (0x1fU 
						      & (IData)(vlTOPp->ADDR)))
						     ? 1U
						     : 
						    ((1U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 6U
						      : 0U))
						    : 
						   ((1U 
						     == 
						     (0x3fU 
						      & ((IData)(vlTOPp->ADDR) 
							 >> 5U)))
						     ? 
						    ((0U 
						      == 
						      (0x1fU 
						       & (IData)(vlTOPp->ADDR)))
						      ? 2U
						      : 
						     ((1U 
						       == 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR)))
						       ? 5U
						       : 
						      ((2U 
							== 
							(0x1fU 
							 & (IData)(vlTOPp->ADDR)))
						        ? 3U
						        : 0U)))
						     : 0U)) 
						  << 0xcU));
    vlTOPp->OUT = ((0xffff7fffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U))) 
						   & ((0U 
						       != 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR))) 
						      & (1U 
							 == 
							 (0x1fU 
							  & (IData)(vlTOPp->ADDR))))) 
						  << 0xfU));
    vlTOPp->OUT = ((0xffbfffffU & vlTOPp->OUT) | ((
						   (0U 
						    == 
						    (0x3fU 
						     & ((IData)(vlTOPp->ADDR) 
							>> 5U))) 
						   & ((0U 
						       != 
						       (0x1fU 
							& (IData)(vlTOPp->ADDR))) 
						      & (1U 
							 == 
							 (0x1fU 
							  & (IData)(vlTOPp->ADDR))))) 
						  << 0x16U));
}

void Vmicrocode::_eval(Vmicrocode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_eval\n"); );
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Vmicrocode::_eval_initial(Vmicrocode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_eval_initial\n"); );
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmicrocode::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::final\n"); );
    // Variables
    Vmicrocode__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmicrocode::_eval_settle(Vmicrocode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_eval_settle\n"); );
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vmicrocode::_change_request(Vmicrocode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_change_request\n"); );
    Vmicrocode* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmicrocode::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xf800U))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((BOOTSTRAP_ADDR & 0xf000U))) {
	Verilated::overWidthError("BOOTSTRAP_ADDR");}
    if (VL_UNLIKELY((N_BOOTED & 0xfeU))) {
	Verilated::overWidthError("N_BOOTED");}
    if (VL_UNLIKELY((BOOTSTRAP_N_WE & 0xfeU))) {
	Verilated::overWidthError("BOOTSTRAP_N_WE");}
}
#endif // VL_DEBUG

void Vmicrocode::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicrocode::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(11);
    OUT = VL_RAND_RESET_I(32);
    BOOTSTRAP_ADDR = VL_RAND_RESET_I(12);
    BOOTSTRAP_DATA = VL_RAND_RESET_I(8);
    N_BOOTED = VL_RAND_RESET_I(1);
    BOOTSTRAP_N_WE = VL_RAND_RESET_I(1);
}
