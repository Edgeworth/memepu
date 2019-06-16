// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshifter.h for the primary calling header

#include "Vshifter.h"
#include "Vshifter__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vshifter) {
    Vshifter__Syms* __restrict vlSymsp = __VlSymsp = new Vshifter__Syms(this, name());
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vshifter::__Vconfigure(Vshifter__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vshifter::~Vshifter() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vshifter::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vshifter::eval\n"); );
    Vshifter__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vshifter::_eval_initial_loop(Vshifter__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vshifter::_combo__TOP__1(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_combo__TOP__1\n"); );
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->shifter__DOT____Vcellout__ander__Y = (1U 
						  & ((IData)(vlTOPp->ARITH) 
						     & (vlTOPp->IN 
							>> 0x1fU)));
    vlTOPp->shifter__DOT____Vcellinp__pre_reverse_mux__B 
	= ((0x80000000U & (vlTOPp->IN << 0x1fU)) | 
	   ((0x40000000U & (vlTOPp->IN << 0x1dU)) | 
	    ((0x20000000U & (vlTOPp->IN << 0x1bU)) 
	     | ((0x10000000U & (vlTOPp->IN << 0x19U)) 
		| ((0x8000000U & (vlTOPp->IN << 0x17U)) 
		   | ((0x4000000U & (vlTOPp->IN << 0x15U)) 
		      | ((0x2000000U & (vlTOPp->IN 
					<< 0x13U)) 
			 | ((0x1000000U & (vlTOPp->IN 
					   << 0x11U)) 
			    | ((0x800000U & (vlTOPp->IN 
					     << 0xfU)) 
			       | ((0x400000U & (vlTOPp->IN 
						<< 0xdU)) 
				  | ((0x200000U & (vlTOPp->IN 
						   << 0xbU)) 
				     | ((0x100000U 
					 & (vlTOPp->IN 
					    << 9U)) 
					| ((0x80000U 
					    & (vlTOPp->IN 
					       << 7U)) 
					   | ((0x40000U 
					       & (vlTOPp->IN 
						  << 5U)) 
					      | ((0x20000U 
						  & (vlTOPp->IN 
						     << 3U)) 
						 | ((0x10000U 
						     & (vlTOPp->IN 
							<< 1U)) 
						    | ((0x8000U 
							& (vlTOPp->IN 
							   >> 1U)) 
						       | ((0x4000U 
							   & (vlTOPp->IN 
							      >> 3U)) 
							  | ((0x2000U 
							      & (vlTOPp->IN 
								 >> 5U)) 
							     | ((0x1000U 
								 & (vlTOPp->IN 
								    >> 7U)) 
								| ((0x800U 
								    & (vlTOPp->IN 
								       >> 9U)) 
								   | ((0x400U 
								       & (vlTOPp->IN 
									  >> 0xbU)) 
								      | ((0x200U 
									  & (vlTOPp->IN 
									     >> 0xdU)) 
									 | ((0x100U 
									     & (vlTOPp->IN 
										>> 0xfU)) 
									    | ((0x80U 
										& (vlTOPp->IN 
										>> 0x11U)) 
									       | ((0x40U 
										& (vlTOPp->IN 
										>> 0x13U)) 
										| ((0x20U 
										& (vlTOPp->IN 
										>> 0x15U)) 
										| ((0x10U 
										& (vlTOPp->IN 
										>> 0x17U)) 
										| ((8U 
										& (vlTOPp->IN 
										>> 0x19U)) 
										| ((4U 
										& (vlTOPp->IN 
										>> 0x1bU)) 
										| ((2U 
										& (vlTOPp->IN 
										>> 0x1dU)) 
										| (1U 
										& (vlTOPp->IN 
										>> 0x1fU)))))))))))))))))))))))))))))))));
    vlTOPp->shifter__DOT____Vcellinp__notter__A = (
						   ((IData)(vlTOPp->LEFT) 
						    << 5U) 
						   | (IData)(vlTOPp->SHFT));
    vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((IData)(vlTOPp->LEFT) ? 0U : vlTOPp->shifter__DOT____Vcellinp__pre_reverse_mux__B) 
	      & ((IData)(vlTOPp->LEFT) ? 0U : 0xffffU)));
    vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((IData)(vlTOPp->LEFT) ? 0U : (vlTOPp->shifter__DOT____Vcellinp__pre_reverse_mux__B 
					      >> 0x10U)) 
	       & ((IData)(vlTOPp->LEFT) ? 0U : 0xffffU)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->IN : 0U) & ((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				       ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->IN >> 0x10U) : 0U) & ((0x20U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__pre_reverse = ((IData)(vlTOPp->LEFT)
					  ? (((vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
					       & ((0x20U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U)) 
					      | (vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
						 & (((0x20U 
						      & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U) 
						    << 0x10U))) 
					     & (((0x20U 
						  & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						  ? 0xffffU
						  : 0U) 
						| (((0x20U 
						     & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   << 0x10U)))
					  : (((vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
					       & ((IData)(vlTOPp->LEFT)
						   ? 0U
						   : 0xffffU)) 
					      | (vlTOPp->shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
						 & (((IData)(vlTOPp->LEFT)
						      ? 0U
						      : 0xffffU) 
						    << 0x10U))) 
					     & (((IData)(vlTOPp->LEFT)
						  ? 0U
						  : 0xffffU) 
						| (((IData)(vlTOPp->LEFT)
						     ? 0U
						     : 0xffffU) 
						   << 0x10U))));
    vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((1U & (IData)(vlTOPp->SHFT)) ? 0U : vlTOPp->shifter__DOT__pre_reverse) 
	      & ((1U & (IData)(vlTOPp->SHFT)) ? 0U : 0xffffU)));
    vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((1U & (IData)(vlTOPp->SHFT)) ? 0U : 
		(vlTOPp->shifter__DOT__pre_reverse 
		 >> 0x10U)) & ((1U & (IData)(vlTOPp->SHFT))
			        ? 0U : 0xffffU)) << 0x10U));
    vlTOPp->shifter__DOT____Vcellinp__shift_left_mux0__A 
	= ((0xfffffffeU & (vlTOPp->shifter__DOT__pre_reverse 
			   << 1U)) | (1U & (IData)(vlTOPp->shifter__DOT____Vcellout__ander__Y)));
    vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((1U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->shifter__DOT____Vcellinp__shift_left_mux0__A
	        : 0U) & ((1U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((1U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->shifter__DOT____Vcellinp__shift_left_mux0__A 
		    >> 0x10U) : 0U) & ((1U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__stage[0U] = ((1U & (IData)(vlTOPp->SHFT))
				        ? (((vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 
					     & ((1U 
						 & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						 ? 0xffffU
						 : 0U)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 
					       & (((1U 
						    & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						    ? 0xffffU
						    : 0U) 
						  << 0x10U))) 
					   & (((1U 
						& (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
					        ? 0xffffU
					        : 0U) 
					      | (((1U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U) 
						 << 0x10U)))
				        : (((vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 
					     & ((1U 
						 & (IData)(vlTOPp->SHFT))
						 ? 0U
						 : 0xffffU)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 
					       & (((1U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU) 
						  << 0x10U))) 
					   & (((1U 
						& (IData)(vlTOPp->SHFT))
					        ? 0U
					        : 0xffffU) 
					      | (((1U 
						   & (IData)(vlTOPp->SHFT))
						   ? 0U
						   : 0xffffU) 
						 << 0x10U))));
    vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((2U & (IData)(vlTOPp->SHFT)) ? 0U : 
	       vlTOPp->shifter__DOT__stage[0U]) & (
						   (2U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU)));
    vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((2U & (IData)(vlTOPp->SHFT)) ? 0U : 
		(vlTOPp->shifter__DOT__stage[0U] >> 0x10U)) 
	       & ((2U & (IData)(vlTOPp->SHFT)) ? 0U
		   : 0xffffU)) << 0x10U));
    vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((4U & (IData)(vlTOPp->SHFT)) ? 0U : 
	       vlTOPp->shifter__DOT__stage[1U]) & (
						   (4U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU)));
    vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((4U & (IData)(vlTOPp->SHFT)) ? 0U : 
		(vlTOPp->shifter__DOT__stage[1U] >> 0x10U)) 
	       & ((4U & (IData)(vlTOPp->SHFT)) ? 0U
		   : 0xffffU)) << 0x10U));
    vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((8U & (IData)(vlTOPp->SHFT)) ? 0U : 
	       vlTOPp->shifter__DOT__stage[2U]) & (
						   (8U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU)));
    vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((8U & (IData)(vlTOPp->SHFT)) ? 0U : 
		(vlTOPp->shifter__DOT__stage[2U] >> 0x10U)) 
	       & ((8U & (IData)(vlTOPp->SHFT)) ? 0U
		   : 0xffffU)) << 0x10U));
    vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x10U & (IData)(vlTOPp->SHFT)) ? 0U
	        : vlTOPp->shifter__DOT__stage[3U]) 
	      & ((0x10U & (IData)(vlTOPp->SHFT)) ? 0U
		  : 0xffffU)));
    vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x10U & (IData)(vlTOPp->SHFT)) ? 0U
		 : (vlTOPp->shifter__DOT__stage[3U] 
		    >> 0x10U)) & ((0x10U & (IData)(vlTOPp->SHFT))
				   ? 0U : 0xffffU)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->shifter__DOT__stage[4U] : 0U) 
	      & ((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		  ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->shifter__DOT__stage[4U] 
		    >> 0x10U) : 0U) & ((0x20U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT____Vcellinp__shift_left_mux1__A 
	= ((0xfffffffcU & (vlTOPp->shifter__DOT__stage
			   [0U] << 2U)) | (3U & VL_NEGATE_I((IData)(
								    (1U 
								     & (IData)(vlTOPp->shifter__DOT____Vcellout__ander__Y))))));
    vlTOPp->shifter__DOT____Vcellinp__shift_left_mux2__A 
	= ((0xfffffff0U & (vlTOPp->shifter__DOT__stage
			   [1U] << 4U)) | (0xfU & VL_NEGATE_I((IData)(
								      (1U 
								       & (IData)(vlTOPp->shifter__DOT____Vcellout__ander__Y))))));
    vlTOPp->shifter__DOT____Vcellinp__shift_left_mux3__A 
	= ((0xffffff00U & (vlTOPp->shifter__DOT__stage
			   [2U] << 8U)) | (0xffU & 
					   VL_NEGATE_I((IData)(
							       (1U 
								& (IData)(vlTOPp->shifter__DOT____Vcellout__ander__Y))))));
    vlTOPp->shifter__DOT____Vcellinp__shift_left_mux4__A 
	= ((0xffff0000U & (vlTOPp->shifter__DOT__stage
			   [3U] << 0x10U)) | (0xffffU 
					      & VL_NEGATE_I((IData)(
								    (1U 
								     & (IData)(vlTOPp->shifter__DOT____Vcellout__ander__Y))))));
    vlTOPp->shifter__DOT____Vcellinp__post_reverse_mux__B 
	= ((0x80000000U & (vlTOPp->shifter__DOT__stage
			   [4U] << 0x1fU)) | ((0x40000000U 
					       & (vlTOPp->shifter__DOT__stage
						  [4U] 
						  << 0x1dU)) 
					      | ((0x20000000U 
						  & (vlTOPp->shifter__DOT__stage
						     [4U] 
						     << 0x1bU)) 
						 | ((0x10000000U 
						     & (vlTOPp->shifter__DOT__stage
							[4U] 
							<< 0x19U)) 
						    | ((0x8000000U 
							& (vlTOPp->shifter__DOT__stage
							   [4U] 
							   << 0x17U)) 
						       | ((0x4000000U 
							   & (vlTOPp->shifter__DOT__stage
							      [4U] 
							      << 0x15U)) 
							  | ((0x2000000U 
							      & (vlTOPp->shifter__DOT__stage
								 [4U] 
								 << 0x13U)) 
							     | ((0x1000000U 
								 & (vlTOPp->shifter__DOT__stage
								    [4U] 
								    << 0x11U)) 
								| ((0x800000U 
								    & (vlTOPp->shifter__DOT__stage
								       [4U] 
								       << 0xfU)) 
								   | ((0x400000U 
								       & (vlTOPp->shifter__DOT__stage
									  [4U] 
									  << 0xdU)) 
								      | ((0x200000U 
									  & (vlTOPp->shifter__DOT__stage
									     [4U] 
									     << 0xbU)) 
									 | ((0x100000U 
									     & (vlTOPp->shifter__DOT__stage
										[4U] 
										<< 9U)) 
									    | ((0x80000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										<< 7U)) 
									       | ((0x40000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										<< 5U)) 
										| ((0x20000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										<< 3U)) 
										| ((0x10000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										<< 1U)) 
										| ((0x8000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 1U)) 
										| ((0x4000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 3U)) 
										| ((0x2000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 5U)) 
										| ((0x1000U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 7U)) 
										| ((0x800U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 9U)) 
										| ((0x400U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0xbU)) 
										| ((0x200U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0xdU)) 
										| ((0x100U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0xfU)) 
										| ((0x80U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x11U)) 
										| ((0x40U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x13U)) 
										| ((0x20U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x15U)) 
										| ((0x10U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x17U)) 
										| ((8U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x19U)) 
										| ((4U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x1bU)) 
										| ((2U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x1dU)) 
										| (1U 
										& (vlTOPp->shifter__DOT__stage
										[4U] 
										>> 0x1fU)))))))))))))))))))))))))))))))));
    vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((2U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->shifter__DOT____Vcellinp__shift_left_mux1__A
	        : 0U) & ((2U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((2U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->shifter__DOT____Vcellinp__shift_left_mux1__A 
		    >> 0x10U) : 0U) & ((2U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((4U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->shifter__DOT____Vcellinp__shift_left_mux2__A
	        : 0U) & ((4U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((4U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->shifter__DOT____Vcellinp__shift_left_mux2__A 
		    >> 0x10U) : 0U) & ((4U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((8U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->shifter__DOT____Vcellinp__shift_left_mux3__A
	        : 0U) & ((8U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((8U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->shifter__DOT____Vcellinp__shift_left_mux3__A 
		    >> 0x10U) : 0U) & ((8U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x10U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
	        ? vlTOPp->shifter__DOT____Vcellinp__shift_left_mux4__A
	        : 0U) & ((0x10U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x10U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
		 ? (vlTOPp->shifter__DOT____Vcellinp__shift_left_mux4__A 
		    >> 0x10U) : 0U) & ((0x10U & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((IData)(vlTOPp->LEFT) ? 0U : vlTOPp->shifter__DOT____Vcellinp__post_reverse_mux__B) 
	      & ((IData)(vlTOPp->LEFT) ? 0U : 0xffffU)));
    vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((IData)(vlTOPp->LEFT) ? 0U : (vlTOPp->shifter__DOT____Vcellinp__post_reverse_mux__B 
					      >> 0x10U)) 
	       & ((IData)(vlTOPp->LEFT) ? 0U : 0xffffU)) 
	      << 0x10U));
    vlTOPp->shifter__DOT__stage[1U] = ((2U & (IData)(vlTOPp->SHFT))
				        ? (((vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 
					     & ((2U 
						 & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						 ? 0xffffU
						 : 0U)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 
					       & (((2U 
						    & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						    ? 0xffffU
						    : 0U) 
						  << 0x10U))) 
					   & (((2U 
						& (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
					        ? 0xffffU
					        : 0U) 
					      | (((2U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U) 
						 << 0x10U)))
				        : (((vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 
					     & ((2U 
						 & (IData)(vlTOPp->SHFT))
						 ? 0U
						 : 0xffffU)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 
					       & (((2U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU) 
						  << 0x10U))) 
					   & (((2U 
						& (IData)(vlTOPp->SHFT))
					        ? 0U
					        : 0xffffU) 
					      | (((2U 
						   & (IData)(vlTOPp->SHFT))
						   ? 0U
						   : 0xffffU) 
						 << 0x10U))));
    vlTOPp->shifter__DOT__stage[2U] = ((4U & (IData)(vlTOPp->SHFT))
				        ? (((vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 
					     & ((4U 
						 & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						 ? 0xffffU
						 : 0U)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 
					       & (((4U 
						    & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						    ? 0xffffU
						    : 0U) 
						  << 0x10U))) 
					   & (((4U 
						& (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
					        ? 0xffffU
					        : 0U) 
					      | (((4U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U) 
						 << 0x10U)))
				        : (((vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 
					     & ((4U 
						 & (IData)(vlTOPp->SHFT))
						 ? 0U
						 : 0xffffU)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 
					       & (((4U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU) 
						  << 0x10U))) 
					   & (((4U 
						& (IData)(vlTOPp->SHFT))
					        ? 0U
					        : 0xffffU) 
					      | (((4U 
						   & (IData)(vlTOPp->SHFT))
						   ? 0U
						   : 0xffffU) 
						 << 0x10U))));
    vlTOPp->shifter__DOT__stage[3U] = ((8U & (IData)(vlTOPp->SHFT))
				        ? (((vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 
					     & ((8U 
						 & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						 ? 0xffffU
						 : 0U)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 
					       & (((8U 
						    & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						    ? 0xffffU
						    : 0U) 
						  << 0x10U))) 
					   & (((8U 
						& (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
					        ? 0xffffU
					        : 0U) 
					      | (((8U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U) 
						 << 0x10U)))
				        : (((vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 
					     & ((8U 
						 & (IData)(vlTOPp->SHFT))
						 ? 0U
						 : 0xffffU)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 
					       & (((8U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU) 
						  << 0x10U))) 
					   & (((8U 
						& (IData)(vlTOPp->SHFT))
					        ? 0U
					        : 0xffffU) 
					      | (((8U 
						   & (IData)(vlTOPp->SHFT))
						   ? 0U
						   : 0xffffU) 
						 << 0x10U))));
    vlTOPp->shifter__DOT__stage[4U] = ((0x10U & (IData)(vlTOPp->SHFT))
				        ? (((vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 
					     & ((0x10U 
						 & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						 ? 0xffffU
						 : 0U)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 
					       & (((0x10U 
						    & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						    ? 0xffffU
						    : 0U) 
						  << 0x10U))) 
					   & (((0x10U 
						& (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
					        ? 0xffffU
					        : 0U) 
					      | (((0x10U 
						   & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						   ? 0xffffU
						   : 0U) 
						 << 0x10U)))
				        : (((vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 
					     & ((0x10U 
						 & (IData)(vlTOPp->SHFT))
						 ? 0U
						 : 0xffffU)) 
					    | (vlTOPp->shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 
					       & (((0x10U 
						    & (IData)(vlTOPp->SHFT))
						    ? 0U
						    : 0xffffU) 
						  << 0x10U))) 
					   & (((0x10U 
						& (IData)(vlTOPp->SHFT))
					        ? 0U
					        : 0xffffU) 
					      | (((0x10U 
						   & (IData)(vlTOPp->SHFT))
						   ? 0U
						   : 0xffffU) 
						 << 0x10U))));
    vlTOPp->OUT = ((IData)(vlTOPp->LEFT) ? (((vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
					      & ((0x20U 
						  & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						  ? 0xffffU
						  : 0U)) 
					     | (vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
						& (((0x20U 
						     & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   << 0x10U))) 
					    & (((0x20U 
						 & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						 ? 0xffffU
						 : 0U) 
					       | (((0x20U 
						    & (IData)(vlTOPp->shifter__DOT____Vcellinp__notter__A))
						    ? 0xffffU
						    : 0U) 
						  << 0x10U)))
		    : (((vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
			 & ((IData)(vlTOPp->LEFT) ? 0U
			     : 0xffffU)) | (vlTOPp->shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
					    & (((IData)(vlTOPp->LEFT)
						 ? 0U
						 : 0xffffU) 
					       << 0x10U))) 
		       & (((IData)(vlTOPp->LEFT) ? 0U
			    : 0xffffU) | (((IData)(vlTOPp->LEFT)
					    ? 0U : 0xffffU) 
					  << 0x10U))));
}

void Vshifter::_eval(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval\n"); );
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vshifter::_eval_initial(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval_initial\n"); );
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vshifter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::final\n"); );
    // Variables
    Vshifter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vshifter::_eval_settle(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval_settle\n"); );
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vshifter::_change_request(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_change_request\n"); );
    Vshifter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->shifter__DOT__stage[0U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
	       [0U])
	 | (vlTOPp->shifter__DOT__stage[1U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
	    [1U])
	 | (vlTOPp->shifter__DOT__stage[2U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
	    [2U])
	 | (vlTOPp->shifter__DOT__stage[3U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
	    [3U])
	 | (vlTOPp->shifter__DOT__stage[4U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
	    [4U]));
    VL_DEBUG_IF( if(__req && ((vlTOPp->shifter__DOT__stage
			       [0U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
			       [0U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->shifter__DOT__stage
			       [1U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
			       [1U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->shifter__DOT__stage
			       [2U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
			       [2U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->shifter__DOT__stage
			       [3U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
			       [3U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->shifter__DOT__stage
			       [4U] ^ vlTOPp->__Vchglast__TOP__shifter__DOT__stage
			       [4U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__shifter__DOT__stage[0U] 
	= vlTOPp->shifter__DOT__stage[0U];
    vlTOPp->__Vchglast__TOP__shifter__DOT__stage[1U] 
	= vlTOPp->shifter__DOT__stage[1U];
    vlTOPp->__Vchglast__TOP__shifter__DOT__stage[2U] 
	= vlTOPp->shifter__DOT__stage[2U];
    vlTOPp->__Vchglast__TOP__shifter__DOT__stage[3U] 
	= vlTOPp->shifter__DOT__stage[3U];
    vlTOPp->__Vchglast__TOP__shifter__DOT__stage[4U] 
	= vlTOPp->shifter__DOT__stage[4U];
    return __req;
}

#ifdef VL_DEBUG
void Vshifter::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((SHFT & 0xe0U))) {
	Verilated::overWidthError("SHFT");}
    if (VL_UNLIKELY((LEFT & 0xfeU))) {
	Verilated::overWidthError("LEFT");}
    if (VL_UNLIKELY((ARITH & 0xfeU))) {
	Verilated::overWidthError("ARITH");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vshifter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_ctor_var_reset\n"); );
    // Body
    IN = VL_RAND_RESET_I(32);
    SHFT = VL_RAND_RESET_I(5);
    LEFT = VL_RAND_RESET_I(1);
    ARITH = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    OUT = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__notter__A = VL_RAND_RESET_I(6);
    shifter__DOT____Vcellout__ander__Y = VL_RAND_RESET_I(4);
    shifter__DOT__pre_reverse = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__pre_reverse_mux__B = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
	    shifter__DOT__stage[__Vi0] = VL_RAND_RESET_I(32);
    }}
    shifter__DOT____Vcellinp__shift_left_mux0__A = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__shift_left_mux1__A = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__shift_left_mux2__A = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__shift_left_mux3__A = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__shift_left_mux4__A = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__post_reverse_mux__B = VL_RAND_RESET_I(32);
    shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
	    __Vchglast__TOP__shifter__DOT__stage[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
