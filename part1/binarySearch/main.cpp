#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &vec, int target) {
  int start{}, end{(int)vec.size() - 1};

  while (start <= end) {
    int mid{(start + end) / 2};

    if (target == vec[mid])
      return mid;

    if (target > vec[mid])
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

int findFirst(const std::vector<int> &nums, int target) {
  int start{}, end{(int)nums.size()};
  int mid{}, position{-1};

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (target == nums[mid]) {
      position = mid;
      end = mid - 1;
    }

    else if (target > nums[mid])
      start = mid + 1;

    else
      end = mid - 1;
  }

  return position;
}

int findLast(const std::vector<int> &nums, int target) {
  int start{}, end{(int)nums.size()};
  int mid{}, position{-1};

  while (start <= end) {
    mid = start + (end - start) / 2;

    if (target == nums[mid]) {
      position = mid;
      start = mid + 1;
    }

    else if (target > nums[mid])
      start = mid + 1;

    else
      end = mid - 1;
  }

  return position;
}
std::vector<int> searchRange(std::vector<int> &nums, int target) {
  int numsSize{(int)nums.size()};

  if (!numsSize)
    return std::vector<int>{-1, -1};

  std::vector<int>::iterator lowerIt{
      std::lower_bound(nums.begin(), nums.end(), target)};

  std::vector<int>::iterator upperIt{
      std::upper_bound(nums.begin(), nums.end(), target)};

  if (lowerIt != nums.end()) {
    int firstIdx = lowerIt - nums.begin();
    int lastIdx = upperIt - nums.begin() - 1;
    return std::vector<int>{firstIdx, lastIdx};
  }
  return nums;
}

double funct(double x) {
  return 4 * std::pow(x, 7) + 3 * std::pow(x, 5) - 1000;
}
int main(int argc, char *argv[]) {
  // std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  // std::cout << binarySearch(vec, 14) << '\n';
  //
  // std::vector<int> maxVec(INT_MAX, 2);
  // std::cout << binarySearch(maxVec, 2) << '\n';

  // std::vector<int> v{-5, -14, -2, -10, 0, 2, 2, 2, 3, 4, 9, 17, 17, 17, 20};
  // std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), 17);
  //
  // if (it != v.end()) {
  //   std::cout << "First element >= 17 " << *it << '\n';
  //   std::cout << "\tIndex: " << it - v.begin() << '\n';
  // }
  //
  // it = std::upper_bound(v.begin(), v.end(), 17);
  // if (it != v.end())
  //   std::cout << "First element > 17 " << *it << '\n';
  //
  // it = std::upper_bound(v.begin(), v.end(), 20);
  // if (it == v.end())
  //   std::cout << "20 doesn't exist\n";
  //
  // int idx = it - v.begin();
  //
  // auto p = std::equal_range(v.begin(), v.end(), 17);
  // std::cout << p.first - v.begin() << ' ' << p.second - v.begin() << '\n';
  //
  // it = std::lower_bound(v.begin(), v.end(),
  //                       *std::max_element(v.begin(), v.end()));
  //
  // while (*it > 0) {
  //   it = std::lower_bound(v.begin(), v.end(), --*it);
  // }
  //
  // std::cout << "First Positive int in array is: " << *it << '\n';

  return 0;
}
