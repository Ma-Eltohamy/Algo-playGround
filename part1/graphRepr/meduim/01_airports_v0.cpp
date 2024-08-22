#include <iostream>
#include <map>
#include <set>

typedef std::map<std::string, std::map<std::string, std::set<int>>> GRAPH;

void addFlight(GRAPH &graph, std::string fromAirPort, std::string toAirPort,
               int cost) {
  graph[fromAirPort][toAirPort].insert(cost);
}

void printAdjacencyMatrix(GRAPH &graph) { // O(V^2 + E)
  for (auto &fromAirPort : graph) {
    std::cout << "Flights from " << fromAirPort.first << ":\n";
    for (auto &toAirPort : fromAirPort.second) {
      for (auto &pathCost : toAirPort.second)
        std::cout << "\tTo " << toAirPort.first << " with cost " << pathCost
                  << '\n';
    }
  }
}
int main(int argc, char *argv[]) {
  int numAirPorts{};
  int nodes, edges;
  std::cin >> nodes >> edges;
  GRAPH graph;

  std::string fromAirPort, toAirPort;
  int cost;
  for (int i = 0; i < edges; ++i) {
    std::cin >> fromAirPort >> toAirPort >> cost;

    addFlight(graph, fromAirPort, toAirPort, cost);
  }

  printAdjacencyMatrix(graph);
  return 0;
}
