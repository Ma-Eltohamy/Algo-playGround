#include <algorithm>
#include <iostream>
#include <vector>

struct edge {
  int from, to, weight;

  edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

  bool operator<(const edge &e) const { return weight < e.weight; }
  bool operator==(const edge &e) const {
    return (from == e.from) && (to == e.to) && (weight == e.weight);
  }

  void print() {
    std::cout << "Edge (" << from << " " << to << " " << weight << ")\n";
  }
};

typedef std::vector<edge> GRAPH;

void addEdge(GRAPH &graph, int from, int to, int cost) {
  // This version support multiple edge and loop-backs
  edge newEdge{from, to, cost};
  int graphSize{(int)graph.size()};
  for (int i = 0; i < graphSize; ++i)
    if (graph[i] == newEdge)
      return;
  graph.push_back(edge(from, to, cost));
}

void printAdjacencyMatrix(GRAPH &graph) {
  int graphSize{(int)graph.size()};

  for (int i = 0; i < graphSize; ++i)
    graph[i].print();
}

int main(int argc, char *argv[]) {
  int nodes, edges;
  std::cin >> nodes >> edges;

  GRAPH graph;

  for (int e = 0; e < edges; ++e) {
    int from, to, cost;
    std::cin >> from >> to >> cost;
    addEdge(graph, from, to, cost);
  }
  std::sort(graph.begin(), graph.end());
  printAdjacencyMatrix(graph);

  return 0;
}
