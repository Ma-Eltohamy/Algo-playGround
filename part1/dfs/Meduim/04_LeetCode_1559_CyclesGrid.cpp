#include <iostream>
#include <utility>
#include <vector>

bool isValid(std::vector<std::vector<char>> &matrix, int row, int col) {
  return (int)matrix.size() > row && row >= 0 &&
         (int)matrix[row].size() > col && col >= 0;
}

void dfs(std::vector<std::vector<char>> &grid,
         std::vector<std::vector<bool>> &visited,
         std::pair<int, int> lastVisited, std::pair<int, int> cur,
         bool &isCycle) {

  bool isValidSameChar{isValid(grid, cur.first, cur.second) &&
                       grid[cur.first][cur.second] ==
                           grid[lastVisited.first][lastVisited.second]};
  if (!isValidSameChar || isCycle)
    return;

  if (visited[cur.first][cur.second]) { // If i returned to any visited place
                                        // that means this is a cycle
    isCycle = true;
    return;
  }

  visited[cur.first][cur.second] = true;

  int rowNeighbors[4]{-1, 0, 1, 0};
  int colNeighbors[4]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i) {
    std::pair<int, int> curNeighbor{
        std::make_pair(cur.first + rowNeighbors[i],
                       cur.second + colNeighbors[i]),
    };

    if (curNeighbor !=
        lastVisited) // To make sure that i'm traversing in one direction
      dfs(grid, visited, cur, curNeighbor, isCycle);
  }
}

bool containsCycle(std::vector<std::vector<char>> &grid) {

  int rowSize{(int)grid.size()};
  int colSize{(int)grid[0].size()};

  bool isCycle{false};
  std::pair<int, int> start{};
  std::pair<int, int> lastVisited{};
  std::pair<int, int> cur{};
  std::vector<std::vector<bool>> visited(rowSize, std::vector<bool>(colSize));

  for (int i = 0; i < rowSize; ++i)
    for (int j = 0; j < colSize; ++j) {
      if (!visited[i][j]) {
        isCycle = false;
        std::pair<int, int> cur{i, j};
        dfs(grid, visited, cur, cur, isCycle);

        if (isCycle)
          return true;
      }
    }

  return false;
}

void print(std::vector<std::vector<int>> grid) {
  for (int i = 0; i < (int)grid.size(); ++i)
    for (int j = 0; j < (int)grid[0].size(); ++j)
      std::cout << grid[i][j] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  // std::vector<std::vector<char>> grid{{'a', 'a', 'a', 'a'},
  //                                     {'a', 'b', 'b', 'a'},
  //                                     {'a', 'b', 'b', 'a'},
  //                                     {'x', 'a', 'a', 'a'}};

  std::vector<std::vector<char>> grid{{'b', 'b', 'b', 'd'},
                                      {'b', 'b', 'b', 'e'},
                                      {'b', 'd', 'd', 'c'},
                                      {'b', 'a', 'a', 'c'}};

  std::cout << containsCycle(grid) << '\n';

  return 0;
}
