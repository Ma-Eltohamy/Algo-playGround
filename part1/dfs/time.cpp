#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirection(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

void dfs(GRAPH &graph, int node, std::vector<std::pair<int, int>> &time,
         int &curTime) {
  time[node].first = ++curTime;

  for (int neighbor : graph[node]) {
    int neighborStart{time[neighbor].first};
    if (neighborStart == -1) { // It's !visited
      std::cout << "From node " << node << " to node " << neighbor
                << " There is a [ RootedTree edge ].\n";
      dfs(graph, neighbor, time, curTime);
    } else {
      if (time[node].first < time[neighbor].first)
        std::cout << "From node " << node << " to node " << neighbor
                  << " There is a [ Forward edge ].\n";

      else if (time[neighbor].second == -1)
        std::cout << "From node " << node << " to node " << neighbor
                  << " There is a [ Back edge ].\n";

      else
        std::cout << "From node " << node << " to node " << neighbor
                  << " There is a [ Cross edge ].\n";
    }
  }
  time[node].second = ++curTime;
}

void classifyEdges(GRAPH &graph) {

  int curTime{};
  int nodes{(int)graph.size()};
  std::vector<std::pair<int, int>> time(nodes, std::make_pair(-1, -1));

  for (int i = 0; i < nodes; ++i)
    if (time[i].first == -1)
      dfs(graph, i, time, curTime);

  for (int i = 0; i < nodes; ++i)
    std::cout << i << ' ' << time[i].first << ' ' << time[i].second << '\n';
}

int main(int argc, char *argv[]) {

  int cases, nodes, edges;
  std::cin >> cases;
  while (cases--) {
    std::cin >> nodes >> edges;

    GRAPH graph(nodes); // observe: empty lists

    for (int e = 0; e < edges; ++e) {
      int from, to;
      std::cin >> from >> to;
      addDirection(graph, from, to);
    }
    classifyEdges(graph);
  }

  return 0;
}
