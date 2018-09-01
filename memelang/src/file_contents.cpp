#include "file_contents.h"

#include <algorithm>
#include <file_contents.h>


FileContents::FileContents(std::string filename, std::string data) : filename_(std::move(filename)), data_(std::move(data)) {
  for (int i = 0; i < data.size(); ++i) {
    if (data[i] == '\n')
      newlines_.push_back(i);
  }
}

int FileContents::getLineNumber(int loc) const {
  return int(std::lower_bound(newlines_.begin(), newlines_.end(), loc) - newlines_.begin());
}

int FileContents::getColNumber(int loc) const {
  return loc - getLineNumber(loc);
}

std::string FileContents::getSpan(int loc, int size) const {
  return data_.substr(loc, size);
}
