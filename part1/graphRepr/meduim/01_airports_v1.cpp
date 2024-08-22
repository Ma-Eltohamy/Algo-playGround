#include <iostream>
#include <map>
#include <set>

struct edge {
  std::string toAirPort{};
  int cost{};

  bool operator<(const edge &other) const {
    if (toAirPort == other.toAirPort)
      return cost < other.cost;
    return toAirPort < other.toAirPort;
  }

  edge(std::string toAirPort, int cost) : toAirPort(toAirPort), cost(cost) {}
};

typedef std::map<std::string, std::multiset<edge>> GRAPH;

void addFlight(GRAPH &graph, std::string fromAirPort, std::string toAirPort,
               int cost) {
  graph[fromAirPort].insert(edge(toAirPort, cost));
}

void printAdjacencyMatrix(GRAPH &graph) { // O(V^2 + E)
  for (auto &fromAirPort : graph) {
    std::cout << "Flights from " << fromAirPort.first << ":\n";
    for (auto &toAirPort : fromAirPort.second) {
      std::cout << "\tTo " << toAirPort.toAirPort << " with cost "
                << toAirPort.cost << '\n';
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
