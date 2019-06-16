// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlut17x8.h for the primary calling header

#include "Vlut17x8.h"
#include "Vlut17x8__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vlut17x8) {
    Vlut17x8__Syms* __restrict vlSymsp = __VlSymsp = new Vlut17x8__Syms(this, name());
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlut17x8::__Vconfigure(Vlut17x8__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vlut17x8::~Vlut17x8() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vlut17x8::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlut17x8::eval\n"); );
    Vlut17x8__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vlut17x8::_eval_initial_loop(Vlut17x8__Syms* __restrict vlSymsp) {
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

void Vlut17x8::_initial__TOP__1(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_initial__TOP__1\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIGW(__Vtemp1,159,0,5);
    // Body
    // INITIAL at lut17x8.v:18
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x68656164U;
    __Vtemp1[2U] = 0x6f6f6b61U;
    __Vtemp1[3U] = 0x6c755f6cU;
    __Vtemp1[4U] = 0x6dU;
    VL_READMEM_W(true,8,131072, 0,5, __Vtemp1, vlTOPp->lut17x8__DOT__mem
		 ,0,~0);
}

VL_INLINE_OPT void Vlut17x8::_sequent__TOP__2(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_sequent__TOP__2\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvval__lut17x8__DOT__mem__v0,7,0);
    VL_SIG(__Vdlyvdim0__lut17x8__DOT__mem__v0,16,0);
    // Body
    // ALWAYS at lut17x8.v:14
    __Vdlyvval__lut17x8__DOT__mem__v0 = vlTOPp->IN_DATA;
    __Vdlyvdim0__lut17x8__DOT__mem__v0 = vlTOPp->ADDR;
    // ALWAYSPOST at lut17x8.v:14
    vlTOPp->lut17x8__DOT__mem[__Vdlyvdim0__lut17x8__DOT__mem__v0] 
	= __Vdlyvval__lut17x8__DOT__mem__v0;
}

VL_INLINE_OPT void Vlut17x8::_settle__TOP__3(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_settle__TOP__3\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT_DATA = ((((IData)(vlTOPp->N_OE) ? 0U
			   : vlTOPp->lut17x8__DOT__mem
			  [vlTOPp->ADDR]) & ((IData)(vlTOPp->N_OE)
					      ? 0U : 0xffU)) 
			& ((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffU));
}

void Vlut17x8::_eval(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_eval\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->N_WE)) & (IData)(vlTOPp->__Vclklast__TOP__N_WE))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_settle__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vlut17x8::_eval_initial(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_eval_initial\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vlut17x8::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::final\n"); );
    // Variables
    Vlut17x8__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlut17x8::_eval_settle(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_eval_settle\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vlut17x8::_change_request(Vlut17x8__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_change_request\n"); );
    Vlut17x8* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlut17x8::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xfffe0000U))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((N_WE & 0xfeU))) {
	Verilated::overWidthError("N_WE");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
}
#endif // VL_DEBUG

void Vlut17x8::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlut17x8::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(17);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    IN_DATA = VL_RAND_RESET_I(8);
    OUT_DATA = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<131072; ++__Vi0) {
	    lut17x8__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
}
