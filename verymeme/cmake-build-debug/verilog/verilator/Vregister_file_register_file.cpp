// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_file.h for the primary calling header

#include "Vregister_file_register_file.h"
#include "Vregister_file__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vregister_file_register_file) {
    VL_CELL(registers, Vregister_file_sram__D5_W20);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vregister_file_register_file::__Vconfigure(Vregister_file__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vregister_file_register_file::~Vregister_file_register_file() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vregister_file_register_file::_settle__TOP__register_file__1(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vregister_file_register_file::_settle__TOP__register_file__1\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__register_file.__Vcellout__reg_sel_mux__OUT 
	= (0xffU & ((0U == (IData)(vlTOPp->REG_SEL))
		     ? ((((1U & ((IData)(1U) << (IData)(vlTOPp->REG_SEL)))
			   ? (IData)(vlTOPp->REG_SRC0)
			   : 0U) & ((1U & ((IData)(1U) 
					   << (IData)(vlTOPp->REG_SEL)))
				     ? 0xffU : 0U)) 
			& ((1U & ((IData)(1U) << (IData)(vlTOPp->REG_SEL)))
			    ? 0xffU : 0U)) : ((1U == (IData)(vlTOPp->REG_SEL))
					       ? ((
						   ((2U 
						     & ((IData)(1U) 
							<< (IData)(vlTOPp->REG_SEL)))
						     ? (IData)(vlTOPp->REG_SRC1)
						     : 0U) 
						   & ((2U 
						       & ((IData)(1U) 
							  << (IData)(vlTOPp->REG_SEL)))
						       ? 0xffU
						       : 0U)) 
						  & ((2U 
						      & ((IData)(1U) 
							 << (IData)(vlTOPp->REG_SEL)))
						      ? 0xffU
						      : 0U))
					       : ((2U 
						   == (IData)(vlTOPp->REG_SEL))
						   ? 
						  ((((4U 
						      & ((IData)(1U) 
							 << (IData)(vlTOPp->REG_SEL)))
						      ? (IData)(vlTOPp->REG_SRC2)
						      : 0U) 
						    & ((4U 
							& ((IData)(1U) 
							   << (IData)(vlTOPp->REG_SEL)))
						        ? 0xffU
						        : 0U)) 
						   & ((4U 
						       & ((IData)(1U) 
							  << (IData)(vlTOPp->REG_SEL)))
						       ? 0xffU
						       : 0U))
						   : 0U))));
}

void Vregister_file_register_file::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vregister_file_register_file::_ctor_var_reset\n"); );
    // Body
    REG_SEL = VL_RAND_RESET_I(2);
    REG_SRC0 = VL_RAND_RESET_I(5);
    REG_SRC1 = VL_RAND_RESET_I(5);
    REG_SRC2 = VL_RAND_RESET_I(5);
    IN_DATA = VL_RAND_RESET_I(32);
    N_WE = VL_RAND_RESET_I(1);
    N_OE = VL_RAND_RESET_I(1);
    N_RST = VL_RAND_RESET_I(1);
    OUT_DATA = VL_RAND_RESET_I(32);
    __Vcellout__reg_sel_mux__OUT = VL_RAND_RESET_I(8);
    OUT_DATA__out = VL_RAND_RESET_I(32);
    OUT_DATA__en = VL_RAND_RESET_I(32);
}
