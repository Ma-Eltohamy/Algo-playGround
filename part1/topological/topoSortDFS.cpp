#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) { graph[from].push_back(to); }

Graph buildGraph(int nodesNum, std::vector<std::vector<int>> &edges) {
  Graph graph(nodesNum);
  for (int i = 0; i < (int)edges.size(); ++i)
    addDirected(graph, edges[i][0], edges[i][1]);

  return graph;
}

void dfs(Graph &graph, std::vector<bool> &visited, std::vector<int> &order,
         int curNode) {
  visited[curNode] = true;

  for (auto &neighbor : graph[curNode])
    if (!visited[neighbor])
      dfs(graph, visited, order, neighbor);

  order.push_back(curNode);
}

std::vector<int> TopoSort(int nodesNum, Graph &matrix) {
  Graph graph{buildGraph(nodesNum, matrix)};

  std::vector<bool> visited((int)graph.size(), false);
  std::vector<int> order;

  for (int i = 0; i < 2; ++i)
    if (i)
      dfs(graph, visited, order, 8);
    else
      dfs(graph, visited, order, 0);

  return order;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> edges{{0, 1}, {1, 3}, {1, 4}, {4, 7}, {0, 2},
                                      {2, 5}, {2, 6}, {8, 2}, {8, 6}};

  std::vector<int> order{TopoSort(9, edges)};
  for (int i = 0; i < (int)order.size(); ++i)
    std::cout << order[i] << ' ';
  std::cout << '\n';
  return 0;
}
