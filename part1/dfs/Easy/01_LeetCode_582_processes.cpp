#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::unordered_map<int, std::vector<int>> GRAPH;

void addDirect(GRAPH &graph, int from, int to) { graph[from].push_back(to); }

void buildGraph(GRAPH &graph, std::vector<int> &PPID, std::vector<int> &PID) {
  int processesNum{(int)PPID.size()};

  for (int i = 0; i < processesNum; ++i)
    addDirect(graph, PPID[i], PID[i]);
}

void dfs(GRAPH &graph, int kill, std::unordered_set<int> &visited) {
  visited.insert(kill);

  for (auto &neighbor : graph[kill])
    if (!visited.count(neighbor))
      dfs(graph, neighbor, visited);
}

std::vector<int> killProcesses(std::vector<int> PPID, std::vector<int> PID,
                               int kill) {
  GRAPH graph;

  buildGraph(graph, PPID, PID);
  // std::vector<int> res{kill};
  std::unordered_set<int> visited;
  dfs(graph, kill, visited);

  return std::vector<int>(visited.begin(), visited.end());
}

void print(std::vector<int> const &vec) {
  for (int i = 0; i < (int)vec.size(); ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<int> pid{1, 3, 10, 5, 11, 12, 13};
  std::vector<int> ppid{3, 0, 5, 3, 10, 10, 10};
  print(killProcesses(ppid, pid, 5));

  return 0;
}
