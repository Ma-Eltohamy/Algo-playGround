#include <iostream>
#include <queue>
#include <vector>

struct cell {
  int r{};
  int c{};
};

bool isValid(std::vector<std::vector<int>> &matrix, int r, int c) {
  return r >= 0 && r < (int)matrix.size() && c >= 0 &&
         c < (int)matrix[0].size();
}

void bfs(std::vector<std::vector<int>> &heights,
         std::vector<std::vector<bool>> &ocean, std::queue<cell> &q) {

  cell curNode{q.front()};
  while (!q.empty()) {
    curNode = q.front();
    q.pop();

    int rdir[4]{-1, 0, 1, 0};
    int cdir[4]{0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
      if (!isValid(heights, curNode.r + rdir[i], curNode.c + cdir[i]) ||
          ocean[curNode.r + rdir[i]][curNode.c + cdir[i]] ||
          heights[curNode.r][curNode.c] >
              heights[curNode.r + rdir[i]][curNode.c + cdir[i]])
        continue;

      q.push({curNode.r + rdir[i], curNode.c + cdir[i]}),
          ocean[curNode.r + rdir[i]][curNode.c + cdir[i]] = true;
    }
  }
}

std::vector<std::vector<int>>
pacificAtlantic(std::vector<std::vector<int>> &heights) {
  int rows{(int)heights.size()};
  int cols{(int)heights[0].size()};

  std::vector<std::vector<bool>> isPacific(rows, std::vector<bool>(cols));
  std::vector<std::vector<bool>> isAtlantic(rows, std::vector<bool>(cols));

  std::queue<cell> q;
  for (int i = 0; i < cols; ++i) {
    isPacific[0][i] = true, q.push({0, i});
    isPacific[i][0] = true, q.push({i, 0});
  }
  bfs(heights, isPacific, q);

  for (int i = 0; i < rows; ++i) {
    isAtlantic[i][rows - 1] = true, q.push({i, rows - 1});
    isAtlantic[cols - 1][i] = true, q.push({cols - 1, i});
  }
  bfs(heights, isAtlantic, q);

  std::vector<std::vector<int>> result;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (isPacific[i][j] && isAtlantic[i][j])
        result.push_back({i, j});

  return result;
}

void print(std::vector<std::vector<int>> const &matrix) {
  for (int i = 0; i < (int)matrix.size(); ++i) {
    for (int j = 0; j < (int)matrix[i].size(); ++j)
      std::cout << matrix[i][j] << ' ';
    std::cout << '\n';
  }
}
int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> lands{{1, 1}, {1, 1}, {1, 1}};

  print(pacificAtlantic(lands));
  return 0;
}
