#ifndef MEMEPU_ASM_H_
#define MEMEPU_ASM_H_
#include "common.h"

enum class Opcode : uint8_t {
  MICROOP_RESET_HACK,
  BOOT,
  FETCH,
  PAGE_FAULT,
  HANDLE_INTERRUPT,
  LDA_IMM,
  LDB_IMM,
  LDM0_IMM,
  ADD,
  SUB,
  JMP,
  DISPLAY,
  SWAP,
  LDA_INT
};

class Asm {
public:
  Asm() {}

  std::string assembleToBinaryData(const std::string& data);

private:
};

#endif  // MEMEPU_ASM_H_
