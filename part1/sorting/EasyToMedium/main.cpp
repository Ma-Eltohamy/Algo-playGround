#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

int largestSumAfterKNegations(std::vector<int> &nums, int k) {
  int numsSize{(int)nums.size()}, sum{};

  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < numsSize; ++i) {
    if (k > 0) {
      if (nums[i] == 0)
        k = 0;

      else if (nums[i] < 0) {
        nums[i] *= -1;
        --k;
      } else if (nums[i] > 0) {
        if (k % 2 == 0)
          k = 0;
        else {
          if (i > 0 && nums[i - 1] < nums[i])
            sum += 2 * (-nums[i - 1]);
          else
            nums[i] *= -1;
          --k;
        }
      }
    }
    sum += nums[i];
  }
  return sum;
}

void print(const std::vector<int> &vec) {
  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{-4, -2, -3};
  largestSumAfterKNegations(vec, 4);
  return 0;
}
