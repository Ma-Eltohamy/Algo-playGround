#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<std::vector<std::pair<int, int>>> GRAPH;

void addDirect(GRAPH &graph, int from, int to, int cost) {
  graph[from].push_back(std::make_pair(to, cost));
}

void printAdjacencyMatrix(GRAPH &graph) {
  int graphSize{(int)graph.size()};

  for (int i = 0; i < graphSize; ++i) {
    for (auto &pair : graph[i])
      std::cout << "From " << i << " to " << pair.first << " the cost is "
                << pair.second << '\n';
  }
}

int main(int argc, char *argv[]) {
  int nodes, edges;
  std::cin >> nodes >> edges;
  GRAPH graph(nodes);

  for (int i = 0; i < edges; ++i) {
    int from, to, weight;
    std::cin >> from >> to >> weight;

    addDirect(graph, from, to, weight);
  }

  printAdjacencyMatrix(graph);
  return 0;
}
