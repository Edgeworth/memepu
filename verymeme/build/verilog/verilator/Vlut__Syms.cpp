// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vlut__Syms.h"
#include "Vlut.h"
#include "Vlut_lut.h"

// FUNCTIONS
Vlut__Syms::Vlut__Syms(Vlut* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__lut                       (Verilated::catName(topp->name(),"lut"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->lut                       = &TOP__lut;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__lut.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_lut.configure(this,name(),"lut");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_lut.varInsert(__Vfinal,"mem", &(TOP__lut.mem), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,2 ,7,0 ,3,0);
    }
}
