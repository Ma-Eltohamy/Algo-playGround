#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int getColor(int color) {
  if (color == 1)
    return 2;
  return 1;
}

void dfs(std::vector<std::vector<int>> &graph, std::unordered_set<int> &visited,
         std::vector<int> &colors, int node, int curColor, bool &isBiPartite) {
  visited.insert(node);
  colors[node] = curColor;

  if (!isBiPartite)
    return;

  int oppisiteColor = getColor(curColor);
  for (auto neighbor : graph[node]) {
    if (colors[neighbor] == 0) // This node doesn't have a color yet
      colors[neighbor] = oppisiteColor;

    else if (colors[neighbor] != oppisiteColor) { // There is a colflict
      isBiPartite = false;
      return;
    }
  }
  for (auto neighbor : graph[node])
    if (!visited.count(neighbor))
      dfs(graph, visited, colors, neighbor, oppisiteColor, isBiPartite);
}

bool isBipartite(std::vector<std::vector<int>> &graph) {
  bool isBiPartite{true};
  int curColor = 1;

  std::unordered_set<int> visited;
  std::vector<int> colors((int)graph.size(), 0);
  for (int i = 0; i < (int)graph.size(); ++i)
    if (!visited.count(i)) {
      dfs(graph, visited, colors, i, curColor, isBiPartite);

      if (!isBiPartite)
        return false;
    }

  return true;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  std::cout << isBipartite(graph);
  // some operations
  return 0;
}
