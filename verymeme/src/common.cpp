
#include <common.h>

namespace {

char READ_BUF[1 << 16];

}  // namespace

std::string readFile(const std::string& filename, bool binary) {
  std::string data;
  FILE* f = fopen(filename.c_str(), binary ? "rb" : "r");
  size_t ret = 0;
  do {
    ret = fread(READ_BUF, 1, sizeof(READ_BUF), f);
    data.append(READ_BUF, ret);
  } while (ret == sizeof(READ_BUF));
  verify_expr(feof(f), "failed to read data - ferror=%d", ferror(f));
  fclose(f);
  return data;
}

void writeFile(const std::string& filename, const std::string& data, bool binary) {
  FILE* f = fopen(filename.c_str(), binary ? "wb" : "w");
  size_t ret = fwrite(data.c_str(), data.size(), 1, f);
  verify_expr(ret == 1, "failed to write data - ferror=%d", ferror(f));
  fclose(f);
}
std::vector<std::string> split(const std::string& data, char delim) {
  std::vector<std::string> splits;
  std::string tmp;
  for (char c : data) {
    if (c == delim && !tmp.empty()) {
      splits.emplace_back(std::move(tmp));
      tmp.clear();
    }
    if (c != delim) tmp += c;
  }
  return splits;
}
