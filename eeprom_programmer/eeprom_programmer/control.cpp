#include "control.h"
#include "eeprom.h"

namespace {

const uint32_t MAX = 1L << 19;

// PIN mapping
enum {
  CTRL_IN0 = 0,
  CTRL_IN1 = 1,
  CTRL_IN2 = 2,
  CTRL_IN3 = 3,
  CTRL_IN4 = 4,
  CTRL_OUT0 = 8,
  CTRL_OUT1 = 9,
  CTRL_OUT2 = 10,
  CTRL_OUT3 = 11,
  CTRL_OUT4 = 12,
  CTRL_MULTI0 = 5,
  CTRL_MULTI1 = 6,
  CTRL_MULTI2 = 7,
  CTRL_MULTI3 = 13,
  MLU_SEL0 = 14,
  MLU_SEL1 = 15,
  MLU_SEL2 = 16,
  CTRL_BUS0 = 16,
  CTRL_BUS1 = 17,
  CTRL_BUS2 = 18,
  CTRL_BUS3 = 19,
  CTRL_BUS4 = 20,
  CTRL_BUS5 = 21,
  CTRL_BUS6 = 22,
  CTRL_BUS7 = 23,
};

// IN plane values
enum {
  IN_NONE = 0,
  IN_N_A = 1,
  IN_N_B = 2,
  IN_N_M0 = 3,
  IN_N_M1 = 4,
  IN_N_N2 = 5,
  IN_N_S0 = 6,
  IN_N_S1 = 7,
  IN_N_S2 = 8,
  IN_N_K0 = 9,
  IN_N_K1 = 10,
  IN_N_K2 = 11,
  IN_N_PC0 = 12,
  IN_N_PC1 = 13,
  IN_N_PC2 = 14,
  IN_N_MMU0 = 15,
  IN_N_MMU1 = 16,
  IN_N_MMU2 = 17,
  IN_N_MMU = 18,
  IN_N_MMU_CONTROL = 19,
  IN_N_DISP = 20,
  IN_N_TASK = 21,
  IN_N_OPCODE0 = 22,
  IN_N_OPCODE1 = 23,
  IN_N_INT0 = 24,
  IN_N_INT1 = 25,
  IN_N_INT2 = 26,
  IN_N_INT3 = 27,
  IN_N_INT4 = 28,
  IN_N_INT5 = 29,
  IN_N_INT6 = 30,
  IN_N_INT7 = 31,
};

// OUT plane values
enum {
  OUT_NONE = 0,
  OUT_N_A = 1,
  OUT_N_B = 2,
  OUT_N_M0 = 3,
  OUT_N_M1 = 4,
  OUT_N_N2 = 5,
  OUT_N_S0 = 6,
  OUT_N_S1 = 7,
  OUT_N_S2 = 8,
  OUT_N_K0 = 9,
  OUT_N_K1 = 10,
  OUT_N_K2 = 11,
  OUT_N_PC0 = 12,
  OUT_N_PC1 = 13,
  OUT_N_PC2 = 14,
  OUT_N_STATUS = 15,
  OUT_N_INTERRUPT = 16,
  OUT_N_SUM = 17,
  OUT_N_MMU = 18,
  OUT_N_MMU_CONTROL = 19,
  OUT_N_TASK = 20,
  OUT_N_MLU = 21,
  OUT_N_CTRLLOGIC = 22,
  OUT_N_INT0 = 24,
  OUT_N_INT1 = 25,
  OUT_N_INT2 = 26,
  OUT_N_INT3 = 27,
  OUT_N_INT4 = 28,
  OUT_N_INT5 = 29,
  OUT_N_INT6 = 30,
  OUT_N_INT7 = 31,
}


// MULTI plane values
enum {
  MULTI_NONE = 0,
  MULTI_N_SUB = 1,
  MULTI_N_RESET = 2,
  MULTI_N_RESET_UOP_COUNT = 3,
  MULTI_N_SET_INT_ENABLE = 4,
  MULTI_N_UNSET_INT_ENABLE = 5,
  MULTI_N_PC_INC = 6,
  MULTI_N_OPCODE0_INC = 7,
  MULTI_N_OPCODE1_INC = 8,
  MULTI_N_SP_INC = 9,
  MULTI_N_SP_DEC = 10,
  MULTI_N_KSP_INC = 11,
  MULTI_N_KSP_DEC = 12,
  MULTI_N_ALU_FLAG_SET = 13,
}

// Control logic input:
enum {
  INPUT_OP0 = 0,
  INPUT_OP1 = 1,
  INPUT_OP2 = 2,
  INPUT_OP3 = 3,
  INPUT_OP4 = 4,
  INPUT_OP5 = 5,
  INPUT_OP6 = 6,
  INPUT_OP7 = 7,
  INPUT_AUX0 = 8, // Corresponds to OP8 to OP11
  INPUT_AUX1 = 9,
  INPUT_AUX2 = 10,
  INPUT_AUX3 = 11,
  INPUT_MICROOP0 = 12,
  INPUT_MICROOP1 = 13,
  INPUT_MICROOP2 = 14,
  INPUT_MICROOP3 = 15,
  INPUT_INT_FLAG = 16,
  INPUT_MMU_FAULT_FLAG = 17,
  INPUT_UNUSED = 18,
}

uint32_t in(int in_plane) {
  uint32_t output = 0;
  if (in_plane & 1) output |= 1 << CTRL_IN0;
  if (in_plane & 2) output |= 1 << CTRL_IN1;
  if (in_plane & 4) output |= 1 << CTRL_IN2;
  if (in_plane & 8) output |= 1 << CTRL_IN3;
  if (in_plane & 16) output |= 1 << CTRL_IN4;
  return output;
}

uint32_t out(int out_plane) {
  uint32_t output = 0;
  if (out_plane & 1) output |= 1 << CTRL_OUT0;
  if (out_plane & 2) output |= 1 << CTRL_OUT1;
  if (out_plane & 4) output |= 1 << CTRL_OUT2;
  if (out_plane & 8) output |= 1 << CTRL_OUT3;
  if (out_plane & 16) output |= 1 << CTRL_OUT4;
  return output;
}

uint32_t multi(int multi_plane) {
  uint32_t output = 0;
  if (multi_plane & 1) output |= 1 << CTRL_MULTI0;
  if (multi_plane & 2) output |= 1 << CTRL_MULTI1;
  if (multi_plane & 4) output |= 1 << CTRL_MULTI2;
  if (multi_plane & 8) output |= 1 << CTRL_MULTI3;
  return output;
}

uint32_t mlu(int mlu_plane) {
  uint32_t output = 0;
  if (mlu_plane & 1) output |= 1 << MLU_SEL0;
  if (mlu_plane & 2) output |= 1 << MLU_SEL1;
  if (mlu_plane & 4) output |= 1 << MLU_SEL2;
  return output;
}

uint32_t bus(int bus_plane) {
  uint32_t output = 0;
  if (bus_plane & 1) output |= 1 << CTRL_BUS0;
  if (bus_plane & 2) output |= 1 << CTRL_BUS1;
  if (bus_plane & 4) output |= 1 << CTRL_BUS2;
  if (bus_plane & 8) output |= 1 << CTRL_BUS3;
  if (bus_plane & 16) output |= 1 << CTRL_BUS4;
  if (bus_plane & 32) output |= 1 << CTRL_BUS5;
  if (bus_plane & 64) output |= 1 << CTRL_BUS6;
  if (bus_plane & 128) output |= 1 << CTRL_BUS7;
  return output;
}

void generateInstructions() {
  // Instruction set:
  // 0: Boot sequence
  // 1: Fetch opcode

  // TODO check interrupt, page fault
  // TODO what can AUX be? e.g. for fetch opcode need to be same for all AUX
  uint32_t microops[] = {
    // Set AUX opcode to 0
    bus(0) | out(OUT_N_CTRLLOGIC) | in(IN_N_OPCODE1),
    // Load PC into MMU registers
    out(OUT_N_PC0) | in(IN_N_MMU0),
    out(OUT_N_PC1) | in(IN_N_MMU1),
    out(OUT_N_PC2) | in(IN_N_MMU2),
    // Load new opcode and reset uop counter.
    out(OUT_N_MMU) | in(IN_N_OPCODE0) | multi(MULTI_N_RESET_UOP_COUNT), 
  }

  // 2: Page fault
  // 3: Handle interrupt

}

}

void runControl() {
  unsigned long start = millis();
  
  SST39SF040 eeprom;

  for (uint32_t i = 0; i < 256; ++i) {
    eeprom.writeByte(i, i % 256);
  }

  printf("Written in %ldms\n", millis() - start);
  // eeprom.print(MAX - 8192, 8192);
  eeprom.print(0, 256);
}