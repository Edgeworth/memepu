#include "common.h"

void writeFile(const std::string& filename, const std::string& data) {
  FILE *f = fopen(filename.c_str(), "wb");
  verify_expr(fwrite(data.c_str(), data.size(), 1, f) == 1, "failed to write data");
  fclose(f);
}
