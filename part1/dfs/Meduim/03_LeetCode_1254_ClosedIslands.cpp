#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<int>> &matrix, int i, int j) {
  return (int)matrix.size() > i && i >= 0 && (int)matrix[i].size() > j &&
         j >= 0;
}

bool isTouchBoundry(std::vector<std::vector<int>> &grid, int sr, int sc) {
  int rowNum{(int)grid.size()};
  int colNum{(int)grid[0].size()};

  return sr == 0 || sc == 0 || sr == rowNum - 1 || sc == colNum - 1;
}

void dfs(std::vector<std::vector<int>> &grid, int sr, int sc,
         bool &isClosedIsland) {

  if (!isValid(grid, sr, sc) || grid[sr][sc] == 1)
    return;

  if (isTouchBoundry(grid, sr, sc)) {
    isClosedIsland = false;
    return;
  }

  grid[sr][sc] = 1;

  int rowNeighbors[4]{-1, 0, 1, 0};
  int colNeighbors[4]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i)
    dfs(grid, sr + rowNeighbors[i], sc + colNeighbors[i], isClosedIsland);
}

int closedIsland(std::vector<std::vector<int>> &grid) {
  bool isClosedIsland{true};
  int counter{};
  for (int i = 0; i < (int)grid.size(); ++i)
    for (int j = 0; j < (int)grid[0].size(); ++j)
      if (grid[i][j] == 0) { // is land
        isClosedIsland = true;
        dfs(grid, i, j, isClosedIsland);

        if (isClosedIsland)
          ++counter;
      }
  return counter;
}
int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid{{0, 1, 1, 1, 0},
                                     {1, 0, 1, 0, 1},
                                     {1, 0, 1, 0, 1},
                                     {1, 0, 0, 0, 1},
                                     {0, 1, 1, 1, 0}};
  std::cout << closedIsland(grid) << '\n';
  return 0;
}
