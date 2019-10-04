#include "memelang/interpreter.h"
#include "memelang/parser.h"
#include "verymeme/file.h"
#include "verymeme/util.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  memelang::FileContents cts(argv[1], readFile(argv[1]));
  memelang::ast::Tokeniser tokeniser(&cts);
  auto tokens = tokeniser.tokenise();
  memelang::ast::Parser parser(&cts, tokens);
  parser.parse();
  printf("AST:\n%s\n", parser.astToString().c_str());
  memelang::interpreter::Interpreter interp(parser.getFile(), &cts);
  interp.run();
}
