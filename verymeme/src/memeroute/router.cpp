#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <random>

#include "memeroute/router_worker.h"
#include "memeroute/router.h"

namespace memeroute {

namespace {

struct WorkMessage {
  enum class Type { ROUTE, FINISH } type;
  int work_id;
  RouterWorker::InvocationParams params;
};

struct ResultMessage {
  int work_id;
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
    printf("Worker %d received message with work id %d\n", id, msg.work_id);

    if (msg.type == WorkMessage::Type::FINISH) break;

    result_queue->push({msg.work_id, worker->route(msg.params)});
  }
  printf("Worker %d finished\n", id);
}


class PermutationGA {
public:
  struct Gene {
    std::vector<int> nums;
    float fitness = -1;

    bool operator<(const Gene& g) const {
      if (fitness != g.fitness) return fitness > g.fitness;  // Highest fitness first.
      return nums < g.nums;
    }
  };

  struct Population {
    std::vector<Gene> genes;
    float total_fitness = -1;
  };

  explicit PermutationGA(int pop_size) : r_(std::random_device()()), pop_size_(pop_size) {}

  Population computeNextGeneration(Population& pop) {
    pop.total_fitness = 0;
    float size_fitness = 0;
    std::sort(pop.genes.begin(), pop.genes.end());
    for (int i = 0; i < int(pop.genes.size()); ++i) {
      verify_expr(pop.genes[i].fitness >= 0.0f, "BUG: %f", pop.genes[i].fitness);
      pop.total_fitness += pop.genes[i].fitness;
      if (i < pop_size_) size_fitness += pop.genes[i].fitness;
    }
    printf("Generation, %f total fitness, %f max fitness.\n", pop.total_fitness,
        pop.genes[0].fitness);

    std::uniform_real_distribution<float> uniform_dist(0.f, size_fitness);
    Population return_pop = {};
    const int new_pop_size = pop_size_ * POP_SIZE_FACTOR;
    return_pop.genes.reserve(new_pop_size);
    for (int i = 0; i < new_pop_size; ++i) {
      const float selection = uniform_dist(r_);
      float round_robin_sum = 0;
      int sel = 0;
      for (; sel < int(pop.genes.size()) && round_robin_sum <= selection; ++sel)
        round_robin_sum += pop.genes[sel].fitness;
      verify_expr(sel != 0, "BUG");
      return_pop.genes.push_back(mutate(pop.genes[sel - 1]));
    }
    return return_pop;
  }

  static Population getRandomPopulation(int num_perm, int size) {
    Population pop = {};
    pop.genes.reserve(num_perm);
    for (int i = 0; i < num_perm; ++i)
      pop.genes.push_back(getRandomGene(size));
    return pop;
  }

private:
  static constexpr int POP_SIZE_FACTOR = 2;
  std::default_random_engine r_;
  int pop_size_;

  static Gene getRandomGene(int size) {
    Gene g = {};
    g.nums.reserve(size);
    for (int i = 0; i < size; ++i) g.nums.push_back(i);
    std::random_shuffle(g.nums.begin(), g.nums.end());
    return g;
  }

  Gene mutate(const Gene& g) {
    Gene g_copy = g;
    g_copy.fitness = -1;
    std::uniform_int_distribution<int> uniform_dist(0, g.nums.size() - 1);
    std::swap(g_copy.nums[uniform_dist(r_)], g_copy.nums[uniform_dist(r_)]);
    return g_copy;
  }
};

RouterWorker::InvocationParams invocationParamsFromGene(const std::vector<std::string>& net_names,
    const PermutationGA::Gene& gene) {
  RouterWorker::InvocationParams params = {};
  params.net_names.reserve(net_names.size());
  verify_expr(net_names.size() == gene.nums.size(), "BUG");
  for (int idx : gene.nums) {
    verify_expr(idx >= 0 && idx < int(net_names.size()), "BUG");
    params.net_names.push_back(net_names[idx]);
  }
  return params;
}

}

Router::Router(const Pcb& pcb) : pcb_(pcb) {}

RouterWorker::RoutingResult Router::route() {
  ConcurrentQueue<WorkMessage> work_queue;
  ConcurrentQueue<ResultMessage> result_queue;

  const int num_threads = std::max(1u, std::thread::hardware_concurrency());
  std::vector<std::thread> threads;
  for (int i = 0; i < num_threads; ++i)
    threads.emplace_back(runWorkerLoop, i, pcb_, &work_queue, &result_queue);

  std::vector<std::string> net_names;
  for (const auto& kv : pcb_.nets)
    net_names.push_back(kv.first);


  const int NUM_GENERATIONS = 2;
  const int POP_SIZE = 8;
  PermutationGA ga(POP_SIZE);
  PermutationGA::Population pop = PermutationGA::getRandomPopulation(POP_SIZE, net_names.size());
  RouterWorker::InvocationParams best_params = {};
  RouterWorker::RoutingResult best_result = {};
  best_result.failed = INT_MAX;  // TODO
  for (int gen_num = 0; gen_num < NUM_GENERATIONS; ++gen_num) {
    printf("Running generation %d...\n", gen_num + 1);
    RouterWorker::RoutingResult best;
    for (int i = 0; i < int(pop.genes.size()); ++i)
      work_queue.push({
          WorkMessage::Type::ROUTE, i /* work_id */,
          invocationParamsFromGene(net_names, pop.genes[i])});

    for (int i = 0; i < int(pop.genes.size()); ++i) {
      const ResultMessage& result = result_queue.yield();
      printf("Got result with work id %d with %d failed\n", result.work_id, result.result.failed);
      pop.genes[result.work_id].fitness = 100.f / (result.result.failed + 1.f);

      if (result.result.failed < best_result.failed) {
        best_params = invocationParamsFromGene(net_names, pop.genes[result.work_id]);
        best_result = result.result;
      }
    }

    // TODO: For now break if we succeed. Later want to optimise cost.
    if (best_result.failed == 0) break;

    pop = ga.computeNextGeneration(pop);
  }


  for (int i = 0; i < num_threads; ++i)
    work_queue.push({WorkMessage::Type::FINISH, -1, {}});
  for (auto& thread : threads) thread.join();

  printf("Got best result, %d failed\n", best_result.failed);
  for (const auto& net_name : best_params.net_names)
    printf("%s\n", net_name.c_str());
  return best_result;
}


}  // memeroute