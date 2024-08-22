#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

void printPathsLen2(GRAPH &graph) {
  for (int i = 0; i < (int)graph.size(); ++i) {
    for (int j = 0; j < (int)graph[i].size(); ++j)
      for (int k = 0; k < (int)graph[graph[i][j]].size(); ++k)
        std::cout << i << ' ' << graph[i][j] << ' ' << graph[graph[i][j]][k]
                  << '\n';
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

  printPathsLen2(graph);

  return 0;
}
