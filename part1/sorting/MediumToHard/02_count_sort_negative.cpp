#include <climits>
#include <iostream>
#include <vector>

std::vector<int> sortArray(std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  int min{INT_MAX}, max{INT_MIN};

  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < min)
      min = nums[i];
    if (nums[i] > max)
      max = nums[i];
  }
  std::vector<int> freq(max + -min + 1);

  for (int i = 0; i < numsSize; ++i)
    ++freq[nums[i] + -min];

  int idx{};
  for (int i = 0; i < max + -min + 1; ++i)
    for (int j = 0; j < freq[i]; ++j)
      nums[idx] = i + min, ++idx;

  return nums;
}

void print(std::vector<int> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<int> vec{10000107, 10000035, 10000001};
  print(vec);
  sortArray(vec);
  print(vec);
  return 0;
}
