#include <iostream>
#include <utility>
#include <vector>

void insertionSort(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 1; i < vecSize; ++i)
    for (int j = i; j > 0 && vec[j] >= vec[j - 1]; --j) {
      std::swap(vec[j], vec[j - 1]);
    }
}

void print(const std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vec.size(); ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{9, 2, 10, 0, 5, 3, 90, 85};
  print(vec);
  insertionSort(vec);
  print(vec);
  return 0;
}
