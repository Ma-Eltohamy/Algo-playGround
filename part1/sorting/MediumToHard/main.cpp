#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

std::vector<int> countSort(const std::vector<int> &array) {
  // cons
  // 1) takes more memory
  // 2) takes more time
  // pros
  // 1) every number has its right idx -1
  int size = array.size();
  int mxVal = array[0];
  for (int i = 1; i < size; ++i)
    if (array[i] > mxVal)
      mxVal = array[i];

  std::vector<int> count(mxVal + 1);
  for (int i = 0; i < size; ++i)
    count[array[i]] += 1;

  for (int i = 1; i <= mxVal; ++i)
    count[i] += count[i - 1];

  std::vector<int> output(size);
  for (int i = size - 1; i >= 0; --i) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]] -= 1;
  }

  return output;
}

void print(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{5, 13, 2, 10, 9};
  print(vec);
  std::vector<int> cc{countSort(vec)};
  print(cc);
  return 0;
}
