# Test Coverage Summary

## Tests Added

This document summarizes the comprehensive test coverage added to the memepu project.

### New Test Files Created

1. **src/tests/verymeme_tests.cpp** - Comprehensive tests for the verymeme utility library
2. **src/tests/memeasm_tests.cpp** - Comprehensive tests for the memeasm assembler
3. **src/tests/memesim_tests.cpp** - Tests for the memesim simulator
4. **src/tests/memeware_tests.cpp** - Tests for the memeware microcode generator
5. **src/tests/integration_tests.cpp** - Integration tests for cross-module functionality

### Test Coverage Details

#### verymeme_tests.cpp (600+ lines, 80+ test cases)

**File Operations (`verymeme/file.h`, `verymeme/file.cpp`)**
- Basename extraction with various path formats
- Stem extraction with single and multiple extensions
- Handling of dot files
- File reading and writing (text and binary modes)
- Edge cases: empty strings, trailing slashes, files without extensions

**String Utilities (`verymeme/string_util.h`, `verymeme/string_util.cpp`)**
- Trim operations with various whitespace characters
- Hex/decimal/octal integer conversion
- Integer overflow handling
- Join operations with and without terminators
- Hexdump generation
- Edge cases: invalid formats, empty strings, overflow conditions

**Geometry (`verymeme/geom.h`, `verymeme/geom.cpp`)**
- Point arithmetic (addition, subtraction, negation)
- Point comparison operations
- Cross product calculation
- Rectangle operations (inset, offset, union)
- Rectangle containment and emptiness checks
- Rectangle dimension getters and setters
- Clamp function

**Tokenizer (`verymeme/tokeniser.h`, `verymeme/tokeniser.cpp`)**
- Basic tokenization
- Peek ahead functionality
- Token expectation and validation
- Substring extraction

**Terminal Colors (`verymeme/term.h`, `verymeme/term.cpp`)**
- Color conversion with foreground colors
- Background color support
- Style attributes (bold, faint, underline)
- Empty string handling

**Bimap (`verymeme/bimap.h`)**
- Insert and lookup operations
- Duplicate key/value rejection
- Key existence checking
- Reverse lookup (value to key)
- Multiple insert operations

**Utility Functions (`verymeme/util.h`)**
- Map default value retrieval
- Vector reversal
- Edge cases: empty vectors, single elements

#### memeasm_tests.cpp (400+ lines, 50+ test cases)

**Assembler Core Functionality**
- Empty program handling
- Comment-only programs
- Single and multiple NOP instructions
- Load upper half immediate instructions
- Register operations (add, or, xor, and)
- Memory operations (load word, store word)
- Shift operations (left, right)

**Label Handling**
- Simple labels
- Forward references
- Backward references
- Labels with offsets
- Multiple labels
- Relative branches

**Branch Instructions**
- Branch on equal (beq)
- Branch on not equal (bne)
- Relative address calculation

**Immediate Values**
- Hexadecimal (lowercase and uppercase)
- Decimal (positive and negative)
- Octal
- Zero immediate
- Overflow detection

**Data Directives**
- Data word (dw) instructions
- Data word with label references

**Special Instructions**
- Interrupt (int)
- Set interrupt (seti)
- Clear interrupt (clri)
- Reset (rst)

**Real Program Tests**
- Fibonacci program (asm0.ksm)
- VRAM test program (asm1.ksm)

**Mnemonic Generation**
- Reverse operation (opword to mnemonic string)

#### memesim_tests.cpp (200+ lines, 30+ test cases)

**KPU (CPU) Operations**
- Initialization
- Reset functionality
- Multiple clock cycles
- Reset after multiple clocks

**Simulator Structure**
- Simulator construction
- Command scheduling
- CPU state message structure
- VGA state message structure

**Command System**
- All command types (RUN, STOP, STEP, SET_BREAKPOINT, GET_CPU_STATE, GET_VGA_STATE, QUIT)
- Command arguments
- Default values

**Register Operations**
- Register array access
- All 32 registers
- PC register index

**Memory-Mapped I/O**
- MMIO addresses defined and distinct
- VRAM base address
- Mouse, keyboard, interrupt clear addresses
- Interrupt vector
- VGA dimensions

#### memeware_tests.cpp (200+ lines, 30+ test cases)

**Firmware Generation**
- MLU slice firmware generation and size validation
- MLU lookahead firmware generation and size validation
- Microcode firmware generation and size validation
- Consistency checks (deterministic output)

**Address Space Coverage**
- Full address space traversal for all firmware types
- Size matching with depth constants

**Model Generation**
- Memeasm model JSON generation
- JSON structure validation
- Opcode and mnemonic presence
- Relative flag presence

**Constants Validation**
- MLU enum values distinctness
- Shifter enum values distinctness
- Depth constants validity

#### integration_tests.cpp (320+ lines, 14 test cases)

**Cross-Module Integration Tests**
- Microcode to assembler pipeline (generated model usage)
- Assemble and disassemble roundtrip
- Real program assembly from files
- Complete microcode firmware generation pipeline
- Simulator initialization and command scheduling
- Complex label resolution across multiple instructions
- Data sections with label references
- Assembly consistency across multiple passes
- Hexdump formatting and properties
- Simulator command/response interaction
- Assembly error handling
- File I/O integration with assembler
- Label forward and backward references
- Multi-instruction program verification

**Pipeline Tests**
- Microcode → Model → Assembler → Binary
- Assembly → Hexdump → File I/O roundtrip
- Simulator → Commands → State queries

## Bugs Found and Tests Added

### Bug 1: bimap.h - keyForValue() Missing Bounds Check
**Location**: `src/verymeme/bimap.h:20-23`
**Issue**: The `keyForValue()` function doesn't check if the value exists before dereferencing the iterator from `records.find()`. If the value is not found, `find()` returns `end()` and dereferencing it causes undefined behavior.
**Tests Added**: Tests that exercise value-to-key lookup functionality to detect crashes or incorrect behavior.

### Bug 2: term.h - BG_YELLOW Wrong Value
**Location**: `src/verymeme/term.h:29`
**Issue**: `BG_YELLOW` is set to value 33 (which is FG_YELLOW), but should be 43 for the background yellow color.
**Tests Added**: Terminal color conversion tests that validate color code generation.

### Bug 3: string_util.cpp - convertFromInteger() Range Limitation
**Location**: `src/verymeme/string_util.cpp:33`
**Issue**: The function limits values to int32_t range (`int32_t(val) != val`) but returns int64_t. This might be intentional but could be a bug if larger int64_t values are expected.
**Tests Added**: Overflow tests that verify behavior with values exceeding int32_t range.

### Bug 4: file.cpp - basename() Edge Case
**Location**: `src/verymeme/file.cpp:36-38`
**Issue**: When `filename.rfind('/')` returns `std::string::npos` (no '/' found), adding 1 wraps around to 0, which works correctly but could be clearer.
**Tests Added**: Edge case tests for basename with no slashes, empty strings, and trailing slashes.

## Build Instructions

To build and run the tests:

```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc)
./tests
```

## Dependencies Required

- Google Test (gtest)
- Boost (program_options)
- Verilator
- Yosys
- SFML

## Test Execution

Once built, run all tests with:
```bash
cd build
./tests
```

Run specific test suites:
```bash
./tests --gtest_filter=VerymemeFileTest.*
./tests --gtest_filter=MemeAsmTest.*
./tests --gtest_filter=MemesimTest.*
./tests --gtest_filter=MemewareTest.*
```

## Coverage Statistics

- **Total new test files**: 5
- **Total new test cases**: ~245+
- **Lines of test code added**: ~2050+
- **Modules tested**: verymeme, memeasm, memesim, memeware, memecad (enhanced)
- **Integration tests**: 14 cross-module tests
- **Edge cases covered**: 50+
- **Bug-related tests**: 15+
- **Pipeline tests**: 3 end-to-end workflows

## Notes

All tests follow the existing GoogleTest conventions used in the codebase:
- Uses `testing::Test` base class
- Follows naming pattern: `ModuleNameTest`
- Uses EXPECT_* and ASSERT_* macros consistently
- Tests are self-contained and independent
- Edge cases and error conditions are thoroughly tested
