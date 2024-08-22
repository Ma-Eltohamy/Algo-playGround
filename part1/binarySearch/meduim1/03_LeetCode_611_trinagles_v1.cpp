#include <algorithm>
#include <iostream>
#include <vector>

int triangleNumber(std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  if (numsSize <= 2)
    return 0;

  std::sort(nums.begin(), nums.end());

  int validTriangles{};
  for (int i = numsSize - 1; i > 1; --i) {
    for (int j = i - 1; j > 0; --j) {
      auto it = std::upper_bound(nums.begin(), nums.end(), nums[i] - nums[j]);
      int targetIdx = it - nums.begin();
      if (targetIdx < j)
        validTriangles += j - targetIdx;
    }
  }

  return validTriangles;
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{2, 2, 3, 4};
  std::cout << triangleNumber(vec) << '\n';
  return 0;
}
