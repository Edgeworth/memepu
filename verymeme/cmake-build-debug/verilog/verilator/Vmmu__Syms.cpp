// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmmu__Syms.h"
#include "Vmmu.h"
#include "Vmmu_mmu.h"
#include "Vmmu_sram__Da_W20.h"

// FUNCTIONS
Vmmu__Syms::Vmmu__Syms(Vmmu* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__mmu                       (Verilated::catName(topp->name(),"mmu"))
	, TOP__mmu__ram                  (Verilated::catName(topp->name(),"mmu.ram"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->mmu                       = &TOP__mmu;
    TOPp->mmu->ram                  = &TOP__mmu__ram;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__mmu.__Vconfigure(this, true);
    TOP__mmu__ram.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_mmu__ram.configure(this,name(),"mmu.ram");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_mmu__ram.varInsert(__Vfinal,"mem", &(TOP__mmu__ram.mem), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,1023,0);
    }
}
