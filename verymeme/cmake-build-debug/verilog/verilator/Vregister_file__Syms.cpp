// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vregister_file__Syms.h"
#include "Vregister_file.h"
#include "Vregister_file_register_file.h"
#include "Vregister_file_sram__D5_W20.h"

// FUNCTIONS
Vregister_file__Syms::Vregister_file__Syms(Vregister_file* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__register_file             (Verilated::catName(topp->name(),"register_file"))
	, TOP__register_file__registers  (Verilated::catName(topp->name(),"register_file.registers"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->register_file             = &TOP__register_file;
    TOPp->register_file->registers  = &TOP__register_file__registers;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__register_file.__Vconfigure(this, true);
    TOP__register_file__registers.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_register_file__registers.configure(this,name(),"register_file.registers");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_register_file__registers.varInsert(__Vfinal,"mem", &(TOP__register_file__registers.mem), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,31,0);
    }
}
