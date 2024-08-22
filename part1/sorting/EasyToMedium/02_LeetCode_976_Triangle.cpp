#include <algorithm>
#include <iostream>
#include <vector>
int largestPerimeter(std::vector<int> &nums) { // O(n + n log n) --> n log n
  int numsSize{(int)nums.size()};

  std::sort(nums.begin(), nums.end(), std::greater<>()); // O(n log n)
  // A triangle be a valid one:
  // عندما يكون مجموع اي ضلعين اكبر من الثالث

  for (int i = 0; i < numsSize - 2; ++i) { // O(n)
    if (nums[i] < (nums[i + 1] + nums[i + 2]))
      return nums[i] + nums[i + 1] + nums[i + 2];
  }
  return 0;
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{1, 2, 1, 10};
  std::cout << largestPerimeter(vec) << '\n';

  return 0;
}
