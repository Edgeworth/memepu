// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmlu.h for the primary calling header

#include "Vmlu.h"
#include "Vmlu__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vmlu) {
    Vmlu__Syms* __restrict vlSymsp = __VlSymsp = new Vmlu__Syms(this, name());
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmlu::__Vconfigure(Vmlu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmlu::~Vmlu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmlu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmlu::eval\n"); );
    Vmlu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmlu::_eval_initial_loop(Vmlu__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vmlu::_combo__TOP__1(Vmlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_combo__TOP__1\n"); );
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Z = (1U & ((IData)(vlTOPp->mlu__DOT____Vcellout__and_level1__Y) 
		       >> 2U));
    // ALWAYS at mlu_lookahead.v:24
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = 
	(1U & vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR);
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 1U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 9U)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfeU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | (IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 2U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0xaU)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfdU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 1U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 3U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0xbU)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfbU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 2U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 4U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0xcU)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xf7U & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 3U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 5U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0xdU)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xefU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 4U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 6U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0xeU)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xdfU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 5U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 7U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0xfU)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xbfU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 6U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__lookahead__DOT__carry = (1U & 
					       (((IData)(vlTOPp->mlu__DOT__lookahead__DOT__prev_carry) 
						 & (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						    >> 8U)) 
						| (vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR 
						   >> 0x10U)));
    vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0x7fU & (IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlTOPp->mlu__DOT__lookahead__DOT__carry) 
	      << 7U));
    vlTOPp->mlu__DOT__lookahead__DOT__prev_carry = vlTOPp->mlu__DOT__lookahead__DOT__carry;
    vlTOPp->mlu__DOT__carrys = ((0x1feU & (IData)(vlTOPp->mlu__DOT__carrys)) 
				| (IData)(vlTOPp->C_IN));
    vlTOPp->mlu__DOT__carrys = ((1U & (IData)(vlTOPp->mlu__DOT__carrys)) 
				| ((IData)(vlTOPp->mlu__DOT____Vcellout__lookahead__CARRYS) 
				   << 1U));
    vlTOPp->C = (1U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		       >> 8U));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 0xbU)) | (((IData)(vlTOPp->OP) 
				    << 8U) | ((0xf0U 
					       & (vlTOPp->B 
						  << 4U)) 
					      | (0xfU 
						 & vlTOPp->A))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 0xaU)) | (((IData)(vlTOPp->OP) 
				    << 8U) | ((0xf0U 
					       & vlTOPp->B) 
					      | (0xfU 
						 & (vlTOPp->A 
						    >> 4U)))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 9U)) | (((IData)(vlTOPp->OP) 
				  << 8U) | ((0xf0U 
					     & (vlTOPp->B 
						>> 4U)) 
					    | (0xfU 
					       & (vlTOPp->A 
						  >> 8U)))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 8U)) | (((IData)(vlTOPp->OP) 
				  << 8U) | ((0xf0U 
					     & (vlTOPp->B 
						>> 8U)) 
					    | (0xfU 
					       & (vlTOPp->A 
						  >> 0xcU)))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 7U)) | (((IData)(vlTOPp->OP) 
				  << 8U) | ((0xf0U 
					     & (vlTOPp->B 
						>> 0xcU)) 
					    | (0xfU 
					       & (vlTOPp->A 
						  >> 0x10U)))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 6U)) | (((IData)(vlTOPp->OP) 
				  << 8U) | ((0xf0U 
					     & (vlTOPp->B 
						>> 0x10U)) 
					    | (0xfU 
					       & (vlTOPp->A 
						  >> 0x14U)))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 5U)) | (((IData)(vlTOPp->OP) 
				  << 8U) | ((0xf0U 
					     & (vlTOPp->B 
						>> 0x14U)) 
					    | (0xfU 
					       & (vlTOPp->A 
						  >> 0x18U)))));
    vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlTOPp->mlu__DOT__carrys) 
		      << 4U)) | (((IData)(vlTOPp->OP) 
				  << 8U) | ((0xf0U 
					     & (vlTOPp->B 
						>> 0x18U)) 
					    | (0xfU 
					       & (vlTOPp->A 
						  >> 0x1cU)))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop = 0U;
    vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				    + ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						  | ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlTOPp->mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlTOPp->mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low))));
    vlTOPp->mlu__DOT__slice_g = ((0xfeU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (1U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
					  >> 5U)));
    vlTOPp->mlu__DOT__slice_p = ((0xfeU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (1U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
					  >> 4U)));
    vlTOPp->OUT = ((0xfffffff0U & vlTOPp->OUT) | (0xfU 
						  & (IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT)));
    vlTOPp->mlu__DOT__slice_z = ((0xfeU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (1U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
					  >> 6U)));
    vlTOPp->mlu__DOT__slice_g = ((0xfdU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (2U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
					  >> 4U)));
    vlTOPp->mlu__DOT__slice_p = ((0xfdU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (2U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
					  >> 3U)));
    vlTOPp->OUT = ((0xffffff0fU & vlTOPp->OUT) | (0xf0U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
						     << 4U)));
    vlTOPp->mlu__DOT__slice_z = ((0xfdU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (2U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
					  >> 5U)));
    vlTOPp->mlu__DOT__slice_g = ((0xfbU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (4U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
					  >> 3U)));
    vlTOPp->mlu__DOT__slice_p = ((0xfbU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (4U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
					  >> 2U)));
    vlTOPp->OUT = ((0xfffff0ffU & vlTOPp->OUT) | (0xf00U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
						     << 8U)));
    vlTOPp->mlu__DOT__slice_z = ((0xfbU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (4U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
					  >> 4U)));
    vlTOPp->mlu__DOT__slice_g = ((0xf7U & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (8U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
					  >> 2U)));
    vlTOPp->mlu__DOT__slice_p = ((0xf7U & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (8U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
					  >> 1U)));
    vlTOPp->OUT = ((0xffff0fffU & vlTOPp->OUT) | (0xf000U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
						     << 0xcU)));
    vlTOPp->mlu__DOT__slice_z = ((0xf7U & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (8U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
					  >> 3U)));
    vlTOPp->mlu__DOT__slice_g = ((0xefU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (0x10U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
					     >> 1U)));
    vlTOPp->mlu__DOT__slice_p = ((0xefU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (0x10U & (IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT)));
    vlTOPp->OUT = ((0xfff0ffffU & vlTOPp->OUT) | (0xf0000U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
						     << 0x10U)));
    vlTOPp->mlu__DOT__slice_z = ((0xefU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (0x10U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
					     >> 2U)));
    vlTOPp->mlu__DOT__slice_g = ((0xdfU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (0x20U & (IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT)));
    vlTOPp->mlu__DOT__slice_p = ((0xdfU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (0x20U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
					     << 1U)));
    vlTOPp->OUT = ((0xff0fffffU & vlTOPp->OUT) | (0xf00000U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
						     << 0x14U)));
    vlTOPp->mlu__DOT__slice_z = ((0xdfU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (0x20U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
					     >> 1U)));
    vlTOPp->mlu__DOT__slice_g = ((0xbfU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (0x40U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
					     << 1U)));
    vlTOPp->mlu__DOT__slice_p = ((0xbfU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (0x40U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
					     << 2U)));
    vlTOPp->OUT = ((0xf0ffffffU & vlTOPp->OUT) | (0xf000000U 
						  & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
						     << 0x18U)));
    vlTOPp->mlu__DOT__slice_z = ((0xbfU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (0x40U & (IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT)));
    vlTOPp->mlu__DOT__slice_g = ((0x7fU & (IData)(vlTOPp->mlu__DOT__slice_g)) 
				 | (0x80U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
					     << 2U)));
    vlTOPp->mlu__DOT__slice_p = ((0x7fU & (IData)(vlTOPp->mlu__DOT__slice_p)) 
				 | (0x80U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
					     << 3U)));
    vlTOPp->OUT = ((0xfffffffU & vlTOPp->OUT) | (0xf0000000U 
						 & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
						    << 0x1cU)));
    vlTOPp->mlu__DOT__slice_z = ((0x7fU & (IData)(vlTOPp->mlu__DOT__slice_z)) 
				 | (0x80U & ((IData)(vlTOPp->mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
					     << 1U)));
    vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR = 
	(((IData)(vlTOPp->mlu__DOT__slice_g) << 9U) 
	 | (((IData)(vlTOPp->mlu__DOT__slice_p) << 1U) 
	    | (IData)(vlTOPp->C_IN)));
    vlTOPp->N = (1U & (vlTOPp->OUT >> 0x1fU));
    vlTOPp->mlu__DOT__z_level0 = (0xfU & ((IData)(vlTOPp->mlu__DOT__slice_z) 
					  & ((IData)(vlTOPp->mlu__DOT__slice_z) 
					     >> 4U)));
    vlTOPp->mlu__DOT____Vcellinp__and_level1__B = (
						   (4U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellout__and_level1__Y) 
						       << 1U)) 
						   | (3U 
						      & ((IData)(vlTOPp->mlu__DOT__z_level0) 
							 >> 2U)));
    vlTOPp->mlu__DOT____Vcellinp__and_level1__A = (
						   (4U 
						    & ((IData)(vlTOPp->mlu__DOT____Vcellout__and_level1__Y) 
						       << 2U)) 
						   | (3U 
						      & (IData)(vlTOPp->mlu__DOT__z_level0)));
    vlTOPp->mlu__DOT____Vcellout__and_level1__Y = ((IData)(vlTOPp->mlu__DOT____Vcellinp__and_level1__A) 
						   & (IData)(vlTOPp->mlu__DOT____Vcellinp__and_level1__B));
}

void Vmlu::_eval(Vmlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_eval\n"); );
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vmlu::_eval_initial(Vmlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_eval_initial\n"); );
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmlu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::final\n"); );
    // Variables
    Vmlu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmlu::_eval_settle(Vmlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_eval_settle\n"); );
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vmlu::_change_request(Vmlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_change_request\n"); );
    Vmlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR ^ vlTOPp->__Vchglast__TOP__mlu__DOT____Vcellinp__lookahead__ADDR)
	 | (vlTOPp->mlu__DOT____Vcellout__and_level1__Y ^ vlTOPp->__Vchglast__TOP__mlu__DOT____Vcellout__and_level1__Y));
    VL_DEBUG_IF( if(__req && ((vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR ^ vlTOPp->__Vchglast__TOP__mlu__DOT____Vcellinp__lookahead__ADDR))) VL_DBG_MSGF("        CHANGE: mlu_lookahead.v:4: mlu.__Vcellinp__lookahead__ADDR\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->mlu__DOT____Vcellout__and_level1__Y ^ vlTOPp->__Vchglast__TOP__mlu__DOT____Vcellout__and_level1__Y))) VL_DBG_MSGF("        CHANGE: chip7408.v:7: mlu.__Vcellout__and_level1__Y\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__mlu__DOT____Vcellinp__lookahead__ADDR 
	= vlTOPp->mlu__DOT____Vcellinp__lookahead__ADDR;
    vlTOPp->__Vchglast__TOP__mlu__DOT____Vcellout__and_level1__Y 
	= vlTOPp->mlu__DOT____Vcellout__and_level1__Y;
    return __req;
}

#ifdef VL_DEBUG
void Vmlu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((OP & 0xf8U))) {
	Verilated::overWidthError("OP");}
    if (VL_UNLIKELY((C_IN & 0xfeU))) {
	Verilated::overWidthError("C_IN");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
    if (VL_UNLIKELY((BOOTSTRAP_ADDR & 0xfffe0000U))) {
	Verilated::overWidthError("BOOTSTRAP_ADDR");}
    if (VL_UNLIKELY((N_BOOTED & 0xfeU))) {
	Verilated::overWidthError("N_BOOTED");}
    if (VL_UNLIKELY((BOOTSTRAP_MLU_SLICE_N_WE & 0xfeU))) {
	Verilated::overWidthError("BOOTSTRAP_MLU_SLICE_N_WE");}
    if (VL_UNLIKELY((BOOTSTRAP_MLU_LOOKAHEAD_N_WE & 0xfeU))) {
	Verilated::overWidthError("BOOTSTRAP_MLU_LOOKAHEAD_N_WE");}
}
#endif // VL_DEBUG

void Vmlu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmlu::_ctor_var_reset\n"); );
    // Body
    A = VL_RAND_RESET_I(32);
    B = VL_RAND_RESET_I(32);
    OP = VL_RAND_RESET_I(3);
    C_IN = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(32);
    Z = VL_RAND_RESET_I(1);
    C = VL_RAND_RESET_I(1);
    N = VL_RAND_RESET_I(1);
    BOOTSTRAP_DATA = VL_RAND_RESET_I(8);
    BOOTSTRAP_ADDR = VL_RAND_RESET_I(17);
    N_BOOTED = VL_RAND_RESET_I(1);
    BOOTSTRAP_MLU_SLICE_N_WE = VL_RAND_RESET_I(1);
    BOOTSTRAP_MLU_LOOKAHEAD_N_WE = VL_RAND_RESET_I(1);
    mlu__DOT__slice_p = VL_RAND_RESET_I(8);
    mlu__DOT__slice_g = VL_RAND_RESET_I(8);
    mlu__DOT__slice_z = VL_RAND_RESET_I(8);
    mlu__DOT__carrys = VL_RAND_RESET_I(9);
    mlu__DOT____Vcellout__lookahead__CARRYS = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__lookahead__ADDR = VL_RAND_RESET_I(17);
    mlu__DOT__z_level0 = VL_RAND_RESET_I(4);
    mlu__DOT____Vcellout__and_level1__Y = VL_RAND_RESET_I(4);
    mlu__DOT____Vcellinp__and_level1__B = VL_RAND_RESET_I(4);
    mlu__DOT____Vcellinp__and_level1__A = VL_RAND_RESET_I(4);
    mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR = VL_RAND_RESET_I(12);
    mlu__DOT__lookahead__DOT__prev_carry = VL_RAND_RESET_I(1);
    mlu__DOT__lookahead__DOT__carry = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __Vchglast__TOP__mlu__DOT____Vcellinp__lookahead__ADDR = VL_RAND_RESET_I(17);
    __Vchglast__TOP__mlu__DOT____Vcellout__and_level1__Y = VL_RAND_RESET_I(4);
}
