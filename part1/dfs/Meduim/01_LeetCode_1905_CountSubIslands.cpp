#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<int>> &matrix, int i, int j) {
  return (int)matrix.size() > i && i >= 0 && (int)matrix[i].size() > j &&
         j >= 0;
}

void dfs(std::vector<std::vector<int>> &grid1,
         std::vector<std::vector<int>> &grid2,
         std::vector<std::vector<int>> &visited, int sr, int sc,
         bool &isSubIsland) {
  if (!isValid(grid2, sr, sc) || visited[sr][sc] == -1)
    return;

  if (grid2[sr][sc] != grid1[sr][sc]) {
    isSubIsland = false;
    return;
  }

  visited[sr][sc] = -1;

  int rowNeighbors[4]{-1, 0, 1, 0};
  int colNeighbors[4]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i)
    dfs(grid1, grid2, visited, sr + rowNeighbors[i], sc + colNeighbors[i],
        isSubIsland);
}

int countSubIslands(std::vector<std::vector<int>> &grid1,
                    std::vector<std::vector<int>> &grid2) {

  bool isSubIsland{true};
  int islandsCounter{};
  std::vector<std::vector<int>> visited{grid2}; // !visited == 1

  for (int i = 0; i < (int)grid2.size(); ++i)
    for (int j = 0; j < (int)grid2[i].size(); ++j) {
      isSubIsland = true;
      if (grid2[i][j] && visited[i][j] != -1) {
        dfs(grid1, grid2, visited, i, j, isSubIsland);
        if (isSubIsland)
          ++islandsCounter;
      }
    }
  return islandsCounter;
}
int main(int argc, char *argv[]) {

  std::vector<std::vector<int>> grid1{

  };
  std::vector<std::vector<int>> grid2{};

  grid1 = {{1, 1, 1, 1, 0, 0}, {1, 1, 0, 1, 0, 0}, {1, 0, 0, 1, 1, 1},
           {1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0}, {1, 0, 1, 0, 1, 0},
           {0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 1, 0},
           {1, 1, 1, 1, 1, 0}};

  grid2 = {{1, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}, {1, 1, 1, 1, 1, 1},
           {0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 1},
           {1, 1, 0, 1, 1, 1}, {1, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1},
           {1, 0, 0, 1, 0, 0}};
  std::cout << countSubIslands(grid1, grid2);
  return 0;
}
