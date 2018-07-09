#include "control.h"
#include "control_constants.h"
#include "asm.h"

#define WRITE_NO_AUX(opcode, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeNoAux(opcode, microops, sizeof(microops) / sizeof(microops[0])); \
}

void ControlLogic::writeNoAux(Opcode opcode0, uint32_t* microops, int num) {
  verify_expr(num < 16, "no more than 16 microops for opcode %d", static_cast<int>(opcode0));
  for (int microop = 0; microop < 16; ++microop) {
    for (int aux = 0; aux < (1 << 4); ++aux) {
      for (int int_flag = 0; int_flag < 2; ++int_flag) {
        for (int mmu_fault_flag = 0; mmu_fault_flag < 2; ++mmu_fault_flag) {
          uint32_t addr = 0;
          addr |= addr_opcode(static_cast<uint8_t>(opcode0));
          addr |= addr_aux(aux);
          addr |= addr_microop(microop);
          addr |= addr_int_flag(static_cast<bool>(int_flag));
          addr |= addr_mmu_fault_flag(static_cast<bool>(mmu_fault_flag));
          // For unused portions, reset uop count for debug purposes.
          if (microop < num) put(addr, microops[microop]);
          else put(addr, multi(MULTI_N_RESET_UOP_COUNT));
        }
      }
    }
  }
}


void ControlLogic::writeAux(Opcode opcode0, int aux, uint32_t* microops, int num) {

}

void ControlLogic::writeLoadImmediate(Opcode opcode0, int in_signal) {
  WRITE_NO_AUX(
      opcode0,
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(in_signal) | multi(MULTI_N_PC_INC),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0)
  );
}

std::string ControlLogic::getBinaryData() {
  // Instruction set:
  // Boot sequence / initialisation
  WRITE_NO_AUX(
      Opcode::BOOT,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC0),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC1),
      bus(0x10) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC2),
      0,
      0,
      multi(MULTI_N_OPCODE0_INC),
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // Fetch. Increments PC.
  WRITE_NO_AUX(
      Opcode::FETCH,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),  // Reset opcode1
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2) | multi(MULTI_N_PC_INC),
  // Fetch opcode and reset micro-op counter
      out(OUT_N_MMU) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT),
  );
  // Page fault
  // Handle interrupt

  // LDA immediate
  writeLoadImmediate(Opcode::LDA_IMM, IN_N_A);
  // LDB immediate
  writeLoadImmediate(Opcode::LDB_IMM, IN_N_B);
  // LDM0 immediate
  writeLoadImmediate(Opcode::LDM0_IMM, IN_N_M0);

  // ADD
  WRITE_NO_AUX(
      Opcode::ADD,
      out(OUT_N_SUM) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0)
  );

  // SUB
  WRITE_NO_AUX(
      Opcode::SUB,
      out(OUT_N_SUM) | in(IN_N_A) | multi(MULTI_N_SUB),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0)
  );

  // JMP
  WRITE_NO_AUX(
      Opcode::JMP,
  // Load next 3 bytes into M0, M1, M2
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M0) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M1) | multi(MULTI_N_PC_INC),
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(IN_N_M2) | multi(MULTI_N_PC_INC),
  // Load PC with value from memory.
      out(OUT_N_M0) | in(IN_N_PC0),
      out(OUT_N_M1) | in(IN_N_PC1),
      out(OUT_N_M2) | in(IN_N_PC2),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0)
  );

  // DISPLAY
  WRITE_NO_AUX(
      Opcode::DISPLAY,
      out(OUT_N_A) | in(IN_N_DISP),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0)
  );

  // SWAP
  WRITE_NO_AUX(
      Opcode::SWAP,
      out(OUT_N_A) | in(IN_N_M0),
      out(OUT_N_B) | in(IN_N_A),
      out(OUT_N_M0) | in(IN_N_B),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0)
  );

  return data_;
}
