#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

typedef std::vector<std::vector<char>> GRAPH;
std::pair<int, int> getPlayerPosition(GRAPH &matrix) {

  for (int i = 0; i < (int)matrix.size(); ++i)
    for (int j = 0; j < (int)matrix[i].size(); ++j)
      if (matrix[i][j] == '*')
        return std::make_pair(i, j);
  return std::make_pair(-1, -1);
}

bool isValid(GRAPH &matrix, int r, int c) {
  return r >= 0 && r < (int)matrix.size() && c >= 0 &&
         c < (int)matrix[r].size();
}

int bfs(GRAPH &matrix, int row, int col) {
  int level{};
  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<bool>> visited(
      (int)matrix.size(), std::vector<bool>((int)matrix[0].size()));

  int rNeighbors[4]{-1, 0, 1, 0};
  int cNeighbors[4]{0, 1, 0, -1};

  std::pair<int, int> curPos{std::make_pair(row, col)};
  q.push(curPos);
  visited[row][col] = true;

  int qSize{(int)q.size()};
  while (!q.empty()) {
    qSize = (int)q.size();
    ++level;

    while (qSize--) {
      curPos = q.front();
      q.pop();

      for (int i = 0; i < 4; ++i) {
        int rNeighPos{curPos.first + rNeighbors[i]};
        int cNeighPos{curPos.second + cNeighbors[i]};

        if (isValid(matrix, rNeighPos, cNeighPos) &&
            !visited[rNeighPos][cNeighPos]) {

          if (matrix[rNeighPos][cNeighPos] == '0')
            q.push(std::make_pair(rNeighPos, cNeighPos));

          else if (matrix[rNeighPos][cNeighPos] == '#')
            return level;
        }
      }
    }
  }

  return -1;
}

int getFood(std::vector<std::vector<char>> &matrix) {
  std::pair<int, int> playerPosition{getPlayerPosition(matrix)};

  if (playerPosition.first == -1)
    return -1;

  return bfs(matrix, playerPosition.first, playerPosition.second);
}

int main(int argc, char *argv[]) {
  // GRAPH matrix{{'X', 'X', 'X', 'x', 'x', 'X', 'x', 'x'},
  //              {'X', '*', '0', 'X', '0', '#', '0', 'x'},
  //              {'x', '0', '0', 'x', '0', '0', 'x', 'x'},
  //              {'x', '0', '0', '0', '0', '#', '0', 'X'},
  //              {'x', 'x', 'x', 'X', 'x', 'X', 'X', 'X'}};
  // GRAPH matrix{{'0', '*'}, {'#', '0'}};
  // GRAPH matrix{{'X', '*'}, {'#', 'X'}};
  std::cout << getFood(matrix) << '\n';
  return 0;
}
