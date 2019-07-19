#ifndef MEMELANG_FILE_CONTENTS_H
#define MEMELANG_FILE_CONTENTS_H

#include <string>
#include <vector>

namespace memelang {

class FileContents {
public:
  FileContents(std::string filename, std::string data);

  const std::string& data() const { return data_; }

  int getLineNumber(int loc) const;
  int getColNumber(int loc) const;
  std::string getSpan(int loc, int size) const;

private:
  std::string filename_;
  std::string data_;
  std::vector<int> newlines_;
};

}  // namespace memelang

#endif  // MEMELANG_FILE_CONTENTS_H
