// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_file.h for the primary calling header

#include "Vregister_file.h"
#include "Vregister_file__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vregister_file) {
    Vregister_file__Syms* __restrict vlSymsp = __VlSymsp = new Vregister_file__Syms(this, name());
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(register_file, Vregister_file_register_file);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vregister_file::__Vconfigure(Vregister_file__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vregister_file::~Vregister_file() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vregister_file::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister_file::eval\n"); );
    Vregister_file__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vregister_file::_eval_initial_loop(Vregister_file__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vregister_file::_settle__TOP__1(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_settle__TOP__1\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->OUT_DATA = (((((IData)(vlTOPp->N_OE) ? 0U
			    : vlSymsp->TOP__register_file__registers.mem
			   [(0x1fU & (IData)(vlSymsp->TOP__register_file.__Vcellout__reg_sel_mux__OUT))]) 
			  & ((IData)(vlTOPp->N_OE) ? 0U
			      : 0xffffffffU)) & ((IData)(vlTOPp->N_OE)
						  ? 0U
						  : 0xffffffffU)) 
			& ((IData)(vlTOPp->N_OE) ? 0U
			    : 0xffffffffU));
}

void Vregister_file::_eval(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->N_WE)) & (IData)(vlTOPp->__Vclklast__TOP__N_WE))) {
	vlSymsp->TOP__register_file__registers._sequent__TOP__register_file__registers__1(vlSymsp);
    }
    vlSymsp->TOP__register_file._settle__TOP__register_file__1(vlSymsp);
    vlTOPp->_settle__TOP__1(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vregister_file::_eval_initial(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval_initial\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__N_WE = vlTOPp->N_WE;
}

void Vregister_file::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::final\n"); );
    // Variables
    Vregister_file__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vregister_file::_eval_settle(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval_settle\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__register_file._settle__TOP__register_file__1(vlSymsp);
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vregister_file::_change_request(Vregister_file__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_change_request\n"); );
    Vregister_file* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregister_file::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((REG_SEL & 0xfcU))) {
	Verilated::overWidthError("REG_SEL");}
    if (VL_UNLIKELY((REG_SRC0 & 0xe0U))) {
	Verilated::overWidthError("REG_SRC0");}
    if (VL_UNLIKELY((REG_SRC1 & 0xe0U))) {
	Verilated::overWidthError("REG_SRC1");}
    if (VL_UNLIKELY((REG_SRC2 & 0xe0U))) {
	Verilated::overWidthError("REG_SRC2");}
    if (VL_UNLIKELY((N_WE & 0xfeU))) {
	Verilated::overWidthError("N_WE");}
    if (VL_UNLIKELY((N_OE & 0xfeU))) {
	Verilated::overWidthError("N_OE");}
    if (VL_UNLIKELY((N_RST & 0xfeU))) {
	Verilated::overWidthError("N_RST");}
}
#endif // VL_DEBUG

void Vregister_file::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_file::_ctor_var_reset\n"); );
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
}
