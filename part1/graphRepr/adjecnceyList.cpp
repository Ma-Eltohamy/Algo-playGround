#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

void addUndirect(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

void printAdjecencyList(GRAPH &graph) {
  int graphSize{(int)graph.size()};
  int colsSize{};

  for (int from = 0; from < graphSize; ++from) {
    colsSize = (int)graph[from].size();
    std::cout << "Node " << from << " has neighbours: ";
    for (int to = 0; to < colsSize; ++to)
      std::cout << graph[from][to] << ' ';
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  GRAPH graph(6, std::vector<int>(0));
  addDirect(graph, 0, 0);
  addDirect(graph, 0, 5);
  addDirect(graph, 1, 4);
  addDirect(graph, 2, 1);
  addDirect(graph, 2, 5);
  addDirect(graph, 2, 0);
  addDirect(graph, 2, 3);
  addDirect(graph, 5, 4);

  printAdjecencyList(graph);
  return 0;
}
