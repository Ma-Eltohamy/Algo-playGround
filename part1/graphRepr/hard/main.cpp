#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { ++graph[from][to]; }

bool isAllIncomming(GRAPH &graph, int idx) {
  int graphSize{(int)graph.size()};

  for (int i = 0; i < graphSize; ++i) {
    if (i != idx && graph[i][idx] == 0)
      return false;
  }
  return true;
}

int getUniversalSink(GRAPH &graph) {
  int graphSize{(int)graph.size()};

  for (int i = 0; i < graphSize; ++i) {
    bool isCurUni{true};
    for (int j = 0; j < graphSize; ++j)
      if (graph[i][j] != 0) {
        isCurUni = false;
        break;
      }
    if (isCurUni && isAllIncomming(graph, i))
      return i;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int testCases;
  std::cin >> testCases;

  for (int i = 0; i < testCases; ++i) {
    int nodes{}, edges{};
    std::cin >> nodes >> edges;
    GRAPH graph(nodes, std::vector<int>(nodes, 0));
    for (int j = 0; j < edges; ++j) {
      int from{}, to{};
      std::cin >> from >> to;
      addDirect(graph, from, to);
    }
    std::cout << getUniversalSink(graph) << '\n';
  }
  return 0;
}
