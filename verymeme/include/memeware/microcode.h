#ifndef VERYMEME_MEMEWARE_MICROCODE_H
#define VERYMEME_MEMEWARE_MICROCODE_H

#include "verymeme/common.h"

namespace memeware {

uint8_t generateSumOutput(uint32_t sum, uint32_t carry_in);

uint8_t generateGeneralOutput(uint32_t result);

std::vector<uint8_t> generateMluSliceFirmware();

std::vector<uint8_t> generateMluLookaheadFirmware();

std::vector<uint8_t> generateMicrocodeFirmware();

}  // memeware

#endif  // VERYMEME_MEMEWARE_MICROCODE_H
