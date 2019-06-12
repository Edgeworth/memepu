#ifndef VERYMEME_MEMEWARE_MICROCODE_H
#define VERYMEME_MEMEWARE_MICROCODE_H

#include "verymeme/common.h"

namespace memeware {

std::vector<uint8_t> generateMluSliceFirmware();

std::vector<uint8_t> generateMluLookaheadFirmware();

std::vector<uint32_t> generateMicrocodeFirmware();

}  // memeware

#endif  // VERYMEME_MEMEWARE_MICROCODE_H
