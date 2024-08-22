#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void dfs(GRAPH &graph, int &curPairIdx, std::vector<bool> &visited) {
  visited[graph[curPairIdx][0]] = true;
  visited[graph[curPairIdx][1]] = true;

  if ((int)graph.size() > curPairIdx)
    dfs(graph, ++curPairIdx, visited);
}

int countComponents(int n, std::vector<std::vector<int>> &edges) {
  int counter{};
  std::vector<bool> visited(n, false);

  int curPairIdx{};
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      dfs(edges, curPairIdx, visited), ++counter;

  return counter;
}

void print(std::vector<int> const &vec) {
  for (int i = 0; i < (int)vec.size(); ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) { return 0; }
