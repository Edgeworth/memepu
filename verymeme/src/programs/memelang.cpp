#include "verymeme/common.h"
#include "verymeme/file.h"

#include "memelang/parser.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  memelang::FileContents contents(argv[1], readFile(argv[1]));
  memelang::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  for (const auto& token : tokens) {
    printf("%s\n", token.toString(&contents).c_str());
  }
  memelang::Parser parser(&contents, tokens);
  parser.parse();
  printf("AST:\n%s\n", parser.astToString(parser.root()).c_str());
}
