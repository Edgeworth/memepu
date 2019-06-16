// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74LVC162244.h for the primary calling header

#include "Vchip74LVC162244.h"
#include "Vchip74LVC162244__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchip74LVC162244) {
    Vchip74LVC162244__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74LVC162244__Syms(this, name());
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74LVC162244::__Vconfigure(Vchip74LVC162244__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74LVC162244::~Vchip74LVC162244() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74LVC162244::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74LVC162244::eval\n"); );
    Vchip74LVC162244__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74LVC162244::_eval_initial_loop(Vchip74LVC162244__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip74LVC162244::_combo__TOP__1(Vchip74LVC162244__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_combo__TOP__1\n"); );
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT = ((((IData)(vlTOPp->N_OE) ? 0U : (IData)(vlTOPp->IN)) 
		    & ((IData)(vlTOPp->N_OE) ? 0U : 0xffffU)) 
		   & ((IData)(vlTOPp->N_OE) ? 0U : 0xffffU));
}

void Vchip74LVC162244::_eval(Vchip74LVC162244__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_eval\n"); );
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vchip74LVC162244::_eval_initial(Vchip74LVC162244__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_eval_initial\n"); );
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74LVC162244::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::final\n"); );
    // Variables
    Vchip74LVC162244__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74LVC162244::_eval_settle(Vchip74LVC162244__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_eval_settle\n"); );
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vchip74LVC162244::_change_request(Vchip74LVC162244__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_change_request\n"); );
    Vchip74LVC162244* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74LVC162244::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
}
#endif // VL_DEBUG

void Vchip74LVC162244::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74LVC162244::_ctor_var_reset\n"); );
    // Body
    IN = VL_RAND_RESET_I(16);
    N_OE = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(16);
}
