#ifndef MEMEWARE_CONSTANTS_H
#define MEMEWARE_CONSTANTS_H

#include "verymeme/common.h"

namespace memeware {

enum Mlu {
  MLU_ADD, MLU_SUB, MLU_AND, MLU_OR, MLU_XOR, MLU_NOT, MLU_NOP0, MLU_NOP1
};

enum Shifter {
  SHIFTER_LEFT_SHIFT, SHIFTER_RIGHT_SHIFT, SHIFTER_SIGNEXT8, SHIFTER_SIGNEXT16
};

constexpr int MLU_SLICE_DEPTH = 12;
constexpr int MLU_LOOKAHEAD_DEPTH = 17;
constexpr int MICROCODE_DEPTH = 12;

}  // memeware

#endif  // MEMEWARE_CONSTANTS_H
