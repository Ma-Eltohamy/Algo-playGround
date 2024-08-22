// https://leetcode.com/problems/course-schedule-ii/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
}

bool dfs(GRAPH &graph, int node, vector<int> &started, vector<int> &finished,
         int &time, vector<int> &ordering) {
  started[node] = time++;

  for (int neighbour : graph[node]) {
    if (started[neighbour] == -1) {
      if (dfs(graph, neighbour, started, finished, time, ordering))
        return true; // cycle
    } else if (finished[neighbour] == -1)
      return true; // back edge
  }
  finished[node] = time++;
  ordering.push_back(node);
  return false; // no cycle
}

vector<int> topological_sort(GRAPH &graph) {
  int nodes = graph.size();

  vector<int> started(nodes, -1), finished(nodes, -1);
  vector<int> ordering;
  int time = 1;

  for (int i = 0; i < nodes; ++i)
    if (started[i] == -1) // not visited
      if (dfs(graph, i, started, finished, time, ordering))
        return vector<int>(); // cycle

  reverse(ordering.begin(), ordering.end());
  return ordering;
}

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    GRAPH graph(numCourses);
    for (auto &pair : prerequisites)
      add_directed_edge(graph, pair[0], pair[1]);

    return topological_sort(graph);
  }
};

int main() {
  std::vector<std::vector<int>> edges{{9, 1}, {1, 3}, {3, 0}, {1, 4}, {4, 7},
                                      {9, 2}, {2, 5}, {2, 6}, {8, 6}};
  std::vector<int> order{Solution().findOrder(10, edges)};

  for (int i = 0; i < (int)order.size(); ++i)
    std::cout << order[i] << ' ';
  std::cout << '\n';
  return 0;
}
