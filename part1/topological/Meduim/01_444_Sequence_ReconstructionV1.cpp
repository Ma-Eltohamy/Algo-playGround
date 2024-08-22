#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::unordered_map<int, std::vector<int>> Graph;

void addDirected(Graph &graph, int from, int to) {
  for (int i = 0; i < (int)graph[from].size();
       ++i) // To prevent duplicate edges
    if (graph[from][i] == to)
      return;

  graph[from].push_back(to);
}

Graph buildGraph(std::vector<std::vector<int>> &seqs) {
  Graph graph;

  for (int i = 0; i < (int)seqs.size(); ++i)
    if ((int)seqs[i].size() == 1) // Just the node
      graph[seqs[i][0]];
    else
      for (int j = 1; j < (int)seqs[i].size(); ++j)
        addDirected(graph, seqs[i][j - 1], seqs[i][j]);

  return graph;
}

void dfs(Graph &graph, std::unordered_set<int> &visited,
         std::vector<int> &order, int curNode) {
  visited.insert(curNode);

  for (auto neighbor : graph[curNode])
    if (!visited.count(neighbor))
      dfs(graph, visited, order, neighbor);

  order.push_back(curNode);
}

bool sequenceReconstruction(std::vector<int> &org,
                            std::vector<std::vector<int>> &seqs) {

  Graph graph{buildGraph(seqs)};

  std::unordered_set<int> visited;
  std::vector<int> order;
  for (auto node : graph)
    if (!visited.count(node.first))
      dfs(graph, visited, order, node.first);

  if ((int)order.size() != (int)org.size())
    return false;

  std::reverse(order.begin(), order.end());
  for (int i = 0; i < (int)org.size(); ++i)
    if (org[i] != order[i])
      return false;

  return true;
}

int main(int argc, char *argv[]) {
  std::vector<int> org{1};
  std::vector<std::vector<int>> seqs{{1}};
  std::cout << sequenceReconstruction(org, seqs) << '\n';
  return 0;
}
