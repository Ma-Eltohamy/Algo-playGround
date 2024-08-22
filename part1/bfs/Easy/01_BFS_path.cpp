#include <iostream>
#include <queue>
#include <string>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

GRAPH buildGraph() {
  int nodes{}, edges{};
  std::cin >> nodes >> edges;

  GRAPH graph(nodes);
  int from{}, to{};
  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;
    addDirect(graph, from, to);
  }

  return graph;
}

std::vector<int> bfs(GRAPH &graph) {
  int nodes{(int)graph.size()};
  std::vector<int> parents(nodes, -1);
  std::queue<int> q;

  int curNode{0};

  q.push(curNode);

  while (!q.empty()) {
    curNode = q.front();
    q.pop();

    for (auto neighbor : graph[curNode])
      if (parents[neighbor] == -1) // Not visited before
        q.push(neighbor), parents[neighbor] = curNode;
  }

  return parents;
}

void printPaths(std::vector<int> &parents) {
  for (int i = 1; i < (int)parents.size(); ++i) {
    std::cout << "Path from 0 to " << i << ": ";
    if (parents[i] == -1) {
      std::cout << "Not exist\n";
      continue;
    }

    std::string path{std::to_string(i)};
    int parent{parents[i]};

    while (parent != -1) {
      path = std::to_string(parent) + ' ' + path;
      parent = parents[parent];
    }

    std::cout << path << '\n';
  }
}

int main(int argc, char *argv[]) {
  int testCases{};
  std::cin >> testCases;

  for (int i = 0; i < testCases; ++i) {
    GRAPH graph{buildGraph()};
    std::vector<int> parents{bfs(graph)};
    printPaths(parents);
  }
  return 0;
}
