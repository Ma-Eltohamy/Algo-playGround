#include <cassert>
#include <iostream>
#include <vector>

int findFirstPosition(const std::vector<int> &nums, int target) {
  int start{}, end{(int)nums.size() - 1};
  int firstPostion{-1};

  while (start <= end) {
    int mid{start + (end - start) / 2};

    if (target == nums[mid])
      firstPostion = mid, end = mid - 1;

    else if (target > nums[mid])
      start = mid + 1;
    else
      end = mid - 1;
  }

  return firstPostion;
}

int findLastPosition(const std::vector<int> &nums, int target) {
  int start{}, end{(int)nums.size() - 1};
  int lastPosition{-1};

  while (start <= end) {
    int mid{start + (end - start) / 2};

    if (target == nums[mid])
      lastPosition = mid, start = mid + 1;

    if (target > nums[mid])
      start = mid + 1;
    else
      end = mid - 1;
  }

  return lastPosition;
}

std::vector<int> searchRange(const std::vector<int> &nums, int target) {
  if ((int)nums.size() == 0)
    return std::vector<int>{-1, -1};
  return std::vector<int>{findFirstPosition(nums, target),
                          findLastPosition(nums, target)};
}

void print(const std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  for (int i = 0; i < numsSize; ++i)
    std::cout << nums[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{2, 2};

  print(searchRange(vec, 3));
  return 0;
}
