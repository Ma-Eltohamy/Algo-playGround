#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::unordered_map<int, std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) { graph[from].push_back(to); }

Graph buildGraph(std::vector<std::vector<int>> &seqs) {
  Graph graph;
  for (int i = 0; i < (int)seqs.size(); ++i)
    if ((int)seqs[i].size() == 1)
      graph[seqs[i][0]];
    else
      for (int j = 1; j < (int)seqs[i].size(); ++j)
        addDirected(graph, seqs[i][j - 1], seqs[i][j]);

  return graph;
}

std::vector<int> topoSort(Graph &graph) {
  std::unordered_map<int, int> indegrees;

  for (auto &node : graph)
    for (int i = 0; i < (int)node.second.size(); ++i)
      ++indegrees[node.second[i]];

  std::queue<int> q;
  for (auto &node : graph)
    if (!indegrees.count(node.first)) // If it isn't count in indegrees then
                                      // it's indegrees is ZERO
      q.push(node.first);

  int curNode;
  std::vector<int> order;

  while (!q.empty()) {
    if (q.size() > 1)
      return std::vector<int>();

    curNode = q.front();
    q.pop();
    order.push_back(curNode);

    for (auto &neighbor : graph[curNode]) {
      --indegrees[neighbor];
      if (indegrees[neighbor] == 0)
        q.push(neighbor);
    }
  }

  return order;
}

bool sequenceReconstruction(std::vector<int> &org,
                            std::vector<std::vector<int>> &seqs) {
  Graph graph{buildGraph(seqs)};

  std::vector<int> ordring{topoSort(graph)};
  return ordring == org;
}

int main(int argc, char *argv[]) {
  std::vector<int> org{1};
  std::vector<std::vector<int>> seqs{{1}};
  std::cout << sequenceReconstruction(org, seqs) << '\n';
  return 0;
}
