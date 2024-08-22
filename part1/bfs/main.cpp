#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

typedef std::vector<std::vector<int>> GRAPH;

void addUndirected(GRAPH &graph, int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

// std::vector<int> BFS_v1(GRAPH &adjList, int start) {
//   std::vector<int> len(adjList.size(), -1);
//   std::queue<int> q;
//   q.push(start);
//   len[start] = 0;
//
//   while (!q.empty()) {
//     int cur = q.front();
//     q.pop();
//
//     for (int neighbour : adjList[cur])
//       if (len[neighbour] == -1) { // never visited
//         q.push(neighbour);
//         len[neighbour] = len[cur] + 1;
//       }
//   }
//   return len;
// }

std::vector<int> BFSv2(GRAPH &graph, int startingNode) {
  std::queue<int> q;
  std::vector<int> shortestPath((int)graph.size(), -1);

  q.push(startingNode);
  shortestPath[startingNode] = 0;

  int curNode{};
  int curLevelNodes{};
  while (!q.empty()) {
    std::cout << "Level " << shortestPath[curNode] + 1 << ": ";
    curLevelNodes = (int)q.size();

    while (curLevelNodes--) {
      curNode = q.front();
      std::cout << curNode << ' ';
      q.pop();

      for (auto neighbor : graph[curNode])
        if (shortestPath[neighbor] == -1) // never visited before
          q.push(neighbor),
              shortestPath[neighbor] =
                  shortestPath[curNode] + 1; // shortestPath == curLevel
    }
    std::cout << '\n';
  }

  return shortestPath;
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
  std::vector<int> shortestPath{BFSv2(graph, startingNode)};

  std::cout << shortestPath[8] << '\n';

  return 0;
}
