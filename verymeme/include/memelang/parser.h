#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include <memory>
#include <unordered_set>
#include <vector>

#include "memelang/file_contents.h"
#include "memelang/tokeniser.h"

namespace memelang {

const inline std::vector<Tok::Type> BUILTIN_TYPES = {
    Tok::AUTO, Tok::I8, Tok::I16, Tok::I32, Tok::U8, Tok::U16, Tok::U32, Tok::BOOL, Tok::BIT};

struct File;

class Parser {
public:
  class Ctx {
  public:
    const FileContents* cts;
    std::unordered_set<std::string> type_idents;

    Ctx(const FileContents* cts, const std::vector<Tok>& tokens);

    const Tok* curTok() const { return curTok(std::vector<Tok::Type>{}); }
    const Tok* curTok(const std::vector<Tok::Type>& ts) const;

    const Tok* consumeTok() { return consumeTok(std::vector<Tok::Type>{}); }
    const Tok* consumeTok(Tok::Type type) { return consumeTok(std::vector<Tok::Type>{type}); }
    const Tok* consumeTok(const std::vector<Tok::Type>& ts);
    bool maybeConsumeTok(Tok::Type type);

    bool hasTok() const { return hasTok(std::vector<Tok::Type>{}); }
    bool hasTok(Tok::Type type, int peek = 0) const {
      return hasTok(std::vector<Tok::Type>{type}, peek);
    }
    bool hasTok(const std::vector<Tok::Type>& ts, int peek = 0) const;

    void compileError(const std::string& msg) const;
    void reset() { idx_ = 0; }

  private:
    std::vector<Tok> toks_;
    int idx_ = 0;
  };

  Parser(const FileContents* cts, const std::vector<Tok>& toks);
  ~Parser();

  bool parse();
  File* getFile() { return root_.get(); }
  std::string astToString();

private:
  void collectTypeIdents();

  std::unique_ptr<Ctx> c_;
  std::unique_ptr<File> root_;
};

}  // namespace memelang

#endif  // MEMELANG_PARSER_H
