#include "control.h"
#include "control_constants.h"

#define WRITE_NO_AUX(opcode, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeNoAux(opcode, microops, sizeof(microops) / sizeof(microops[0])); \
}

#define WRITE_AUX(opcode, aux, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeAux(opcode, aux, microops, sizeof(microops) / sizeof(microops[0])); \
}

#define WRITE_INT_FLAG(opcode, int_flag, ...) { \
  uint32_t microops[] = {__VA_ARGS__}; \
  writeIntFlag(opcode, int_flag, microops, sizeof(microops) / sizeof(microops[0])); \
}

void ControlLogic::writeNoAux(Opcode opcode0, uint32_t* microops, int num) {
  for (int aux = 0; aux < (1 << 4); ++aux)
    writeAux(opcode0, aux, microops, num);
}

void ControlLogic::writeAux(Opcode opcode0, int aux, uint32_t* microops, int num) {
  writeMicroops(opcode0, aux, 0, 0, microops, num);
  writeMicroops(opcode0, aux, 0, 1, microops, num);
  writeMicroops(opcode0, aux, 1, 0, microops, num);
  writeMicroops(opcode0, aux, 1, 1, microops, num);
}

void ControlLogic::writeIntFlag(Opcode opcode0, int int_flag, uint32_t* microops, int num) {
  for (int aux = 0; aux < (1 << 4); ++aux) {
    writeMicroops(opcode0, aux, int_flag, 0, microops, num);
    writeMicroops(opcode0, aux, int_flag, 1, microops, num);
  }
}

void ControlLogic::writeMicroops(Opcode opcode0, int aux, int int_flag, int mmu_fault_flag, uint32_t* microops, int num) {
  verify_expr(num <= 16, "no more than 16 microops for opcode %d", static_cast<int>(opcode0));
  for (int microop_idx = 0; microop_idx < 16; ++microop_idx) {
    // Verify last micro-op resets micro-op counter, unless it's the final micro-op.
    if (microop_idx == num - 1 && microop_idx != 15)
      verify_expr(multi_from_microop(microops[microop_idx]) == MULTI_N_RESET_UOP_COUNT,
                  "last micro-op must reset micro-op count, opcode: %d", static_cast<int>(opcode0));

    // For unused portions, reset uop count for debug purposes.
    if (microop_idx < num) write(opcode0, aux, int_flag, mmu_fault_flag, microop_idx, microops[microop_idx]);
    else write(opcode0, aux, int_flag, mmu_fault_flag, microop_idx, multi(MULTI_N_RESET_UOP_COUNT));
  }
}

void ControlLogic::write(Opcode opcode0, int aux, int int_flag, int mmu_fault_flag, int microop_idx, uint32_t microop_data) {
  uint32_t addr = 0;
  addr |= addr_opcode(static_cast<uint8_t>(opcode0));
  addr |= addr_aux(aux);
  addr |= addr_microop(microop_idx);
  addr |= addr_int_flag(static_cast<bool>(int_flag));
  addr |= addr_mmu_fault_flag(static_cast<bool>(mmu_fault_flag));
  put(addr, microop_data);
}

void ControlLogic::writeLoadImmediate(Opcode opcode0, int in_signal) {
  WRITE_NO_AUX(
      opcode0,
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      out(OUT_N_MMU) | in(in_signal) | multi(MULTI_N_PC_INC),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );
}

std::string ControlLogic::getBinaryData() {
  // Instruction set:
  // Hack to reset micro-op counter before booting
  WRITE_NO_AUX(
      Opcode::MICROOP_RESET_HACK,
      bus(static_cast<uint8_t>(Opcode::BOOT)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  // Rest of microops automatically filled to reset UOP count.
  );

  // Boot sequence / initialisation
  // TODO: Loads hard-coded address
  WRITE_NO_AUX(
      Opcode::BOOT,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC0) | multi(MULTI_N_SET_INT_ENABLE), // Enable interrupts (TODO)
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC1),
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_PC2),  // TODO: EEPROM has line 20 low - BUG.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  // Banned combinations:
  // Last microop resets uop counter. All cases?

  // Fetch. Increments PC.
  WRITE_INT_FLAG(
      Opcode::FETCH,
      0,
      bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),  // Reset opcode1
      // After reading in the interrupt register, we may switch to processing this interrupt.
      in(IN_N_INT7),  // TODO: Bug - no way to clock interrupt register to read (INT_IN_CLK) so bodge IN_N_INT7 to do it.
      out(OUT_N_PC0) | in(IN_N_MMU0),
      out(OUT_N_PC1) | in(IN_N_MMU1),
      out(OUT_N_PC2) | in(IN_N_MMU2),
      multi(MULTI_N_PC_INC),  // Happens on falling edge, so make sure not to let it affect the load into MMU2.
      out(OUT_N_MMU) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT), // Fetch opcode and reset micro-op counter
  );
  // Check for interrupt on fetch
  WRITE_INT_FLAG(
      Opcode::FETCH,
      1,
      0, // Skip here. We start at 2.
      0,
      bus(static_cast<uint8_t>(Opcode::HANDLE_INTERRUPT)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT),
  );

  // Page fault

  // Handle interrupt
  // TODO: Loads hard-coded address
  WRITE_NO_AUX(
      Opcode::HANDLE_INTERRUPT,
      bus(0) | in(IN_N_PC0) | multi(MULTI_N_UNSET_INT_ENABLE),  // Disable interrupts.
      bus(0) | in(IN_N_PC1),
      bus(4) | in(IN_N_PC2),  // Load 0x040000 = 256K - halfway through EEPROM.
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  )

  // LDA immediate
  writeLoadImmediate(Opcode::LDA_IMM, IN_N_A);
  // LDB immediate
  writeLoadImmediate(Opcode::LDB_IMM, IN_N_B);
  // LDM0 immediate
  writeLoadImmediate(Opcode::LDM0_IMM, IN_N_M0);

  // LDA_INT
  WRITE_NO_AUX(
      Opcode::LDA_INT,
      out(OUT_N_INTERRUPT) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  // ADD
  WRITE_NO_AUX(
      Opcode::ADD,
      out(OUT_N_SUM) | in(IN_N_A),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  // SUB
  WRITE_NO_AUX(
      Opcode::SUB,
      out(OUT_N_SUM) | in(IN_N_A) | multi(MULTI_N_SUB),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  // JMP
  WRITE_AUX(
      Opcode::JMP,
      0,
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
      bus(1) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1)  // Go to next part of the instruction.
  );
  WRITE_AUX(
      Opcode::JMP,
      1,
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) |
      multi(MULTI_N_RESET_UOP_COUNT)
  );

  // DISPLAY
  WRITE_NO_AUX(
      Opcode::DISPLAY,
      out(OUT_N_A) | in(IN_N_DISP),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  // SWAP
  WRITE_NO_AUX(
      Opcode::SWAP,
      out(OUT_N_A) | in(IN_N_M0),
      out(OUT_N_B) | in(IN_N_A),
      out(OUT_N_M0) | in(IN_N_B),
      bus(static_cast<uint8_t>(Opcode::FETCH)) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT)
  );

  return data_;
}
