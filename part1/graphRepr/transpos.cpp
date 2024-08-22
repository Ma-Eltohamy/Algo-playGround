#include <iostream>
#include <set>
#include <vector>

// We can easyl transpose a graph by using another graph but this costs O(V^2)
// space. While we can just use an unordered set to store the changed cells to
// not touch it again.
//
//
// We had better use the unorderd set but there is no hash for pairs

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { ++graph[from][to]; }

void transpose(GRAPH &graph) {
  int graphSize{(int)graph.size()};

  std::set<std::pair<int, int>> fliped;

  for (int i = 0; i < graphSize; ++i) {
    for (int j = 0; j < graph[i].size(); ++j) {
      if (graph[i][j] != 0 && !fliped.count(std::make_pair(i, j)))
        graph[j][i] = graph[i][j], graph[i][j] = 0,
        fliped.insert(std::make_pair(j, i));
    }
  }
}

void printAdjacencyMatrix(GRAPH &graph) {
  for (int i = 0; i < (int)graph.size(); ++i) {
    for (int j = 0; j < (int)graph.size(); ++j)
      std::cout << graph[i][j] << ' ';
    std::cout << '\n';
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

  printAdjacencyMatrix(graph);
  std::cout << '\n';
  transpose(graph);
  std::cout << '\n';
  printAdjacencyMatrix(graph);
  return 0;
}
