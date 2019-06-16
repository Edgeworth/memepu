// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip74107.h for the primary calling header

#include "Vchip74107.h"
#include "Vchip74107__Syms.h"


//--------------------
// STATIC VARIABLES

// Begin mtask footprint  all: 
VL_ST_SIG8(Vchip74107::__Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[128],0,0);
VL_ST_SIG8(Vchip74107::__Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[128],0,0);

//--------------------

VL_CTOR_IMP(Vchip74107) {
    Vchip74107__Syms* __restrict vlSymsp = __VlSymsp = new Vchip74107__Syms(this, name());
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchip74107::__Vconfigure(Vchip74107__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchip74107::~Vchip74107() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchip74107::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip74107::eval\n"); );
    Vchip74107__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vchip74107::_eval_initial_loop(Vchip74107__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vchip74107::_combo__TOP__1(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_combo__TOP__1\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1 
	= (1U & (IData)(vlTOPp->N_CP));
    vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2 
	= (1U & (IData)(vlTOPp->N_R));
    vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1 
	= (1U & ((IData)(vlTOPp->N_CP) >> 1U));
    vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2 
	= (1U & ((IData)(vlTOPp->N_R) >> 1U));
}

void Vchip74107::_initial__TOP__3(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_initial__TOP__3\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at chip74107.v:22
    if ((1U & (~ (IData)(vlTOPp->N_R)))) {
	vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data = 0U;
    }
    // INITIAL at chip74107.v:22
    if ((1U & (~ ((IData)(vlTOPp->N_R) >> 1U)))) {
	vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data = 0U;
    }
}

VL_INLINE_OPT void Vchip74107::_sequent__TOP__4(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_sequent__TOP__4\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vtableidx1,6,0);
    // Body
    // ALWAYS at chip74107.v:27
    __Vtableidx1 = (((IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data) 
		     << 6U) | (((IData)(vlTOPp->K) 
				<< 4U) | (((IData)(vlTOPp->J) 
					   << 2U) | (IData)(vlTOPp->N_R))));
    vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data 
	= vlTOPp->__Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data
	[__Vtableidx1];
    vlTOPp->Q = ((2U & (IData)(vlTOPp->Q)) | (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data));
    vlTOPp->N_Q = ((2U & (IData)(vlTOPp->N_Q)) | (1U 
						  & (~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data))));
}

VL_INLINE_OPT void Vchip74107::_sequent__TOP__5(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_sequent__TOP__5\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vtableidx2,6,0);
    // Body
    // ALWAYS at chip74107.v:27
    __Vtableidx2 = (((IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data) 
		     << 6U) | (((IData)(vlTOPp->K) 
				<< 4U) | (((IData)(vlTOPp->J) 
					   << 2U) | (IData)(vlTOPp->N_R))));
    vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data 
	= vlTOPp->__Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data
	[__Vtableidx2];
    vlTOPp->Q = ((1U & (IData)(vlTOPp->Q)) | ((IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data) 
					      << 1U));
    vlTOPp->N_Q = ((1U & (IData)(vlTOPp->N_Q)) | (2U 
						  & ((~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data)) 
						     << 1U)));
}

void Vchip74107::_settle__TOP__6(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_settle__TOP__6\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Q = ((2U & (IData)(vlTOPp->Q)) | (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data));
    vlTOPp->N_Q = ((2U & (IData)(vlTOPp->N_Q)) | (1U 
						  & (~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT__data))));
    vlTOPp->Q = ((1U & (IData)(vlTOPp->Q)) | ((IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data) 
					      << 1U));
    vlTOPp->N_Q = ((1U & (IData)(vlTOPp->N_Q)) | (2U 
						  & ((~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT__data)) 
						     << 1U)));
}

void Vchip74107::_eval(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_eval\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if ((((~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1)) 
	  & (IData)(vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1)) 
	 | ((~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2)) 
	    & (IData)(vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1)) 
	  & (IData)(vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1)) 
	 | ((~ (IData)(vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2)) 
	    & (IData)(vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1 
	= vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2 
	= vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2;
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1 
	= vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2 
	= vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2;
}

void Vchip74107::_eval_initial(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_eval_initial\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1 
	= vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2 
	= vlTOPp->chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2;
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1 
	= vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2 
	= vlTOPp->chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2;
}

void Vchip74107::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::final\n"); );
    // Variables
    Vchip74107__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchip74107::_eval_settle(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_eval_settle\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__6(vlSymsp);
}

VL_INLINE_OPT QData Vchip74107::_change_request(Vchip74107__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_change_request\n"); );
    Vchip74107* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vchip74107::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((J & 0xfcU))) {
	Verilated::overWidthError("J");}
    if (VL_UNLIKELY((K & 0xfcU))) {
	Verilated::overWidthError("K");}
    if (VL_UNLIKELY((N_CP & 0xfcU))) {
	Verilated::overWidthError("N_CP");}
    if (VL_UNLIKELY((N_R & 0xfcU))) {
	Verilated::overWidthError("N_R");}
}
#endif // VL_DEBUG

void Vchip74107::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip74107::_ctor_var_reset\n"); );
    // Body
    J = VL_RAND_RESET_I(2);
    K = VL_RAND_RESET_I(2);
    N_CP = VL_RAND_RESET_I(2);
    N_R = VL_RAND_RESET_I(2);
    Q = VL_RAND_RESET_I(2);
    N_Q = VL_RAND_RESET_I(2);
    chip74107__DOT__genblk1__BRA__0__KET____DOT__data = VL_RAND_RESET_I(1);
    chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr1 = VL_RAND_RESET_I(1);
    chip74107__DOT__genblk1__BRA__0__KET____DOT____Vsenitemexpr2 = VL_RAND_RESET_I(1);
    chip74107__DOT__genblk1__BRA__1__KET____DOT__data = VL_RAND_RESET_I(1);
    chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr1 = VL_RAND_RESET_I(1);
    chip74107__DOT__genblk1__BRA__1__KET____DOT____Vsenitemexpr2 = VL_RAND_RESET_I(1);
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[0] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[1] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[2] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[3] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[4] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[5] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[6] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[7] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[8] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[9] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[10] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[11] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[12] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[13] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[14] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[15] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[16] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[17] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[18] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[19] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[20] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[21] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[22] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[23] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[24] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[25] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[26] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[27] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[28] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[29] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[30] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[31] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[32] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[33] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[34] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[35] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[36] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[37] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[38] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[39] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[40] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[41] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[42] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[43] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[44] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[45] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[46] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[47] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[48] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[49] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[50] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[51] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[52] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[53] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[54] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[55] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[56] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[57] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[58] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[59] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[60] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[61] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[62] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[63] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[64] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[65] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[66] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[67] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[68] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[69] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[70] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[71] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[72] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[73] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[74] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[75] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[76] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[77] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[78] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[79] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[80] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[81] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[82] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[83] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[84] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[85] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[86] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[87] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[88] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[89] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[90] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[91] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[92] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[93] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[94] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[95] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[96] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[97] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[98] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[99] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[100] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[101] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[102] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[103] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[104] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[105] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[106] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[107] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[108] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[109] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[110] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[111] = 1U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[112] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[113] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[114] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[115] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[116] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[117] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[118] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[119] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[120] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[121] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[122] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[123] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[124] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[125] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[126] = 0U;
    __Vtable1_chip74107__DOT__genblk1__BRA__0__KET____DOT__data[127] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[0] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[1] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[2] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[3] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[4] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[5] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[6] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[7] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[8] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[9] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[10] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[11] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[12] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[13] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[14] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[15] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[16] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[17] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[18] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[19] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[20] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[21] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[22] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[23] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[24] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[25] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[26] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[27] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[28] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[29] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[30] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[31] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[32] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[33] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[34] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[35] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[36] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[37] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[38] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[39] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[40] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[41] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[42] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[43] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[44] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[45] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[46] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[47] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[48] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[49] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[50] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[51] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[52] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[53] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[54] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[55] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[56] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[57] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[58] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[59] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[60] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[61] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[62] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[63] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[64] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[65] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[66] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[67] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[68] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[69] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[70] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[71] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[72] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[73] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[74] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[75] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[76] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[77] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[78] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[79] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[80] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[81] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[82] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[83] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[84] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[85] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[86] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[87] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[88] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[89] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[90] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[91] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[92] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[93] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[94] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[95] = 1U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[96] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[97] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[98] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[99] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[100] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[101] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[102] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[103] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[104] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[105] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[106] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[107] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[108] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[109] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[110] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[111] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[112] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[113] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[114] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[115] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[116] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[117] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[118] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[119] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[120] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[121] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[122] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[123] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[124] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[125] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[126] = 0U;
    __Vtable2_chip74107__DOT__genblk1__BRA__1__KET____DOT__data[127] = 0U;
}
