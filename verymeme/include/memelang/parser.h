#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include <memory>
#include <unordered_set>
#include <vector>

#include "memelang/file_contents.h"
#include "memelang/tokeniser.h"

namespace memelang {

struct File;

class Parser {
public:
  class Context {
  public:
    const FileContents* cts;
    std::vector<std::string> type_idents;

    Context(const FileContents* cts, std::vector<Tok> tokens);

    const Tok* curToken() const { return curToken(std::vector<Tok::Type>{}); }
    const Tok* curToken(const std::vector<Tok::Type>& ts) const;

    const Tok* consumeToken() { return consumeToken(std::vector<Tok::Type>{}); }
    const Tok* consumeToken(Tok::Type type) { return consumeToken(std::vector<Tok::Type>{type}); }
    const Tok* consumeToken(const std::vector<Tok::Type>& ts);
    bool maybeConsumeToken(Tok::Type type);

    bool hasToken() const { return hasToken(std::vector<Tok::Type>{}); }
    bool hasToken(Tok::Type type, int peek = 0) const {
      return hasToken(std::vector<Tok::Type>{type}, peek);
    }
    bool hasToken(const std::vector<Tok::Type>& ts, int peek = 0) const;

    void compileError(const std::string& msg) const;

  private:
    std::vector<Tok> toks_;
    int idx_ = 0;
  };

  Parser(const FileContents* contents, const std::vector<Tok>& tokens);
  ~Parser();

  bool parse();
  std::string astToString();

private:
  void collectTypeIdents();

  std::unique_ptr<Context> ctx_;
  std::unique_ptr<File> root_;
};

}  // namespace memelang

#endif  // MEMELANG_PARSER_H
