#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void wiggleSort(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  // https://www.naukri.com/code360/problems/wiggle-sort_3155169
  // is a valid solution

  for (int i = 0; i < vecSize - 1; ++i) {
    if (i % 2 == 0 && vec[i] <= vec[i + 1]) // even position
      continue;
    else if (i % 2 == 1 && vec[i] >= vec[i + 1]) // odd position
      continue;

    std::swap(vec[i], vec[i + 1]);
  }
}

void print(const std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}
int main(int argc, char *argv[]) {
  // std::vector<int> vec{3, 5, 2, 1, 6, 4};
  std::vector<int> vec{1, 2, 3, 4, 5};
  print(vec);
  wiggleSort(vec);
  print(vec);

  return 0;
}
