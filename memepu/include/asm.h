#ifndef MEMEPU_ASM_H_
#define MEMEPU_ASM_H_

#include <sstream>
#include <map>
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
  LDA_INT,
  DUMP,
  RETURN_FROM_ISR
};

class Asm {
public:
  Asm(const std::string& data) : data_(data) {}

  std::string assembleToBinaryData();

private:
  std::string data_;
  std::map<int, std::string> extents_;
  std::map<std::string, uint32_t> labels_;
  int cur_extent_ = 0;

  void parseLabelOrOffset(std::string token);
  void parseInstruction(std::string token, std::istringstream& stream);
  std::string mergeExtents();
};

#endif  // MEMEPU_ASM_H_
