// Copyright 2019 E.
#ifndef MEMELANG_PARSER_H
#define MEMELANG_PARSER_H

#include <memory>
#include <unordered_set>
#include <vector>

#include "memelang/file_contents.h"
#include "memelang/tokeniser.h"

namespace memelang::ast {

struct Module;

class Parser {
public:
  class Ctx {
  public:
    const FileContents* cts;
    std::unordered_set<std::string> types;  // Regular types - may be qualified.

    explicit Ctx(const FileContents* cts);

    const Tok* peekTok(int peek = 0) const;
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

    void error(const std::string& msg) const;
    void reset() { idx_ = 0; }
    const std::vector<Tok>& tokens() const { return toks_; }

  private:
    std::vector<Tok> toks_;
    int idx_ = 0;
  };

  explicit Parser(const std::vector<std::unique_ptr<FileContents>>& cts);
  ~Parser();

  bool parse();
  Module* module() { return root_.get(); }
  const std::vector<std::unique_ptr<Ctx>>& ctxs() const { return c_; }
  std::string astToString();

private:
  void collectTypeIdents();

  std::vector<std::unique_ptr<Ctx>> c_;
  std::unique_ptr<Module> root_;
};

}  // namespace memelang::ast

#endif  // MEMELANG_PARSER_H
