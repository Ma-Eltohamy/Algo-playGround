#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { ++graph[from][to]; }

void addUndirect(GRAPH &graph, int from, int to) {
  ++graph[from][to];
  ++graph[to][from];
}

void printAdjecencyMatrix(GRAPH &graph) {
  int graphSize{(int)graph.size()};
  int rowSize{};

  std::cout << "Output:\n";
  for (int i = 0; i < graphSize; ++i) {
    rowSize = (int)graph[i].size();

    for (int j = 0; j < rowSize; ++j)
      if (graph[i][j])
        std::cout << "From " << i << " to " << j << " there are " << graph[i][j]
                  << " edges.\n";
  }
}

int main(int argc, char *argv[]) {
  int nodes{}, edges{};
  std::cin >> nodes >> edges;

  GRAPH graph(nodes, std::vector<int>(nodes, 0));

  for (int i = 0; i < edges; ++i) {
    int from{}, to{};
    std::cin >> from >> to;

    addDirect(graph, from, to);
  }

  printAdjecencyMatrix(graph);
  return 0;
}
