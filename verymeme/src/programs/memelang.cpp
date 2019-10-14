#include "memelang/exec.h"
#include "memelang/parser.h"
#include "verymeme/file.h"
#include "verymeme/macros.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  memelang::FileContents cts(argv[1], readFile(argv[1]));
  memelang::ast::Tokeniser tokeniser(&cts);
  auto tokens = tokeniser.tokenise();
  memelang::ast::Parser parser(&cts, tokens);
  parser.parse();
  printf("AST:\n%s\n", parser.astToString().c_str());
  memelang::exec::Exec interp(parser.getFile(), &cts);
  interp.run();
}
