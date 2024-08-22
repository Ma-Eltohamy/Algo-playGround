#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> findRightInterval(std::vector<std::vector<int>> &intervals) {
  int intervalsSize{(int)intervals.size()};

  for (int i = 0; i < intervalsSize; ++i)
    intervals[i].push_back(i);

  std::sort(intervals.begin(), intervals.end());

  std::vector<int> res(intervalsSize, -1);

  for (int i = 0; i < intervalsSize; ++i) {
    std::vector<int> target{intervals[i][1], intervals[i][2]};
    auto it = std::lower_bound(intervals.begin(), intervals.end(), target);
    if (it != intervals.end())
      res[intervals[i][2]] = intervals[it - intervals.begin()][2];
  }

  return res;
}

void print(const std::vector<int> &vec) {
  for (int i = 0; i < vec.size(); ++i)
    std::cout << vec[i] << ' ';

  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> vec{{1, 4}, {2, 3}, {3, 4}};
  print(findRightInterval(vec));

  return 0;
}
