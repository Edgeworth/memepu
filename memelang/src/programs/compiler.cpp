#include <llvm.h>
#include "parser.h"
#include "compile.h"
#include "file_contents.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  meme::FileContents contents(argv[1], readFile(argv[1]));
  meme::Tokeniser tokeniser(&contents);
  auto tokens = tokeniser.tokenise();
  for (const auto& token : tokens) {
    printf("%s\n", token.toString(&contents).c_str());
  }
  meme::Parser parser(&contents, tokens);
  parser.parse();
  printf("AST:\n%s\n", parser.astToString(parser.root()).c_str());
  meme::Compile compile(&contents, parser.root());
  printf("Compile: %s\n", compile.generateCode().c_str());

  meme::LlvmCodegen codegen(&contents, compile);
  codegen.codegen();
}