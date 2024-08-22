#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;
void printNodesNeighbours(GRAPH &graph, int r, int c) {
  int graphSize{(int)graph.size()};
  int colSize{};

  int curCell{};
  for (int i = 0; i < graphSize; ++i) {
    colSize = (int)graph[i].size();
    for (int j = 0; j < colSize; ++j) {
      std::cout << "Node " << curCell << " has neighbors: ";

      // UP
      bool isValid{0 <= (i + -1) && (i + -1) < r};
      if (isValid)
        std::cout << i + -1 << ' ';

      // Right
      isValid = (0 <= (j + 1) && (j + 1) < c);
      if (isValid)
        std::cout << j + 1 << ' ';

      // Down
      isValid = (0 <= (i + 1) && (i + 1) < r);
      if (isValid)
        std::cout << i + 1 << ' ';

      // Left
      isValid = (0 <= (j + -1) && (j + -1) < c);
      if (isValid)
        std::cout << j + -1 << ' ';
      std::cout << '\n';
      ++curCell;
    }
  }
}

int main(int argc, char *argv[]) {
  int r, c;
  std::cin >> r >> c;
  GRAPH graph(r, std::vector<int>(c));

  printNodesNeighbours(graph, r, c);
  return 0;
}
