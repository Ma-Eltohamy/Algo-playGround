#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr) {
  int arrSize{(int)arr.size()};
  std::sort(arr.begin(), arr.end());

  int minDiff{INT_MAX};
  std::vector<std::vector<int>> res;
  for (int i = 0; i < arrSize - 1; ++i) {
    int currentDiff{arr[i] - arr[i + 1]};
    if (currentDiff < 0)
      currentDiff *= -1;

    if (currentDiff > minDiff)
      continue;

    if (currentDiff < minDiff)
      res.clear(), minDiff = currentDiff;

    res.push_back(std::vector<int>{arr[i], arr[i + 1]});
  }

  return res;
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{4, 2, 1, 3};
  std::vector<std::vector<int>> res{minimumAbsDifference(vec)};

  for (auto &v : res)
    for (auto &n : v)
      std::cout << n << ' ';
  return 0;
}
