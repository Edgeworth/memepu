// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmlu_lookahead.h for the primary calling header

#include "Vmlu_lookahead.h"
#include "Vmlu_lookahead__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmlu_lookahead) {
    Vmlu_lookahead__Syms* __restrict vlSymsp = __VlSymsp = new Vmlu_lookahead__Syms(this, name());
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmlu_lookahead::__Vconfigure(Vmlu_lookahead__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmlu_lookahead::~Vmlu_lookahead() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmlu_lookahead::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmlu_lookahead::eval\n"); );
    Vmlu_lookahead__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmlu_lookahead::_eval_initial_loop(Vmlu_lookahead__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vmlu_lookahead::_combo__TOP__1(Vmlu_lookahead__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_combo__TOP__1\n"); );
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at mlu_lookahead.v:24
    vlTOPp->mlu_lookahead__DOT__prev_carry = (1U & vlTOPp->ADDR);
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 1U)) 
					       | (vlTOPp->ADDR 
						  >> 9U)));
    vlTOPp->CARRYS = ((0xfeU & (IData)(vlTOPp->CARRYS)) 
		      | (IData)(vlTOPp->mlu_lookahead__DOT__carry));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 2U)) 
					       | (vlTOPp->ADDR 
						  >> 0xaU)));
    vlTOPp->CARRYS = ((0xfdU & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 1U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 3U)) 
					       | (vlTOPp->ADDR 
						  >> 0xbU)));
    vlTOPp->CARRYS = ((0xfbU & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 2U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 4U)) 
					       | (vlTOPp->ADDR 
						  >> 0xcU)));
    vlTOPp->CARRYS = ((0xf7U & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 3U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 5U)) 
					       | (vlTOPp->ADDR 
						  >> 0xdU)));
    vlTOPp->CARRYS = ((0xefU & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 4U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 6U)) 
					       | (vlTOPp->ADDR 
						  >> 0xeU)));
    vlTOPp->CARRYS = ((0xdfU & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 5U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 7U)) 
					       | (vlTOPp->ADDR 
						  >> 0xfU)));
    vlTOPp->CARRYS = ((0xbfU & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 6U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
    vlTOPp->mlu_lookahead__DOT__carry = (1U & (((IData)(vlTOPp->mlu_lookahead__DOT__prev_carry) 
						& (vlTOPp->ADDR 
						   >> 8U)) 
					       | (vlTOPp->ADDR 
						  >> 0x10U)));
    vlTOPp->CARRYS = ((0x7fU & (IData)(vlTOPp->CARRYS)) 
		      | ((IData)(vlTOPp->mlu_lookahead__DOT__carry) 
			 << 7U));
    vlTOPp->mlu_lookahead__DOT__prev_carry = vlTOPp->mlu_lookahead__DOT__carry;
}

void Vmlu_lookahead::_eval(Vmlu_lookahead__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_eval\n"); );
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vmlu_lookahead::_eval_initial(Vmlu_lookahead__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_eval_initial\n"); );
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmlu_lookahead::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::final\n"); );
    // Variables
    Vmlu_lookahead__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmlu_lookahead::_eval_settle(Vmlu_lookahead__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_eval_settle\n"); );
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vmlu_lookahead::_change_request(Vmlu_lookahead__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_change_request\n"); );
    Vmlu_lookahead* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmlu_lookahead::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ADDR & 0xfffe0000U))) {
	Verilated::overWidthError("ADDR");}
    if (VL_UNLIKELY((BOOTSTRAP_ADDR & 0xfffe0000U))) {
	Verilated::overWidthError("BOOTSTRAP_ADDR");}
    if (VL_UNLIKELY((N_BOOTED & 0xfeU))) {
	Verilated::overWidthError("N_BOOTED");}
    if (VL_UNLIKELY((BOOTSTRAP_N_WE & 0xfeU))) {
	Verilated::overWidthError("BOOTSTRAP_N_WE");}
}
#endif // VL_DEBUG

void Vmlu_lookahead::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu_lookahead::_ctor_var_reset\n"); );
    // Body
    ADDR = VL_RAND_RESET_I(17);
    CARRYS = VL_RAND_RESET_I(8);
    BOOTSTRAP_ADDR = VL_RAND_RESET_I(17);
    BOOTSTRAP_DATA = VL_RAND_RESET_I(8);
    N_BOOTED = VL_RAND_RESET_I(1);
    BOOTSTRAP_N_WE = VL_RAND_RESET_I(1);
    mlu_lookahead__DOT__prev_carry = VL_RAND_RESET_I(1);
    mlu_lookahead__DOT__carry = VL_RAND_RESET_I(1);
}
