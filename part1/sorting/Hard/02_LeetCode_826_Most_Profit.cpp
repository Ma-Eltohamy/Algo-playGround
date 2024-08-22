#include <algorithm>
#include <vector>
int maxProfitAssignment(std::vector<int> &difficulty, std::vector<int> &profit,
                        std::vector<int> &worker) {
  std::vector<std::pair<int, int>> jobs{};
  int jobsSize{(int)difficulty.size()};

  for (int i = 0; i < jobsSize; ++i)
    jobs.push_back(std::make_pair(profit[i], difficulty[i]));

  std::sort(jobs.begin(), jobs.end());
  std::sort(worker.begin(), worker.end());
  int jobsIdx{jobsSize - 1};
  int totalProfit{};
  for (int i = (int)worker.size() - 1; i >= 0; --i) {
    while (jobsIdx >= 0 && worker[i] < jobs[jobsIdx].second)
      --jobsIdx;

    if (jobsIdx >= 0 && worker[i] >= jobs[jobsIdx].second)
      totalProfit += jobs[jobsIdx].first;
  }

  return totalProfit;
}
