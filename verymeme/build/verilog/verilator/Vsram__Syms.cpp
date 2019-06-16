// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsram__Syms.h"
#include "Vsram.h"
#include "Vsram_sram.h"

// FUNCTIONS
Vsram__Syms::Vsram__Syms(Vsram* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__sram                      (Verilated::catName(topp->name(),"sram"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->sram                      = &TOP__sram;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__sram.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_sram.configure(this,name(),"sram");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_sram.varInsert(__Vfinal,"mem", &(TOP__sram.mem), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,2 ,7,0 ,3,0);
    }
}
