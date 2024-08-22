#include <algorithm>
#include <iostream>
#include <vector>

void wiggleSort(std::vector<int> &nums) {
  std::sort(nums.begin(), nums.end()); // O(n log n)
  std::vector<int> res{};
  int numsSize{(int)nums.size()};

  int i{(numsSize - 1) / 2}, j{numsSize - 1};

  while (i >= 0) { // O(n / 2)
    res.push_back(nums[i]);
    res.push_back(nums[j]);
    --i, --j;
  }

  nums = res; // O(n)
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{1, 1, 2, 1, 2, 2, 1};
  wiggleSort(vec);
  return 0;
}
