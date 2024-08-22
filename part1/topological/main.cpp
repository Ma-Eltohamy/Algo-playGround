#include <algorithm>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) { graph[from].push_back(to); }

Graph buildGraph(int numCourses, std::vector<std::vector<int>> &matrix) {
  Graph graph(numCourses);

  for (int i = 0; i < (int)matrix.size(); ++i)
    addDirected(graph, matrix[i][1], matrix[i][0]);

  return graph;
}

void dfs(Graph &graph, std::vector<int> &order, std::vector<int> &started,
         std::vector<int> &finished, int time, int curNode, bool &isCycle) {
  if (isCycle)
    return;

  started[curNode] = ++time;

  for (auto &neighbor : graph[curNode])
    if (started[neighbor] == -1)
      dfs(graph, order, started, finished, time, neighbor, isCycle);

    else if (finished[neighbor] == -1) { // This is a back edge
      isCycle = true;
      return;
    }

  finished[curNode] = ++time;
  order.push_back(curNode);
}

std::vector<int> findOrder(int numCourses,
                           std::vector<std::vector<int>> &prerequisites) {
  Graph graph{buildGraph(numCourses, prerequisites)};
  std::vector<int> order;
  std::vector<int> started((int)graph.size(), -1),
      finished((int)graph.size(), -1);
  bool isCycle{};

  for (int i = 0; i < (int)graph.size(); ++i) {
    if (started[i] == -1)
      dfs(graph, order, started, finished, 0, i, isCycle);
    if (isCycle)
      return std::vector<int>();
  }

  std::reverse(order.begin(), order.end());
  return order;
}

int main(int argc, char *argv[]) {
  // std::vector<std::vector<int>> edges{{9, 1}, {1, 3}, {3, 0}, {1, 4}, {4, 7},
  //                                     {9, 2}, {2, 5}, {2, 6}, {8, 6}};
  std::vector<std::vector<int>> edges{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  std::vector<int> order{findOrder(4, edges)};

  for (int i = 0; i < (int)order.size(); ++i)
    std::cout << order[i] << ' ';
  std::cout << '\n';
  return 0;
}
