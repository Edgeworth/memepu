// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkpu.h for the primary calling header

#include "Vkpu.h"
#include "Vkpu__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vkpu) {
    Vkpu__Syms* __restrict vlSymsp = __VlSymsp = new Vkpu__Syms(this, name());
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(kpu, Vkpu_kpu);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vkpu::__Vconfigure(Vkpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vkpu::~Vkpu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vkpu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vkpu::eval\n"); );
    Vkpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vkpu::_eval_initial_loop(Vkpu__Syms* __restrict vlSymsp) {
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

void Vkpu::_eval(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::_eval\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu._combo__TOP__kpu__2(vlSymsp);
    if ((((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK)) 
	 | ((~ (IData)(vlTOPp->N_RST_ASYNC)) & (IData)(vlTOPp->__Vclklast__TOP__N_RST_ASYNC)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__kpu__n_rst)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__n_rst)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__7(vlSymsp);
    }
    if ((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst)))) {
	vlSymsp->TOP__kpu__control._sequent__TOP__kpu__control__3(vlSymsp);
    }
    if (((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK)))) {
	vlSymsp->TOP__kpu__control._sequent__TOP__kpu__control__4(vlSymsp);
	vlSymsp->TOP__kpu._sequent__TOP__kpu__8(vlSymsp);
    }
    vlSymsp->TOP__kpu._combo__TOP__kpu__9(vlSymsp);
    vlSymsp->TOP__kpu__control._combo__TOP__kpu__control__5(vlSymsp);
    vlSymsp->TOP__kpu._combo__TOP__kpu__10(vlSymsp);
    if (((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	  | ((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK)))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__kpu__n_rst)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__n_rst)))) {
	vlSymsp->TOP__kpu._multiclk__TOP__kpu__11(vlSymsp);
    }
    if ((((IData)(vlSymsp->TOP__kpu__control.__PVT__opcode_in_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu__control____PVT__opcode_in_clk))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__kpu__n_rst)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__n_rst)))) {
	vlSymsp->TOP__kpu__control._sequent__TOP__kpu__control__6(vlSymsp);
    }
    if (((IData)(vlSymsp->TOP__kpu.__PVT__control_opword_in_clk) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_opword_in_clk)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__13(vlSymsp);
    }
    if (((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp1_in_clk)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__14(vlSymsp);
    }
    if (((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__15(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->CLK)) & (IData)(vlTOPp->__Vclklast__TOP__CLK)) 
	 | ((~ (IData)(vlTOPp->N_RST_ASYNC)) & (IData)(vlTOPp->__Vclklast__TOP__N_RST_ASYNC)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__16(vlSymsp);
    }
    if (((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK)))) {
	vlSymsp->TOP__kpu__control._sequent__TOP__kpu__control__7(vlSymsp);
    }
    if ((((((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK))) 
	   | ((~ (IData)(vlTOPp->__VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst)) 
	      & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst))) 
	  | ((IData)(vlSymsp->TOP__kpu__control.__PVT__opcode_in_clk) 
	     & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu__control____PVT__opcode_in_clk)))) 
	 | ((~ (IData)(vlTOPp->__VinpClk__TOP__kpu__n_rst)) 
	    & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__n_rst)))) {
	vlSymsp->TOP__kpu__control._multiclk__TOP__kpu__control__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK))) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp1_in_clk))))) {
	vlSymsp->TOP__kpu._multiclk__TOP__kpu__17(vlSymsp);
    }
    vlSymsp->TOP__kpu__control._combo__TOP__kpu__control__9(vlSymsp);
    vlSymsp->TOP__kpu__regs._combo__TOP__kpu__regs__2(vlSymsp);
    vlSymsp->TOP__kpu__mmu._settle__TOP__kpu__mmu__1(vlSymsp);
    if (((~ (IData)(vlSymsp->TOP__kpu__regs__registers.__PVT__N_WE)) 
	 & (IData)(vlTOPp->__Vclklast__TOP__kpu__regs__registers____PVT__N_WE))) {
	vlSymsp->TOP__kpu__regs__registers._sequent__TOP__kpu__regs__registers__1(vlSymsp);
    }
    if (((~ (IData)(vlSymsp->TOP__kpu__mmu__ram.__PVT__N_WE)) 
	 & (IData)(vlTOPp->__Vclklast__TOP__kpu__mmu__ram____PVT__N_WE))) {
	vlSymsp->TOP__kpu__mmu__ram._sequent__TOP__kpu__mmu__ram__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK))) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__control_opword_in_clk) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_opword_in_clk))))) {
	vlSymsp->TOP__kpu__regs._multiclk__TOP__kpu__regs__3(vlSymsp);
    }
    if (((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk)))) {
	vlSymsp->TOP__kpu._sequent__TOP__kpu__18(vlSymsp);
    }
    if ((((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK))) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk))))) {
	vlSymsp->TOP__kpu._multiclk__TOP__kpu__19(vlSymsp);
    }
    vlSymsp->TOP__kpu._combo__TOP__kpu__20(vlSymsp);
    if (((((IData)(vlTOPp->N_CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__N_CLK))) 
	  | ((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk) 
	     & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk)))) 
	 | ((IData)(vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp1_in_clk))))) {
	vlSymsp->TOP__kpu._multiclk__TOP__kpu__21(vlSymsp);
    }
    vlSymsp->TOP__kpu._combo__TOP__kpu__22(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_RST_ASYNC = vlTOPp->N_RST_ASYNC;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__n_rst 
	= vlTOPp->__VinpClk__TOP__kpu__n_rst;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst 
	= vlTOPp->__VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst;
    vlTOPp->__Vclklast__TOP__N_CLK = vlTOPp->N_CLK;
    vlTOPp->__Vclklast__TOP__kpu__control____PVT__opcode_in_clk 
	= vlSymsp->TOP__kpu__control.__PVT__opcode_in_clk;
    vlTOPp->__Vclklast__TOP__kpu____PVT__control_opword_in_clk 
	= vlSymsp->TOP__kpu.__PVT__control_opword_in_clk;
    vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp1_in_clk 
	= vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk;
    vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk 
	= vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk;
    vlTOPp->__Vclklast__TOP__kpu__regs__registers____PVT__N_WE 
	= vlSymsp->TOP__kpu__regs__registers.__PVT__N_WE;
    vlTOPp->__Vclklast__TOP__kpu__mmu__ram____PVT__N_WE 
	= vlSymsp->TOP__kpu__mmu__ram.__PVT__N_WE;
    vlTOPp->__VinpClk__TOP__kpu__n_rst = vlSymsp->TOP__kpu.n_rst;
    vlTOPp->__VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst 
	= vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst;
}

void Vkpu::_eval_initial(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::_eval_initial\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu__control._initial__TOP__kpu__control__1(vlSymsp);
    vlSymsp->TOP__kpu._initial__TOP__kpu__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
    vlTOPp->__Vclklast__TOP__N_RST_ASYNC = vlTOPp->N_RST_ASYNC;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__n_rst 
	= vlTOPp->__VinpClk__TOP__kpu__n_rst;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst 
	= vlTOPp->__VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst;
    vlTOPp->__Vclklast__TOP__N_CLK = vlTOPp->N_CLK;
    vlTOPp->__Vclklast__TOP__kpu__control____PVT__opcode_in_clk 
	= vlSymsp->TOP__kpu__control.__PVT__opcode_in_clk;
    vlTOPp->__Vclklast__TOP__kpu____PVT__control_opword_in_clk 
	= vlSymsp->TOP__kpu.__PVT__control_opword_in_clk;
    vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp1_in_clk 
	= vlSymsp->TOP__kpu.__PVT__control_tmp1_in_clk;
    vlTOPp->__Vclklast__TOP__kpu____PVT__control_tmp0_in_clk 
	= vlSymsp->TOP__kpu.__PVT__control_tmp0_in_clk;
    vlTOPp->__Vclklast__TOP__kpu__regs__registers____PVT__N_WE 
	= vlSymsp->TOP__kpu__regs__registers.__PVT__N_WE;
    vlTOPp->__Vclklast__TOP__kpu__mmu__ram____PVT__N_WE 
	= vlSymsp->TOP__kpu__mmu__ram.__PVT__N_WE;
}

void Vkpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::final\n"); );
    // Variables
    Vkpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vkpu::_eval_settle(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::_eval_settle\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__kpu._settle__TOP__kpu__3(vlSymsp);
    vlSymsp->TOP__kpu__control._settle__TOP__kpu__control__2(vlSymsp);
    vlSymsp->TOP__kpu._settle__TOP__kpu__4(vlSymsp);
    vlSymsp->TOP__kpu__regs._settle__TOP__kpu__regs__1(vlSymsp);
    vlSymsp->TOP__kpu__mmu._settle__TOP__kpu__mmu__1(vlSymsp);
    vlSymsp->TOP__kpu._settle__TOP__kpu__5(vlSymsp);
    vlSymsp->TOP__kpu._settle__TOP__kpu__12(vlSymsp);
}

VL_INLINE_OPT QData Vkpu::_change_request(Vkpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::_change_request\n"); );
    Vkpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSymsp->TOP__kpu.n_rst ^ vlTOPp->__Vchglast__TOP__kpu__n_rst)
	 | (vlSymsp->TOP__kpu.__PVT__timer__DOT__rco ^ vlTOPp->__Vchglast__TOP__kpu__timer__DOT__rco)
	 | (vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR ^ vlTOPp->__Vchglast__TOP__kpu__mlu__DOT____Vcellinp__lookahead__ADDR)
	 | (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	    [0U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
	    [0U])
	 | (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	    [1U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
	    [1U])
	 | (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	    [2U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
	    [2U])
	 | (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	    [3U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
	    [3U])
	 | (vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	    [4U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
	    [4U])
	 | (vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst ^ vlTOPp->__Vchglast__TOP__kpu__control__counter_combined_n_rst));
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.n_rst ^ vlTOPp->__Vchglast__TOP__kpu__n_rst))) VL_DBG_MSGF("        CHANGE: kpu.v:12: n_rst\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.__PVT__timer__DOT__rco ^ vlTOPp->__Vchglast__TOP__kpu__timer__DOT__rco))) VL_DBG_MSGF("        CHANGE: timer.v:10: timer.rco\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR ^ vlTOPp->__Vchglast__TOP__kpu__mlu__DOT____Vcellinp__lookahead__ADDR))) VL_DBG_MSGF("        CHANGE: mlu_lookahead.v:4: mlu.__Vcellinp__lookahead__ADDR\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			       [0U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
			       [0U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			       [1U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
			       [1U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			       [2U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
			       [2U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			       [3U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
			       [3U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
			       [4U] ^ vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage
			       [4U]))) VL_DBG_MSGF("        CHANGE: shifter.v:28\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst ^ vlTOPp->__Vchglast__TOP__kpu__control__counter_combined_n_rst))) VL_DBG_MSGF("        CHANGE: control_logic.v:41: counter_combined_n_rst\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__kpu__n_rst = vlSymsp->TOP__kpu.n_rst;
    vlTOPp->__Vchglast__TOP__kpu__timer__DOT__rco = vlSymsp->TOP__kpu.__PVT__timer__DOT__rco;
    vlTOPp->__Vchglast__TOP__kpu__mlu__DOT____Vcellinp__lookahead__ADDR 
	= vlSymsp->TOP__kpu.mlu__DOT____Vcellinp__lookahead__ADDR;
    vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage[0U] 
	= vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	[0U];
    vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage[1U] 
	= vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	[1U];
    vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage[2U] 
	= vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	[2U];
    vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage[3U] 
	= vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	[3U];
    vlTOPp->__Vchglast__TOP__kpu__shifter__DOT__stage[4U] 
	= vlSymsp->TOP__kpu.__PVT__shifter__DOT__stage
	[4U];
    vlTOPp->__Vchglast__TOP__kpu__control__counter_combined_n_rst 
	= vlSymsp->TOP__kpu__control.__PVT__counter_combined_n_rst;
    return __req;
}

#ifdef VL_DEBUG
void Vkpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLK & 0xfeU))) {
	Verilated::overWidthError("CLK");}
    if (VL_UNLIKELY((N_CLK & 0xfeU))) {
	Verilated::overWidthError("N_CLK");}
    if (VL_UNLIKELY((N_RST_ASYNC & 0xfeU))) {
	Verilated::overWidthError("N_RST_ASYNC");}
}
#endif // VL_DEBUG

void Vkpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkpu::_ctor_var_reset\n"); );
    // Body
    CLK = VL_RAND_RESET_I(1);
    N_CLK = VL_RAND_RESET_I(1);
    N_RST_ASYNC = VL_RAND_RESET_I(1);
    __VinpClk__TOP__kpu__n_rst = VL_RAND_RESET_I(1);
    __VinpClk__TOP__kpu__control____PVT__counter_combined_n_rst = VL_RAND_RESET_I(1);
    __Vchglast__TOP__kpu__n_rst = VL_RAND_RESET_I(1);
    __Vchglast__TOP__kpu__timer__DOT__rco = VL_RAND_RESET_I(9);
    __Vchglast__TOP__kpu__mlu__DOT____Vcellinp__lookahead__ADDR = VL_RAND_RESET_I(17);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
	    __Vchglast__TOP__kpu__shifter__DOT__stage[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vchglast__TOP__kpu__control__counter_combined_n_rst = VL_RAND_RESET_I(1);
}
