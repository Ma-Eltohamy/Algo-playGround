#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) { graph[from].push_back(to); }

Graph buildGraph(int numCourses, std::vector<std::vector<int>> &matrix) {
  Graph graph(numCourses);
  for (int i = 0; i < (int)matrix.size(); ++i)
    addDirected(graph, matrix[i][1], matrix[i][0]);
  return graph;
}

int longestPath(Graph &graph) {
  std::queue<int> q;

  // Getting the indegrees of all nodes
  std::vector<int> indegrees((int)graph.size(), 0);
  for (int i = 0; i < (int)graph.size(); ++i)
    for (auto &neighbor : graph[i])
      ++indegrees[neighbor];

  // Pushing all starting nodes
  for (int i = 0; i < (int)indegrees.size(); ++i)
    if (!indegrees[i])
      q.push(i);

  int level{}, foundNodes{}, qSize{}, curNode{};

  while (!q.empty()) {
    ++level;
    qSize = q.size();

    while (qSize--) {
      curNode = q.front();
      ++foundNodes;
      q.pop();

      for (auto &neighbor : graph[curNode]) {
        --indegrees[neighbor];
        if (!indegrees[neighbor])
          q.push(neighbor);
      }
    }
  }

  if (foundNodes != (int)graph.size())
    return -1;
  return level;
}

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  Graph graph{buildGraph(numCourses, prerequisites)};

  if (longestPath(graph) == -1)
    return false;
  return true;
}
int main(int argc, char *argv[]) {
  // some operations
  return 0;
}
