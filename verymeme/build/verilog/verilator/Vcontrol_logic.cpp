// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_logic.h for the primary calling header

#include "Vcontrol_logic.h"
#include "Vcontrol_logic__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vcontrol_logic) {
    Vcontrol_logic__Syms* __restrict vlSymsp = __VlSymsp = new Vcontrol_logic__Syms(this, name());
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(control_logic, Vcontrol_logic_control_logic);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcontrol_logic::__Vconfigure(Vcontrol_logic__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcontrol_logic::~Vcontrol_logic() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vcontrol_logic::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol_logic::eval\n"); );
    Vcontrol_logic__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vcontrol_logic::_eval_initial_loop(Vcontrol_logic__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vcontrol_logic::_sequent__TOP__1(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_sequent__TOP__1\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SHIFTER_PLANE = (3U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
				   >> 0x14U));
    vlTOPp->CTRL_DATA = (0x3fU & vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out);
    vlTOPp->REG_SEL = (3U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
			     >> 6U));
    vlTOPp->MLU_PLANE = (0xfU & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
				 >> 0x10U));
    vlTOPp->CTRL_DATA_N_OUT = (1U & (~ (0xffU & (((IData)(1U) 
						  << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
						 >> 8U))));
    vlTOPp->TIMER_N_OUT = (1U & (~ (0x1ffU & (((IData)(1U) 
					       << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					      >> 7U))));
    vlTOPp->SHIFTER_N_OUT = (1U & (~ (0x3ffU & (((IData)(1U) 
						 << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
						>> 6U))));
    vlTOPp->MLU_N_OUT = (1U & (~ (0x7ffU & (((IData)(1U) 
					     << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					    >> 5U))));
    vlTOPp->MMU_N_OUT = (1U & (~ (0xfffU & (((IData)(1U) 
					     << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					    >> 4U))));
    vlTOPp->TMP1_N_OUT = (1U & (~ (0x1fffU & (((IData)(1U) 
					       << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					      >> 3U))));
    vlTOPp->TMP0_N_OUT = (1U & (~ (0x3fffU & (((IData)(1U) 
					       << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					      >> 2U))));
    vlTOPp->REG_N_OUT = (1U & (~ (0x7fffU & (((IData)(1U) 
					      << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					     >> 1U))));
}

void Vcontrol_logic::_settle__TOP__2(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_settle__TOP__2\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SHIFTER_PLANE = (3U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
				   >> 0x14U));
    vlTOPp->CTRL_DATA = (0x3fU & vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out);
    vlTOPp->REG_SEL = (3U & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
			     >> 6U));
    vlTOPp->MLU_PLANE = (0xfU & (vlSymsp->TOP__control_logic.__Vcelloutt__microcode_latch__OUT__out 
				 >> 0x10U));
    vlTOPp->CTRL_DATA_N_OUT = (1U & (~ (0xffU & (((IData)(1U) 
						  << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
						 >> 8U))));
    vlTOPp->TIMER_N_OUT = (1U & (~ (0x1ffU & (((IData)(1U) 
					       << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					      >> 7U))));
    vlTOPp->SHIFTER_N_OUT = (1U & (~ (0x3ffU & (((IData)(1U) 
						 << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
						>> 6U))));
    vlTOPp->MLU_N_OUT = (1U & (~ (0x7ffU & (((IData)(1U) 
					     << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					    >> 5U))));
    vlTOPp->MMU_N_OUT = (1U & (~ (0xfffU & (((IData)(1U) 
					     << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					    >> 4U))));
    vlTOPp->TMP1_N_OUT = (1U & (~ (0x1fffU & (((IData)(1U) 
					       << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					      >> 3U))));
    vlTOPp->TMP0_N_OUT = (1U & (~ (0x3fffU & (((IData)(1U) 
					       << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					      >> 2U))));
    vlTOPp->REG_N_OUT = (1U & (~ (0x7fffU & (((IData)(1U) 
					      << (IData)(vlSymsp->TOP__control_logic.control_out_plane)) 
					     >> 1U))));
    vlTOPp->OPWORD_IN_CLK = (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
				   >> 5U));
    vlTOPp->TMP1_IN_CLK = (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
				 >> 3U));
    vlTOPp->TMP0_IN_CLK = (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
				 >> 2U));
    vlTOPp->MMU_N_IN_CLK = (1U & (~ ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A) 
				     >> 1U)));
    vlTOPp->REG_N_IN_CLK = (1U & (~ (IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A)));
}

VL_INLINE_OPT void Vcontrol_logic::_combo__TOP__3(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_combo__TOP__3\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OPWORD_IN_CLK = (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
				   >> 5U));
    vlTOPp->TMP1_IN_CLK = (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
				 >> 3U));
    vlTOPp->TMP0_IN_CLK = (1U & ((IData)(vlSymsp->TOP__control_logic.__Vcellout__in_plane_decoder__Y) 
				 >> 2U));
}

VL_INLINE_OPT void Vcontrol_logic::_combo__TOP__4(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_combo__TOP__4\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MMU_N_IN_CLK = (1U & (~ ((IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A) 
				     >> 1U)));
    vlTOPp->REG_N_IN_CLK = (1U & (~ (IData)(vlSymsp->TOP__control_logic.__Vcellinp__inverter__A)));
}

void Vcontrol_logic::_eval(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_eval\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__control_logic____PVT__counter_combined_n_rst)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__control_logic____PVT__counter_combined_n_rst)))) {
	vlSymsp->TOP__control_logic._sequent__TOP__control_logic__2(vlSymsp);
    }
    if (((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK)))) {
	vlSymsp->TOP__control_logic._sequent__TOP__control_logic__3(vlSymsp);
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlSymsp->TOP__control_logic._combo__TOP__control_logic__5(vlSymsp);
    vlTOPp->_combo__TOP__3(vlSymsp);
    if ((((~ (IData)(vlTOPp->N_RST)) & (IData)(vlTOPp->__Vclklast__TOP__N_RST)) 
	 | ((IData)(vlSymsp->TOP__control_logic.__PVT__opcode_in_clk) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__control_logic____PVT__opcode_in_clk))))) {
	vlSymsp->TOP__control_logic._sequent__TOP__control_logic__6(vlSymsp);
    }
    if (((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK)))) {
	vlSymsp->TOP__control_logic._sequent__TOP__control_logic__7(vlSymsp);
    }
    if ((((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	   | ((~ (IData)(vlTOPp->N_RST)) & (IData)(vlTOPp->__Vclklast__TOP__N_RST))) 
	  | ((~ (IData)(vlTOPp->__VinpClk__TOP__control_logic____PVT__counter_combined_n_rst)) 
	     & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__control_logic____PVT__counter_combined_n_rst))) 
	 | ((IData)(vlSymsp->TOP__control_logic.__PVT__opcode_in_clk) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__control_logic____PVT__opcode_in_clk))))) {
	vlSymsp->TOP__control_logic._multiclk__TOP__control_logic__8(vlSymsp);
    }
    vlSymsp->TOP__control_logic._combo__TOP__control_logic__9(vlSymsp);
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__control_logic____PVT__counter_combined_n_rst 
	= vlTOPp->__VinpClk__TOP__control_logic____PVT__counter_combined_n_rst;
    vlTOPp->__Vclklast__TOP__N_CLK = vlTOPp->N_CLK;
    vlTOPp->__Vclklast__TOP__N_RST = vlTOPp->N_RST;
    vlTOPp->__Vclklast__TOP__control_logic____PVT__opcode_in_clk 
	= vlSymsp->TOP__control_logic.__PVT__opcode_in_clk;
    vlTOPp->__VinpClk__TOP__control_logic____PVT__counter_combined_n_rst 
	= vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst;
}

void Vcontrol_logic::_eval_initial(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_eval_initial\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic._initial__TOP__control_logic__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__control_logic____PVT__counter_combined_n_rst 
	= vlTOPp->__VinpClk__TOP__control_logic____PVT__counter_combined_n_rst;
    vlTOPp->__Vclklast__TOP__N_CLK = vlTOPp->N_CLK;
    vlTOPp->__Vclklast__TOP__N_RST = vlTOPp->N_RST;
    vlTOPp->__Vclklast__TOP__control_logic____PVT__opcode_in_clk 
	= vlSymsp->TOP__control_logic.__PVT__opcode_in_clk;
}

void Vcontrol_logic::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::final\n"); );
    // Variables
    Vcontrol_logic__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcontrol_logic::_eval_settle(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_eval_settle\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__control_logic._settle__TOP__control_logic__4(vlSymsp);
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vcontrol_logic::_change_request(Vcontrol_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_change_request\n"); );
    Vcontrol_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst ^ vlTOPp->__Vchglast__TOP__control_logic__counter_combined_n_rst));
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst ^ vlTOPp->__Vchglast__TOP__control_logic__counter_combined_n_rst))) VL_DBG_MSGF("        CHANGE: control_logic.v:41: counter_combined_n_rst\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__control_logic__counter_combined_n_rst 
	= vlSymsp->TOP__control_logic.__PVT__counter_combined_n_rst;
    return __req;
}

#ifdef VL_DEBUG
void Vcontrol_logic::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_CLK & 0xfeU))) {
	Verilated::overWidthError("N_CLK");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
    if (VL_UNLIKELY((OPWORD & 0xc0U))) {
	Verilated::overWidthError("OPWORD");}
    if (VL_UNLIKELY((BOOTSTRAP_ADDR & 0xf000U))) {
	Verilated::overWidthError("BOOTSTRAP_ADDR");}
    if (VL_UNLIKELY((N_BOOTED & 0xfeU))) {
	Verilated::overWidthError("N_BOOTED");}
    if (VL_UNLIKELY((BOOTSTRAP_N_WE & 0xfeU))) {
	Verilated::overWidthError("BOOTSTRAP_N_WE");}
}
#endif // VL_DEBUG

void Vcontrol_logic::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_logic::_ctor_var_reset\n"); );
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
    __VinpClk__TOP__control_logic____PVT__counter_combined_n_rst = VL_RAND_RESET_I(1);
    __Vchglast__TOP__control_logic__counter_combined_n_rst = VL_RAND_RESET_I(1);
}
