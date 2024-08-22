#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

int eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed) {
  std::vector<int> res{};
  int monstersNumber{(int)dist.size()};
  for (int i = 0; i < monstersNumber; ++i)
    res.push_back(ceil((double)dist[i] / speed[i]));

  std::sort(res.begin(), res.end());

  int counter{1};
  for (int i = 1; i < monstersNumber; ++i) {
    if (res[i] - i <= 0)
      break;
    ++counter;
  }
  return counter;
}

void print(const std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}
int main(int argc, char *argv[]) { return 0; }
