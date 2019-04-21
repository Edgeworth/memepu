#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>

#include "memeroute/router_worker.h"
#include "memeroute/router.h"

namespace memeroute {

namespace {

struct WorkMessage {
  enum class Type { ROUTE, FINISH } type;
  RouterWorker::InvocationParams params;
};

struct ResultMessage {
  RouterWorker::RoutingResult result;
};

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

void runWorkerLoop(int id, Pcb pcb, ConcurrentQueue<WorkMessage>* work_queue,
    ConcurrentQueue<ResultMessage>* result_queue) {
  // Create on heap because stack size too big.
  printf("Worker %d starting up\n", id);
  auto worker = std::make_unique<RouterWorker>(pcb);
  while (true) {
    const WorkMessage& msg = work_queue->yield();
    printf("Worker %d received message\n", id);

    if (msg.type == WorkMessage::Type::FINISH) break;

    result_queue->push({worker->route(msg.params)});
  }
  printf("Worker %d finished\n", id);
}

}

Router::Router(const Pcb& pcb) : pcb_(pcb) {}

std::vector<Shape> Router::route() {
  ConcurrentQueue<WorkMessage> work_queue;
  ConcurrentQueue<ResultMessage> result_queue;

  const int num_threads = std::max(1u, std::thread::hardware_concurrency());
  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i)
    threads.emplace_back(runWorkerLoop, i, pcb_, &work_queue, &result_queue);

  RouterWorker::InvocationParams params = {};
  for (const auto& kv : pcb_.nets)
    params.net_names.push_back(kv.first);

  const int NUM_RUNS = 100;
  for (int i = 0; i < NUM_RUNS; ++i) {
    std::random_shuffle(params.net_names.begin(), params.net_names.end());
    work_queue.push({WorkMessage::Type::ROUTE, params});
  }

  RouterWorker::RoutingResult best;
  best.failed = INT_MAX;
  for (int i = 0; i < NUM_RUNS; ++i) {
    ResultMessage result = result_queue.yield();
    printf("Got result with %d failed\n", result.result.failed);
    if (result.result.failed < best.failed)
      best = std::move(result.result);
  }

  for (int i = 0; i < num_threads; ++i)
    work_queue.push({WorkMessage::Type::FINISH, {}});
  for (auto& thread : threads) thread.join();

  printf("Got best result, %d failed\n", best.failed);
  return best.traces;
}


}  // memeroute
