#include "parser.h"
#include "compile.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  FileContents contents(argv[1], readFile(argv[1]));
  Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  for (const auto& token : tokens) {
    printf("%s\n", token.toString(&contents).c_str());
  }
  Parser parser(&contents, tokens);
  parser.parse();
  printf("AST:\n%s\n", parser.astToString(parser.root()).c_str());
  Compile gen(&contents, parser.root());
  printf("Compile: %s\n", gen.generateCode().c_str());
}