// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vkpu__Syms.h"
#include "Vkpu.h"
#include "Vkpu_kpu.h"
#include "Vkpu_mmu.h"
#include "Vkpu_register_file.h"
#include "Vkpu_control_logic.h"
#include "Vkpu_sram__D5_W20.h"
#include "Vkpu_sram__Da_W20.h"

// FUNCTIONS
Vkpu__Syms::Vkpu__Syms(Vkpu* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__kpu                       (Verilated::catName(topp->name(),"kpu"))
	, TOP__kpu__control              (Verilated::catName(topp->name(),"kpu.control"))
	, TOP__kpu__mmu                  (Verilated::catName(topp->name(),"kpu.mmu"))
	, TOP__kpu__mmu__ram             (Verilated::catName(topp->name(),"kpu.mmu.ram"))
	, TOP__kpu__regs                 (Verilated::catName(topp->name(),"kpu.regs"))
	, TOP__kpu__regs__registers      (Verilated::catName(topp->name(),"kpu.regs.registers"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->kpu                       = &TOP__kpu;
    TOPp->kpu->control              = &TOP__kpu__control;
    TOPp->kpu->mmu                  = &TOP__kpu__mmu;
    TOPp->kpu->mmu->ram             = &TOP__kpu__mmu__ram;
    TOPp->kpu->regs                 = &TOP__kpu__regs;
    TOPp->kpu->regs->registers      = &TOP__kpu__regs__registers;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__kpu.__Vconfigure(this, true);
    TOP__kpu__control.__Vconfigure(this, true);
    TOP__kpu__mmu.__Vconfigure(this, true);
    TOP__kpu__mmu__ram.__Vconfigure(this, true);
    TOP__kpu__regs.__Vconfigure(this, true);
    TOP__kpu__regs__registers.__Vconfigure(this, true);
    // Setup scope names
    __Vscope_kpu.configure(this,name(),"kpu");
    __Vscope_kpu__control.configure(this,name(),"kpu.control");
    __Vscope_kpu__mmu__ram.configure(this,name(),"kpu.mmu.ram");
    __Vscope_kpu__regs__registers.configure(this,name(),"kpu.regs.registers");
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
	__Vscope_kpu.varInsert(__Vfinal,"bus", &(TOP__kpu.bus), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_kpu.varInsert(__Vfinal,"mlu_val", &(TOP__kpu.mlu_val), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_kpu.varInsert(__Vfinal,"n_rst", &(TOP__kpu.n_rst), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
	__Vscope_kpu.varInsert(__Vfinal,"opword_val", &(TOP__kpu.opword_val), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
	__Vscope_kpu.varInsert(__Vfinal,"timer_val", &(TOP__kpu.timer_val), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_kpu.varInsert(__Vfinal,"tmp0_val", &(TOP__kpu.tmp0_val), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_kpu.varInsert(__Vfinal,"tmp1_val", &(TOP__kpu.tmp1_val), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
	__Vscope_kpu__control.varInsert(__Vfinal,"control_in_plane", &(TOP__kpu__control.control_in_plane), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,2,0);
	__Vscope_kpu__control.varInsert(__Vfinal,"control_misc_plane", &(TOP__kpu__control.control_misc_plane), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
	__Vscope_kpu__control.varInsert(__Vfinal,"control_opcode_sel", &(TOP__kpu__control.control_opcode_sel), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
	__Vscope_kpu__control.varInsert(__Vfinal,"control_out_plane", &(TOP__kpu__control.control_out_plane), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
	__Vscope_kpu__control.varInsert(__Vfinal,"microop_count", &(TOP__kpu__control.microop_count), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
	__Vscope_kpu__control.varInsert(__Vfinal,"opcode", &(TOP__kpu__control.opcode), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,5,0);
	__Vscope_kpu__mmu__ram.varInsert(__Vfinal,"mem", &(TOP__kpu__mmu__ram.mem), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,1023,0);
	__Vscope_kpu__regs__registers.varInsert(__Vfinal,"mem", &(TOP__kpu__regs__registers.mem), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,31,0);
    }
}
