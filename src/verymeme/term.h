// Copyright 2019 E.
#ifndef VERYMEME_TERM_H_
#define VERYMEME_TERM_H_

#include <string>

enum class TermColor {
  FG_DEFAULT = 39,
  FG_BLACK = 30,
  FG_RED = 31,
  FG_GREEN = 32,
  FG_YELLOW = 33,
  FG_BLUE = 34,
  FG_MAGENTA = 35,
  FG_CYAN = 36,
  FG_LIGHT_GRAY = 37,
  FG_DARK_GRAY = 90,
  FG_LIGHT_RED = 91,
  FG_LIGHT_GREEN = 92,
  FG_LIGHT_YELLOW = 93,
  FG_LIGHT_BLUE = 94,
  FG_LIGHT_MAGENTA = 95,
  FG_LIGHT_CYAN = 96,
  FG_WHITE = 97,
  BG_DEFAULT = 49,
  BG_BLACK = 40,
  BG_RED = 41,
  BG_GREEN = 42,
  BG_YELLOW = 33,
  BG_BLUE = 44,
  BG_MAGENTA = 45,
  BG_CYAN = 46,
  BG_LIGHT_GRAY = 47,
  BG_DARK_GRAY = 100,
  BG_LIGHT_RED = 101,
  BG_LIGHT_GREEN = 102,
  BG_LIGHT_YELLOW = 103,
  BG_LIGHT_BLUE = 104,
  BG_LIGHT_MAGENTA = 105,
  BG_LIGHT_CYAN = 106,
  BG_WHITE = 107
};

enum class TermStyle { RESET = 0, BOLD = 1, FAINT = 2, UNDERLINE = 4 };

std::string convertToColor(const std::string& s, TermColor foreground,
    TermColor background = TermColor::BG_DEFAULT, TermStyle style = TermStyle::RESET);

#endif  // VERYMEME_TERM_H_
