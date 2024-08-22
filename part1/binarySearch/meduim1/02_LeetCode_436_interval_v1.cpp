#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

// int binarySearch(const std::vector<std::vector<int>> &intervals, int target)
// {
//   int start{}, end{(int)intervals.size() - 1};
//   int pos{-1}, mid{-1};
//
//   while (start <= end) {
//     mid = start + (end - start) / 2;
//
//     if (target == intervals[mid][0])
//       return mid;
//
//     if (target < intervals[mid][0])
//       pos = mid, end = mid - 1;
//     else
//       start = mid + 1;
//   }
//   return pos;
// }
//
// std::vector<int> findRightInterval(std::vector<std::vector<int>> &intervals)
// {
//   int intervalsSize{(int)intervals.size()};
//
//   // because we want to keep the old order so push idx for every element
//   before
//   // sorting
//   for (int i = 0; i < intervalsSize; ++i)
//     intervals[i].push_back(i);
//
//   // they will be sorted depending of the first
//   // element which is start(the uniqe value)
//   std::sort(intervals.begin(), intervals.end());
//
//   std::vector<int> res(intervalsSize, -1);
//
//   for (int i = 0; i < intervalsSize; ++i) {
//     int rightIntervalIdx{binarySearch(intervals, intervals[i][1])};
//     if (rightIntervalIdx != -1)
//       res[intervals[i][2]] = intervals[rightIntervalIdx][2];
//   }
//
//   return res;
// }
int binarySearch(const std::vector<std::vector<int>> &intervals, int target) {
  int start{}, end{(int)intervals.size()};
  int lastPosition{-1};

  while (start <= end) {
    int mid{start + (end - start) / 2};

    if (intervals[mid][0] >= target)
      lastPosition = mid, end = mid - 1;
    else
      start = mid + 1;
  }

  return lastPosition;
}

std::vector<int> findRightInterval(std::vector<std::vector<int>> &intervals) {
  int intervalsSize{(int)intervals.size()};

  for (int i = 0; i < intervalsSize; ++i)
    intervals[i].push_back(i);

  std::vector<int> res(intervalsSize, -1);

  std::sort(intervals.begin(), intervals.end());
  for (int i = 0; i < intervalsSize; ++i) {
    int idx{binarySearch(intervals, intervals[i][1])};
    if (idx != -1)
      res[intervals[i][2]] = intervals[idx][2];
  }
  return res;
}

void print(const std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  for (int i = 0; i < numsSize; ++i)
    std::cout << nums[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  // std::vector<std::vector<int>> vec{{1, 2}};
  std::vector<std::vector<int>> vec{{3, 4}, {2, 3}, {1, 2}};
  // std::vector<std::vector<int>> vec{{1, 4}, {2, 3}, {3, 4}};

  print(findRightInterval(vec));
  return 0;
}
