#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

bool processChildren(std::unordered_set<std::string> &visited,
                     std::queue<std::string> &q, std::string curNode,
                     std::string target, int Nslots) {

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < Nslots; ++j) {
      std::string curChild{curNode};

      if (!i) {
        if (curChild[j] == '0') {
          curChild[j] = '9';
        } else
          --curChild[j];
      } else {
        if (curChild[j] == '9') {
          curChild[j] = '0';
        } else
          ++curChild[j];
      }

      if (curChild == target)
        return true;
      if (!visited.count(curChild))
        q.push(curChild), visited.insert(curChild);
    }

  return false;
}

int bfs(std::vector<std::string> &deadends, std ::string target) {
  if (target == "0000")
    return 0;

  int const Nslots{4};
  std::queue<std::string> q;
  q.push("0000");

  std::string curNode{target};
  int level{}, qSize{(int)q.size()};

  std::unordered_set<std::string> visited(deadends.begin(), deadends.end());

  if (visited.count("0000"))
    return -1;

  visited.insert("0000");

  while (!q.empty()) {
    qSize = (int)q.size();
    ++level;

    while (qSize--) {
      curNode = q.front();
      q.pop();

      if (processChildren(visited, q, curNode, target, Nslots))
        return level;
    }
  }
  return -1;
}
int openLock(std::vector<std::string> &deadends, std::string target) {
  return bfs(deadends, target);
}
int main(int argc, char *argv[]) {
  std::vector<std::string> nums{"0201", "0101", "0102", "1212", "2002"};
  std::cout << openLock(nums, "0202") << '\n';
  return 0;
}
