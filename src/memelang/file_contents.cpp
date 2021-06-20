// Copyright 2019 E.
#include "memelang/file_contents.h"

#include <utility>

namespace memelang {

FileContents::FileContents(std::string filename, std::string data)
    : filename_(std::move(filename)), data_(std::move(data)) {
  newlines_.push_back(0);
  for (int i = 0; i < static_cast<int>(data_.size()); ++i) {
    if (data_[i] == '\n') { newlines_.push_back(i); }
  }
}

int FileContents::lnum(int loc) const {
  return static_cast<int>(
      std::upper_bound(newlines_.begin(), newlines_.end(), loc) - newlines_.begin());
}

int FileContents::cnum(int loc) const { return loc - newlines_[lnum(loc) - 1]; }

std::string FileContents::span(int loc, int size) const {
  return data_.substr(uint64_t(loc), uint64_t(size));
}

std::string FileContents::fpos(int loc) const {
  return filename_ + ":" + std::to_string(lnum(loc)) + ":" + std::to_string(cnum(loc));
}

}  // namespace memelang
