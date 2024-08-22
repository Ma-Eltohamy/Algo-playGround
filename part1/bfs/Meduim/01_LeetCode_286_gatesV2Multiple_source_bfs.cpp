#include <iostream>
#include <queue>
#include <vector>

struct cell {
  int r{};
  int c{};
};

bool isValid(std::vector<std::vector<int>> &rooms, int r, int c) {
  if (r >= 0 && r < (int)rooms.size() && c >= 0 && c < (int)rooms[0].size())
    return true;
  return false;
}

void bfs(std::vector<std::vector<int>> &rooms, std::queue<cell> &q,
         std::vector<std::vector<bool>> &visited) {
  int level{}, qSize{(int)q.size()};
  cell curCell{};

  while (!q.empty()) {
    level++, qSize = (int)q.size();

    while (qSize--) {
      curCell = q.front();
      q.pop();

      int rdir[4]{-1, 0, 1, 0};
      int cdir[4]{0, 1, 0, -1};

      for (int i = 0; i < 4; ++i) {
        cell nCell{rdir[i] + curCell.r, cdir[i] + curCell.c};

        if (isValid(rooms, nCell.r, nCell.c) && !visited[nCell.r][nCell.c]) {
          q.push(cell{nCell.r, nCell.c});
          rooms[nCell.r][nCell.c] = level;
          visited[nCell.r][nCell.c] = true;
        }
      }
    }
  }
}

void wallsAndGates(std::vector<std::vector<int>> &rooms) {
  bool isGate{}, isObstecl{};
  int rows{(int)rooms.size()};
  int cols{(int)rooms[0].size()};

  std::queue<cell> q;
  std::vector<std::vector<bool>> visited(
      (int)rooms.size(), std::vector<bool>((int)rooms[0].size()));

  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j) {

      isObstecl = rooms[i][j] == -1;
      isGate = rooms[i][j] == 0;

      if (isGate)
        q.push(cell{i, j}), visited[i][j] = true;
      else if (isObstecl)
        visited[i][j] = true;
    }

  bfs(rooms, q, visited);
}

void print(std::vector<std::vector<int>> &rooms) {
  for (int i = 0; i < (int)rooms.size(); ++i) {
    for (int j = 0; j < (int)rooms[i].size(); ++j)
      std::cout << rooms[i][j] << ' ';
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> rooms{{2147483647, -1, 0, 2147483647},
                                      {2147483647, 2147483647, 2147483647, -1},
                                      {2147483647, -1, 2147483647, -1},
                                      {0, -1, 2147483647, 2147483647}};

  wallsAndGates(rooms);
  print(rooms);

  return 0;
}
