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

void dfs(std::vector<std::vector<int>> &matrix, int sr, int sc, int &nodes) {

  if (!isValid(matrix, sr, sc) || matrix[sr][sc] == 0)
    return;

  ++nodes;
  matrix[sr][sc] = 0;

  int rowNeighbor[]{-1, 0, 1, 0};
  int colNeighbor[]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i)
    dfs(matrix, sr + rowNeighbor[i], sc + colNeighbor[i], nodes);
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> grid1{{1, 1, 1, 0, 0},
                                      {0, 1, 1, 1, 1},
                                      {0, 0, 0, 0, 0},
                                      {1, 0, 0, 0, 0},
                                      {1, 1, 0, 1, 1}};

  int nodes{};
  std::vector<std::vector<int>> &matrix{grid1};
  for (int i = 0; i < (int)matrix.size(); ++i)
    for (int j = 0; j < (int)matrix[0].size(); ++j) {
      dfs(matrix, i, j, nodes);
      std::cout << nodes << '\n';
    }

  std::cout << "Total nodes: " << nodes << '\n';

  return 0;
}
