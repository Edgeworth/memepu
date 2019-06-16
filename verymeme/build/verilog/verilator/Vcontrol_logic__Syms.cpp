// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vcontrol_logic__Syms.h"
#include "Vcontrol_logic.h"
#include "Vcontrol_logic_control_logic.h"

// FUNCTIONS
Vcontrol_logic__Syms::Vcontrol_logic__Syms(Vcontrol_logic* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__control_logic             (Verilated::catName(topp->name(),"control_logic"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->control_logic             = &TOP__control_logic;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__control_logic.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_control_logic.configure(this,name(),"control_logic");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_control_logic.varInsert(__Vfinal,"control_in_plane", &(TOP__control_logic.control_in_plane), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
	__Vscope_control_logic.varInsert(__Vfinal,"control_misc_plane", &(TOP__control_logic.control_misc_plane), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
	__Vscope_control_logic.varInsert(__Vfinal,"control_opcode_sel", &(TOP__control_logic.control_opcode_sel), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
	__Vscope_control_logic.varInsert(__Vfinal,"control_out_plane", &(TOP__control_logic.control_out_plane), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
	__Vscope_control_logic.varInsert(__Vfinal,"microop_count", &(TOP__control_logic.microop_count), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
	__Vscope_control_logic.varInsert(__Vfinal,"opcode", &(TOP__control_logic.opcode), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
    }
}
