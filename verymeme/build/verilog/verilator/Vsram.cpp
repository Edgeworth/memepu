// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsram.h for the primary calling header

#include "Vsram.h"
#include "Vsram__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsram) {
    Vsram__Syms* __restrict vlSymsp = __VlSymsp = new Vsram__Syms(this, name());
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(sram, Vsram_sram);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsram::__Vconfigure(Vsram__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsram::~Vsram() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsram::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsram::eval\n"); );
    Vsram__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vsram::_eval_initial_loop(Vsram__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vsram::_settle__TOP__1(Vsram__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_settle__TOP__1\n"); );
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT_DATA = ((((IData)(vlTOPp->N_OE) ? 0U
			   : vlSymsp->TOP__sram.mem
			  [vlTOPp->ADDR]) & ((IData)(vlTOPp->N_OE)
					      ? 0U : 0xffU)) 
			& ((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffU));
}

void Vsram::_eval(Vsram__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_eval\n"); );
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->N_WE)) & (IData)(vlTOPp->__Vclklast__TOP__N_WE))) {
	vlSymsp->TOP__sram._sequent__TOP__sram__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__1(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vsram::_eval_initial(Vsram__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_eval_initial\n"); );
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vsram::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::final\n"); );
    // Variables
    Vsram__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsram::_eval_settle(Vsram__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_eval_settle\n"); );
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vsram::_change_request(Vsram__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_change_request\n"); );
    Vsram* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsram::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xfcU))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((N_WE & 0xfeU))) {
	Verilated::overWidthError("N_WE");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vsram::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(2);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    IN_DATA = VL_RAND_RESET_I(8);
    N_RST = VL_RAND_RESET_I(1);
    OUT_DATA = VL_RAND_RESET_I(8);
}
