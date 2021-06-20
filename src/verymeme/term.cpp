// Copyright 2019 E.
#include "verymeme/term.h"

std::string convertToColor(
    const std::string& s, TermColor foreground, TermColor background, TermStyle style) {
  return "\033[" + std::to_string(int(style)) + ";" + std::to_string(int(foreground)) + ";" +
      std::to_string(int(background)) + "m" + s + "\033[0m";
}
