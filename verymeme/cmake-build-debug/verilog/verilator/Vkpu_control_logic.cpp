// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkpu.h for the primary calling header

#include "Vkpu_control_logic.h"
#include "Vkpu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vkpu_control_logic) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vkpu_control_logic::__Vconfigure(Vkpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vkpu_control_logic::~Vkpu_control_logic() {
}

//--------------------
// Internal Methods

void Vkpu_control_logic::_initial__TOP__kpu__control__1(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_initial__TOP__kpu__control__1\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at chip74273.v:16
    if ((1U & (~ (IData)(vlSymsp->TOP__kpu.n_rst)))) {
	vlSymsp->TOP__kpu__control.__PVT__opcode_reg__DOT__value = 0U;
    }
}

void Vkpu_control_logic::_settle__TOP__kpu__control__2(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_settle__TOP__kpu__control__2\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= (0xfff0ffffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val);
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= (0xffcfffffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val);
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= (0x7fffffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val);
    vlSymsp->TOP__kpu__control.microop_count = (0x1fU 
						& (IData)(vlSymsp->TOP__kpu__control.__PVT__counter__DOT__counter__DOT__count));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out4 
	= ((0xffff00ffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out4) 
	   | ((IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__low16__DOT__high8) 
	      << 8U));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out5 
	= ((0xffffff00U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out5) 
	   | (IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out6 
	= ((0xffffffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out6) 
	   | ((IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__high16__DOT__high8) 
	      << 0x18U));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out7 
	= ((0xff00ffffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out7) 
	   | ((IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__high16__DOT__low8) 
	      << 0x10U));
    vlSymsp->TOP__kpu__control.opcode = (0x3fU & (IData)(vlSymsp->TOP__kpu__control.__PVT__opcode_reg__DOT__value));
    vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
	= ((((0xff00U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out4) 
	     | (0xffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out5)) 
	    | (0xff000000U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out6)) 
	   | (0xff0000U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR 
	= (((IData)(vlSymsp->TOP__kpu__control.opcode) 
	    << 5U) | (IData)(vlSymsp->TOP__kpu__control.microop_count));
    vlSymsp->TOP__kpu__control.control_misc_plane = 
	(1U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
	       >> 0xfU));
    vlSymsp->TOP__kpu__control.control_out_plane = 
	(0xfU & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
		 >> 8U));
    vlSymsp->TOP__kpu__control.control_in_plane = (7U 
						   & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						      >> 0xcU));
    vlSymsp->TOP__kpu__control.control_opcode_sel = 
	(1U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
	       >> 0x16U));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffffffc0U & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | ((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
			       >> 5U))) ? ((0U == (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					    ? 0x1fU
					    : ((1U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					        ? 1U
					        : 0U))
	       : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				   >> 5U))) ? ((0U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					        ? 0x1fU
					        : (
						   (1U 
						    == 
						    (0x1fU 
						     & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						    ? 0U
						    : 
						   ((2U 
						     == 
						     (0x1fU 
						      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						     ? 1U
						     : 0U)))
		   : 0U)));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffffff3fU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					     ? 2U : 0U)
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						  ? 0U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						   ? 2U
						   : 0U)))
		    : 0U)) << 6U));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xfffff0ffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					     ? 0U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					      ? 8U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						 ? 1U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						  ? 4U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						   ? 1U
						   : 0U)))
		    : 0U)) << 8U));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffff8fffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					     ? 1U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					      ? 6U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						  ? 5U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						   ? 3U
						   : 0U)))
		    : 0U)) << 0xcU));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffff7fffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))))) 
	      << 0xfU));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffbfffffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))))) 
	      << 0x16U));
    vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst 
	= ((~ (0x7fU & (((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_misc_plane)) 
			>> 1U))) & (IData)(vlSymsp->TOP__kpu.n_rst));
    vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y 
	= (0xffU & ((IData)(vlTOPp->CLK) ? ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__kpu__control.control_in_plane))
		     : 0U));
    vlSymsp->TOP__kpu__control.__PVT__opcode_in_clk 
	= (1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
		 >> 6U));
    vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A 
	= (((IData)(vlSymsp->TOP__kpu__control.control_opcode_sel) 
	    << 2U) | ((2U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
			     >> 3U)) | (1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
					      >> 1U))));
}

VL_INLINE_OPT void Vkpu_control_logic::_sequent__TOP__kpu__control__3(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_sequent__TOP__kpu__control__3\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74590.v:13
    vlSymsp->TOP__kpu__control.__PVT__counter__DOT__counter__DOT__count 
	= (0xffU & ((IData)(vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst)
		     ? ((IData)(1U) + (IData)(vlSymsp->TOP__kpu__control.__PVT__counter__DOT__counter__DOT__count))
		     : 0U));
    vlSymsp->TOP__kpu__control.microop_count = (0x1fU 
						& (IData)(vlSymsp->TOP__kpu__control.__PVT__counter__DOT__counter__DOT__count));
}

VL_INLINE_OPT void Vkpu_control_logic::_sequent__TOP__kpu__control__4(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_sequent__TOP__kpu__control__4\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__high16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu__control.__PVT__microcode_val 
		    >> 0x18U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__high16__DOT__low8 
	= (0xffU & (vlSymsp->TOP__kpu__control.__PVT__microcode_val 
		    >> 0x10U));
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__low16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__kpu__control.__PVT__microcode_val 
		    >> 8U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__low16__DOT__low8 
	= (0xffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val);
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out6 
	= ((0xffffffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out6) 
	   | ((IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__high16__DOT__high8) 
	      << 0x18U));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out7 
	= ((0xff00ffffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out7) 
	   | ((IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__high16__DOT__low8) 
	      << 0x10U));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out4 
	= ((0xffff00ffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out4) 
	   | ((IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__low16__DOT__high8) 
	      << 8U));
    vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out5 
	= ((0xffffff00U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out5) 
	   | (IData)(vlSymsp->TOP__kpu__control.__PVT__microcode_latch__DOT__low16__DOT__low8));
    vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
	= ((((0xff00U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out4) 
	     | (0xffU & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out5)) 
	    | (0xff000000U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out6)) 
	   | (0xff0000U & vlSymsp->TOP__kpu__control.microcode_latch__DOT__OUT__out__out7));
    vlSymsp->TOP__kpu__control.control_misc_plane = 
	(1U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
	       >> 0xfU));
    vlSymsp->TOP__kpu__control.control_out_plane = 
	(0xfU & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
		 >> 8U));
    vlSymsp->TOP__kpu__control.control_in_plane = (7U 
						   & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						      >> 0xcU));
}

VL_INLINE_OPT void Vkpu_control_logic::_combo__TOP__kpu__control__5(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_combo__TOP__kpu__control__5\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst 
	= ((~ (0x7fU & (((IData)(1U) << (IData)(vlSymsp->TOP__kpu__control.control_misc_plane)) 
			>> 1U))) & (IData)(vlSymsp->TOP__kpu.n_rst));
    vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y 
	= (0xffU & ((IData)(vlTOPp->CLK) ? ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__kpu__control.control_in_plane))
		     : 0U));
    vlSymsp->TOP__kpu__control.__PVT__opcode_in_clk 
	= (1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
		 >> 6U));
}

VL_INLINE_OPT void Vkpu_control_logic::_sequent__TOP__kpu__control__6(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_sequent__TOP__kpu__control__6\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74273.v:21
    vlSymsp->TOP__kpu__control.__PVT__opcode_reg__DOT__value 
	= ((IData)(vlSymsp->TOP__kpu.n_rst) ? (0x3fU 
					       & ((IData)(vlSymsp->TOP__kpu__control.control_opcode_sel)
						   ? 
						  ((((4U 
						      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A))
						      ? vlSymsp->TOP__kpu.bus
						      : 0U) 
						    & ((4U 
							& (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A))
						        ? 0xffU
						        : 0U)) 
						   & ((4U 
						       & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A))
						       ? 0xffU
						       : 0U))
						   : 
						  ((((IData)(vlSymsp->TOP__kpu__control.control_opcode_sel)
						      ? 0U
						      : (IData)(vlSymsp->TOP__kpu.opword_val)) 
						    & ((IData)(vlSymsp->TOP__kpu__control.control_opcode_sel)
						        ? 0U
						        : 0xffU)) 
						   & ((IData)(vlSymsp->TOP__kpu__control.control_opcode_sel)
						       ? 0U
						       : 0xffU))))
	    : 0U);
    vlSymsp->TOP__kpu__control.opcode = (0x3fU & (IData)(vlSymsp->TOP__kpu__control.__PVT__opcode_reg__DOT__value));
}

VL_INLINE_OPT void Vkpu_control_logic::_sequent__TOP__kpu__control__7(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_sequent__TOP__kpu__control__7\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__control.control_opcode_sel = 
	(1U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
	       >> 0x16U));
}

VL_INLINE_OPT void Vkpu_control_logic::_multiclk__TOP__kpu__control__8(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_multiclk__TOP__kpu__control__8\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR 
	= (((IData)(vlSymsp->TOP__kpu__control.opcode) 
	    << 5U) | (IData)(vlSymsp->TOP__kpu__control.microop_count));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffffffc0U & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | ((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
			       >> 5U))) ? ((0U == (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					    ? 0x1fU
					    : ((1U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					        ? 1U
					        : 0U))
	       : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				   >> 5U))) ? ((0U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					        ? 0x1fU
					        : (
						   (1U 
						    == 
						    (0x1fU 
						     & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						    ? 0U
						    : 
						   ((2U 
						     == 
						     (0x1fU 
						      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						     ? 1U
						     : 0U)))
		   : 0U)));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffffff3fU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					     ? 2U : 0U)
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						  ? 0U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						   ? 2U
						   : 0U)))
		    : 0U)) << 6U));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xfffff0ffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					     ? 0U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					      ? 8U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						 ? 1U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						  ? 4U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						   ? 1U
						   : 0U)))
		    : 0U)) << 8U));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffff8fffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					     ? 1U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
					      ? 6U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						  ? 5U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR)))
						   ? 3U
						   : 0U)))
		    : 0U)) << 0xcU));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffff7fffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))))) 
	      << 0xfU));
    vlSymsp->TOP__kpu__control.__PVT__microcode_val 
	= ((0xffbfffffU & vlSymsp->TOP__kpu__control.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__microcode__ADDR))))) 
	      << 0x16U));
}

VL_INLINE_OPT void Vkpu_control_logic::_combo__TOP__kpu__control__9(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_combo__TOP__kpu__control__9\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A 
	= (((IData)(vlSymsp->TOP__kpu__control.control_opcode_sel) 
	    << 2U) | ((2U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
			     >> 3U)) | (1U & ((IData)(vlSymsp->TOP__kpu__control.__Vcellout__in_plane_decoder__Y) 
					      >> 1U))));
}

void Vkpu_control_logic::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_control_logic::_ctor_var_reset\n"); );
    // Body
    __PVT__CLK = VL_RAND_RESET_I(1);
    __PVT__N_CLK = VL_RAND_RESET_I(1);
    __PVT__N_RST = VL_RAND_RESET_I(1);
    __PVT__BUS = VL_RAND_RESET_I(8);
    __PVT__OPWORD = VL_RAND_RESET_I(6);
    __PVT__CTRL_DATA = VL_RAND_RESET_I(6);
    __PVT__REG_SEL = VL_RAND_RESET_I(2);
    __PVT__MLU_PLANE = VL_RAND_RESET_I(4);
    __PVT__SHIFTER_PLANE = VL_RAND_RESET_I(2);
    __PVT__REG_N_IN_CLK = VL_RAND_RESET_I(1);
    __PVT__TMP0_IN_CLK = VL_RAND_RESET_I(1);
    __PVT__TMP1_IN_CLK = VL_RAND_RESET_I(1);
    __PVT__MMU_N_IN_CLK = VL_RAND_RESET_I(1);
    __PVT__OPWORD_IN_CLK = VL_RAND_RESET_I(1);
    __PVT__REG_N_OUT = VL_RAND_RESET_I(1);
    __PVT__TMP0_N_OUT = VL_RAND_RESET_I(1);
    __PVT__TMP1_N_OUT = VL_RAND_RESET_I(1);
    __PVT__MMU_N_OUT = VL_RAND_RESET_I(1);
    __PVT__MLU_N_OUT = VL_RAND_RESET_I(1);
    __PVT__SHIFTER_N_OUT = VL_RAND_RESET_I(1);
    __PVT__TIMER_N_OUT = VL_RAND_RESET_I(1);
    __PVT__CTRL_DATA_N_OUT = VL_RAND_RESET_I(1);
    __PVT__BOOTSTRAP_ADDR = VL_RAND_RESET_I(12);
    __PVT__BOOTSTRAP_DATA = VL_RAND_RESET_I(8);
    __PVT__N_BOOTED = VL_RAND_RESET_I(1);
    __PVT__BOOTSTRAP_N_WE = VL_RAND_RESET_I(1);
    __Vcellinp__inverter__A = VL_RAND_RESET_I(6);
    __PVT__counter_combined_n_rst = VL_RAND_RESET_I(1);
    microop_count = VL_RAND_RESET_I(5);
    opcode = VL_RAND_RESET_I(6);
    __PVT__microcode_val = VL_RAND_RESET_I(32);
    __Vcellinp__microcode__ADDR = VL_RAND_RESET_I(11);
    control_in_plane = VL_RAND_RESET_I(3);
    control_out_plane = VL_RAND_RESET_I(4);
    control_misc_plane = VL_RAND_RESET_I(1);
    control_opcode_sel = VL_RAND_RESET_I(1);
    __Vcelloutt__microcode_latch__OUT__out = VL_RAND_RESET_I(32);
    __PVT__opcode_in_clk = VL_RAND_RESET_I(1);
    __Vcellout__in_plane_decoder__Y = VL_RAND_RESET_I(8);
    CTRL_DATA__out = VL_RAND_RESET_I(6);
    CTRL_DATA__en = VL_RAND_RESET_I(6);
    REG_SEL__out = VL_RAND_RESET_I(2);
    REG_SEL__en = VL_RAND_RESET_I(2);
    MLU_PLANE__out = VL_RAND_RESET_I(4);
    MLU_PLANE__en = VL_RAND_RESET_I(4);
    SHIFTER_PLANE__out = VL_RAND_RESET_I(2);
    SHIFTER_PLANE__en = VL_RAND_RESET_I(2);
    __PVT__counter__DOT__counter__DOT__count = VL_RAND_RESET_I(8);
    __PVT__opcode_reg__DOT__value = VL_RAND_RESET_I(8);
    microcode_latch__DOT__OUT__out__out4 = VL_RAND_RESET_I(32);
    microcode_latch__DOT__OUT__out__out5 = VL_RAND_RESET_I(32);
    microcode_latch__DOT__OUT__out__out6 = VL_RAND_RESET_I(32);
    microcode_latch__DOT__OUT__out__out7 = VL_RAND_RESET_I(32);
    __PVT__microcode_latch__DOT__low16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__microcode_latch__DOT__low16__DOT__high8 = VL_RAND_RESET_I(8);
    __PVT__microcode_latch__DOT__high16__DOT__low8 = VL_RAND_RESET_I(8);
    __PVT__microcode_latch__DOT__high16__DOT__high8 = VL_RAND_RESET_I(8);
}
