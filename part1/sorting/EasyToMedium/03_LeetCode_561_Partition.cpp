#include <algorithm>
#include <iostream>
#include <vector>
int arrayPairSum(std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  std::sort(nums.begin(), nums.end());

  int res{};
  for (int i = 0; i < numsSize; i += 2)
    res += nums[i];
  return res;
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{6, 2, 6, 5, 1, 2};
  std::cout << arrayPairSum(vec) << '\n';

  return 0;
}
