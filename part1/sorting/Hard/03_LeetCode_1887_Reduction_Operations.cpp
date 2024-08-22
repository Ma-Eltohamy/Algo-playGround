#include <algorithm>
#include <vector>
int reductionOperations(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end(), std::greater<>());
  int numsSize{(int)nums.size()};

  int largest{nums[0]};
  int operations{};
  for (int i = 0; i < numsSize - 1; ++i) {
    if (largest > nums[i + 1]) {
      operations += i + 1;
      largest = nums[i + 1];
    }
  }
  return operations;
}
