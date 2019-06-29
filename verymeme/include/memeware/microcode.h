#ifndef MEMEWARE_MICROCODE_H
#define MEMEWARE_MICROCODE_H

#include "verymeme/common.h"

namespace memeware {

std::vector<uint8_t> generateMluSliceFirmware();

std::vector<uint8_t> generateMluLookaheadFirmware();

std::vector<uint32_t> generateMicrocodeFirmware();

std::string generateMemeasmModel();

}  // memeware

#endif  // MEMEWARE_MICROCODE_H
