#include <iostream>
#include <queue>
#include <string>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addUndirect(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

bool isCycleBFS(GRAPH &graph, std::vector<bool> &visited) {
  std::queue<int> q;
  q.push(0);
  visited[0] = true;
  std::vector<int> parents((int)visited.size(), -1);
  int curNode{};

  while (!q.empty()) {
    curNode = q.front();
    q.pop();

    for (auto neighbor : graph[curNode]) {
      if (neighbor != parents[curNode] && visited[neighbor])
        return true;
      else
        q.push(neighbor), visited[neighbor] = true, parents[neighbor] = curNode;
    }
  }

  return false;
}

bool isConnectedComponent(std::vector<bool> &visited) {
  int nodes{(int)visited.size()};
  for (int i = 0; i < nodes; ++i)
    if (!visited[i])
      return false;
  return true;
}

bool validTree(int n, std::vector<std::vector<int>> &edges) {
  GRAPH graph(n);
  for (auto &edge : edges)
    addUndirect(graph, edge[0], edge[1]);

  std::vector<bool> visited(n);
  return isCycleBFS(graph, visited) && isConnectedComponent(visited);
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  std::cout << validTree(5, edges);
  return 0;
}
