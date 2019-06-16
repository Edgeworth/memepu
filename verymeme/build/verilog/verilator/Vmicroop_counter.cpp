// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmicroop_counter.h for the primary calling header

#include "Vmicroop_counter.h"
#include "Vmicroop_counter__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmicroop_counter) {
    Vmicroop_counter__Syms* __restrict vlSymsp = __VlSymsp = new Vmicroop_counter__Syms(this, name());
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmicroop_counter::__Vconfigure(Vmicroop_counter__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmicroop_counter::~Vmicroop_counter() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmicroop_counter::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmicroop_counter::eval\n"); );
    Vmicroop_counter__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmicroop_counter::_eval_initial_loop(Vmicroop_counter__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vmicroop_counter::_sequent__TOP__1(Vmicroop_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_sequent__TOP__1\n"); );
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74590.v:13
    vlTOPp->microop_counter__DOT__counter__DOT__count 
	= (0xffU & ((IData)(vlTOPp->N_RST) ? ((IData)(1U) 
					      + (IData)(vlTOPp->microop_counter__DOT__counter__DOT__count))
		     : 0U));
    vlTOPp->COUNT = (0x1fU & (IData)(vlTOPp->microop_counter__DOT__counter__DOT__count));
}

void Vmicroop_counter::_settle__TOP__2(Vmicroop_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_settle__TOP__2\n"); );
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->COUNT = (0x1fU & (IData)(vlTOPp->microop_counter__DOT__counter__DOT__count));
}

void Vmicroop_counter::_eval(Vmicroop_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_eval\n"); );
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	 | ((~ (IData)(vlTOPp->N_RST)) & (IData)(vlTOPp->__Vclklast__TOP__N_RST)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_RST = vlTOPp->N_RST;
}

void Vmicroop_counter::_eval_initial(Vmicroop_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_eval_initial\n"); );
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_RST = vlTOPp->N_RST;
}

void Vmicroop_counter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::final\n"); );
    // Variables
    Vmicroop_counter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmicroop_counter::_eval_settle(Vmicroop_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_eval_settle\n"); );
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vmicroop_counter::_change_request(Vmicroop_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_change_request\n"); );
    Vmicroop_counter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmicroop_counter::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vmicroop_counter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmicroop_counter::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    COUNT = VL_RAND_RESET_I(5);
    microop_counter__DOT__counter__DOT__count = VL_RAND_RESET_I(8);
}
