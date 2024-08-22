#include <iostream>
#include <unordered_set>
#include <vector>

typedef std::vector<std::unordered_set<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].insert(to); }

void addUndirect(GRAPH &graph, int from, int to) {
  graph[from].insert(to);
  graph[to].insert(from);
}

void printAdjacencyMatrix(GRAPH &graph) {
  int graphSize{(int)graph.size()};

  for (int i = 0; i < graphSize; ++i) {
    std::cout << "Node " << i << " has neighbours: ";
    for (auto const &neighbour : graph[i])
      std::cout << neighbour << ' ';
    std::cout << '\n';
  }
}

void getInDegreeNeighbours(GRAPH &graph, int to,
                           std::vector<int> &InDegreeNeighboursI) {
  int graphSize{(int)graph.size()};

  for (int i = 0; i < graphSize; ++i)
    if (graph[i].count(to))
      InDegreeNeighboursI.push_back(i);
}

void printVec(const std::vector<int> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  int nodes, edges;
  std::cin >> nodes >> edges;

  GRAPH graph(nodes + 1);

  for (int e = 0; e < edges; ++e) {
    int from, to;
    std::cin >> from >> to;
    addDirect(graph, from, to);
  }

  std::vector<int> vec{};
  getInDegreeNeighbours(graph, 3, vec);
  printVec(vec);
  printAdjacencyMatrix(graph);

  return 0;
}
