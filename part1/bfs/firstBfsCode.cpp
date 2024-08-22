#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addUndirected(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

void bfs(GRAPH &graph, int startingNode) {
  std::queue<int> q;
  std::unordered_set<int> visited;

  q.push(startingNode);
  visited.insert(startingNode);

  int curNode{};
  int curLevel{}, curLevelNodes{1};
  while (!q.empty()) {
    std::cout << "Level " << curLevel++ << ": ";
    curLevelNodes = (int)q.size();

    while (curLevelNodes--) {
      curNode = q.front();
      std::cout << curNode << ' ';
      q.pop();

      for (auto neighbor : graph[curNode])
        if (!visited.count(neighbor))
          q.push(neighbor), visited.insert(neighbor);
    }
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  int nodes{}, edges{};
  std::cin >> nodes >> edges;
  GRAPH graph(nodes);

  int from{}, to{};
  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;
    addUndirected(graph, from, to);
  }

  int startingNode{};
  std::cin >> startingNode;
  bfs(graph, startingNode);

  return 0;
}
