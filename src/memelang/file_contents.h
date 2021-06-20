// Copyright 2019 E.
#ifndef MEMELANG_FILE_CONTENTS_H
#define MEMELANG_FILE_CONTENTS_H

#include <string>
#include <vector>

namespace memelang {

class FileContents {
 public:
  FileContents(std::string filename, std::string data);

  const std::string& data() const { return data_; }
  const std::string& filename() const { return filename_; }

  int lnum(int loc) const;
  int cnum(int loc) const;
  std::string fpos(int loc) const;
  std::string span(int loc, int size) const;

 private:
  std::string filename_;
  std::string data_;
  std::vector<int> newlines_;
};

}  // namespace memelang

#endif  // MEMELANG_FILE_CONTENTS_H
