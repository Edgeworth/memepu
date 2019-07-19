#ifndef VERYMEME_CONCURRENT_QUEUE_H
#define VERYMEME_CONCURRENT_QUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <optional>
#include "verymeme/util.h"

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

#endif  // VERYMEME_CONCURRENT_QUEUE_H
