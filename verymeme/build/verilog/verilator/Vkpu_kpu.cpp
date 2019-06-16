// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkpu.h for the primary calling header

#include "Vkpu_kpu.h"
#include "Vkpu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vkpu_kpu) {
    VL_CELL(mmu, Vkpu_mmu);
    VL_CELL(regs, Vkpu_register_file);
    VL_CELL(control, Vkpu_control_logic);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vkpu_kpu::__Vconfigure(Vkpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vkpu_kpu::~Vkpu_kpu() {
}

//--------------------
// Internal Methods

void Vkpu_kpu::_initial__TOP__kpu__1(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_initial__TOP__kpu__1\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at chip74107.v:22
    if ((1U & (~ (IData)(vlTOPp->N_RST_ASYNC)))) {
	vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__0__KET____DOT__data = 0U;
    }
    // INITIAL at chip74107.v:22
    if ((1U & (~ (IData)(vlTOPp->N_RST_ASYNC)))) {
	vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data = 0U;
    }
}

VL_INLINE_OPT void Vkpu_kpu::_combo__TOP__kpu__2(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_combo__TOP__kpu__2\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at mlu_lookahead.v:24
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= (1U & vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR);
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 1U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 9U)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfeU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 2U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xaU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfdU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 1U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 3U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xbU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfbU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 2U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 4U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xcU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xf7U & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 3U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 5U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xdU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xefU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 4U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 6U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xeU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xdfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 5U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 7U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xfU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xbfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 6U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 8U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0x10U)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0x7fU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 7U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys = ((1U 
						  & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys)) 
						 | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS) 
						    << 1U));
}

void Vkpu_kpu::_settle__TOP__kpu__3(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_settle__TOP__kpu__3\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at mlu_lookahead.v:24
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= (1U & vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR);
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 1U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 9U)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfeU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 2U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xaU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfdU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 1U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 3U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xbU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xfbU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 2U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 4U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xcU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xf7U & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 3U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 5U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xdU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xefU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 4U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 6U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xeU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xdfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 5U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 7U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0xfU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0xbfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 6U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry) 
		  & (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
		     >> 8U)) | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
				>> 0x10U)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS 
	= ((0x7fU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS)) 
	   | ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry) 
	      << 7U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__prev_carry 
	= vlSymsp->TOP__kpu.__PVT__mlu__DOT__lookahead__DOT__carry;
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = (1U 
						| (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco));
    vlSymsp->TOP__kpu.timer_val = ((0xfffffff0U & vlSymsp->TOP__kpu.timer_val) 
				   | (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count));
    vlSymsp->TOP__kpu.timer_val = ((0xffffff0fU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count) 
				      << 4U));
    vlSymsp->TOP__kpu.timer_val = ((0xfffff0ffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count) 
				      << 8U));
    vlSymsp->TOP__kpu.timer_val = ((0xffff0fffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count) 
				      << 0xcU));
    vlSymsp->TOP__kpu.timer_val = ((0xfff0ffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count) 
				      << 0x10U));
    vlSymsp->TOP__kpu.timer_val = ((0xff0fffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count) 
				      << 0x14U));
    vlSymsp->TOP__kpu.timer_val = ((0xf0ffffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count) 
				      << 0x18U));
    vlSymsp->TOP__kpu.timer_val = ((0xfffffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count) 
				      << 0x1cU));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out4 = 
	((0xffff00ffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out4) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__low16__DOT__high8) 
	    << 8U));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out5 = 
	((0xffffff00U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out5) 
	 | (IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out6 = 
	((0xffffffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out6) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__high16__DOT__high8) 
	    << 0x18U));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out7 = 
	((0xff00ffffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out7) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__high16__DOT__low8) 
	    << 0x10U));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out4 = (
						   (0xffff00ffU 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out4) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__low16__DOT__high8) 
						      << 8U));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out5 = (
						   (0xffffff00U 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out5) 
						   | (IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out6 = (
						   (0xffffffU 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out6) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__high16__DOT__high8) 
						      << 0x18U));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out7 = (
						   (0xff00ffffU 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out7) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__high16__DOT__low8) 
						      << 0x10U));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out4 = (
						   (0xffff00ffU 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out4) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__low16__DOT__high8) 
						      << 8U));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out5 = (
						   (0xffffff00U 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out5) 
						   | (IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out6 = (
						   (0xffffffU 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out6) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__high16__DOT__high8) 
						      << 0x18U));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out7 = (
						   (0xff00ffffU 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out7) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__high16__DOT__low8) 
						      << 0x10U));
    vlSymsp->TOP__kpu.__Vcellout__jkflip__Q = ((2U 
						& (IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q)) 
					       | (IData)(vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__0__KET____DOT__data));
    vlSymsp->TOP__kpu.__Vcellout__jkflip__Q = ((1U 
						& (IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q)) 
					       | ((IData)(vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data) 
						  << 1U));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys = ((1U 
						  & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys)) 
						 | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__lookahead__CARRYS) 
						    << 1U));
    vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out 
	= ((((0xff00U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out4) 
	     | (0xffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out5)) 
	    | (0xff000000U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out6)) 
	   | (0xff0000U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu.tmp1_val = ((((0xff00U & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out4) 
				    | (0xffU & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out5)) 
				   | (0xff000000U & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out6)) 
				  | (0xff0000U & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu.tmp0_val = ((((0xff00U & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out4) 
				    | (0xffU & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out5)) 
				   | (0xff000000U & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out6)) 
				  | (0xff0000U & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu.n_rst = (1U & ((IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q) 
				     >> 1U));
    vlSymsp->TOP__kpu.opword_val = (0x3fU & vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out);
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__pre_reverse_mux__B 
	= ((0x80000000U & (vlSymsp->TOP__kpu.tmp0_val 
			   << 0x1fU)) | ((0x40000000U 
					  & (vlSymsp->TOP__kpu.tmp0_val 
					     << 0x1dU)) 
					 | ((0x20000000U 
					     & (vlSymsp->TOP__kpu.tmp0_val 
						<< 0x1bU)) 
					    | ((0x10000000U 
						& (vlSymsp->TOP__kpu.tmp0_val 
						   << 0x19U)) 
					       | ((0x8000000U 
						   & (vlSymsp->TOP__kpu.tmp0_val 
						      << 0x17U)) 
						  | ((0x4000000U 
						      & (vlSymsp->TOP__kpu.tmp0_val 
							 << 0x15U)) 
						     | ((0x2000000U 
							 & (vlSymsp->TOP__kpu.tmp0_val 
							    << 0x13U)) 
							| ((0x1000000U 
							    & (vlSymsp->TOP__kpu.tmp0_val 
							       << 0x11U)) 
							   | ((0x800000U 
							       & (vlSymsp->TOP__kpu.tmp0_val 
								  << 0xfU)) 
							      | ((0x400000U 
								  & (vlSymsp->TOP__kpu.tmp0_val 
								     << 0xdU)) 
								 | ((0x200000U 
								     & (vlSymsp->TOP__kpu.tmp0_val 
									<< 0xbU)) 
								    | ((0x100000U 
									& (vlSymsp->TOP__kpu.tmp0_val 
									   << 9U)) 
								       | ((0x80000U 
									   & (vlSymsp->TOP__kpu.tmp0_val 
									      << 7U)) 
									  | ((0x40000U 
									      & (vlSymsp->TOP__kpu.tmp0_val 
										<< 5U)) 
									     | ((0x20000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										<< 3U)) 
										| ((0x10000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										<< 1U)) 
										| ((0x8000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 1U)) 
										| ((0x4000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 3U)) 
										| ((0x2000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 5U)) 
										| ((0x1000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 7U)) 
										| ((0x800U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 9U)) 
										| ((0x400U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0xbU)) 
										| ((0x200U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0xdU)) 
										| ((0x100U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0xfU)) 
										| ((0x80U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x11U)) 
										| ((0x40U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x13U)) 
										| ((0x20U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x15U)) 
										| ((0x10U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x17U)) 
										| ((8U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x19U)) 
										| ((4U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x1bU)) 
										| ((2U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x1dU)) 
										| (1U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x1fU)))))))))))))))))))))))))))))))));
}

void Vkpu_kpu::_settle__TOP__kpu__4(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_settle__TOP__kpu__4\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys = ((0x1feU 
						  & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys)) 
						 | (1U 
						    & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						       >> 0x13U)));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A 
	= ((0x20U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
		     >> 0xfU)) | (0x1fU & vlSymsp->TOP__kpu.tmp1_val));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y 
	= (1U & ((vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
		  >> 0x15U) & (vlSymsp->TOP__kpu.tmp0_val 
			       >> 0x1fU)));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
	        ? 0U : vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__pre_reverse_mux__B) 
	      & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		  ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		 ? 0U : (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__pre_reverse_mux__B 
			 >> 0x10U)) & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out2) 
	   | (((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.timer_val : 0U) 
	      & ((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out3) 
	   | ((((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.timer_val >> 0x10U)
		 : 0U) & ((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out2) 
	   | (((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.tmp1_val : 0U) 
	      & ((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out3) 
	   | ((((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.tmp1_val >> 0x10U)
		 : 0U) & ((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out2) 
	   | (((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.tmp0_val : 0U) 
	      & ((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out3) 
	   | ((((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.tmp0_val >> 0x10U)
		 : 0U) & ((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.__PVT__control_opword_in_clk 
	= (1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
		 >> 5U));
    vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk = 
	(1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
	       >> 3U));
    vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk = 
	(1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
	       >> 2U));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 0xbU)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					      >> 8U)) 
				   | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
						<< 4U)) 
				      | (0xfU & vlSymsp->TOP__kpu.tmp0_val))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 0xaU)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					      >> 8U)) 
				   | ((0xf0U & vlSymsp->TOP__kpu.tmp1_val) 
				      | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
						 >> 4U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 9U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 4U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 8U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 8U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 8U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0xcU)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 7U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0xcU)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x10U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 6U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0x10U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x14U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 5U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0x14U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x18U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 4U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0x18U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x1cU)))));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.tmp0_val : 0U) 
	      & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.tmp0_val >> 0x10U)
		 : 0U) & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			   ? 0xffffU : 0U)) << 0x10U));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse 
	= ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
	    ? (((vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
		 & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		     ? 0xffffU : 0U)) | (vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
					 & (((0x20U 
					      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
					      ? 0xffffU
					      : 0U) 
					    << 0x10U))) 
	       & (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		    ? 0xffffU : 0U) | (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
					 ? 0xffffU : 0U) 
				       << 0x10U))) : 
	   (((vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	      & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		  ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
				      & (((0x100000U 
					   & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
					   ? 0U : 0xffffU) 
					 << 0x10U))) 
	    & (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		 ? 0U : 0xffffU) | (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
				      ? 0U : 0xffffU) 
				    << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xfeU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (1U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
							>> 5U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xfeU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (1U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
							>> 4U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfffffff0U & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xfdU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (2U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
							>> 4U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xfdU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (2U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
							>> 3U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xffffff0fU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf0U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
					     << 4U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xfbU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (4U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
							>> 3U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xfbU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (4U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
							>> 2U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfffff0ffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf00U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
					      << 8U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xf7U 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (8U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
							>> 2U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xf7U 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (8U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
							>> 1U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xffff0fffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
					       << 0xcU)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xefU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x10U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
							>> 1U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xefU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x10U 
						     & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfff0ffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf0000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
						<< 0x10U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xdfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x20U 
						     & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xdfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x20U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
							<< 1U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xff0fffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf00000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
						 << 0x14U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xbfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x40U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
							<< 1U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xbfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x40U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
							<< 2U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xf0ffffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf000000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
						  << 0x18U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0x7fU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x80U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
							<< 2U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0x7fU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x80U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
							<< 3U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfffffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf0000000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
						   << 0x1cU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((1U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse) 
	      & ((1U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		  : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((1U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse 
		    >> 0x10U)) & ((1U & vlSymsp->TOP__kpu.tmp1_val)
				   ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux0__A 
	= ((0xfffffffeU & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse 
			   << 1U)) | (1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
	= (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g) 
	    << 9U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p) 
		       << 1U) | (1U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
				       >> 0x13U))));
    vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out2) 
	   | (((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.mlu_val : 0U) & 
	      ((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out3) 
	   | ((((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.mlu_val >> 0x10U)
		 : 0U) & ((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux0__A
	        : 0U) & ((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux0__A 
		    >> 0x10U) : 0U) & ((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[0U] 
	= ((1U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 
						  & ((1U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 
						    & (((1U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((1U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((1U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 
		 & ((1U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 
					 & (((1U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((1U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((1U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((2U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [0U]) & ((2U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((2U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [0U] >> 0x10U)) & ((2U & vlSymsp->TOP__kpu.tmp1_val)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((4U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [1U]) & ((4U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((4U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [1U] >> 0x10U)) & ((4U & vlSymsp->TOP__kpu.tmp1_val)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((8U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [2U]) & ((8U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((8U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [2U] >> 0x10U)) & ((8U & vlSymsp->TOP__kpu.tmp1_val)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x10U & vlSymsp->TOP__kpu.tmp1_val)
	        ? 0U : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [3U]) & ((0x10U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x10U & vlSymsp->TOP__kpu.tmp1_val)
		 ? 0U : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			 [3U] >> 0x10U)) & ((0x10U 
					     & vlSymsp->TOP__kpu.tmp1_val)
					     ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux1__A 
	= ((0xfffffffcU & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [0U] << 2U)) | (3U & VL_NEGATE_I((IData)(
								    (1U 
								     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux2__A 
	= ((0xfffffff0U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [1U] << 4U)) | (0xfU & VL_NEGATE_I((IData)(
								      (1U 
								       & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux3__A 
	= ((0xffffff00U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [2U] << 8U)) | (0xffU & 
					   VL_NEGATE_I((IData)(
							       (1U 
								& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux4__A 
	= ((0xffff0000U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [3U] << 0x10U)) | (0xffffU 
					      & VL_NEGATE_I((IData)(
								    (1U 
								     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [4U] : 0U) & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			      ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [4U] >> 0x10U) : 0U) & ((0x20U 
					     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
					     ? 0xffffU
					     : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__post_reverse_mux__B 
	= ((0x80000000U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [4U] << 0x1fU)) | ((0x40000000U 
					       & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
						  [4U] 
						  << 0x1dU)) 
					      | ((0x20000000U 
						  & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
						     [4U] 
						     << 0x1bU)) 
						 | ((0x10000000U 
						     & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
							[4U] 
							<< 0x19U)) 
						    | ((0x8000000U 
							& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
							   [4U] 
							   << 0x17U)) 
						       | ((0x4000000U 
							   & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
							      [4U] 
							      << 0x15U)) 
							  | ((0x2000000U 
							      & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
								 [4U] 
								 << 0x13U)) 
							     | ((0x1000000U 
								 & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
								    [4U] 
								    << 0x11U)) 
								| ((0x800000U 
								    & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
								       [4U] 
								       << 0xfU)) 
								   | ((0x400000U 
								       & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
									  [4U] 
									  << 0xdU)) 
								      | ((0x200000U 
									  & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
									     [4U] 
									     << 0xbU)) 
									 | ((0x100000U 
									     & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 9U)) 
									    | ((0x80000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 7U)) 
									       | ((0x40000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 5U)) 
										| ((0x20000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 3U)) 
										| ((0x10000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 1U)) 
										| ((0x8000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 1U)) 
										| ((0x4000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 3U)) 
										| ((0x2000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 5U)) 
										| ((0x1000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 7U)) 
										| ((0x800U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 9U)) 
										| ((0x400U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0xbU)) 
										| ((0x200U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0xdU)) 
										| ((0x100U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0xfU)) 
										| ((0x80U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x11U)) 
										| ((0x40U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x13U)) 
										| ((0x20U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x15U)) 
										| ((0x10U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x17U)) 
										| ((8U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x19U)) 
										| ((4U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x1bU)) 
										| ((2U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x1dU)) 
										| (1U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x1fU)))))))))))))))))))))))))))))))));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux1__A
	        : 0U) & ((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux1__A 
		    >> 0x10U) : 0U) & ((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux2__A
	        : 0U) & ((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux2__A 
		    >> 0x10U) : 0U) & ((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux3__A
	        : 0U) & ((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux3__A 
		    >> 0x10U) : 0U) & ((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux4__A
	        : 0U) & ((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux4__A 
		    >> 0x10U) : 0U) & ((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
	        ? 0U : vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__post_reverse_mux__B) 
	      & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		  ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		 ? 0U : (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__post_reverse_mux__B 
			 >> 0x10U)) & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[1U] 
	= ((2U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 
						  & ((2U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 
						    & (((2U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((2U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((2U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 
		 & ((2U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 
					 & (((2U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((2U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((2U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[2U] 
	= ((4U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 
						  & ((4U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 
						    & (((4U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((4U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((4U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 
		 & ((4U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 
					 & (((4U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((4U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((4U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[3U] 
	= ((8U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 
						  & ((8U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 
						    & (((8U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((8U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((8U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 
		 & ((8U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 
					 & (((8U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((8U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((8U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[4U] 
	= ((0x10U & vlSymsp->TOP__kpu.tmp1_val) ? (
						   ((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 
						     & ((0x10U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U)) 
						    | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 
						       & (((0x10U 
							    & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							    ? 0xffffU
							    : 0U) 
							  << 0x10U))) 
						   & (((0x10U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      | (((0x10U 
							   & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							   ? 0xffffU
							   : 0U) 
							 << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 
		 & ((0x10U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 
					 & (((0x10U 
					      & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((0x10U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((0x10U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter_val = ((0x100000U 
					     & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
					     ? (((vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
						  & ((0x20U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
						    & (((0x20U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((0x20U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((0x20U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
					     : (((vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
						  & ((0x100000U 
						      & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						      ? 0U
						      : 0xffffU)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
						    & (((0x100000U 
							 & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
							 ? 0U
							 : 0xffffU) 
						       << 0x10U))) 
						& (((0x100000U 
						     & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						     ? 0U
						     : 0xffffU) 
						   | (((0x100000U 
							& vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						        ? 0U
						        : 0xffffU) 
						      << 0x10U))));
    vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out2) 
	   | (((0x40U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.__PVT__shifter_val
	        : 0U) & ((0x40U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out3) 
	   | ((((0x40U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.__PVT__shifter_val 
		    >> 0x10U) : 0U) & ((0x40U & ((IData)(1U) 
						 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
}

void Vkpu_kpu::_settle__TOP__kpu__5(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_settle__TOP__kpu__5\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.bus = ((2U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			      ? (((((2U & ((IData)(1U) 
					   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				     ? vlSymsp->TOP__kpu__regs__registers.mem
				    [(0x1fU & (IData)(vlSymsp->TOP__kpu__regs.__Vcellout__reg_sel_mux__OUT))]
				     : 0U) & ((2U & 
					       ((IData)(1U) 
						<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					       ? 0xffffffffU
					       : 0U)) 
				  & ((2U & ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				      ? 0xffffffffU
				      : 0U)) & ((2U 
						 & ((IData)(1U) 
						    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						 ? 0xffffffffU
						 : 0U))
			      : ((4U & ((IData)(1U) 
					<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				  ? (((vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out2 
				       & ((4U & ((IData)(1U) 
						 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					   ? 0xffffU
					   : 0U)) | 
				      (vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out3 
				       & (((4U & ((IData)(1U) 
						  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					    ? 0xffffU
					    : 0U) << 0x10U))) 
				     & (((4U & ((IData)(1U) 
						<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					  ? 0xffffU
					  : 0U) | (
						   ((4U 
						     & ((IData)(1U) 
							<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						     ? 0xffffU
						     : 0U) 
						   << 0x10U)))
				  : ((8U & ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				      ? (((vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out2 
					   & ((8U & 
					       ((IData)(1U) 
						<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					       ? 0xffffU
					       : 0U)) 
					  | (vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out3 
					     & (((8U 
						  & ((IData)(1U) 
						     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						  ? 0xffffU
						  : 0U) 
						<< 0x10U))) 
					 & (((8U & 
					      ((IData)(1U) 
					       << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					      ? 0xffffU
					      : 0U) 
					    | (((8U 
						 & ((IData)(1U) 
						    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						 ? 0xffffU
						 : 0U) 
					       << 0x10U)))
				      : ((0x20U & ((IData)(1U) 
						   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					  ? (((vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out2 
					       & ((0x20U 
						   & ((IData)(1U) 
						      << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						   ? 0xffffU
						   : 0U)) 
					      | (vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out3 
						 & (((0x20U 
						      & ((IData)(1U) 
							 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						      ? 0xffffU
						      : 0U) 
						    << 0x10U))) 
					     & (((0x20U 
						  & ((IData)(1U) 
						     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						  ? 0xffffU
						  : 0U) 
						| (((0x20U 
						     & ((IData)(1U) 
							<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						     ? 0xffffU
						     : 0U) 
						   << 0x10U)))
					  : ((0x40U 
					      & ((IData)(1U) 
						 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					      ? (((vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out2 
						   & ((0x40U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 0xffffU
						       : 0U)) 
						  | (vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out3 
						     & (((0x40U 
							  & ((IData)(1U) 
							     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							  ? 0xffffU
							  : 0U) 
							<< 0x10U))) 
						 & (((0x40U 
						      & ((IData)(1U) 
							 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						      ? 0xffffU
						      : 0U) 
						    | (((0x40U 
							 & ((IData)(1U) 
							    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U)))
					      : ((0x80U 
						  & ((IData)(1U) 
						     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						  ? 
						 (((vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out2 
						    & ((0x80U 
							& ((IData)(1U) 
							   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						        ? 0xffffU
						        : 0U)) 
						   | (vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out3 
						      & (((0x80U 
							   & ((IData)(1U) 
							      << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							   ? 0xffffU
							   : 0U) 
							 << 0x10U))) 
						  & (((0x80U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 0xffffU
						       : 0U) 
						     | (((0x80U 
							  & ((IData)(1U) 
							     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							  ? 0xffffU
							  : 0U) 
							<< 0x10U)))
						  : 
						 ((0x10U 
						   & ((IData)(1U) 
						      << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						   ? 
						  (((((0x10U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 
						      vlSymsp->TOP__kpu__mmu__ram.mem
						      [
						      (0x3ffU 
						       & vlSymsp->TOP__kpu.tmp0_val)]
						       : 0U) 
						     & ((0x10U 
							 & ((IData)(1U) 
							    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							 ? 0xffffffffU
							 : 0U)) 
						    & ((0x10U 
							& ((IData)(1U) 
							   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						        ? 0xffffffffU
						        : 0U)) 
						   & ((0x10U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 0xffffffffU
						       : 0U))
						   : 
						  ((0x100U 
						    & ((IData)(1U) 
						       << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						    ? 
						   (0x3fU 
						    & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						    : 0U))))))));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__6(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__6\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74107.v:27
    vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__0__KET____DOT__data 
	= vlTOPp->N_RST_ASYNC;
    // ALWAYS at chip74107.v:27
    vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data 
	= ((IData)(vlTOPp->N_RST_ASYNC) & ((1U & (IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q))
					    ? (IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q)
					    : (IData)(vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data)));
    vlSymsp->TOP__kpu.__Vcellout__jkflip__Q = ((2U 
						& (IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q)) 
					       | (IData)(vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__0__KET____DOT__data));
    vlSymsp->TOP__kpu.__Vcellout__jkflip__Q = ((1U 
						& (IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q)) 
					       | ((IData)(vlSymsp->TOP__kpu.__PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data) 
						  << 1U));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__7(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__7\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((0x80U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((0x40U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((0x20U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((0x10U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((8U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((4U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((2U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count = 0U;
    }
    // ALWAYS at chip74161.v:19
    if (vlSymsp->TOP__kpu.n_rst) {
	if ((1U & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco))) {
	    vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count 
		= (0xfU & ((IData)(1U) + (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count)));
	}
    } else {
	vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count = 0U;
    }
    vlSymsp->TOP__kpu.timer_val = ((0xfffffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count) 
				      << 0x1cU));
    vlSymsp->TOP__kpu.timer_val = ((0xf0ffffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count) 
				      << 0x18U));
    vlSymsp->TOP__kpu.timer_val = ((0xff0fffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count) 
				      << 0x14U));
    vlSymsp->TOP__kpu.timer_val = ((0xfff0ffffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count) 
				      << 0x10U));
    vlSymsp->TOP__kpu.timer_val = ((0xffff0fffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count) 
				      << 0xcU));
    vlSymsp->TOP__kpu.timer_val = ((0xfffff0ffU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count) 
				      << 8U));
    vlSymsp->TOP__kpu.timer_val = ((0xffffff0fU & vlSymsp->TOP__kpu.timer_val) 
				   | ((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count) 
				      << 4U));
    vlSymsp->TOP__kpu.timer_val = ((0xfffffff0U & vlSymsp->TOP__kpu.timer_val) 
				   | (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__8(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__8\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys = ((0x1feU 
						  & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys)) 
						 | (1U 
						    & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						       >> 0x13U)));
}

VL_INLINE_OPT void Vkpu_kpu::_combo__TOP__kpu__9(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_combo__TOP__kpu__9\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 7U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 6U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 5U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 4U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 3U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 2U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 1U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		  & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0xffU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO) 
						   << 8U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x17fU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO) 
						   << 7U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1bfU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO) 
						   << 6U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1dfU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO) 
						   << 5U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1efU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO) 
						   << 4U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1f7U 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO) 
						   << 3U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1fbU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO) 
						   << 2U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1fdU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO) 
						   << 1U));
}

VL_INLINE_OPT void Vkpu_kpu::_combo__TOP__kpu__10(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_combo__TOP__kpu__10\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.__PVT__control_opword_in_clk 
	= (1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
		 >> 5U));
    vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk = 
	(1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
	       >> 3U));
    vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk = 
	(1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
	       >> 2U));
}

VL_INLINE_OPT void Vkpu_kpu::_multiclk__TOP__kpu__11(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_multiclk__TOP__kpu__11\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out2) 
	   | (((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.timer_val : 0U) 
	      & ((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out3) 
	   | ((((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.timer_val >> 0x10U)
		 : 0U) & ((0x80U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
}

void Vkpu_kpu::_settle__TOP__kpu__12(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_settle__TOP__kpu__12\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO 
	= (1U & (((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		  & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 1U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 2U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 3U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 4U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 5U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 6U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO 
	= (1U & ((((IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco) 
		   >> 7U) & (0xfU == (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count)))
		  ? 1U : 0U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1fdU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO) 
						   << 1U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1fbU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO) 
						   << 2U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1f7U 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO) 
						   << 3U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1efU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO) 
						   << 4U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1dfU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO) 
						   << 5U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x1bfU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO) 
						   << 6U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0x17fU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO) 
						   << 7U));
    vlSymsp->TOP__kpu.__PVT__timer__DOT__rco = ((0xffU 
						 & (IData)(vlSymsp->TOP__kpu.__PVT__timer__DOT__rco)) 
						| ((IData)(vlSymsp->TOP__kpu.timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO) 
						   << 8U));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__13(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__13\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu.__PVT__opword__DOT__high16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 0x18U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu.__PVT__opword__DOT__high16__DOT__low8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 0x10U));
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu.__PVT__opword__DOT__low16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 8U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu.__PVT__opword__DOT__low16__DOT__low8 
	= (0xffU & vlSymsp->TOP__kpu.bus);
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out6 = 
	((0xffffffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out6) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__high16__DOT__high8) 
	    << 0x18U));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out7 = 
	((0xff00ffffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out7) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__high16__DOT__low8) 
	    << 0x10U));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out4 = 
	((0xffff00ffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out4) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__low16__DOT__high8) 
	    << 8U));
    vlSymsp->TOP__kpu.opword__DOT__OUT__out__out5 = 
	((0xffffff00U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out5) 
	 | (IData)(vlSymsp->TOP__kpu.__PVT__opword__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out 
	= ((((0xff00U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out4) 
	     | (0xffU & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out5)) 
	    | (0xff000000U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out6)) 
	   | (0xff0000U & vlSymsp->TOP__kpu.opword__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu.opword_val = (0x3fU & vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out);
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__14(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__14\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu.__PVT__tmp1__DOT__high16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 0x18U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu.__PVT__tmp1__DOT__high16__DOT__low8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 0x10U));
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu.__PVT__tmp1__DOT__low16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 8U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu.__PVT__tmp1__DOT__low16__DOT__low8 
	= (0xffU & vlSymsp->TOP__kpu.bus);
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out6 = (
						   (0xffffffU 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out6) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__high16__DOT__high8) 
						      << 0x18U));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out7 = (
						   (0xff00ffffU 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out7) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__high16__DOT__low8) 
						      << 0x10U));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out4 = (
						   (0xffff00ffU 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out4) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__low16__DOT__high8) 
						      << 8U));
    vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out5 = (
						   (0xffffff00U 
						    & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out5) 
						   | (IData)(vlSymsp->TOP__kpu.__PVT__tmp1__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu.tmp1_val = ((((0xff00U & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out4) 
				    | (0xffU & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out5)) 
				   | (0xff000000U & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out6)) 
				  | (0xff0000U & vlSymsp->TOP__kpu.tmp1__DOT__OUT__out__out7));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__15(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__15\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu.__PVT__tmp0__DOT__high16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 0x18U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu.__PVT__tmp0__DOT__high16__DOT__low8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 0x10U));
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu.__PVT__tmp0__DOT__low16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu.bus >> 8U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu.__PVT__tmp0__DOT__low16__DOT__low8 
	= (0xffU & vlSymsp->TOP__kpu.bus);
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out6 = (
						   (0xffffffU 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out6) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__high16__DOT__high8) 
						      << 0x18U));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out7 = (
						   (0xff00ffffU 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out7) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__high16__DOT__low8) 
						      << 0x10U));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out4 = (
						   (0xffff00ffU 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out4) 
						   | ((IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__low16__DOT__high8) 
						      << 8U));
    vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out5 = (
						   (0xffffff00U 
						    & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out5) 
						   | (IData)(vlSymsp->TOP__kpu.__PVT__tmp0__DOT__low16__DOT__low8));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__16(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__16\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.n_rst = (1U & ((IData)(vlSymsp->TOP__kpu.__Vcellout__jkflip__Q) 
				     >> 1U));
}

VL_INLINE_OPT void Vkpu_kpu::_multiclk__TOP__kpu__17(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_multiclk__TOP__kpu__17\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out2) 
	   | (((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.tmp1_val : 0U) 
	      & ((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out3) 
	   | ((((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.tmp1_val >> 0x10U)
		 : 0U) & ((8U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A 
	= ((0x20U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
		     >> 0xfU)) | (0x1fU & vlSymsp->TOP__kpu.tmp1_val));
}

VL_INLINE_OPT void Vkpu_kpu::_sequent__TOP__kpu__18(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_sequent__TOP__kpu__18\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.tmp0_val = ((((0xff00U & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out4) 
				    | (0xffU & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out5)) 
				   | (0xff000000U & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out6)) 
				  | (0xff0000U & vlSymsp->TOP__kpu.tmp0__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__pre_reverse_mux__B 
	= ((0x80000000U & (vlSymsp->TOP__kpu.tmp0_val 
			   << 0x1fU)) | ((0x40000000U 
					  & (vlSymsp->TOP__kpu.tmp0_val 
					     << 0x1dU)) 
					 | ((0x20000000U 
					     & (vlSymsp->TOP__kpu.tmp0_val 
						<< 0x1bU)) 
					    | ((0x10000000U 
						& (vlSymsp->TOP__kpu.tmp0_val 
						   << 0x19U)) 
					       | ((0x8000000U 
						   & (vlSymsp->TOP__kpu.tmp0_val 
						      << 0x17U)) 
						  | ((0x4000000U 
						      & (vlSymsp->TOP__kpu.tmp0_val 
							 << 0x15U)) 
						     | ((0x2000000U 
							 & (vlSymsp->TOP__kpu.tmp0_val 
							    << 0x13U)) 
							| ((0x1000000U 
							    & (vlSymsp->TOP__kpu.tmp0_val 
							       << 0x11U)) 
							   | ((0x800000U 
							       & (vlSymsp->TOP__kpu.tmp0_val 
								  << 0xfU)) 
							      | ((0x400000U 
								  & (vlSymsp->TOP__kpu.tmp0_val 
								     << 0xdU)) 
								 | ((0x200000U 
								     & (vlSymsp->TOP__kpu.tmp0_val 
									<< 0xbU)) 
								    | ((0x100000U 
									& (vlSymsp->TOP__kpu.tmp0_val 
									   << 9U)) 
								       | ((0x80000U 
									   & (vlSymsp->TOP__kpu.tmp0_val 
									      << 7U)) 
									  | ((0x40000U 
									      & (vlSymsp->TOP__kpu.tmp0_val 
										<< 5U)) 
									     | ((0x20000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										<< 3U)) 
										| ((0x10000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										<< 1U)) 
										| ((0x8000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 1U)) 
										| ((0x4000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 3U)) 
										| ((0x2000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 5U)) 
										| ((0x1000U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 7U)) 
										| ((0x800U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 9U)) 
										| ((0x400U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0xbU)) 
										| ((0x200U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0xdU)) 
										| ((0x100U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0xfU)) 
										| ((0x80U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x11U)) 
										| ((0x40U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x13U)) 
										| ((0x20U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x15U)) 
										| ((0x10U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x17U)) 
										| ((8U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x19U)) 
										| ((4U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x1bU)) 
										| ((2U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x1dU)) 
										| (1U 
										& (vlSymsp->TOP__kpu.tmp0_val 
										>> 0x1fU)))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void Vkpu_kpu::_multiclk__TOP__kpu__19(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_multiclk__TOP__kpu__19\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out2) 
	   | (((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.tmp0_val : 0U) 
	      & ((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out3) 
	   | ((((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.tmp0_val >> 0x10U)
		 : 0U) & ((4U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y 
	= (1U & ((vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
		  >> 0x15U) & (vlSymsp->TOP__kpu.tmp0_val 
			       >> 0x1fU)));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
	        ? 0U : vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__pre_reverse_mux__B) 
	      & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		  ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		 ? 0U : (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__pre_reverse_mux__B 
			 >> 0x10U)) & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
}

VL_INLINE_OPT void Vkpu_kpu::_combo__TOP__kpu__20(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_combo__TOP__kpu__20\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 0xbU)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					      >> 8U)) 
				   | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
						<< 4U)) 
				      | (0xfU & vlSymsp->TOP__kpu.tmp0_val))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 0xaU)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					      >> 8U)) 
				   | ((0xf0U & vlSymsp->TOP__kpu.tmp1_val) 
				      | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
						 >> 4U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 9U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 4U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 8U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 8U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 8U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0xcU)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 7U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0xcU)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x10U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 6U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0x10U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x14U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 5U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0x14U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x18U)))));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR 
	= ((0x800U & ((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__carrys) 
		      << 4U)) | ((0x700U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					    >> 8U)) 
				 | ((0xf0U & (vlSymsp->TOP__kpu.tmp1_val 
					      >> 0x18U)) 
				    | (0xfU & (vlSymsp->TOP__kpu.tmp0_val 
					       >> 0x1cU)))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low))));
    // ALWAYS at mlu_slice.v:29
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop = 0U;
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen = 0U;
    if (((((((((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			     >> 8U))) | (1U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	      | (2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			      >> 8U)))) | (3U == (7U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 8U)))) 
	    | (4U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			    >> 8U)))) | (5U == (7U 
						& ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   >> 8U)))) 
	  | (6U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			  >> 8U)))) | (7U == (7U & 
					      ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					       >> 8U))))) {
	if ((0U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			  >> 8U)))) {
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		= (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			       >> 4U)) + (1U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						>> 0xbU))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop 
		= (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				    + ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				       >> 4U))));
	    vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen 
		= (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR)) 
				    + (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					       >> 4U)))));
	} else {
	    if ((1U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
			      >> 8U)))) {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		    = (0xfU & (((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				      >> 4U))) + (1U 
						  & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 0xbU))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop 
		    = (0xfU == (0xfU & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					+ (~ ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					      >> 4U)))));
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen 
		    = (0xfU < (0x1fU & ((0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR)) 
					+ (0xfU & (~ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						    >> 4U))))));
	    } else {
		vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low 
		    = (0xfU & ((2U == (7U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
					     >> 8U)))
			        ? ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
				      >> 4U)) : ((3U 
						  == 
						  (7U 
						   & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						      >> 8U)))
						  ? 
						 ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						  | ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						     >> 4U))
						  : 
						 ((4U 
						   == 
						   (7U 
						    & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						       >> 8U)))
						   ? 
						  ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						   ^ 
						   ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
						    >> 4U))
						   : 
						  ((5U 
						    == 
						    (7U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR) 
							>> 8U)))
						    ? 
						   (~ (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR))
						    : 0U)))));
	    }
	}
    }
    vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT 
	= (((0U == (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low)) 
	    << 6U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen) 
		       << 5U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop) 
				  << 4U) | (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low))));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xfeU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (1U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
							>> 5U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xfeU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (1U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT) 
							>> 4U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfffffff0U & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xfU & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xfdU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (2U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
							>> 4U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xfdU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (2U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
							>> 3U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xffffff0fU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf0U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT) 
					     << 4U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xfbU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (4U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
							>> 3U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xfbU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (4U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
							>> 2U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfffff0ffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf00U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT) 
					      << 8U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xf7U 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (8U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
							>> 2U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xf7U 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (8U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
							>> 1U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xffff0fffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT) 
					       << 0xcU)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xefU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x10U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
							>> 1U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xefU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x10U 
						     & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfff0ffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf0000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT) 
						<< 0x10U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xdfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x20U 
						     & (IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xdfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x20U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
							<< 1U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xff0fffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf00000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT) 
						 << 0x14U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0xbfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x40U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
							<< 1U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0xbfU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x40U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
							<< 2U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xf0ffffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf000000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT) 
						  << 0x18U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g = ((0x7fU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g)) 
						  | (0x80U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
							<< 2U)));
    vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p = ((0x7fU 
						   & (IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p)) 
						  | (0x80U 
						     & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
							<< 3U)));
    vlSymsp->TOP__kpu.mlu_val = ((0xfffffffU & vlSymsp->TOP__kpu.mlu_val) 
				 | (0xf0000000U & ((IData)(vlSymsp->TOP__kpu.mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT) 
						   << 0x1cU)));
    vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR 
	= (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_g) 
	    << 9U) | (((IData)(vlSymsp->TOP__kpu.__PVT__mlu__DOT__slice_p) 
		       << 1U) | (1U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
				       >> 0x13U))));
    vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out2) 
	   | (((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.mlu_val : 0U) & 
	      ((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out3) 
	   | ((((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.mlu_val >> 0x10U)
		 : 0U) & ((0x20U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			   ? 0xffffU : 0U)) << 0x10U));
}

VL_INLINE_OPT void Vkpu_kpu::_multiclk__TOP__kpu__21(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_multiclk__TOP__kpu__21\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.tmp0_val : 0U) 
	      & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.tmp0_val >> 0x10U)
		 : 0U) & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			   ? 0xffffU : 0U)) << 0x10U));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse 
	= ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
	    ? (((vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
		 & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		     ? 0xffffU : 0U)) | (vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
					 & (((0x20U 
					      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
					      ? 0xffffU
					      : 0U) 
					    << 0x10U))) 
	       & (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		    ? 0xffffU : 0U) | (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
					 ? 0xffffU : 0U) 
				       << 0x10U))) : 
	   (((vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	      & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		  ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
				      & (((0x100000U 
					   & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
					   ? 0U : 0xffffU) 
					 << 0x10U))) 
	    & (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		 ? 0U : 0xffffU) | (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
				      ? 0U : 0xffffU) 
				    << 0x10U))));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((1U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse) 
	      & ((1U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		  : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((1U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse 
		    >> 0x10U)) & ((1U & vlSymsp->TOP__kpu.tmp1_val)
				   ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux0__A 
	= ((0xfffffffeU & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__pre_reverse 
			   << 1U)) | (1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux0__A
	        : 0U) & ((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux0__A 
		    >> 0x10U) : 0U) & ((1U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[0U] 
	= ((1U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2 
						  & ((1U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3 
						    & (((1U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((1U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((1U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2 
		 & ((1U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3 
					 & (((1U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((1U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((1U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
}

VL_INLINE_OPT void Vkpu_kpu::_combo__TOP__kpu__22(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_combo__TOP__kpu__22\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((2U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [0U]) & ((2U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((2U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [0U] >> 0x10U)) & ((2U & vlSymsp->TOP__kpu.tmp1_val)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((4U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [1U]) & ((4U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((4U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [1U] >> 0x10U)) & ((4U & vlSymsp->TOP__kpu.tmp1_val)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((8U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
	        : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [2U]) & ((8U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((8U & vlSymsp->TOP__kpu.tmp1_val) ? 0U
		 : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [2U] >> 0x10U)) & ((8U & vlSymsp->TOP__kpu.tmp1_val)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x10U & vlSymsp->TOP__kpu.tmp1_val)
	        ? 0U : vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [3U]) & ((0x10U & vlSymsp->TOP__kpu.tmp1_val)
			 ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x10U & vlSymsp->TOP__kpu.tmp1_val)
		 ? 0U : (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			 [3U] >> 0x10U)) & ((0x10U 
					     & vlSymsp->TOP__kpu.tmp1_val)
					     ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux1__A 
	= ((0xfffffffcU & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [0U] << 2U)) | (3U & VL_NEGATE_I((IData)(
								    (1U 
								     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux2__A 
	= ((0xfffffff0U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [1U] << 4U)) | (0xfU & VL_NEGATE_I((IData)(
								      (1U 
								       & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux3__A 
	= ((0xffffff00U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [2U] << 8U)) | (0xffU & 
					   VL_NEGATE_I((IData)(
							       (1U 
								& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux4__A 
	= ((0xffff0000U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [3U] << 0x10U)) | (0xffffU 
					      & VL_NEGATE_I((IData)(
								    (1U 
								     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellout__ander__Y))))));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	       [4U] : 0U) & ((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			      ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x20U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
		    [4U] >> 0x10U) : 0U) & ((0x20U 
					     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
					     ? 0xffffU
					     : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__post_reverse_mux__B 
	= ((0x80000000U & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			   [4U] << 0x1fU)) | ((0x40000000U 
					       & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
						  [4U] 
						  << 0x1dU)) 
					      | ((0x20000000U 
						  & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
						     [4U] 
						     << 0x1bU)) 
						 | ((0x10000000U 
						     & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
							[4U] 
							<< 0x19U)) 
						    | ((0x8000000U 
							& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
							   [4U] 
							   << 0x17U)) 
						       | ((0x4000000U 
							   & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
							      [4U] 
							      << 0x15U)) 
							  | ((0x2000000U 
							      & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
								 [4U] 
								 << 0x13U)) 
							     | ((0x1000000U 
								 & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
								    [4U] 
								    << 0x11U)) 
								| ((0x800000U 
								    & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
								       [4U] 
								       << 0xfU)) 
								   | ((0x400000U 
								       & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
									  [4U] 
									  << 0xdU)) 
								      | ((0x200000U 
									  & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
									     [4U] 
									     << 0xbU)) 
									 | ((0x100000U 
									     & (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 9U)) 
									    | ((0x80000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 7U)) 
									       | ((0x40000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 5U)) 
										| ((0x20000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 3U)) 
										| ((0x10000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										<< 1U)) 
										| ((0x8000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 1U)) 
										| ((0x4000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 3U)) 
										| ((0x2000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 5U)) 
										| ((0x1000U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 7U)) 
										| ((0x800U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 9U)) 
										| ((0x400U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0xbU)) 
										| ((0x200U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0xdU)) 
										| ((0x100U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0xfU)) 
										| ((0x80U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x11U)) 
										| ((0x40U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x13U)) 
										| ((0x20U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x15U)) 
										| ((0x10U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x17U)) 
										| ((8U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x19U)) 
										| ((4U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x1bU)) 
										| ((2U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x1dU)) 
										| (1U 
										& (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
										[4U] 
										>> 0x1fU)))))))))))))))))))))))))))))))));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux1__A
	        : 0U) & ((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux1__A 
		    >> 0x10U) : 0U) & ((2U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux2__A
	        : 0U) & ((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux2__A 
		    >> 0x10U) : 0U) & ((4U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux3__A
	        : 0U) & ((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux3__A 
		    >> 0x10U) : 0U) & ((8U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2) 
	   | (((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
	        ? vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux4__A
	        : 0U) & ((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3) 
	   | ((((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
		 ? (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__shift_left_mux4__A 
		    >> 0x10U) : 0U) & ((0x10U & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2) 
	   | (((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
	        ? 0U : vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__post_reverse_mux__B) 
	      & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		  ? 0U : 0xffffU)));
    vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3) 
	   | ((((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
		 ? 0U : (vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__post_reverse_mux__B 
			 >> 0x10U)) & ((0x100000U & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
				        ? 0U : 0xffffU)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[1U] 
	= ((2U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2 
						  & ((2U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3 
						    & (((2U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((2U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((2U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2 
		 & ((2U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3 
					 & (((2U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((2U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((2U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[2U] 
	= ((4U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2 
						  & ((4U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3 
						    & (((4U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((4U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((4U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2 
		 & ((4U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3 
					 & (((4U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((4U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((4U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[3U] 
	= ((8U & vlSymsp->TOP__kpu.tmp1_val) ? (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2 
						  & ((8U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3 
						    & (((8U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((8U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((8U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2 
		 & ((8U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3 
					 & (((8U & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((8U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((8U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage[4U] 
	= ((0x10U & vlSymsp->TOP__kpu.tmp1_val) ? (
						   ((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2 
						     & ((0x10U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U)) 
						    | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3 
						       & (((0x10U 
							    & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							    ? 0xffffU
							    : 0U) 
							  << 0x10U))) 
						   & (((0x10U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      | (((0x10U 
							   & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							   ? 0xffffU
							   : 0U) 
							 << 0x10U)))
	    : (((vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2 
		 & ((0x10U & vlSymsp->TOP__kpu.tmp1_val)
		     ? 0U : 0xffffU)) | (vlSymsp->TOP__kpu.shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3 
					 & (((0x10U 
					      & vlSymsp->TOP__kpu.tmp1_val)
					      ? 0U : 0xffffU) 
					    << 0x10U))) 
	       & (((0x10U & vlSymsp->TOP__kpu.tmp1_val)
		    ? 0U : 0xffffU) | (((0x10U & vlSymsp->TOP__kpu.tmp1_val)
					 ? 0U : 0xffffU) 
				       << 0x10U))));
    vlSymsp->TOP__kpu.__PVT__shifter_val = ((0x100000U 
					     & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
					     ? (((vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2 
						  & ((0x20U 
						      & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						      ? 0xffffU
						      : 0U)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3 
						    & (((0x20U 
							 & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U))) 
						& (((0x20U 
						     & (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						     ? 0xffffU
						     : 0U) 
						   | (((0x20U 
							& (IData)(vlSymsp->TOP__kpu.shifter__DOT____Vcellinp__notter__A))
						        ? 0xffffU
						        : 0U) 
						      << 0x10U)))
					     : (((vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2 
						  & ((0x100000U 
						      & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						      ? 0U
						      : 0xffffU)) 
						 | (vlSymsp->TOP__kpu.shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3 
						    & (((0x100000U 
							 & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
							 ? 0U
							 : 0xffffU) 
						       << 0x10U))) 
						& (((0x100000U 
						     & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						     ? 0U
						     : 0xffffU) 
						   | (((0x100000U 
							& vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						        ? 0U
						        : 0xffffU) 
						      << 0x10U))));
    vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out2 
	= ((0xffff0000U & vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out2) 
	   | (((0x40U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
	        ? vlSymsp->TOP__kpu.__PVT__shifter_val
	        : 0U) & ((0x40U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			  ? 0xffffU : 0U)));
    vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out3 
	= ((0xffffU & vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out3) 
	   | ((((0x40U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
		 ? (vlSymsp->TOP__kpu.__PVT__shifter_val 
		    >> 0x10U) : 0U) & ((0x40U & ((IData)(1U) 
						 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				        ? 0xffffU : 0U)) 
	      << 0x10U));
    vlSymsp->TOP__kpu.bus = ((2U & ((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
			      ? (((((2U & ((IData)(1U) 
					   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				     ? vlSymsp->TOP__kpu__regs__registers.mem
				    [(0x1fU & (IData)(vlSymsp->TOP__kpu__regs.__Vcellout__reg_sel_mux__OUT))]
				     : 0U) & ((2U & 
					       ((IData)(1U) 
						<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					       ? 0xffffffffU
					       : 0U)) 
				  & ((2U & ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				      ? 0xffffffffU
				      : 0U)) & ((2U 
						 & ((IData)(1U) 
						    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						 ? 0xffffffffU
						 : 0U))
			      : ((4U & ((IData)(1U) 
					<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				  ? (((vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out2 
				       & ((4U & ((IData)(1U) 
						 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					   ? 0xffffU
					   : 0U)) | 
				      (vlSymsp->TOP__kpu.tmp0_buf__DOT__OUT__out__out3 
				       & (((4U & ((IData)(1U) 
						  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					    ? 0xffffU
					    : 0U) << 0x10U))) 
				     & (((4U & ((IData)(1U) 
						<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					  ? 0xffffU
					  : 0U) | (
						   ((4U 
						     & ((IData)(1U) 
							<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						     ? 0xffffU
						     : 0U) 
						   << 0x10U)))
				  : ((8U & ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
				      ? (((vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out2 
					   & ((8U & 
					       ((IData)(1U) 
						<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					       ? 0xffffU
					       : 0U)) 
					  | (vlSymsp->TOP__kpu.tmp1_buf__DOT__OUT__out__out3 
					     & (((8U 
						  & ((IData)(1U) 
						     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						  ? 0xffffU
						  : 0U) 
						<< 0x10U))) 
					 & (((8U & 
					      ((IData)(1U) 
					       << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					      ? 0xffffU
					      : 0U) 
					    | (((8U 
						 & ((IData)(1U) 
						    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						 ? 0xffffU
						 : 0U) 
					       << 0x10U)))
				      : ((0x20U & ((IData)(1U) 
						   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					  ? (((vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out2 
					       & ((0x20U 
						   & ((IData)(1U) 
						      << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						   ? 0xffffU
						   : 0U)) 
					      | (vlSymsp->TOP__kpu.mlu_buf__DOT__OUT__out__out3 
						 & (((0x20U 
						      & ((IData)(1U) 
							 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						      ? 0xffffU
						      : 0U) 
						    << 0x10U))) 
					     & (((0x20U 
						  & ((IData)(1U) 
						     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						  ? 0xffffU
						  : 0U) 
						| (((0x20U 
						     & ((IData)(1U) 
							<< (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						     ? 0xffffU
						     : 0U) 
						   << 0x10U)))
					  : ((0x40U 
					      & ((IData)(1U) 
						 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
					      ? (((vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out2 
						   & ((0x40U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 0xffffU
						       : 0U)) 
						  | (vlSymsp->TOP__kpu.shifter_buf__DOT__OUT__out__out3 
						     & (((0x40U 
							  & ((IData)(1U) 
							     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							  ? 0xffffU
							  : 0U) 
							<< 0x10U))) 
						 & (((0x40U 
						      & ((IData)(1U) 
							 << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						      ? 0xffffU
						      : 0U) 
						    | (((0x40U 
							 & ((IData)(1U) 
							    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							 ? 0xffffU
							 : 0U) 
						       << 0x10U)))
					      : ((0x80U 
						  & ((IData)(1U) 
						     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						  ? 
						 (((vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out2 
						    & ((0x80U 
							& ((IData)(1U) 
							   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						        ? 0xffffU
						        : 0U)) 
						   | (vlSymsp->TOP__kpu.timer_buf__DOT__OUT__out__out3 
						      & (((0x80U 
							   & ((IData)(1U) 
							      << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							   ? 0xffffU
							   : 0U) 
							 << 0x10U))) 
						  & (((0x80U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 0xffffU
						       : 0U) 
						     | (((0x80U 
							  & ((IData)(1U) 
							     << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							  ? 0xffffU
							  : 0U) 
							<< 0x10U)))
						  : 
						 ((0x10U 
						   & ((IData)(1U) 
						      << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						   ? 
						  (((((0x10U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 
						      vlSymsp->TOP__kpu__mmu__ram.mem
						      [
						      (0x3ffU 
						       & vlSymsp->TOP__kpu.tmp0_val)]
						       : 0U) 
						     & ((0x10U 
							 & ((IData)(1U) 
							    << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
							 ? 0xffffffffU
							 : 0U)) 
						    & ((0x10U 
							& ((IData)(1U) 
							   << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						        ? 0xffffffffU
						        : 0U)) 
						   & ((0x10U 
						       & ((IData)(1U) 
							  << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						       ? 0xffffffffU
						       : 0U))
						   : 
						  ((0x100U 
						    & ((IData)(1U) 
						       << (IData)(vlSymsp->TOP__kpu__control.control_out_plane)))
						    ? 
						   (0x3fU 
						    & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
						    : 0U))))))));
}

void Vkpu_kpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vkpu_kpu::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    N_CLK = VL_RAND_RESET_I(1);
    N_RST_ASYNC = VL_RAND_RESET_I(1);
    bus = VL_RAND_RESET_I(32);
    n_rst = VL_RAND_RESET_I(1);
    __Vcellout__jkflip__Q = VL_RAND_RESET_I(2);
    timer_val = VL_RAND_RESET_I(32);
    mlu_val = VL_RAND_RESET_I(32);
    __PVT__shifter_val = VL_RAND_RESET_I(32);
    tmp0_val = VL_RAND_RESET_I(32);
    tmp1_val = VL_RAND_RESET_I(32);
    opword_val = VL_RAND_RESET_I(6);
    __Vcelloutt__opword__OUT__out = VL_RAND_RESET_I(32);
    __PVT__control_tmp0_in_clk = VL_RAND_RESET_I(1);
    __PVT__control_tmp1_in_clk = VL_RAND_RESET_I(1);
    __PVT__control_opword_in_clk = VL_RAND_RESET_I(1);
    __PVT__jkflip__DOT__genblk1__BRA__0__KET____DOT__data = VL_RAND_RESET_I(1);
    __PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data = VL_RAND_RESET_I(1);
    __PVT__timer__DOT__rco = VL_RAND_RESET_I(9);
    timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO = VL_RAND_RESET_I(1);
    __PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    __PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count = VL_RAND_RESET_I(4);
    timer_buf__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    timer_buf__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    __PVT__mlu__DOT__slice_p = VL_RAND_RESET_I(8);
    __PVT__mlu__DOT__slice_g = VL_RAND_RESET_I(8);
    __PVT__mlu__DOT__carrys = VL_RAND_RESET_I(9);
    mlu__DOT____Vcellout__lookahead__CARRYS = VL_RAND_RESET_I(8);
    mlu__DOT____Vcellinp__lookahead__ADDR = VL_RAND_RESET_I(17);
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
    __PVT__mlu__DOT__lookahead__DOT__prev_carry = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__lookahead__DOT__carry = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low = VL_RAND_RESET_I(4);
    __PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop = VL_RAND_RESET_I(1);
    __PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen = VL_RAND_RESET_I(1);
    mlu_buf__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    mlu_buf__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__notter__A = VL_RAND_RESET_I(6);
    shifter__DOT____Vcellout__ander__Y = VL_RAND_RESET_I(4);
    __PVT__shifter__DOT__pre_reverse = VL_RAND_RESET_I(32);
    shifter__DOT____Vcellinp__pre_reverse_mux__B = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
	    __PVT__shifter__DOT__stage[__Vi0] = VL_RAND_RESET_I(32);
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
    shifter_buf__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    shifter_buf__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    tmp0__DOT__OUT__out__out4 = VL_RAND_RESET_I(32);
    tmp0__DOT__OUT__out__out5 = VL_RAND_RESET_I(32);
    tmp0__DOT__OUT__out__out6 = VL_RAND_RESET_I(32);
    tmp0__DOT__OUT__out__out7 = VL_RAND_RESET_I(32);
    __PVT__tmp0__DOT__low16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__tmp0__DOT__low16__DOT__high8 = VL_RAND_RESET_I(8);
    __PVT__tmp0__DOT__high16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__tmp0__DOT__high16__DOT__high8 = VL_RAND_RESET_I(8);
    tmp0_buf__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    tmp0_buf__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    tmp1__DOT__OUT__out__out4 = VL_RAND_RESET_I(32);
    tmp1__DOT__OUT__out__out5 = VL_RAND_RESET_I(32);
    tmp1__DOT__OUT__out__out6 = VL_RAND_RESET_I(32);
    tmp1__DOT__OUT__out__out7 = VL_RAND_RESET_I(32);
    __PVT__tmp1__DOT__low16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__tmp1__DOT__low16__DOT__high8 = VL_RAND_RESET_I(8);
    __PVT__tmp1__DOT__high16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__tmp1__DOT__high16__DOT__high8 = VL_RAND_RESET_I(8);
    tmp1_buf__DOT__OUT__out__out2 = VL_RAND_RESET_I(32);
    tmp1_buf__DOT__OUT__out__out3 = VL_RAND_RESET_I(32);
    opword__DOT__OUT__out__out4 = VL_RAND_RESET_I(32);
    opword__DOT__OUT__out__out5 = VL_RAND_RESET_I(32);
    opword__DOT__OUT__out__out6 = VL_RAND_RESET_I(32);
    opword__DOT__OUT__out__out7 = VL_RAND_RESET_I(32);
    __PVT__opword__DOT__low16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__opword__DOT__low16__DOT__high8 = VL_RAND_RESET_I(8);
    __PVT__opword__DOT__high16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__opword__DOT__high16__DOT__high8 = VL_RAND_RESET_I(8);
}
