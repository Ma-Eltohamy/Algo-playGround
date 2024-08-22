#include <iostream>
#include <vector>

typedef std::vector<int> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from] = to; }

void printChain(GRAPH &graph, int from, bool isFirst = true) {
  if (graph[from] == -1) {
    std::cout << '\n';
    return;
  }
  if (isFirst) {
    std::cout << from;
    isFirst = false;
  }

  std::cout << ' ' << graph[from];
  printChain(graph, graph[from], false);
}

int main(int argc, char *argv[]) {
  int nodes, edges;
  std::cin >> nodes >> edges;

  GRAPH graph(nodes, -1); // no multiple paths because this is just a chain so
                          // no way to have multiple paths

  int from{}, to{};
  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;
    addDirect(graph, from, to);
  }

  int quries{}, query{};
  std::cin >> quries;

  for (int i = 0; i < quries; ++i) {
    std::cin >> query;
    printChain(graph, query);
  }

  return 0;
}
