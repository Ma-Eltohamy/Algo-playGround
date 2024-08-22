#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

void printAdjacencyList(GRAPH &graph) {
  for (int i = 0; i < (int)graph.size(); ++i) {
    std::cout << "Node " << i << " has neighbors:";
    for (int j = 0; j < (int)graph[i].size(); ++j)
      std::cout << ' ' << graph[i][j];
    std::cout << '\n';
  }
}

void dfs(GRAPH &graph, int node, std::vector<bool> &visited) {
  visited[node] = true;

  for (auto neighbor : graph[node])
    if (!visited[neighbor]) {
      std::cout << ' ' << neighbor;
      dfs(graph, neighbor, visited);
    }
}

void reachability(GRAPH &graph) {
  int nodesNum{(int)graph.size()};
  for (int i = 0; i < nodesNum; ++i) {
    std::vector<bool> visited(nodesNum, false);
    std::cout << "We can reach these node from " << i << ":";
    dfs(graph, i, visited);
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  int nodes, edges;
  std::cin >> nodes >> edges;

  GRAPH graph(nodes, std::vector<int>());

  int from{}, to{};
  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;
    addDirect(graph, from, to);
  }

  reachability(graph);
  printAdjacencyList(graph);
  return 0;
}
