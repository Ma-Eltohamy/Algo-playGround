#include <iostream>
#include <vector>

void print(std::vector<int> &v) {
  int vSize{(int)v.size()};
  for (int i = 0; i < vSize; ++i)
    std::cout << v[i] << ' ';
  std::cout << '\n';
}

void countSort(std::vector<int> &v) {
  int vSize{(int)v.size()};
  int max{v[0]};
  for (int i = 0; i < vSize; ++i)
    if (v[i] > max)
      max = v[i];

  std::vector<int> freq(max + 1);

  for (int i = 0; i < vSize; ++i)
    ++freq[v[i]];

  int idx{};
  for (int i = 0; i < max + 1; ++i)
    for (int j = 0; j < freq[i]; ++j)
      v[idx] = i, ++idx;
}

int main(int argc, char *argv[]) {
  std::vector<int> v{9, 3, 10, 9, 5, 3, 90, 9};
  print(v);
  countSort(v);
  print(v);
  return 0;
}
