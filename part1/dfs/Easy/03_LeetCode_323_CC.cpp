#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addUndirect(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

void buildGraph(GRAPH &graph, std::vector<std::vector<int>> &edges) {
  int edgesNum{(int)edges.size()};

  for (int i = 0; i < edgesNum; ++i)
    addUndirect(graph, edges[i][0], edges[i][1]);
}

void dfs(GRAPH &graph, int node, std::vector<bool> &visited) {
  visited[node] = true;

  for (auto neighbor : graph[node])
    if (!visited[neighbor])
      dfs(graph, neighbor, visited);
}

int countComponents(int n, std::vector<std::vector<int>> &edges) {
  int counter{};
  GRAPH graph;
  buildGraph(graph, edges);

  int graphSize{(int)graph.size()};
  std::vector<bool> visited(graphSize, false);
  for (int i = 0; i < graphSize; ++i)
    if (!visited[i])
      ++counter, dfs(graph, i, visited);

  return counter;
}

void print(std::vector<int> const &vec) {
  for (int i = 0; i < (int)vec.size(); ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) { return 0; }
