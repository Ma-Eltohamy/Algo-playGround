#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

bool isValid(std::vector<std::vector<int>> &rooms, int r, int c) {
  if (r >= 0 && r < (int)rooms.size() && c >= 0 && c < (int)rooms[0].size() &&
      rooms[r][c] != -1) // is in the matrix & not a wall
    return true;
  return false;
}

void bfs(std::vector<std::vector<int>> &rooms,
         std::vector<std::vector<bool>> &visited, int r, int c) {

  std::queue<std::pair<int, int>> q;
  std::pair<int, int> curNode{r, c};
  q.push(curNode);
  visited[r][c] = true;

  int level{}, qSize{};
  while (!q.empty()) {
    ++level;
    qSize = (int)q.size();

    while (qSize--) {
      curNode = q.front();
      q.pop();

      int rdir[4]{-1, 0, 1, 0};
      int cdir[4]{0, 1, 0, -1};
      int rNeigh{}, cNeigh{};

      for (int i = 0; i < 4; ++i) {
        rNeigh = curNode.first + rdir[i], cNeigh = curNode.second + cdir[i];
        if (isValid(rooms, rNeigh, cNeigh) && !visited[rNeigh][cNeigh]) {
          if (rooms[rNeigh][cNeigh] == 0) {
            rooms[r][c] = level;
            return;
          }

          q.push(std::make_pair(rNeigh, cNeigh)),
              visited[rNeigh][cNeigh] = true;
        }
      }
    }
  }
}

void wallsAndGates(std::vector<std::vector<int>> &rooms) {
  bool isEmptyRoot{};
  int rows{(int)rooms.size()};
  int cols{(int)rooms[0].size()};

  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j) {
      std::vector<std::vector<bool>> visited(
          (int)rooms.size(), std::vector<bool>((int)rooms[0].size()));
      isEmptyRoot = rooms[i][j] == 2147483647;

      if (isEmptyRoot)
        bfs(rooms, visited, i, j);
    }
}

void print(std::vector<std::vector<int>> &rooms) {
  for (int i = 0; i < (int)rooms.size(); ++i) {
    for (int j = 0; j < (int)rooms[i].size(); ++j)
      std::cout << rooms[i][j] << ' ';
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  // std::vector<std::vector<int>> rooms{{2147483647, -1, 0, 2147483647},
  //                                     {2147483647, 2147483647, 2147483647,
  //                                     -1}, {2147483647, -1, 2147483647, -1},
  //                                     {0, -1, 2147483647, 2147483647}};
  std::vector<std::vector<int>> rooms{{0, -1}, {2147483647, 2147483647}};

  wallsAndGates(rooms);
  print(rooms);

  return 0;
}
