#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) { graph[from].push_back(to); }

Graph buildGraph() {
  int nodes{}, edges{}, from{}, to{};
  std::cin >> nodes >> edges;
  Graph graph(nodes);

  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;
    addDirected(graph, from, to);
  }

  return graph;
}

std::vector<int> getIndegrees(Graph &graph) {
  int nodes{(int)graph.size()};
  std::vector<int> indegress(nodes, 0);
  for (int i = 0; i < nodes; ++i)
    for (int j = 0; j < (int)graph[i].size(); ++j)
      ++indegress[graph[i][j]];

  return indegress;
}

std::vector<int> topoSort(Graph &graph, std::vector<int> indegrees) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  for (int i = 0; i < (int)indegrees.size(); ++i)
    if (!indegrees[i])
      pq.push(i);

  std::vector<int> topoSortedNodes;
  int curNode{};

  while (!pq.empty()) {
    curNode = pq.top();
    pq.pop();
    topoSortedNodes.push_back(curNode);

    for (auto neighbor : graph[curNode]) {
      --indegrees[neighbor];

      if (!indegrees[neighbor])
        pq.push(neighbor);
    }
  }
  if (topoSortedNodes.size() != graph.size()) // There is a cycle
    topoSortedNodes.clear();
  return topoSortedNodes;
}

void print(std::vector<int> const &vec) {

  for (int i = 0; i < (int)vec.size(); ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  Graph graph{buildGraph()}; // O(V+E)

  std::vector<int> indegress{getIndegrees(graph)}; // O(V+E)
  print(topoSort(graph, indegress));               // O(V+E)

  return 0;
}
