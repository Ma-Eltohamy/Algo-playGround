#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<int>> &matrix, int row, int col) {
  return (int)matrix.size() > row && row >= 0 &&
         (int)matrix[row].size() > col && col >= 0;
}

void dfs(std::vector<std::vector<int>> &grid,
         std::vector<std::vector<bool>> &visited, int row, int col, int color) {

  if (!isValid(grid, row, col) || visited[row][col] || grid[row][col] != color)
    return;

  visited[row][col] = true;

  int rowNeighbors[4]{-1, 0, 1, 0};
  int colNeighbors[4]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i)
    dfs(grid, visited, row + rowNeighbors[i], col + colNeighbors[i], color);
}

void changeColor(std::vector<std::vector<int>> &grid,
                 std::vector<std::vector<bool>> &visited, int newColor) {
  int rowNeighbors[4]{-1, 0, 1, 0};
  int colNeighbors[4]{0, 1, 0, -1};
  for (int i = 0; i < (int)grid.size(); ++i)
    for (int j = 0; j < (int)grid[0].size(); ++j)
      for (int k = 0; k < 4; ++k) {
        if (!visited[i][j])
          continue;
        if (!isValid(grid, i + rowNeighbors[k], j + colNeighbors[k]) ||
            !visited[i + rowNeighbors[k]][j + colNeighbors[k]])
          grid[i][j] = newColor;
      }
}

std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>> &grid,
                                          int row, int col, int color) {
  int oldColor{grid[row][col]};
  int rowSize{(int)grid.size()};
  int colSize{(int)grid[0].size()};

  std::vector<std::vector<bool>> visited(rowSize, std::vector<bool>(colSize));

  dfs(grid, visited, row, col, oldColor);
  changeColor(grid, visited, color);

  return grid;
}

void print(std::vector<std::vector<int>> grid) {
  for (int i = 0; i < (int)grid.size(); ++i)
    for (int j = 0; j < (int)grid[0].size(); ++j)
      std::cout << grid[i][j] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  // std::vector<std::vector<int>> grid{{1, 1}, {1, 2}};
  std::vector<std::vector<int>> grid{
      {1, 2, 1, 2, 1, 2}, {2, 2, 2, 2, 1, 2}, {1, 2, 2, 2, 1, 2}};
  print(grid);

  print(colorBorder(grid, 1, 3, 1));
  return 0;
}
