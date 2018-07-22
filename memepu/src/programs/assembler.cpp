#include "asm.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  std::string data = readFile(argv[1]);
  Asm assembler(data);
  writeFile("rom.bin", assembler.assembleToBinaryData());
}
