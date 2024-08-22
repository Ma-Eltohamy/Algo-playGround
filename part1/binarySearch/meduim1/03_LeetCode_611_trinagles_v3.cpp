#include <algorithm>
#include <iostream>
#include <vector>

int triangleNumber(std::vector<int> &nums) { // O(n^2)
  int count{}, numsSize{(int)nums.size()};
  std::sort(nums.begin(), nums.end());

  for (int i = numsSize - 1; i >= 2; --i) {
    int start{}, end{i - 1};

    while (start < end) {
      if (nums[start] + nums[end] > nums[i])
        count += (end - start), --end;
      else
        ++start;
    }
  }
  return count;
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{2, 2, 3, 4};
  std::cout << triangleNumber(vec) << '\n';
  return 0;
}
