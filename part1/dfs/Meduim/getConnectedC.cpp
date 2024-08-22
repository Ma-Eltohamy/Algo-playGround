#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> &grid) {
  for (int i = 0; i < (int)grid.size(); ++i) {
    for (int j = 0; j < (int)grid[0].size(); ++j)
      std::cout << grid[i][j] << ' ';
    std::cout << '\n';
  }
}

bool isValid(std::vector<std::vector<int>> &grid, int sr, int sc) {
  return sr >= 0 && sr < (int)grid.size() && sc >= 0 &&
         sc < (int)grid[0].size();
}

void dfs(std::vector<std::vector<int>> &matrix, int sr, int sc) {

  if (!isValid(matrix, sr, sc) || matrix[sr][sc] == 0)
    return;

  matrix[sr][sc] = 0;

  int rowNeighbor[]{-1, 0, 1, 0};
  int colNeighbor[]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i)
    dfs(matrix, sr + rowNeighbor[i], sc + colNeighbor[i]);
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid1{{1, 1, 1, 0, 0},
                                      {0, 1, 1, 1, 1},
                                      {0, 0, 0, 0, 0},
                                      {1, 0, 0, 0, 0},
                                      {1, 1, 0, 1, 1}};

  std::vector<std::vector<int>> grid2{{1, 1, 1, 0, 0},
                                      {0, 0, 1, 1, 1},
                                      {0, 1, 0, 0, 0},
                                      {1, 0, 1, 1, 0},
                                      {0, 1, 0, 1, 0}};

  int conectedComponents{};
  std::vector<std::vector<int>> &matrix{grid2};
  for (int i = 0; i < (int)matrix.size(); ++i)
    for (int j = 0; j < (int)matrix[0].size(); ++j) {
      if (matrix[i][j]) {
        dfs(matrix, i, j);
        ++conectedComponents;
      }
      std::cout << conectedComponents << '\n';
    }

  std::cout << "Total components: " << conectedComponents << '\n';

  return 0;
}
