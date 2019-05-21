#ifndef VERYMEME_CONSTANTS_H
#define VERYMEME_CONSTANTS_H

#include "verymeme/common.h"

namespace memeware {

enum Mlu {
  MLU_ADD, MLU_SUB, MLU_AND, MLU_OR, MLU_XOR, MLU_NOT, MLU_NOP0, MLU_NOP1
};

enum Opcode {
  OP_ADD,
};

}  // memeware

#endif  //VERYMEME_CONSTANTS_H
