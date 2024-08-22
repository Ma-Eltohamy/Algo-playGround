#include <iostream>
#include <vector>

int lis(std::vector<int> &mem, std::vector<int> &nums, int idx) {
  if (idx == (int)nums.size())
    return 0;

  if (mem[idx] != -1)
    return mem[idx];

  int pick{1};
  for (int i = idx + 1; i < (int)nums.size(); ++i)
    if (nums[i] > nums[idx])
      pick = std::max(lis(mem, nums, i) + 1, pick);

  return mem[idx] = pick;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  // std::vector<int> nums{7, 1, 5, 6, 8};
  std::vector<int> mem((int)nums.size(), -1);
  int max{};
  for (int i = 0; i < (int)nums.size(); ++i)
    max = std::max(lis(mem, nums, i), max);
  std::cout << max << '\n';
  return 0;
}
