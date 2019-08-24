#ifndef MEMEWARE_CONSTANTS_H
#define MEMEWARE_CONSTANTS_H

namespace memeware {

// See common.v
enum Mlu { MLU_ADD, MLU_SUB, MLU_AND, MLU_OR, MLU_XOR, MLU_NOT, MLU_ANOT, MLU_NOP1 };
enum Shifter { SHIFTER_LEFT_SHIFT, SHIFTER_RIGHT_SHIFT, SHIFTER_SIGNEXT8, SHIFTER_SIGNEXT16 };

// LUT sizes
constexpr int MLU_SLICE_DEPTH = 12;
constexpr int MLU_LOOKAHEAD_DEPTH = 17;
constexpr int MICROCODE_DEPTH = 12;

// Special registers.
constexpr int NUM_REG = 32;
constexpr int PC_REG = 31;

// Memory mapped IO
constexpr int OPWORD_SIZE = 1;
constexpr int VGA_WIDTH = 256;
constexpr int VGA_HEIGHT = 256;
constexpr uint32_t MMIO_VRAM_BASE = 0x10000;  // TODO change.
constexpr uint32_t MMIO_MOUSE_BASE = 0xffff;

}  // namespace memeware

#endif  // MEMEWARE_CONSTANTS_H
