#include "verymeme/tokenizer.h"

namespace {

std::vector<std::string> tokenize(const std::string& data, const std::regex& token) {
  std::vector<std::string> toks;
  for (auto i = std::sregex_iterator(data.begin(), data.end(), token); i != std::sregex_iterator();
       ++i) {
    const std::smatch& sm = *i;
    toks.push_back(sm[0].str());
  }
  return toks;
}

}  // namespace

Tokenizer::Tokenizer(const std::string& data, const std::regex& token)
    : toks_(tokenize(data, token)) {}

std::string Tokenizer::getLines(int num_lines) {
  const int start_idx = idx_;
  while (num_lines > 0)
    if (next() == "\n") num_lines--;
  return getSubstr(start_idx, idx_);
}

std::string Tokenizer::getSubstr(int st, int en) {
  std::string substr;
  for (int i = st; i < en; ++i) {
    // Only separate by a space if there's at least one character accumulated, and it's:
    // 1. not already terminated with a newline (prevent space on next line)
    // 2. not about to be terminated with a newline (prevent space before newline)
    // 3. same two rules as above for tab.
    if (!substr.empty() && substr.back() != '\n' && toks_[i] != "\n" && substr.back() != '\t' &&
        toks_[i] != "\t")
      substr += ' ';
    substr += toks_[i];
  }
  return substr;
}
void Tokenizer::expect(const std::vector<std::string>& toks) {
  for (const std::string& tok : toks) {
    const std::string next_tok = next();
    verify_expr(tok == next_tok, "expected '%s', got '%s'", tok.c_str(), next_tok.c_str());
  }
}
