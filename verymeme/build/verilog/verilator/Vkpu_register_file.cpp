// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkpu.h for the primary calling header

#include "Vkpu_register_file.h"
#include "Vkpu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vkpu_register_file) {
    VL_CELL(registers, Vkpu_sram__D5_W20);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vkpu_register_file::__Vconfigure(Vkpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vkpu_register_file::~Vkpu_register_file() {
}

//--------------------
// Internal Methods

void Vkpu_register_file::_settle__TOP__kpu__regs__1(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_register_file::_settle__TOP__kpu__regs__1\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__regs.__Vcellout__reg_sel_mux__OUT 
	= (0xffU & ((0U == (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
				  >> 6U))) ? ((((1U 
						 & ((IData)(1U) 
						    << 
						    (3U 
						     & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							>> 6U))))
						 ? 
						(0x1fU 
						 & (vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out 
						    >> 6U))
						 : 0U) 
					       & ((1U 
						   & ((IData)(1U) 
						      << 
						      (3U 
						       & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							  >> 6U))))
						   ? 0xffU
						   : 0U)) 
					      & ((1U 
						  & ((IData)(1U) 
						     << 
						     (3U 
						      & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							 >> 6U))))
						  ? 0xffU
						  : 0U))
		     : ((1U == (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
				      >> 6U))) ? ((
						   ((2U 
						     & ((IData)(1U) 
							<< 
							(3U 
							 & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							    >> 6U))))
						     ? 
						    (0x1fU 
						     & (vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out 
							>> 0xbU))
						     : 0U) 
						   & ((2U 
						       & ((IData)(1U) 
							  << 
							  (3U 
							   & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							      >> 6U))))
						       ? 0xffU
						       : 0U)) 
						  & ((2U 
						      & ((IData)(1U) 
							 << 
							 (3U 
							  & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							     >> 6U))))
						      ? 0xffU
						      : 0U))
			 : ((2U == (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					  >> 6U))) ? 
			    ((((4U & ((IData)(1U) << 
				      (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					     >> 6U))))
			        ? (0x1fU & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
			        : 0U) & ((4U & ((IData)(1U) 
						<< 
						(3U 
						 & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						    >> 6U))))
					  ? 0xffU : 0U)) 
			     & ((4U & ((IData)(1U) 
				       << (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						 >> 6U))))
				 ? 0xffU : 0U)) : 0U))));
    vlSymsp->TOP__kpu__regs__registers.__PVT__N_WE 
	= (1U & (~ (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A)));
}

VL_INLINE_OPT void Vkpu_register_file::_combo__TOP__kpu__regs__2(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_register_file::_combo__TOP__kpu__regs__2\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__regs__registers.__PVT__N_WE 
	= (1U & (~ (IData)(vlSymsp->TOP__kpu__control.__Vcellinp__inverter__A)));
}

VL_INLINE_OPT void Vkpu_register_file::_multiclk__TOP__kpu__regs__3(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_register_file::_multiclk__TOP__kpu__regs__3\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__regs.__Vcellout__reg_sel_mux__OUT 
	= (0xffU & ((0U == (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
				  >> 6U))) ? ((((1U 
						 & ((IData)(1U) 
						    << 
						    (3U 
						     & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							>> 6U))))
						 ? 
						(0x1fU 
						 & (vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out 
						    >> 6U))
						 : 0U) 
					       & ((1U 
						   & ((IData)(1U) 
						      << 
						      (3U 
						       & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							  >> 6U))))
						   ? 0xffU
						   : 0U)) 
					      & ((1U 
						  & ((IData)(1U) 
						     << 
						     (3U 
						      & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							 >> 6U))))
						  ? 0xffU
						  : 0U))
		     : ((1U == (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
				      >> 6U))) ? ((
						   ((2U 
						     & ((IData)(1U) 
							<< 
							(3U 
							 & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							    >> 6U))))
						     ? 
						    (0x1fU 
						     & (vlSymsp->TOP__kpu.__Vcelloutt__opword__OUT__out 
							>> 0xbU))
						     : 0U) 
						   & ((2U 
						       & ((IData)(1U) 
							  << 
							  (3U 
							   & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							      >> 6U))))
						       ? 0xffU
						       : 0U)) 
						  & ((2U 
						      & ((IData)(1U) 
							 << 
							 (3U 
							  & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
							     >> 6U))))
						      ? 0xffU
						      : 0U))
			 : ((2U == (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					  >> 6U))) ? 
			    ((((4U & ((IData)(1U) << 
				      (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
					     >> 6U))))
			        ? (0x1fU & vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out)
			        : 0U) & ((4U & ((IData)(1U) 
						<< 
						(3U 
						 & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						    >> 6U))))
					  ? 0xffU : 0U)) 
			     & ((4U & ((IData)(1U) 
				       << (3U & (vlSymsp->TOP__kpu__control.__Vcelloutt__microcode_latch__OUT__out 
						 >> 6U))))
				 ? 0xffU : 0U)) : 0U))));
}

void Vkpu_register_file::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vkpu_register_file::_ctor_var_reset\n"); );
    // Body
    __PVT__REG_SEL = VL_RAND_RESET_I(2);
    __PVT__REG_SRC0 = VL_RAND_RESET_I(5);
    __PVT__REG_SRC1 = VL_RAND_RESET_I(5);
    __PVT__REG_SRC2 = VL_RAND_RESET_I(5);
    __PVT__IN_DATA = VL_RAND_RESET_I(32);
    __PVT__N_WE = VL_RAND_RESET_I(1);
    __PVT__N_OE = VL_RAND_RESET_I(1);
    __PVT__N_RST = VL_RAND_RESET_I(1);
    __PVT__OUT_DATA = VL_RAND_RESET_I(32);
    __Vcellout__reg_sel_mux__OUT = VL_RAND_RESET_I(8);
    OUT_DATA__out = VL_RAND_RESET_I(32);
    OUT_DATA__en = VL_RAND_RESET_I(32);
}
