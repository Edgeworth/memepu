#include "memelang/file_contents.h"

#include <algorithm>

namespace memelang {

FileContents::FileContents(std::string filename, std::string data) : filename_(std::move(filename)),
                                                                     data_(std::move(data)) {
  newlines_.push_back(0);
  for (int i = 0; i < int(data_.size()); ++i) {
    if (data_[i] == '\n') {
      newlines_.push_back(i);
    }
  }
}

int FileContents::getLineNumber(int loc) const {
  return int(std::upper_bound(newlines_.begin(), newlines_.end(), loc) - newlines_.begin());
}

int FileContents::getColNumber(int loc) const {
  return loc - newlines_[getLineNumber(loc) - 1];
}

std::string FileContents::getSpan(int loc, int size) const {
  return data_.substr(loc, size);
}

}  // namespace memelang
