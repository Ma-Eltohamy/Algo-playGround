#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void addUndirect(std::unordered_map<int, std::vector<int>> &adjacentList,
                 int from, int to) {
  adjacentList[from].push_back(to);
  adjacentList[to].push_back(from);
}

void dfs(std::unordered_map<int, std::vector<int>> &adjacentList,
         std::vector<int> &res, int node, std::unordered_set<int> &visited) {
  visited.insert(node);

  for (int neighbor : adjacentList[node])
    if (!visited.count(neighbor)) {
      res.push_back(neighbor);
      dfs(adjacentList, res, neighbor, visited);
    }
}

std::vector<int> restoreArray(std::vector<std::vector<int>> &adjacentPairs) {
  std::unordered_map<int, std::vector<int>> adjacentList{};

  for (auto &pair : adjacentPairs)
    addUndirect(adjacentList, pair[0], pair[1]);

  std::unordered_set<int> visited;
  std::vector<int> res{};

  for (auto &key : adjacentList)
    if ((int)key.second.size() == 1) {
      res.push_back(key.first);
      dfs(adjacentList, res, key.first, visited);
      break;
    }

  return res;
}

void print(std::vector<int> const &vec) {
  for (int i = 0; i < (int)vec.size(); ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> nums{{2, 1}, {3, 4}, {3, 2}};

  print(restoreArray(nums));
  return 0;
}
