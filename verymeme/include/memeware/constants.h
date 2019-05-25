#ifndef VERYMEME_CONSTANTS_H
#define VERYMEME_CONSTANTS_H

#include "verymeme/common.h"

namespace memeware {

enum Mlu {
  MLU_ADD, MLU_SUB, MLU_AND, MLU_OR, MLU_XOR, MLU_NOT, MLU_NOP0, MLU_NOP1
};

enum Opcode {
  OP_RESET,
  OP_ADD,
};

enum RegisterSelect {
  REG_SEL_OP0, REG_SEL_OP1, REG_SEL_CONTROL
};

enum InPlane {
  IN_NONE, IN_REG, IN_TMP0, IN_TMP1, IN_OPWORD, IN_OPCODE
};

enum OutPlane {
  OUT_NONE, OUT_REG, OUT_TMP0, OUT_TMP1, OUT_MLU
};

}  // memeware

#endif  //VERYMEME_CONSTANTS_H
