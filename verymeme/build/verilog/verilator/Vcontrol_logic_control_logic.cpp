// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_logic.h for the primary calling header

#include "Vcontrol_logic_control_logic.h"
#include "Vcontrol_logic__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vcontrol_logic_control_logic) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vcontrol_logic_control_logic::__Vconfigure(Vcontrol_logic__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcontrol_logic_control_logic::~Vcontrol_logic_control_logic() {
}

//--------------------
// Internal Methods

void Vcontrol_logic_control_logic::_initial__TOP__control_logic__1(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_initial__TOP__control_logic__1\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at chip74273.v:16
    if ((1U & (~ (IData)(vlTOPp->N_RST)))) {
	vlSymsp->TOP__control_logic.__PVT__opcode_reg__DOT__value = 0U;
    }
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_sequent__TOP__control_logic__2(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_sequent__TOP__control_logic__2\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74590.v:13
    vlSymsp->TOP__control_logic.__PVT__counter__DOT__counter__DOT__count 
	= (0xffU & ((IData)(vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst)
		     ? ((IData)(1U) + (IData)(vlSymsp->TOP__control_logic.__PVT__counter__DOT__counter__DOT__count))
		     : 0U));
    vlSymsp->TOP__control_logic.microop_count = (0x1fU 
						 & (IData)(vlSymsp->TOP__control_logic.__PVT__counter__DOT__counter__DOT__count));
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_sequent__TOP__control_logic__3(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_sequent__TOP__control_logic__3\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__high16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__control_logic.__PVT__microcode_val 
		    >> 0x18U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__high16__DOT__low8 
	= (0xffU & (vlSymsp->TOP__control_logic.__PVT__microcode_val 
		    >> 0x10U));
    // ALWAYS at chip7416374.v:20
    vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__low16__DOT__high8 
	= (0xffU & (vlSymsp->TOP__control_logic.__PVT__microcode_val 
		    >> 8U));
    // ALWAYS at chip7416374.v:19
    vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__low16__DOT__low8 
	= (0xffU & vlSymsp->TOP__control_logic.__PVT__microcode_val);
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out6 
	= ((0xffffffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out6) 
	   | ((IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__high16__DOT__high8) 
	      << 0x18U));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out7 
	= ((0xff00ffffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out7) 
	   | ((IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__high16__DOT__low8) 
	      << 0x10U));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out4 
	= ((0xffff00ffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out4) 
	   | ((IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__low16__DOT__high8) 
	      << 8U));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out5 
	= ((0xffffff00U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out5) 
	   | (IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__low16__DOT__low8));
    vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
	= ((((0xff00U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out4) 
	     | (0xffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out5)) 
	    | (0xff000000U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out6)) 
	   | (0xff0000U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out7));
    vlSymsp->TOP__control_logic.control_misc_plane 
	= (1U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
		 >> 0xfU));
    vlSymsp->TOP__control_logic.control_out_plane = 
	(0xfU & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
		 >> 8U));
    vlSymsp->TOP__control_logic.control_in_plane = 
	(7U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
	       >> 0xcU));
}

void Vcontrol_logic_control_logic::_settle__TOP__control_logic__4(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_settle__TOP__control_logic__4\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= (0xfff0ffffU & vlSymsp->TOP__control_logic.__PVT__microcode_val);
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= (0xffcfffffU & vlSymsp->TOP__control_logic.__PVT__microcode_val);
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= (0x7fffffU & vlSymsp->TOP__control_logic.__PVT__microcode_val);
    vlSymsp->TOP__control_logic.microop_count = (0x1fU 
						 & (IData)(vlSymsp->TOP__control_logic.__PVT__counter__DOT__counter__DOT__count));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out4 
	= ((0xffff00ffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out4) 
	   | ((IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__low16__DOT__high8) 
	      << 8U));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out5 
	= ((0xffffff00U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out5) 
	   | (IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__low16__DOT__low8));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out6 
	= ((0xffffffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out6) 
	   | ((IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__high16__DOT__high8) 
	      << 0x18U));
    vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out7 
	= ((0xff00ffffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out7) 
	   | ((IData)(vlSymsp->TOP__control_logic.__PVT__microcode_latch__DOT__high16__DOT__low8) 
	      << 0x10U));
    vlSymsp->TOP__control_logic.opcode = (0x3fU & (IData)(vlSymsp->TOP__control_logic.__PVT__opcode_reg__DOT__value));
    vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
	= ((((0xff00U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out4) 
	     | (0xffU & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out5)) 
	    | (0xff000000U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out6)) 
	   | (0xff0000U & vlSymsp->TOP__control_logic.microcode_latch__DOT__OUT__out__out7));
    vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR 
	= (((IData)(vlSymsp->TOP__control_logic.opcode) 
	    << 5U) | (IData)(vlSymsp->TOP__control_logic.microop_count));
    vlSymsp->TOP__control_logic.control_misc_plane 
	= (1U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
		 >> 0xfU));
    vlSymsp->TOP__control_logic.control_out_plane = 
	(0xfU & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
		 >> 8U));
    vlSymsp->TOP__control_logic.control_in_plane = 
	(7U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
	       >> 0xcU));
    vlSymsp->TOP__control_logic.control_opcode_sel 
	= (1U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
		 >> 0x16U));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffffffc0U & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | ((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
			       >> 5U))) ? ((0U == (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					    ? 0x1fU
					    : ((1U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					        ? 1U
					        : 0U))
	       : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				   >> 5U))) ? ((0U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					        ? 0x1fU
					        : (
						   (1U 
						    == 
						    (0x1fU 
						     & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						    ? 0U
						    : 
						   ((2U 
						     == 
						     (0x1fU 
						      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						     ? 1U
						     : 0U)))
		   : 0U)));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffffff3fU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					     ? 2U : 0U)
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						  ? 0U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						   ? 2U
						   : 0U)))
		    : 0U)) << 6U));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xfffff0ffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					     ? 0U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					      ? 8U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						 ? 1U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						  ? 4U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						   ? 1U
						   : 0U)))
		    : 0U)) << 8U));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffff8fffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					     ? 1U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					      ? 6U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						  ? 5U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						   ? 3U
						   : 0U)))
		    : 0U)) << 0xcU));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffff7fffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))))) 
	      << 0xfU));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffbfffffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))))) 
	      << 0x16U));
    vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst 
	= ((~ (0x7fU & (((IData)(1U) << (IData)(vlSymsp->TOP__control_logic.control_misc_plane)) 
			>> 1U))) & (IData)(vlTOPp->N_RST));
    vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y 
	= (0xffU & ((IData)(vlTOPp->CLK) ? ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__control_logic.control_in_plane))
		     : 0U));
    vlSymsp->TOP__control_logic.__PVT__opcode_in_clk 
	= (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
		 >> 6U));
    vlSymsp->TOP__control_logic.__Vcellinp__inverter__A 
	= (((IData)(vlSymsp->TOP__control_logic.control_opcode_sel) 
	    << 2U) | ((2U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
			     >> 3U)) | (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
					      >> 1U))));
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_combo__TOP__control_logic__5(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_combo__TOP__control_logic__5\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst 
	= ((~ (0x7fU & (((IData)(1U) << (IData)(vlSymsp->TOP__control_logic.control_misc_plane)) 
			>> 1U))) & (IData)(vlTOPp->N_RST));
    vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y 
	= (0xffU & ((IData)(vlTOPp->CLK) ? ((IData)(1U) 
					    << (IData)(vlSymsp->TOP__control_logic.control_in_plane))
		     : 0U));
    vlSymsp->TOP__control_logic.__PVT__opcode_in_clk 
	= (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
		 >> 6U));
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_sequent__TOP__control_logic__6(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_sequent__TOP__control_logic__6\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at chip74273.v:21
    vlSymsp->TOP__control_logic.__PVT__opcode_reg__DOT__value 
	= ((IData)(vlTOPp->N_RST) ? (0x3fU & ((IData)(vlSymsp->TOP__control_logic.control_opcode_sel)
					       ? ((
						   ((4U 
						     & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A))
						     ? (IData)(vlTOPp->BUS)
						     : 0U) 
						   & ((4U 
						       & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A))
						       ? 0xffU
						       : 0U)) 
						  & ((4U 
						      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A))
						      ? 0xffU
						      : 0U))
					       : ((
						   ((IData)(vlSymsp->TOP__control_logic.control_opcode_sel)
						     ? 0U
						     : (IData)(vlTOPp->OPWORD)) 
						   & ((IData)(vlSymsp->TOP__control_logic.control_opcode_sel)
						       ? 0U
						       : 0xffU)) 
						  & ((IData)(vlSymsp->TOP__control_logic.control_opcode_sel)
						      ? 0U
						      : 0xffU))))
	    : 0U);
    vlSymsp->TOP__control_logic.opcode = (0x3fU & (IData)(vlSymsp->TOP__control_logic.__PVT__opcode_reg__DOT__value));
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_sequent__TOP__control_logic__7(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_sequent__TOP__control_logic__7\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic.control_opcode_sel 
	= (1U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
		 >> 0x16U));
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_multiclk__TOP__control_logic__8(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_multiclk__TOP__control_logic__8\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR 
	= (((IData)(vlSymsp->TOP__control_logic.opcode) 
	    << 5U) | (IData)(vlSymsp->TOP__control_logic.microop_count));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffffffc0U & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | ((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
			       >> 5U))) ? ((0U == (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					    ? 0x1fU
					    : ((1U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					        ? 1U
					        : 0U))
	       : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				   >> 5U))) ? ((0U 
						== 
						(0x1fU 
						 & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					        ? 0x1fU
					        : (
						   (1U 
						    == 
						    (0x1fU 
						     & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						    ? 0U
						    : 
						   ((2U 
						     == 
						     (0x1fU 
						      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						     ? 1U
						     : 0U)))
		   : 0U)));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffffff3fU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					     ? 2U : 0U)
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						  ? 0U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						   ? 2U
						   : 0U)))
		    : 0U)) << 6U));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xfffff0ffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					     ? 0U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					      ? 8U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						 ? 1U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						  ? 4U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						   ? 1U
						   : 0U)))
		    : 0U)) << 8U));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffff8fffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) ? ((0U == 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					     ? 1U : 
					    ((1U == 
					      (0x1fU 
					       & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
					      ? 6U : 0U))
	        : ((1U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				    >> 5U))) ? ((0U 
						 == 
						 (0x1fU 
						  & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						 ? 2U
						 : 
						((1U 
						  == 
						  (0x1fU 
						   & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						  ? 5U
						  : 
						 ((2U 
						   == 
						   (0x1fU 
						    & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR)))
						   ? 3U
						   : 0U)))
		    : 0U)) << 0xcU));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffff7fffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))))) 
	      << 0xfU));
    vlSymsp->TOP__control_logic.__PVT__microcode_val 
	= ((0xffbfffffU & vlSymsp->TOP__control_logic.__PVT__microcode_val) 
	   | (((0U == (0x3fU & ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR) 
				>> 5U))) & ((0U != 
					     (0x1fU 
					      & (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))) 
					    & (1U == 
					       (0x1fU 
						& (IData)(vlSymsp->TOP__control_logic.__Vcellinp__microcode__ADDR))))) 
	      << 0x16U));
}

VL_INLINE_OPT void Vcontrol_logic_control_logic::_combo__TOP__control_logic__9(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_combo__TOP__control_logic__9\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic.__Vcellinp__inverter__A 
	= (((IData)(vlSymsp->TOP__control_logic.control_opcode_sel) 
	    << 2U) | ((2U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
			     >> 3U)) | (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
					      >> 1U))));
}

void Vcontrol_logic_control_logic::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vcontrol_logic_control_logic::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    N_CLK = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    BUS = VL_RAND_RESET_I(8);
    OPWORD = VL_RAND_RESET_I(6);
    CTRL_DATA = VL_RAND_RESET_I(6);
    REG_SEL = VL_RAND_RESET_I(2);
    MLU_PLANE = VL_RAND_RESET_I(4);
    SHIFTER_PLANE = VL_RAND_RESET_I(2);
    REG_N_IN_CLK = VL_RAND_RESET_I(1);
    TMP0_IN_CLK = VL_RAND_RESET_I(1);
    TMP1_IN_CLK = VL_RAND_RESET_I(1);
    MMU_N_IN_CLK = VL_RAND_RESET_I(1);
    OPWORD_IN_CLK = VL_RAND_RESET_I(1);
    REG_N_OUT = VL_RAND_RESET_I(1);
    TMP0_N_OUT = VL_RAND_RESET_I(1);
    TMP1_N_OUT = VL_RAND_RESET_I(1);
    MMU_N_OUT = VL_RAND_RESET_I(1);
    MLU_N_OUT = VL_RAND_RESET_I(1);
    SHIFTER_N_OUT = VL_RAND_RESET_I(1);
    TIMER_N_OUT = VL_RAND_RESET_I(1);
    CTRL_DATA_N_OUT = VL_RAND_RESET_I(1);
    BOOTSTRAP_ADDR = VL_RAND_RESET_I(12);
    BOOTSTRAP_DATA = VL_RAND_RESET_I(8);
    N_BOOTED = VL_RAND_RESET_I(1);
    BOOTSTRAP_N_WE = VL_RAND_RESET_I(1);
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
