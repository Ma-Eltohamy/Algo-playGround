#include <iostream>
#include <utility>
#include <vector>

void print(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

// void insertionSort(std::vector<int> &vec) {
//   int vecSize{(int)vec.size()};
//   for (int i = 0; i < vecSize; ++i) {
//
//     int j{i};
//     while (j > 0 && vec[j] <= vec[j - 1]) {
//       std::swap(vec[j], vec[j - 1]);
//       --j;
//     }
//   }
// }

void insertionSort(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i) {
    // Enhancement (just shfit other elements without swaping)
    int j{i};
    int tmp{vec[j]};
    while (j > 0 && tmp <= vec[j - 1]) {
      vec[j] = vec[j - 1];
      --j;
    }
    vec[j] = tmp;
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{9, 2, 10, 0, 5, 3, 90, 85};
  print(vec);
  insertionSort(vec);
  print(vec);
  return 0;
}
