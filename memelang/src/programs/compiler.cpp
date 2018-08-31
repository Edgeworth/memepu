#include "common.h"
#include "tokeniser.h"

int main(int argc, char* argv[]) {
  verify_expr(argc == 2, "need filename");
  std::string data = readFile(argv[1]);
  Tokeniser tokeniser(data);
  auto tokens = tokeniser.tokenise();
  for (const auto& token : tokens) {
    printf("%s: '%s' %d:%d\n", token.type == Token::IDENT ? "IDENT" : "Token", token.data.c_str(), token.linenum, token.colnum);
  }
}