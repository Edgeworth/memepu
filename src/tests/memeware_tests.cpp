// Copyright 2019 Eliot Courtney.
#include "gtest/gtest.h"
#include "memeware/microcode.h"
#include "memeware/constants.h"

namespace {

using MemewareTest = testing::Test;

TEST_F(MemewareTest, GenerateMluSliceFirmware) {
  std::vector<uint8_t> firmware = memeware::generateMluSliceFirmware();
  int expected_size = (1 << memeware::MLU_SLICE_DEPTH);
  ASSERT_EQ(expected_size, firmware.size());
}

TEST_F(MemewareTest, MluSliceFirmwareNonEmpty) {
  std::vector<uint8_t> firmware = memeware::generateMluSliceFirmware();
  EXPECT_FALSE(firmware.empty());
}

TEST_F(MemewareTest, GenerateMluLookaheadFirmware) {
  std::vector<uint8_t> firmware = memeware::generateMluLookaheadFirmware();
  int expected_size = (1 << memeware::MLU_LOOKAHEAD_DEPTH);
  ASSERT_EQ(expected_size, firmware.size());
}

TEST_F(MemewareTest, MluLookaheadFirmwareNonEmpty) {
  std::vector<uint8_t> firmware = memeware::generateMluLookaheadFirmware();
  EXPECT_FALSE(firmware.empty());
}

TEST_F(MemewareTest, GenerateMicrocodeFirmware) {
  std::vector<uint32_t> firmware = memeware::generateMicrocodeFirmware();
  int expected_size = (1 << memeware::MICROCODE_DEPTH);
  ASSERT_EQ(expected_size, firmware.size());
}

TEST_F(MemewareTest, MicrocodeFirmwareNonEmpty) {
  std::vector<uint32_t> firmware = memeware::generateMicrocodeFirmware();
  EXPECT_FALSE(firmware.empty());
}

TEST_F(MemewareTest, GenerateMemeasmModel) {
  std::string model = memeware::generateMemeasmModel();
  EXPECT_FALSE(model.empty());
  // Should be valid JSON
  EXPECT_NE(std::string::npos, model.find("["));
  EXPECT_NE(std::string::npos, model.find("]"));
}

TEST_F(MemewareTest, MemeasmModelContainsOpcodes) {
  std::string model = memeware::generateMemeasmModel();
  // Check for common opcodes
  EXPECT_NE(std::string::npos, model.find("opcode"));
  EXPECT_NE(std::string::npos, model.find("mnemonic"));
}

TEST_F(MemewareTest, MluSliceDepthValid) {
  EXPECT_GT(memeware::MLU_SLICE_DEPTH, 0);
  EXPECT_LE(memeware::MLU_SLICE_DEPTH, 20);  // Reasonable upper bound
}

TEST_F(MemewareTest, MluLookaheadDepthValid) {
  EXPECT_GT(memeware::MLU_LOOKAHEAD_DEPTH, 0);
  EXPECT_LE(memeware::MLU_LOOKAHEAD_DEPTH, 20);  // Reasonable upper bound
}

TEST_F(MemewareTest, MicrocodeDepthValid) {
  EXPECT_GT(memeware::MICROCODE_DEPTH, 0);
  EXPECT_LE(memeware::MICROCODE_DEPTH, 20);  // Reasonable upper bound
}

TEST_F(MemewareTest, MluSliceFirmwareConsistency) {
  std::vector<uint8_t> firmware1 = memeware::generateMluSliceFirmware();
  std::vector<uint8_t> firmware2 = memeware::generateMluSliceFirmware();
  ASSERT_EQ(firmware1.size(), firmware2.size());
  for (size_t i = 0; i < firmware1.size(); i++) {
    EXPECT_EQ(firmware1[i], firmware2[i]) << "Mismatch at index " << i;
  }
}

TEST_F(MemewareTest, MluLookaheadFirmwareConsistency) {
  std::vector<uint8_t> firmware1 = memeware::generateMluLookaheadFirmware();
  std::vector<uint8_t> firmware2 = memeware::generateMluLookaheadFirmware();
  ASSERT_EQ(firmware1.size(), firmware2.size());
  for (size_t i = 0; i < firmware1.size(); i++) {
    EXPECT_EQ(firmware1[i], firmware2[i]) << "Mismatch at index " << i;
  }
}

TEST_F(MemewareTest, MicrocodeFirmwareConsistency) {
  std::vector<uint32_t> firmware1 = memeware::generateMicrocodeFirmware();
  std::vector<uint32_t> firmware2 = memeware::generateMicrocodeFirmware();
  ASSERT_EQ(firmware1.size(), firmware2.size());
  for (size_t i = 0; i < firmware1.size(); i++) {
    EXPECT_EQ(firmware1[i], firmware2[i]) << "Mismatch at index " << i;
  }
}

TEST_F(MemewareTest, MluEnumValues) {
  // Test that MLU enum values are distinct
  EXPECT_NE(memeware::MLU_ADD, memeware::MLU_SUB);
  EXPECT_NE(memeware::MLU_ADD, memeware::MLU_AND);
  EXPECT_NE(memeware::MLU_ADD, memeware::MLU_OR);
  EXPECT_NE(memeware::MLU_ADD, memeware::MLU_XOR);
  EXPECT_NE(memeware::MLU_ADD, memeware::MLU_NOT);
}

TEST_F(MemewareTest, ShifterEnumValues) {
  // Test that Shifter enum values are distinct
  EXPECT_NE(memeware::SHIFTER_LEFT_SHIFT, memeware::SHIFTER_RIGHT_SHIFT);
  EXPECT_NE(memeware::SHIFTER_LEFT_SHIFT, memeware::SHIFTER_SIGNEXT8);
  EXPECT_NE(memeware::SHIFTER_LEFT_SHIFT, memeware::SHIFTER_SIGNEXT16);
  EXPECT_NE(memeware::SHIFTER_RIGHT_SHIFT, memeware::SHIFTER_SIGNEXT8);
  EXPECT_NE(memeware::SHIFTER_RIGHT_SHIFT, memeware::SHIFTER_SIGNEXT16);
  EXPECT_NE(memeware::SHIFTER_SIGNEXT8, memeware::SHIFTER_SIGNEXT16);
}

TEST_F(MemewareTest, MluSliceFirmwareAddressSpace) {
  std::vector<uint8_t> firmware = memeware::generateMluSliceFirmware();
  // Check that we can access all addresses
  for (size_t i = 0; i < firmware.size(); i++) {
    // Just access the value to ensure it's valid
    uint8_t val = firmware[i];
    (void)val;  // Suppress unused variable warning
  }
}

TEST_F(MemewareTest, MluLookaheadFirmwareAddressSpace) {
  std::vector<uint8_t> firmware = memeware::generateMluLookaheadFirmware();
  // Check that we can access all addresses
  for (size_t i = 0; i < firmware.size(); i++) {
    uint8_t val = firmware[i];
    (void)val;
  }
}

TEST_F(MemewareTest, MicrocodeFirmwareAddressSpace) {
  std::vector<uint32_t> firmware = memeware::generateMicrocodeFirmware();
  // Check that we can access all addresses
  for (size_t i = 0; i < firmware.size(); i++) {
    uint32_t val = firmware[i];
    (void)val;
  }
}

TEST_F(MemewareTest, MemeasmModelContainsRelativeFlag) {
  std::string model = memeware::generateMemeasmModel();
  EXPECT_NE(std::string::npos, model.find("imm_relative"));
}

TEST_F(MemewareTest, MluSliceFirmwareSizeMatchesDepth) {
  std::vector<uint8_t> firmware = memeware::generateMluSliceFirmware();
  size_t expected = static_cast<size_t>(1) << memeware::MLU_SLICE_DEPTH;
  EXPECT_EQ(expected, firmware.size());
}

TEST_F(MemewareTest, MluLookaheadFirmwareSizeMatchesDepth) {
  std::vector<uint8_t> firmware = memeware::generateMluLookaheadFirmware();
  size_t expected = static_cast<size_t>(1) << memeware::MLU_LOOKAHEAD_DEPTH;
  EXPECT_EQ(expected, firmware.size());
}

TEST_F(MemewareTest, MicrocodeFirmwareSizeMatchesDepth) {
  std::vector<uint32_t> firmware = memeware::generateMicrocodeFirmware();
  size_t expected = static_cast<size_t>(1) << memeware::MICROCODE_DEPTH;
  EXPECT_EQ(expected, firmware.size());
}

}  // namespace
