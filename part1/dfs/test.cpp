#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

void dfs(GRAPH &graph, int node, std::vector<bool> &visited) {
  visited[node] = true;

  for (auto neighbor : graph[node])
    if (!visited[neighbor]) {
      std::cout << ' ' << neighbor;
      dfs(graph, neighbor, visited);
    }
}

void reachability(GRAPH &graph) {
  int graphSize{(int)graph.size()};
  for (int i = 0; i < graphSize; ++i) {
    std::cout << "Node " << i << " can reach to:";
    std::vector<bool> visited(graphSize);
    dfs(graph, i, visited);
    std::cout << '\n';
  }
}

void printAdjacencyList(GRAPH &graph) {
  for (int i = 0; i < (int)graph.size(); ++i) {
    std::cout << "Node " << i << " has neighbors:";
    for (int j = 0; j < (int)graph[i].size(); ++j)
      std::cout << ' ' << graph[i][j];
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  int nodes{}, edges{};
  std::cin >> nodes >> edges;

  GRAPH graph(nodes);

  int from{}, to{};
  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;

    addDirect(graph, from, to);
  }
  printAdjacencyList(graph);
  reachability(graph);
  return 0;
}
