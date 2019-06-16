// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkpu.h for the primary calling header

#ifndef _Vkpu_kpu_H_
#define _Vkpu_kpu_H_

#include "verilated.h"
#include "Vkpu__Dpi.h"

class Vkpu__Syms;
class Vkpu_mmu;
class Vkpu_register_file;
class Vkpu_control_logic;

//----------

VL_MODULE(Vkpu_kpu) {
  public:
    // CELLS
    Vkpu_mmu*          	mmu;
    Vkpu_register_file*	regs;
    Vkpu_control_logic*	control;
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(CLK,0,0);
    VL_IN8(N_CLK,0,0);
    VL_IN8(N_RST_ASYNC,0,0);
    
    // LOCAL SIGNALS
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	// Begin mtask footprint  all: 
	VL_SIG8(n_rst,0,0);
	VL_SIG8(__PVT__control_tmp0_in_clk,0,0);
	VL_SIG8(__PVT__control_tmp1_in_clk,0,0);
	VL_SIG8(__PVT__control_opword_in_clk,0,0);
	VL_SIG8(opword_val,5,0);
	VL_SIG8(__PVT__jkflip__DOT__genblk1__BRA__0__KET____DOT__data,0,0);
	VL_SIG8(__PVT__jkflip__DOT__genblk1__BRA__1__KET____DOT__data,0,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__0__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__1__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__2__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__3__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__4__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__5__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__6__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__timer__DOT__genblk1__BRA__7__KET____DOT__counter__DOT__count,3,0);
	VL_SIG8(__PVT__mlu__DOT__slice_p,7,0);
	VL_SIG8(__PVT__mlu__DOT__slice_g,7,0);
	VL_SIG8(__PVT__mlu__DOT__lookahead__DOT__prev_carry,0,0);
	VL_SIG8(__PVT__mlu__DOT__lookahead__DOT__carry,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__0__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__1__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__2__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__3__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__4__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__5__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__6__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__out_low,3,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__prop,0,0);
	VL_SIG8(__PVT__mlu__DOT__genblk1__BRA__7__KET____DOT__slice__DOT__gen,0,0);
	VL_SIG8(__PVT__tmp0__DOT__low16__DOT__low8,7,0);
	VL_SIG8(__PVT__tmp0__DOT__low16__DOT__high8,7,0);
	VL_SIG8(__PVT__tmp0__DOT__high16__DOT__low8,7,0);
	VL_SIG8(__PVT__tmp0__DOT__high16__DOT__high8,7,0);
	VL_SIG8(__PVT__tmp1__DOT__low16__DOT__low8,7,0);
	VL_SIG8(__PVT__tmp1__DOT__low16__DOT__high8,7,0);
	VL_SIG8(__PVT__tmp1__DOT__high16__DOT__low8,7,0);
	VL_SIG8(__PVT__tmp1__DOT__high16__DOT__high8,7,0);
	VL_SIG8(__PVT__opword__DOT__low16__DOT__low8,7,0);
	VL_SIG8(__PVT__opword__DOT__low16__DOT__high8,7,0);
	VL_SIG8(__PVT__opword__DOT__high16__DOT__low8,7,0);
	VL_SIG8(__PVT__opword__DOT__high16__DOT__high8,7,0);
	VL_SIG16(__PVT__timer__DOT__rco,8,0);
	VL_SIG16(__PVT__mlu__DOT__carrys,8,0);
	VL_SIG(bus,31,0);
	VL_SIG(timer_val,31,0);
	VL_SIG(mlu_val,31,0);
	VL_SIG(__PVT__shifter_val,31,0);
	VL_SIG(tmp0_val,31,0);
	VL_SIG(tmp1_val,31,0);
	VL_SIG(__PVT__shifter__DOT__pre_reverse,31,0);
    };
    struct {
	VL_SIG(__PVT__shifter__DOT__stage[5],31,0);
    };
    
    // LOCAL VARIABLES
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	// Begin mtask footprint  all: 
	VL_SIG8(__Vcellout__jkflip__Q,1,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__0__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__1__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__2__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__3__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__4__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__5__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__6__KET____DOT__counter__RCO,0,0);
	VL_SIG8(timer__DOT____Vcellout__genblk1__BRA__7__KET____DOT__counter__RCO,0,0);
	VL_SIG8(mlu__DOT____Vcellout__lookahead__CARRYS,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__0__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__1__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__2__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__3__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__4__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__5__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__6__KET____DOT__slice__OUT,7,0);
	VL_SIG8(mlu__DOT____Vcellout__genblk1__BRA__7__KET____DOT__slice__OUT,7,0);
	VL_SIG8(shifter__DOT____Vcellinp__notter__A,5,0);
	VL_SIG8(shifter__DOT____Vcellout__ander__Y,3,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__0__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__1__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__2__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__3__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__4__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__5__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__6__KET____DOT__slice__ADDR,11,0);
	VL_SIG16(mlu__DOT____Vcellinp__genblk1__BRA__7__KET____DOT__slice__ADDR,11,0);
	VL_SIG(__Vcelloutt__opword__OUT__out,31,0);
	VL_SIG(timer_buf__DOT__OUT__out__out2,31,0);
	VL_SIG(timer_buf__DOT__OUT__out__out3,31,0);
	VL_SIG(mlu__DOT____Vcellinp__lookahead__ADDR,16,0);
	VL_SIG(mlu_buf__DOT__OUT__out__out2,31,0);
	VL_SIG(mlu_buf__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT____Vcellinp__pre_reverse_mux__B,31,0);
	VL_SIG(shifter__DOT____Vcellinp__shift_left_mux0__A,31,0);
	VL_SIG(shifter__DOT____Vcellinp__shift_left_mux1__A,31,0);
	VL_SIG(shifter__DOT____Vcellinp__shift_left_mux2__A,31,0);
	VL_SIG(shifter__DOT____Vcellinp__shift_left_mux3__A,31,0);
	VL_SIG(shifter__DOT____Vcellinp__shift_left_mux4__A,31,0);
	VL_SIG(shifter__DOT____Vcellinp__post_reverse_mux__B,31,0);
	VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__pre_reverse_mux__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux0__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux1__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux2__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux3__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out2,31,0);
    };
    struct {
	VL_SIG(shifter__DOT__shift_left_mux4__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_a__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter__DOT__post_reverse_mux__DOT__mux_b__DOT__OUT__out__out3,31,0);
	VL_SIG(shifter_buf__DOT__OUT__out__out2,31,0);
	VL_SIG(shifter_buf__DOT__OUT__out__out3,31,0);
	VL_SIG(tmp0__DOT__OUT__out__out4,31,0);
	VL_SIG(tmp0__DOT__OUT__out__out5,31,0);
	VL_SIG(tmp0__DOT__OUT__out__out6,31,0);
	VL_SIG(tmp0__DOT__OUT__out__out7,31,0);
	VL_SIG(tmp0_buf__DOT__OUT__out__out2,31,0);
	VL_SIG(tmp0_buf__DOT__OUT__out__out3,31,0);
	VL_SIG(tmp1__DOT__OUT__out__out4,31,0);
	VL_SIG(tmp1__DOT__OUT__out__out5,31,0);
	VL_SIG(tmp1__DOT__OUT__out__out6,31,0);
	VL_SIG(tmp1__DOT__OUT__out__out7,31,0);
	VL_SIG(tmp1_buf__DOT__OUT__out__out2,31,0);
	VL_SIG(tmp1_buf__DOT__OUT__out__out3,31,0);
	VL_SIG(opword__DOT__OUT__out__out4,31,0);
	VL_SIG(opword__DOT__OUT__out__out5,31,0);
	VL_SIG(opword__DOT__OUT__out__out6,31,0);
	VL_SIG(opword__DOT__OUT__out__out7,31,0);
    };
    
    // INTERNAL VARIABLES
  private:
    Vkpu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkpu_kpu);  ///< Copying not allowed
  public:
    Vkpu_kpu(const char* name="TOP");
    ~Vkpu_kpu();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vkpu__Syms* symsp, bool first);
    static void _combo__TOP__kpu__10(Vkpu__Syms* __restrict vlSymsp);
    static void _combo__TOP__kpu__2(Vkpu__Syms* __restrict vlSymsp);
    static void _combo__TOP__kpu__20(Vkpu__Syms* __restrict vlSymsp);
    static void _combo__TOP__kpu__22(Vkpu__Syms* __restrict vlSymsp);
    static void _combo__TOP__kpu__9(Vkpu__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__kpu__1(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__kpu__11(Vkpu__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__kpu__17(Vkpu__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__kpu__19(Vkpu__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__kpu__21(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__13(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__14(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__15(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__16(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__18(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__6(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__7(Vkpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__kpu__8(Vkpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__kpu__12(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__kpu__3(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__kpu__4(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__kpu__5(Vkpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
