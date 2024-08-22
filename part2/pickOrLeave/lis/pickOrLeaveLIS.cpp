#include <iostream>
#include <vector>

// std::vector<int> seq{100, 10, 20, 30, 40, 50, 60, 70};
// std::vector<std::vector<int>> mem(8, std::vector<int>(8, -1));

int lis(std::vector<std::vector<int>> &mem, std::vector<int> &nums, int curIdx,
        int prevIdx) {
  if (curIdx == (int)nums.size())
    return 0;

  if (prevIdx != -1 && mem[curIdx][prevIdx] != -1)
    return mem[curIdx][prevIdx];

  int pick{};
  if (prevIdx == -1 || nums[curIdx] > nums[prevIdx])
    pick = lis(mem, nums, curIdx + 1, curIdx) + 1;
  int leave = lis(mem, nums, curIdx + 1, prevIdx);

  if (prevIdx != -1)
    return mem[curIdx][prevIdx] = std::max(pick, leave);
  return std::max(pick, leave);
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  std::vector<std::vector<int>> mem((int)nums.size(),
                                    std::vector<int>((int)nums.size(), -1));
  std::cout << lis(mem, nums, 0, -1) << '\n';
  return 0;
}
