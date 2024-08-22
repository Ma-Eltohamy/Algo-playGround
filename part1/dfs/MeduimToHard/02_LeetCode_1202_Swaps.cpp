#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addUndirect(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

void dfs(GRAPH &graph, std::vector<bool> &visited, std::vector<int> &indecies,
         int node) {
  visited[node] = true;
  indecies.push_back(node);

  for (auto neighbor : graph[node])
    if (!visited[neighbor])
      dfs(graph, visited, indecies, neighbor);
}

std::string smallestStringWithSwaps(std::string s,
                                    std::vector<std::vector<int>> &pairs) {
  int strSize{(int)s.size()};
  GRAPH graph(strSize);

  for (auto &pair : pairs)
    addUndirect(graph, pair[0], pair[1]);

  std::vector<bool> visited(strSize);

  for (int i = 0; i < strSize; ++i)
    if (!visited[i]) {
      std::vector<int> indecies;
      dfs(graph, visited, indecies, i);

      std::string curStr{};
      for (int j = 0; j < (int)indecies.size(); ++j)
        curStr += s[indecies[j]];

      std::sort(curStr.begin(), curStr.end());
      std::sort(indecies.begin(), indecies.end());

      for (int k = 0; k < (int)indecies.size(); ++k)
        s[indecies[k]] = curStr[k];
    }

  return s;
}

int main(int argc, char *argv[]) {
  std::string s{"cba"};
  std::vector<std::vector<int>> pairs{{1, 2}, {0, 2}};
  std::cout << smallestStringWithSwaps(s, pairs) << '\n';
  return 0;
}
