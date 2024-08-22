#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

bool isPossible(int n, int k) { return n >= (k * (k + 1)) / 2; }
int arrangeCoins(int n) {
  int start{1}, end{n};
  int lastRow{0};

  while (start <= end) {
    int mid{start + (end - start) / 2};

    // if(returned True)
    // then i should search on my right side
    if (isPossible(n, mid))
      lastRow = mid, start = mid + 1;

    // Not completed row then search on your left side
    else
      end = mid - 1;
  }
  return lastRow;
}
void print(const std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  for (int i = 0; i < numsSize; ++i)
    std::cout << nums[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 12; ++i)
    std::cout << arrangeCoins(i) << ' ';
  std::cout << '\n';
  return 0;
}
