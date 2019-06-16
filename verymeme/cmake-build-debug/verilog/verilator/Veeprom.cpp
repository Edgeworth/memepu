// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Veeprom.h for the primary calling header

#include "Veeprom.h"
#include "Veeprom__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Veeprom) {
    Veeprom__Syms* __restrict vlSymsp = __VlSymsp = new Veeprom__Syms(this, name());
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Veeprom::__Vconfigure(Veeprom__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Veeprom::~Veeprom() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Veeprom::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Veeprom::eval\n"); );
    Veeprom__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Veeprom::_eval_initial_loop(Veeprom__Syms* __restrict vlSymsp) {
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

void Veeprom::_initial__TOP__1(Veeprom__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_initial__TOP__1\n"); );
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIGW(__Vtemp1,95,0,3);
    // Body
    // INITIAL at eeprom.v:14
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x726d616cU;
    __Vtemp1[2U] = 0x666fU;
    VL_READMEM_W(true,8,4, 0,3, __Vtemp1, vlTOPp->eeprom__DOT__mem
		 ,0,~0);
}

VL_INLINE_OPT void Veeprom::_combo__TOP__2(Veeprom__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_combo__TOP__2\n"); );
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT_DATA = ((((IData)(vlTOPp->N_OE) ? 0U
			   : vlTOPp->eeprom__DOT__mem
			  [vlTOPp->ADDR]) & ((IData)(vlTOPp->N_OE)
					      ? 0U : 0xffU)) 
			& ((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffU));
}

void Veeprom::_eval(Veeprom__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_eval\n"); );
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Veeprom::_eval_initial(Veeprom__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_eval_initial\n"); );
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Veeprom::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::final\n"); );
    // Variables
    Veeprom__Syms* __restrict vlSymsp = this->__VlSymsp;
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Veeprom::_eval_settle(Veeprom__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_eval_settle\n"); );
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Veeprom::_change_request(Veeprom__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_change_request\n"); );
    Veeprom* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Veeprom::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xfcU))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
}
#endif // VL_DEBUG

void Veeprom::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Veeprom::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(2);
    N_OE = VL_RAND_RESET_I(1);
    OUT_DATA = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    eeprom__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
}
