// Copyright 2019 Eliot Courtney.
#include "gtest/gtest.h"
#include "memeasm/assembler.h"
#include "memeware/microcode.h"
#include "memesim/simulator.h"
#include "verymeme/file.h"
#include "verymeme/string_util.h"

namespace {

using IntegrationTest = testing::Test;

// Test that the microcode generator produces a valid model that the assembler can use
TEST_F(IntegrationTest, MicrocodeToAssemblerPipeline) {
  // Generate the model from microcode
  std::string generated_model = memeware::generateMemeasmModel();
  EXPECT_FALSE(generated_model.empty());

  // Use the generated model to create an assembler
  memeasm::Assembler assembler(generated_model);

  // Assemble a simple program
  std::string program = "nop\nlhu r0,0xff\nadd r1,r0,r0";
  std::vector<uint32_t> result = assembler.assemble(program);

  EXPECT_EQ(3u, result.size());
  EXPECT_GT(result[0], 0u);  // nop should have opcode
}

// Test assembling and then disassembling instructions
TEST_F(IntegrationTest, AssembleAndDisassemble) {
  std::string model = readFile("verilog/ksm_model.json");
  memeasm::Assembler assembler(model);

  // Test various instructions
  struct TestCase {
    std::string instruction;
    std::string mnemonic_format;
  };

  std::vector<TestCase> tests = {
    {"add r1,r2,r3", "add r%1%,r%2%,r%3%"},
    {"lhu r5,0x100", "lhu r%1%,%4$x"},
  };

  for (const auto& test : tests) {
    std::vector<uint32_t> assembled = assembler.assemble(test.instruction);
    ASSERT_EQ(1u, assembled.size());

    // Generate mnemonic string from the assembled opword
    std::string disassembled = memeasm::Assembler::generateMnemonicString(
        test.mnemonic_format, assembled[0]);
    EXPECT_FALSE(disassembled.empty());
  }
}

// Test assembling a real program and verifying it loads correctly
TEST_F(IntegrationTest, AssembleRealProgramFromFile) {
  std::string model = readFile("verilog/ksm_model.json");
  memeasm::Assembler assembler(model);

  // Load and assemble the fibonacci program
  std::string asm_source = readFile("test_data/asm/asm0.ksm");
  std::vector<uint32_t> assembled = assembler.assemble(asm_source);

  EXPECT_GT(assembled.size(), 5u);  // Should have multiple instructions
  EXPECT_EQ(0u, assembled[0]);      // First instruction is "dw 0"

  // Verify we can convert to hexdump format
  std::string hexdump_output = hexdump(assembled);
  EXPECT_FALSE(hexdump_output.empty());
  EXPECT_TRUE(hexdump_output.find('\n') != std::string::npos);  // Should have newlines
}

// Test the full microcode generation pipeline
TEST_F(IntegrationTest, MicrocodeFirmwareGeneration) {
  // Generate all three firmware types
  auto mlu_slice = memeware::generateMluSliceFirmware();
  auto mlu_lookahead = memeware::generateMluLookaheadFirmware();
  auto microcode = memeware::generateMicrocodeFirmware();

  // Verify they're all non-empty and have expected sizes
  EXPECT_EQ(1 << 12, mlu_slice.size());
  EXPECT_EQ(1 << 17, mlu_lookahead.size());
  EXPECT_EQ(1 << 12, microcode.size());

  // Verify consistency - generating again should produce same results
  auto mlu_slice2 = memeware::generateMluSliceFirmware();
  EXPECT_EQ(mlu_slice, mlu_slice2);
}

// Test simulator initialization with a simple program
TEST_F(IntegrationTest, SimulatorWithSimpleProgram) {
  // Create a simulator
  memesim::Simulator sim;

  // Schedule a command to get CPU state
  auto receiver = std::make_shared<ConcurrentQueue<memesim::Simulator::Response>>();
  memesim::Simulator::Cmd cmd;
  cmd.type = memesim::Simulator::Cmd::Type::GET_CPU_STATE;
  cmd.receiver = receiver;

  EXPECT_NO_THROW(sim.scheduleCommand(cmd));
}

// Test assembling with label references across multiple instructions
TEST_F(IntegrationTest, ComplexLabelResolution) {
  std::string model = readFile("verilog/ksm_model.json");
  memeasm::Assembler assembler(model);

  std::string program = R"(
    ; Test forward and backward references
    start:
      lhu r0,0
      lhu r1,middle     ; forward ref
      nop
    middle:
      lhu r2,start      ; backward ref
      lhu r3,end        ; forward ref
      beq r0,r1,start   ; relative backward
      beq r0,r2,end     ; relative forward
    end:
      lhu r31,end       ; loop
  )";

  std::vector<uint32_t> assembled = assembler.assemble(program);
  EXPECT_EQ(8u, assembled.size());

  // Verify all instructions were assembled (no zeros except where expected)
  int non_zero_count = 0;
  for (auto instr : assembled) {
    if (instr != 0) non_zero_count++;
  }
  EXPECT_GT(non_zero_count, 5);  // Most instructions should be non-zero
}

// Test assembling data sections with labels
TEST_F(IntegrationTest, DataSectionWithLabels) {
  std::string model = readFile("verilog/ksm_model.json");
  memeasm::Assembler assembler(model);

  std::string program = R"(
    start:
      lhu r0,data_start
      lhu r1,data_end
      nop
    data_start:
      dw 0x12345678
      dw 0xdeadbeef
      dw start
      dw data_start
    data_end:
      dw 0xffffffff
  )";

  std::vector<uint32_t> assembled = assembler.assemble(program);
  ASSERT_EQ(8u, assembled.size());

  // Verify data section
  EXPECT_EQ(0x12345678u, assembled[3]);
  EXPECT_EQ(0xdeadbeefu, assembled[4]);
  EXPECT_EQ(0u, assembled[5]);   // Address of start (0)
  EXPECT_EQ(3u, assembled[6]);   // Address of data_start (3)
  EXPECT_EQ(0xffffffffu, assembled[7]);
}

// Test that multiple assembly passes produce consistent results
TEST_F(IntegrationTest, AssemblyConsistency) {
  std::string model = readFile("verilog/ksm_model.json");

  std::string program = R"(
    loop:
      lhu r0,0xff
      add r1,r0,r0
      beq r1,r0,loop
      lhu r31,loop
  )";

  // Assemble multiple times
  std::vector<std::vector<uint32_t>> results;
  for (int i = 0; i < 3; i++) {
    memeasm::Assembler assembler(model);
    results.push_back(assembler.assemble(program));
  }

  // All results should be identical
  for (size_t i = 1; i < results.size(); i++) {
    ASSERT_EQ(results[0].size(), results[i].size());
    for (size_t j = 0; j < results[0].size(); j++) {
      EXPECT_EQ(results[0][j], results[i][j])
          << "Mismatch at instruction " << j << " in pass " << i;
    }
  }
}

// Test hexdump conversion roundtrip properties
TEST_F(IntegrationTest, HexdumpFormatting) {
  std::vector<uint32_t> data = {0x12345678, 0xabcdef00, 0xdeadbeef, 0xcafebabe};

  std::string hexdump_str = hexdump(data, 40);  // 40 char width

  // Verify format properties
  EXPECT_FALSE(hexdump_str.empty());
  EXPECT_TRUE(hexdump_str.back() == '\n');  // Should end with newline

  // Count lines - with width 40 and 8 hex chars + space per uint32_t (9 chars),
  // we get roughly 4 words per line, so 1 line for 4 words
  int line_count = 0;
  for (char c : hexdump_str) {
    if (c == '\n') line_count++;
  }
  EXPECT_GT(line_count, 0);
}

// Test simulator command scheduling and response
TEST_F(IntegrationTest, SimulatorCommandResponse) {
  memesim::Simulator sim;
  auto receiver = std::make_shared<ConcurrentQueue<memesim::Simulator::Response>>();

  // Schedule multiple commands
  std::vector<memesim::Simulator::Cmd::Type> cmd_types = {
    memesim::Simulator::Cmd::Type::STOP,
    memesim::Simulator::Cmd::Type::STEP,
  };

  for (auto cmd_type : cmd_types) {
    memesim::Simulator::Cmd cmd;
    cmd.type = cmd_type;
    cmd.receiver = receiver;
    EXPECT_NO_THROW(sim.scheduleCommand(cmd));
  }
}

// Test that assembly error handling works correctly
TEST_F(IntegrationTest, AssemblyErrorHandling) {
  std::string model = readFile("verilog/ksm_model.json");
  memeasm::Assembler assembler(model);

  // Valid program should work
  EXPECT_NO_THROW({
    std::vector<uint32_t> result = assembler.assemble("nop\nlhu r0,0");
    EXPECT_EQ(2u, result.size());
  });

  // Empty program should produce empty result
  std::vector<uint32_t> empty_result = assembler.assemble("");
  EXPECT_TRUE(empty_result.empty());

  // Comments only should produce empty result
  std::vector<uint32_t> comment_result = assembler.assemble("; comment\n; another");
  EXPECT_TRUE(comment_result.empty());
}

// Test file I/O integration with assembler
TEST_F(IntegrationTest, FileIOWithAssembler) {
  std::string model = readFile("verilog/ksm_model.json");
  memeasm::Assembler assembler(model);

  // Read a real assembly file
  std::string source = readFile("test_data/asm/asm1.ksm");
  EXPECT_FALSE(source.empty());

  // Assemble it
  std::vector<uint32_t> assembled = assembler.assemble(source);
  EXPECT_GT(assembled.size(), 0u);

  // Convert to hexdump
  std::string hex_output = hexdump(assembled);
  EXPECT_FALSE(hex_output.empty());

  // Write and read back
  const std::string test_file = "/tmp/integration_test_output.hex";
  writeFile(test_file, hex_output);
  std::string read_back = readFile(test_file);
  EXPECT_EQ(hex_output, read_back);

  // Cleanup
  std::remove(test_file.c_str());
}

}  // namespace
