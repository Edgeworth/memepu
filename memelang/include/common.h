#ifndef MEMEPU_COMMON_H_
#define MEMEPU_COMMON_H_

#include <cstdio>
#include <cstdint>
#include <string>

std::string readFile(const std::string& filename);
void writeFile(const std::string& filename, const std::string& data);

#define format_str(str, fmt, ...) \
  do { \
    char buf[256]; \
    snprintf(buf, sizeof(buf), fmt, __VA_ARGS__); \
    str = buf; \
  } while (0)

#define verify_expr(expr, ...)                        \
  do {                                                \
    if (!(expr)) {                                    \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                   \
      fprintf(stderr, "\n");                          \
      exit(1);                                        \
    }                                                 \
  } while (0)


#endif  // MEMEPU_COMMON_H_
