#include <iostream>
#include <vector>

std::vector<int> nums{100, 10, 20, 30, 40, 50, 60, 70};
std::vector<std::vector<int>> mem((int)nums.size(),
                                  std::vector<int>((int)nums.size(), -1));

int lis(int idx, int prev) {
  if (idx == (int)nums.size())
    return 0;

  if (prev != -1 && mem[idx][prev] != -1)
    return mem[idx][prev];

  int pick{};
  if (prev == -1 || nums[idx] > nums[prev])
    pick = lis(idx + 1, idx) + 1;
  int leave = lis(idx + 1, prev);

  if (prev != -1)
    return mem[idx][prev] = std::max(pick, leave);
  return std::max(pick, leave);
}

int main(int argc, char *argv[]) {
  std::cout << lis(0, -1) << '\n';
  return 0;
}
