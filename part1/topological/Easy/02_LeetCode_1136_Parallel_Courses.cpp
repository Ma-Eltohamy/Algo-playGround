#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) { graph[from].push_back(to); }

Graph buildGraph(int n, std::vector<std::vector<int>> &relations) {
  Graph graph(n);
  for (int i = 0; i < (int)relations.size(); ++i)
    addDirected(graph, relations[i][0] - 1, relations[i][1] - 1);

  return graph;
}

int longestPath(Graph &graph) {
  std::vector<int> indegree((int)graph.size(), 0);

  for (int i = 0; i < (int)graph.size(); ++i)
    for (int j = 0; j < (int)graph[i].size(); ++j)
      ++indegree[graph[i][j]];

  std::queue<int> q;
  for (int i = 0; i < (int)indegree.size(); ++i)
    if (!indegree[i])
      q.push(i);

  int curNode{}, level{}, qSize{}, foundNodes{};

  while (!q.empty()) {
    ++level;
    qSize = q.size();

    while (qSize--) {
      curNode = q.front();
      ++foundNodes;
      q.pop();

      for (auto &neighbor : graph[curNode]) {
        --indegree[neighbor];
        if (indegree[neighbor] == 0)
          q.push(neighbor);
      }
    }
  }

  if (foundNodes != (int)indegree.size())
    return -1;
  return level;
}
int minimumSemesters(int n, std::vector<std::vector<int>> &relations) {
  Graph graph{buildGraph(n, relations)};
  return longestPath(graph);
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> subjects{{1, 2}, {2, 3}, {2, 4}, {3, 4}};
  std::cout << minimumSemesters(4, subjects) << '\n';
  return 0;
}
