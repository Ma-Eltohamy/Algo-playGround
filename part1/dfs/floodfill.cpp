#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<int>> &image, int sr, int sc) {
  if (sr >= 0 && sr < (int)image.size() && sc >= 0 && sc < (int)image[0].size())
    return true;
  return false;
}

void dfs(std::vector<std::vector<int>> &image, int sr, int sc, int newColor,
         int oldColor) {
  if (!isValid(image, sr, sc) || image[sr][sc] != oldColor)
    return;

  image[sr][sc] = newColor;
  int rowNeighbor[]{-1, 0, 1, 0};
  int colNeighbor[]{0, 1, 0, -1};

  for (int i = 0; i < 4; ++i)
    dfs(image, sr + rowNeighbor[i], sc + colNeighbor[i], newColor, oldColor);
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image,
                                        int sr, int sc, int color) {
  if (!isValid(image, sr, sc) || image[sr][sc] == color)
    return image;

  int oldColor{image[sr][sc]};
  dfs(image, sr, sc, color, oldColor);
  return image;
}

void print(std::vector<std::vector<int>> &image) {
  for (int i = 0; i < (int)image.size(); ++i) {
    for (int j = 0; j < (int)image[0].size(); ++j)
      std::cout << image[i][j] << ' ';
    std::cout << '\n';
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  print(image);
  floodFill(image, 1, 1, 2);
  print(image);
  // some operations
  return 0;
}
