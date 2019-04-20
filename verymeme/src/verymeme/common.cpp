#include "verymeme/common.h"

namespace {

char READ_BUF[1 << 16];

}  // namespace

std::string readFile(const std::string& filename, bool binary) {
  std::string data;
  FILE* f = fopen(filename.c_str(), binary ? "rb" : "r");
  verify_expr(f != nullptr, "can't open file '%s'", filename.c_str());
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
  verify_expr(f != nullptr, "can't open file '%s'", filename.c_str());
  size_t ret = fwrite(data.c_str(), data.size(), 1, f);
  verify_expr(ret == 1, "failed to write data - ferror=%d", ferror(f));
  fclose(f);
}

std::string basename(const std::string& filename) {
  return filename.substr(filename.rfind('/') + 1);
}

std::string stem(const std::string& filename) {
  const std::string base = basename(filename);
  if (base.empty() || base[0] == '.') return base;
  return base.substr(0, base.find('.'));
}

void checked_chdir(const std::string& path) {
  verify_expr(chdir(path.c_str()) == 0, "could not change directory");
}

std::ostream& operator<<(std::ostream& str, const Point& p) {
  return str << p.x << " " << p.y;
}

Point& Point::operator+=(const Point& p) {
  x += p.x;
  y += p.y;
  return *this;
}

Point Point::operator+(const Point& p) const {
  return {x + p.x, y + p.y};
}

Point Point::operator-(const Point& p) const {
  return {x - p.x, y - p.y};
}

bool Point::operator<(const Point& p) const {
  return std::tie(x, y) < std::tie(p.x, p.y);
}

Point Point::operator-() const {
  return {-x, -y};
}

bool Point::operator!=(const Point& p) const {
  return x != p.x || y != p.y;
}
int64_t Point::cross(const Point& p) const {
  return x * p.y - y * p.x;
}

Rect Rect::enclosing(const Point& a, const Point& b) {
  Rect r{};
  // Make one larger for right and bottom so |b| is inside.
  r.left = std::min(a.x, b.x);
  r.right = std::max(a.x, b.x) + 1;
  r.top = std::min(a.y, b.y);
  r.bottom = std::max(a.y, b.y) + 1;
  return r;
}
