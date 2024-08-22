#include <algorithm>
#include <iostream>
#include <vector>

int findUnsortedSubarray(std::vector<int> &nums) {
  std::vector<int> sorted{nums};
  std::sort(sorted.begin(), sorted.end());
  int numsSize{(int)nums.size()};

  int start{-1}, end{-1};
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] != sorted[i]) {
      if (start == -1)
        start = i;
      else
        end = i;
    }
  }
  if (start == -1)
    return 0;
  return end - start + 1;
}
