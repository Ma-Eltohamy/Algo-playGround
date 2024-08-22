#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef std::unordered_map<int, std::vector<int>> GRAPH;

void addDirected(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

void dfs(GRAPH &graph, std::unordered_set<int> &visited, int node,
         int &curCounter) {
  visited.insert(node);
  ++curCounter;

  for (auto neighbor : graph[node])
    if (!visited.count(neighbor))
      dfs(graph, visited, neighbor, curCounter);
}

int longestConsecutive(std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  if (numsSize == 0)
    return 0;

  std::unordered_set<int> numsSet(nums.begin(), nums.end());

  GRAPH graph;
  for (int i = 0; i < numsSize; ++i)
    if (numsSet.count(nums[i] - 1))
      addDirected(graph, nums[i], nums[i] - 1);

  std::unordered_set<int> visited;
  int curCounter = 0;
  int res = 1;

  for (int i = 0; i < numsSize; ++i)
    if (!visited.count(nums[i])) {
      curCounter = 0;
      dfs(graph, visited, nums[i], curCounter);

      if (curCounter > res)
        res = curCounter;
    }

  return res;
}

int main(int argc, char *argv[]) {
  // std::vector<int> nums{100, 4, 200, 1, 3, 2};
  std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  std::cout << longestConsecutive(nums);
  return 0;
}
