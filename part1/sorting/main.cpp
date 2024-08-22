#include <climits>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

void print(const std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

void insertionSort(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 0; i < vecSize; ++i) {
    int tmp{vec[i]};
    int j{i};

    while (j > 0 && tmp <= vec[j - 1]) {
      vec[j] = vec[j - 1], --j;
    }

    vec[j] = tmp;
  }
}

void selectionSort(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 0; i < vecSize; ++i) {
    int minIdx{i};
    for (int j = i; j < vecSize; ++j)
      if (vec[j] < vec[minIdx])
        minIdx = j;
    std::swap(vec[i], vec[minIdx]);
  }
}

void countSort(std::vector<int> &vec) {

  int min{INT_MAX}, max{INT_MIN};
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    if (vec[i] > max)
      max = vec[i];
    else if (vec[i] < min)
      min = vec[i];

  std::vector<int> freq(++max);

  for (int i = 0; i < vecSize; ++i)
    ++freq[vec[i]];

  int idx{};
  for (int i = 0; i < max; ++i)
    while (freq[i]--)
      vec[idx++] = i;
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{9, 2, 10, 0, 5, 3, 90, 85};
  print(vec);
  // insertionSort(vec);
  // selectionSort(vec);
  countSort(vec);
  print(vec);
  return 0;
}
