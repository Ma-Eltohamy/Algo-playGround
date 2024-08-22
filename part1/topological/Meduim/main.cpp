#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void addUndirected(Graph &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

Graph buildGraph(int n, std::vector<std::vector<int>> &edges) {
  Graph graph(n, std::vector<int>());

  for (int i = 0; i < (int)edges.size(); ++i)
    addUndirected(graph, edges[i][0], edges[i][1]);

  return graph;
}

// LongestPath, curNode
std::pair<int, int> bfs(Graph &graph, int n, int node, int levelTarget = -1) {
  std::queue<int> q;
  std::vector<bool> visited(n, false);

  q.push(node);
  int curNode{node}, level{-1}, qSize{};

  while (!q.empty()) {
    ++level;
    if (level == levelTarget) {
      curNode = q.front();
      break;
    }
    qSize = q.size();

    while (qSize--) {
      curNode = q.front();
      q.pop();
      visited[curNode] = true;

      for (auto neighbor : graph[curNode])
        if (!visited[neighbor])
          q.push(neighbor);
    }
  }

  return std::make_pair(level, curNode);
}

std::vector<int> findMinHeightTrees(int n,
                                    std::vector<std::vector<int>> &edges) {
  Graph graph{buildGraph(n, edges)};

  std::pair<int, int> edgeNodeInfo{bfs(graph, n, 0)};
  std::pair<int, int> longestPathInfo{bfs(graph, n, edgeNodeInfo.second)};

  std::vector<int> result;
  int levelTarget = longestPathInfo.first / 2;
  std::pair<int, int> centerNode{
      bfs(graph, n, edgeNodeInfo.second, levelTarget)};
  result.push_back(centerNode.second);

  if (longestPathInfo.first % 2 == 0) // LongestPath is even
    result.push_back(graph[centerNode.second][0]);

  return result;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> edges /* {{1, 0}, {1, 2}, {1, 3}}; */
      {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
  std::vector<int> res{findMinHeightTrees(6, edges)};

  for (int i = 0; i < (int)res.size(); ++i)
    std::cout << res[i] << ' ';
  std::cout << '\n';

  return 0;
}
