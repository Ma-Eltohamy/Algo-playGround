#include <iostream>
#include <map>
#include <vector>

std::vector<int> findRightInterval(std::vector<std::vector<int>> &intervals) {
  std::map<int, int> mp;
  int intervalsSize{(int)intervals.size()};

  for (int i = 0; i < intervalsSize; ++i)
    mp[intervals[i][0]] = i;

  std::vector<int> res(intervalsSize, -1);

  for (int i = 0; i < intervalsSize; ++i) {
    std::vector<int> target{intervals[i][1], 0};
    auto it = mp.lower_bound(intervals[i][1]);

    if (it != mp.end()) {
      res[mp[intervals[i][2]]] = it->second;
    }
  }
  return res;
}
int main(int argc, char *argv[]) {
  // some operations
  return 0;
}
