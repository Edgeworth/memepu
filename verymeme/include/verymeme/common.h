#ifndef VERYMEME_COMMON_H
#define VERYMEME_COMMON_H

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <boost/stacktrace/stacktrace.hpp>
#include <boost/lexical_cast.hpp>
#include <iomanip>
#include <bitset>
#include <condition_variable>
#include <mutex>
#include <queue>

#define verify_expr(expr, ...)                        \
  do {                                                \
    if (!(expr)) {                                    \
      fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
      fprintf(stderr, __VA_ARGS__);                   \
      fprintf(stderr, "\n");                          \
      std::stringstream _s; \
      _s << boost::stacktrace::stacktrace(); \
      fprintf(stderr, "Stack:\n%s\n", _s.str().c_str()); \
      exit(1);                                        \
    }                                                 \
  } while (0)

constexpr float EP = 1e-6;

template<typename T>
class ConcurrentQueue {
public:
  T yield() {
    std::unique_lock<std::mutex> lock(q_lock_);
    while (q_.empty()) has_items_cv_.wait(lock);
    verify_expr(!q_.empty(), "BUG");
    T val = std::move(q_.front());
    q_.pop();
    return val;
  }

  std::optional<T> tryYield() {
    std::unique_lock<std::mutex> lock(q_lock_);
    if (q_.empty()) return std::nullopt;
    T val = std::move(q_.front());
    q_.pop();
    return val;
  }

  void push(const T& t) {
    std::scoped_lock<std::mutex> lock(q_lock_);  // Lock the queue.
    q_.push(t);
    has_items_cv_.notify_all();
  }

private:
  std::condition_variable has_items_cv_;
  std::mutex q_lock_;
  std::queue<T> q_;
};

template<typename M, typename K, typename V>
V getDefault(const M& map, const K& key, const V& def) {
  auto iter = map.find(key);
  if (iter == map.end()) return def;
  return iter->second;
}

template<typename T>
std::vector<T> reverse(std::vector<T>&& vec) {
  std::vector<T> reversed;
  reversed.reserve(vec.size());
  for (int i = int(vec.size()) - 1; i >= 0; --i)
    reversed.emplace_back(std::move(vec[i]));
  return reversed;
}

template<typename T>
std::string tos(const T& val) { return boost::lexical_cast<std::string>(val); }

template<typename T>
std::ostream&
outputEnum(std::ostream& str, const T& enumeration, const std::string (& mapping)[int(T::COUNT)]) {
  return str << mapping[int(enumeration)];
}

template<typename T>
std::istream&
inputEnum(std::istream& str, T& enumeration, const std::string (& mapping)[int(T::COUNT)]) {
  std::string v;
  str >> v;
  for (int i = 0; i < int(T::COUNT); ++i) {
    if (mapping[i] == v) {
      enumeration = T(i);
      return str;
    }
  }
  verify_expr(false, "unknown enum with string value '%s'", v.c_str());
}

std::string trim(const std::string& data, const std::string& c);

template<typename T>
std::string hexdump(const std::vector<T>& input, int width = 40) {
  static_assert(sizeof(T) <= sizeof(uint64_t), "input type too large");
  std::stringstream stream;
  int count = 0;
  for (auto c : input) {
    stream << std::hex << std::setw(2 * sizeof(T)) << std::setfill('0') << uint64_t(c);
    if (++count == width) {
      stream << "\n";
      count = 0;
    } else {
      stream << " ";
    }
  }
  if (count) stream << "\n";
  return stream.str();
}

template<typename T, std::size_t N>
std::string hexdump(const T (& input)[N], int width = 40) {
  return hexdump(std::vector<T>(input, input + N), width);
}

template<std::size_t N>
std::string convertToString(const uint32_t (& data)[N]) {
  std::string str;
  str.reserve(N * sizeof(uint32_t));
  for (uint32_t c : data) {
    str += char(c & 0xFF);
    str += char((c >> 8) & 0xFF);
    str += char((c >> 16) & 0xFF);
    str += char((c >> 24) & 0xFF);
  }
  std::string trimmed(str.c_str());  // Cut off at first 0 byte.
  return std::string(trimmed.rbegin(), trimmed.rend()); // Reverse
}

template<typename T>
std::string convertToHex(T val) {
  std::stringstream stream;
  stream << std::hex << val;
  return stream.str();
}

int convertFromHex(const std::string& s);

int convertFromDec(const std::string& s);

template<std::size_t N>
std::string convertToBinary(int val) {
  static_assert(N <= 32, "number of bits too large");
  std::bitset<N> bs(val);
  return bs.to_string();
}

#endif  // VERYMEME_COMMON_H
