// Copyright 2019 Eliot Courtney.
#include "gtest/gtest.h"
#include "memeasm/assembler.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"

namespace {

const std::string MODEL_JSON = readFile("verilog/ksm_model.json");

using MemeAsmTest = testing::Test;

TEST_F(MemeAsmTest, EmptyProgram) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("");
  EXPECT_TRUE(result.empty());
}

TEST_F(MemeAsmTest, CommentsOnly) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("; this is a comment\n; another comment");
  EXPECT_TRUE(result.empty());
}

TEST_F(MemeAsmTest, SimpleNop) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("nop");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(1u << 6, result[0]);  // opcode 1 shifted by 6
}

TEST_F(MemeAsmTest, MultipleNops) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("nop\nnop\nnop");
  ASSERT_EQ(3u, result.size());
  for (const auto& instr : result) {
    EXPECT_EQ(1u << 6, instr);
  }
}

TEST_F(MemeAsmTest, LoadUpperHalfImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("lhu r0,0xff");
  ASSERT_EQ(1u, result.size());
  // opcode 2, register 0, immediate 0xff
  uint32_t expected = (2 << 6) | (0 << 11) | (0xff << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, AddWithRegisters) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("add r1,r2,r3");
  ASSERT_EQ(1u, result.size());
  // opcode 4, r1, r2, r3
  uint32_t expected = (4 << 6) | (1 << 11) | (2 << 16) | (3 << 21);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, AddWithImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("addu r5,r10,0x20");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (3 << 6) | (5 << 11) | (10 << 16) | (0x20 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, StoreWord) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("sw [r1,0x10],r2");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (5 << 6) | (1 << 11) | (2 << 16) | (0x10 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, LoadWord) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("lw r3,[r4,0x8]");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (9 << 6) | (3 << 11) | (4 << 16) | (0x8 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, SimpleLabel) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("start:\nnop\nlhu r31,start");
  ASSERT_EQ(2u, result.size());
  EXPECT_EQ(1u << 6, result[0]);  // nop
  // lhu with address 0 (start label)
  uint32_t expected = (2 << 6) | (31 << 11) | (0 << 16);
  EXPECT_EQ(expected, result[1]);
}

TEST_F(MemeAsmTest, ForwardLabel) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("lhu r0,end\nnop\nend:");
  ASSERT_EQ(2u, result.size());
  // lhu with address pointing to end (address 1)
  uint32_t expected = (2 << 6) | (0 << 11) | (1 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, BackwardLabel) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("start:\nnop\nlhu r0,start");
  ASSERT_EQ(2u, result.size());
  // lhu with address 0 (start label)
  uint32_t expected = (2 << 6) | (0 << 11) | (0 << 16);
  EXPECT_EQ(expected, result[1]);
}

TEST_F(MemeAsmTest, RelativeBranch) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("loop:\nbeq r1,r2,loop");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (8 << 6) | (1 << 11) | (2 << 16) | (uint16_t(-1) << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, BranchNotEqual) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("end:\nbne r5,r6,end");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (11 << 6) | (5 << 11) | (6 << 16) | (uint16_t(-1) << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, ShiftLeft) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("sll r1,r2,0x3");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (10 << 6) | (1 << 11) | (2 << 16) | (3 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, ShiftRight) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("srl r7,r8,0x5");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (14 << 6) | (7 << 11) | (8 << 16) | (5 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, OrOperation) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("or r10,r11,r12");
  ASSERT_EQ(1u, result.size());
  // opcode 6, r10, r11, r12
  uint32_t expected = (6 << 6) | (10 << 11) | (11 << 16) | (12 << 21);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, XorOperation) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("xor r15,r16,r17");
  ASSERT_EQ(1u, result.size());
  // opcode 13, r15, r16, r17
  uint32_t expected = (13 << 6) | (15 << 11) | (16 << 16) | (17 << 21);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, AndWithImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("and r20,r21,0xf");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (12 << 6) | (20 << 11) | (21 << 16) | (0xf << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, DataWord) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("dw 0xdeadbeef");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(0xdeadbeef, result[0]);
}

TEST_F(MemeAsmTest, DataWordWithLabel) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("data:\ndw data");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(0u, result[0]);  // Address of data label is 0
}

TEST_F(MemeAsmTest, MixedInstructions) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::string program =
    "lhu r0,0\n"
    "lhu r1,1\n"
    "add r2,r0,r1\n"
    "nop";
  std::vector<uint32_t> result = assembler.assemble(program);
  ASSERT_EQ(4u, result.size());
}

TEST_F(MemeAsmTest, NegativeImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("addu r1,r2,-5");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (3 << 6) | (1 << 11) | (2 << 16) | (uint16_t(-5) << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, MaxRegisterNumber) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("add r31,r30,r29");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (4 << 6) | (31 << 11) | (30 << 16) | (29 << 21);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, LabelWithOffset) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("start:\nnop\nnop\nlhu r0,start+2");
  ASSERT_EQ(3u, result.size());
  uint32_t expected = (2 << 6) | (0 << 11) | (2 << 16);
  EXPECT_EQ(expected, result[2]);
}

TEST_F(MemeAsmTest, MultipleLabels) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble(
    "start:\n"
    "nop\n"
    "middle:\n"
    "nop\n"
    "end:\n"
    "nop");
  ASSERT_EQ(3u, result.size());
}

TEST_F(MemeAsmTest, CommentsAfterInstructions) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble(
    "nop ; this is a comment\n"
    "lhu r0,0xff ; another comment");
  ASSERT_EQ(2u, result.size());
}

TEST_F(MemeAsmTest, BlankLines) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("\n\nnop\n\n\nlhu r1,0\n\n");
  ASSERT_EQ(2u, result.size());
}

TEST_F(MemeAsmTest, Interrupt) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("int");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(16u << 6, result[0]);
}

TEST_F(MemeAsmTest, SetInterrupt) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("seti");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(17u << 6, result[0]);
}

TEST_F(MemeAsmTest, ClearInterrupt) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("clri");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(18u << 6, result[0]);
}

TEST_F(MemeAsmTest, Reset) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("rst");
  ASSERT_EQ(1u, result.size());
  EXPECT_EQ(0u, result[0]);
}

TEST_F(MemeAsmTest, LoadSignExtended) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("lh r5,0xf000");
  ASSERT_EQ(1u, result.size());
  // opcode 7, r5, immediate 0xf000
  uint32_t expected = (7 << 6) | (5 << 11) | (0xf000 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, RealProgramFibonacci) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::string program = readFile("test_data/asm/asm0.ksm");
  std::vector<uint32_t> result = assembler.assemble(program);
  EXPECT_GT(result.size(), 0u);
  // First instruction should be dw 0
  EXPECT_EQ(0u, result[0]);
}

TEST_F(MemeAsmTest, RealProgramVramTest) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::string program = readFile("test_data/asm/asm1.ksm");
  std::vector<uint32_t> result = assembler.assemble(program);
  EXPECT_GT(result.size(), 0u);
  // First instruction should be dw 0
  EXPECT_EQ(0u, result[0]);
}

TEST_F(MemeAsmTest, GenerateMnemonicString) {
  // Test the reverse operation - generating mnemonic from opword
  std::string mnemonic_format = "add r%1%,r%2%,r%3%";
  uint32_t opword = (1 << 11) | (2 << 16) | (3 << 21);  // r1, r2, r3
  std::string result = memeasm::Assembler::generateMnemonicString(mnemonic_format, opword);
  EXPECT_TRUE(result.find("1") != std::string::npos);
  EXPECT_TRUE(result.find("2") != std::string::npos);
  EXPECT_TRUE(result.find("3") != std::string::npos);
}

TEST_F(MemeAsmTest, HexImmediateFormats) {
  memeasm::Assembler assembler(MODEL_JSON);

  // Lowercase hex
  std::vector<uint32_t> result1 = assembler.assemble("lhu r0,0xff");
  ASSERT_EQ(1u, result1.size());

  // Uppercase hex
  std::vector<uint32_t> result2 = assembler.assemble("lhu r0,0xFF");
  ASSERT_EQ(1u, result2.size());

  EXPECT_EQ(result1[0], result2[0]);
}

TEST_F(MemeAsmTest, OctalImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("lhu r0,010");  // Octal 10 = decimal 8
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (2 << 6) | (0 << 11) | (8 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, ZeroImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("lhu r0,0");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (2 << 6) | (0 << 11) | (0 << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, AllRegisters) {
  memeasm::Assembler assembler(MODEL_JSON);
  // Test that we can use all 32 registers
  for (int i = 0; i < 32; i++) {
    std::string program = "lhu r" + std::to_string(i) + ",0";
    std::vector<uint32_t> result = assembler.assemble(program);
    ASSERT_EQ(1u, result.size());
  }
}

TEST_F(MemeAsmTest, MaximumImmediate) {
  memeasm::Assembler assembler(MODEL_JSON);
  // Test maximum positive 16-bit immediate
  std::vector<uint32_t> result = assembler.assemble("lhu r0,0xffff");
  ASSERT_EQ(1u, result.size());
  uint32_t expected = (2 << 6) | (0 << 11) | (0xffff << 16);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, LabelReferencesInDataWords) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble(
    "start:\n"
    "nop\n"
    "dw start\n"
    "dw start+1");
  ASSERT_EQ(3u, result.size());
  EXPECT_EQ(0u, result[1]);  // Address of start
  EXPECT_EQ(1u, result[2]);  // Address of start + 1
}

TEST_F(MemeAsmTest, ComplexProgram) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::string program =
    "; Complex test program\n"
    "start:\n"
    "  lhu r0,0 ; Initialize r0\n"
    "  lhu r1,1\n"
    "  lhu r2,10\n"
    "\n"
    "loop:\n"
    "  add r3,r0,r1 ; Add\n"
    "  addu r0,r1,0 ; Copy\n"
    "  addu r1,r3,0\n"
    "  beq r3,r2,end ; Check if done\n"
    "  lhu r31,loop\n"
    "\n"
    "end:\n"
    "  nop\n"
    "  lhu r31,end ; Infinite loop\n";

  std::vector<uint32_t> result = assembler.assemble(program);
  EXPECT_GT(result.size(), 5u);
}

TEST_F(MemeAsmTest, WhitespaceVariations) {
  memeasm::Assembler assembler(MODEL_JSON);

  // Test with tabs
  std::vector<uint32_t> r1 = assembler.assemble("\t\tnop");
  ASSERT_EQ(1u, r1.size());

  // Test with multiple spaces
  std::vector<uint32_t> r2 = assembler.assemble("    nop    ");
  ASSERT_EQ(1u, r2.size());

  // Results should be identical
  EXPECT_EQ(r1[0], r2[0]);
}

TEST_F(MemeAsmTest, ShiftLeftWithRegister) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble("sll r1,r2,r3");
  ASSERT_EQ(1u, result.size());
  // opcode 15, r1, r2, r3
  uint32_t expected = (15 << 6) | (1 << 11) | (2 << 16) | (3 << 21);
  EXPECT_EQ(expected, result[0]);
}

TEST_F(MemeAsmTest, AllBranchInstructions) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::string program =
    "target:\n"
    "beq r1,r2,target\n"
    "bne r3,r4,target\n";

  std::vector<uint32_t> result = assembler.assemble(program);
  ASSERT_EQ(2u, result.size());
}

TEST_F(MemeAsmTest, StoreAndLoadMemory) {
  memeasm::Assembler assembler(MODEL_JSON);
  std::vector<uint32_t> result = assembler.assemble(
    "sw [r1,0x100],r2\n"
    "lw r3,[r4,0x200]");

  ASSERT_EQ(2u, result.size());
}

}  // namespace
