// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmmu.h for the primary calling header

#include "Vmmu.h"
#include "Vmmu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmmu) {
    Vmmu__Syms* __restrict vlSymsp = __VlSymsp = new Vmmu__Syms(this, name());
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(mmu, Vmmu_mmu);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmmu::__Vconfigure(Vmmu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmmu::~Vmmu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmmu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmmu::eval\n"); );
    Vmmu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmmu::_eval_initial_loop(Vmmu__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vmmu::_settle__TOP__1(Vmmu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_settle__TOP__1\n"); );
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT = (((((IData)(vlTOPp->N_OE) ? 0U : 
		      vlSymsp->TOP__mmu__ram.mem[(0x3ffU 
						  & vlTOPp->ADDR)]) 
		     & ((IData)(vlTOPp->N_OE) ? 0U : 0xffffffffU)) 
		    & ((IData)(vlTOPp->N_OE) ? 0U : 0xffffffffU)) 
		   & ((IData)(vlTOPp->N_OE) ? 0U : 0xffffffffU));
}

void Vmmu::_eval(Vmmu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_eval\n"); );
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->N_WE)) & (IData)(vlTOPp->__Vclklast__TOP__N_WE))) {
	vlSymsp->TOP__mmu__ram._sequent__TOP__mmu__ram__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__1(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vmmu::_eval_initial(Vmmu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_eval_initial\n"); );
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vmmu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::final\n"); );
    // Variables
    Vmmu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmmu::_eval_settle(Vmmu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_eval_settle\n"); );
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vmmu::_change_request(Vmmu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_change_request\n"); );
    Vmmu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmmu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((N_WE & 0xfeU))) {
	Verilated::overWidthError("N_WE");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vmmu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmmu::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(32);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    IN = VL_RAND_RESET_I(32);
    OUT = VL_RAND_RESET_I(32);
}
