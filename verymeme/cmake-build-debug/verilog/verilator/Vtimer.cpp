// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtimer.h for the primary calling header

#include "Vtimer.h"
#include "Vtimer__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtimer) {
    Vtimer__Syms* __restrict vlSymsp = __VlSymsp = new Vtimer__Syms(this, name());
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtimer::__Vconfigure(Vtimer__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtimer::~Vtimer() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtimer::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtimer::eval\n"); );
    Vtimer__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vtimer::_eval_initial_loop(Vtimer__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vtimer::_sequent__TOP__1(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_sequent__TOP__1\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((0x80U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((0x40U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((0x20U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((0x10U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((8U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((4U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((2U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlTOPp->N_RST) {
	if ((1U & (IData)(vlTOPp->timer__DOT__rco))) {
	    vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count = 0U;
    }
    vlTOPp->TIME = ((0xfffffffU & vlTOPp->TIME) | ((IData)(vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count) 
						   << 0x1cU));
    vlTOPp->TIME = ((0xf0ffffffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count) 
		     << 0x18U));
    vlTOPp->TIME = ((0xff0fffffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count) 
		     << 0x14U));
    vlTOPp->TIME = ((0xfff0ffffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count) 
		     << 0x10U));
    vlTOPp->TIME = ((0xffff0fffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count) 
		     << 0xcU));
    vlTOPp->TIME = ((0xfffff0ffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count) 
		     << 8U));
    vlTOPp->TIME = ((0xffffff0fU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count) 
		     << 4U));
    vlTOPp->TIME = ((0xfffffff0U & vlTOPp->TIME) | (IData)(vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count));
}

void Vtimer::_settle__TOP__2(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_settle__TOP__2\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->timer__DOT__rco = (1U | (IData)(vlTOPp->timer__DOT__rco));
    vlTOPp->TIME = ((0xfffffff0U & vlTOPp->TIME) | (IData)(vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count));
    vlTOPp->TIME = ((0xffffff0fU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count) 
		     << 4U));
    vlTOPp->TIME = ((0xfffff0ffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count) 
		     << 8U));
    vlTOPp->TIME = ((0xffff0fffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count) 
		     << 0xcU));
    vlTOPp->TIME = ((0xfff0ffffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count) 
		     << 0x10U));
    vlTOPp->TIME = ((0xff0fffffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count) 
		     << 0x14U));
    vlTOPp->TIME = ((0xf0ffffffU & vlTOPp->TIME) | 
		    ((IData)(vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count) 
		     << 0x18U));
    vlTOPp->TIME = ((0xfffffffU & vlTOPp->TIME) | ((IData)(vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count) 
						   << 0x1cU));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO 
	= (1U & (((IData)(vlTOPp->timer__DOT__rco) 
		  & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 1U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 2U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 3U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 4U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 5U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 6U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 7U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT__rco = ((0x1fdU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO) 
				  << 1U));
    vlTOPp->timer__DOT__rco = ((0x1fbU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO) 
				  << 2U));
    vlTOPp->timer__DOT__rco = ((0x1f7U & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO) 
				  << 3U));
    vlTOPp->timer__DOT__rco = ((0x1efU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO) 
				  << 4U));
    vlTOPp->timer__DOT__rco = ((0x1dfU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO) 
				  << 5U));
    vlTOPp->timer__DOT__rco = ((0x1bfU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO) 
				  << 6U));
    vlTOPp->timer__DOT__rco = ((0x17fU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO) 
				  << 7U));
    vlTOPp->timer__DOT__rco = ((0xffU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO) 
				  << 8U));
}

VL_INLINE_OPT void Vtimer::_combo__TOP__3(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_combo__TOP__3\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 7U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 6U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 5U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 4U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 3U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 2U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlTOPp->timer__DOT__rco) 
		   >> 1U) & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO 
	= (1U & (((IData)(vlTOPp->timer__DOT__rco) 
		  & (0xfU == (IData)(vlTOPp->timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlTOPp->timer__DOT__rco = ((0xffU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO) 
				  << 8U));
    vlTOPp->timer__DOT__rco = ((0x17fU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO) 
				  << 7U));
    vlTOPp->timer__DOT__rco = ((0x1bfU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO) 
				  << 6U));
    vlTOPp->timer__DOT__rco = ((0x1dfU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO) 
				  << 5U));
    vlTOPp->timer__DOT__rco = ((0x1efU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO) 
				  << 4U));
    vlTOPp->timer__DOT__rco = ((0x1f7U & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO) 
				  << 3U));
    vlTOPp->timer__DOT__rco = ((0x1fbU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO) 
				  << 2U));
    vlTOPp->timer__DOT__rco = ((0x1fdU & (IData)(vlTOPp->timer__DOT__rco)) 
			       | ((IData)(vlTOPp->timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO) 
				  << 1U));
}

void Vtimer::_eval(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_eval\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	 | ((~ (IData)(vlTOPp->N_RST)) & (IData)(vlTOPp->__Vclklast__TOP__N_RST)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_RST = vlTOPp->N_RST;
}

void Vtimer::_eval_initial(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_eval_initial\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_RST = vlTOPp->N_RST;
}

void Vtimer::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::final\n"); );
    // Variables
    Vtimer__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtimer::_eval_settle(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_eval_settle\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vtimer::_change_request(Vtimer__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_change_request\n"); );
    Vtimer* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->timer__DOT__rco ^ vlTOPp->__Vchglast__TOP__timer__DOT__rco));
    VL_DEBUG_IF( if(__req && ((vlTOPp->timer__DOT__rco ^ vlTOPp->__Vchglast__TOP__timer__DOT__rco))) VL_DBG_MSGF("        CHANGE: timer.v:10: timer.rco\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__timer__DOT__rco = vlTOPp->timer__DOT__rco;
    return __req;
}

#ifdef VL_DEBUG
void Vtimer::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vtimer::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    TIME = VL_RAND_RESET_I(32);
    timer__DOT__rco = VL_RAND_RESET_I(9);
    timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __Vchglast__TOP__timer__DOT__rco = VL_RAND_RESET_I(9);
}
