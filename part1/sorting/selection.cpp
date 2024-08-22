#include <iostream>
#include <utility>
#include <vector>

void print(std::vector<int> &v) {
  int vSize{(int)v.size()};
  for (int i = 0; i < vSize; ++i)
    std::cout << v[i] << ' ';
  std::cout << '\n';
}

void selectionSort(std::vector<int> &v) {
  int vSize{(int)v.size()};
  for (int i = 0; i < vSize; ++i) {
    int minIdx{i};
    for (int j = i + 1; j < vSize; ++j)
      if (v[j] < v[minIdx])
        minIdx = j;
    std::swap(v[i], v[minIdx]);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> v{9, 85, 10, 0, 5, 3, 90, 2};
  print(v);
  selectionSort(v);
  print(v);
  return 0;
}
