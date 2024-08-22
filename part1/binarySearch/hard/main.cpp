#include <cassert>
#include <iostream>
#include <vector>

int missingElementFromTo(std::vector<int> &nums, int start, int end) {
  return (nums[end] - nums[start]) - (end - start);
}

int missingElement(std::vector<int> &nums, int k) {
  int numsSize{(int)nums.size()};
  if (k < 1 || numsSize < 2)
    return -1;

  int start{0}, end{numsSize - 1};
  int kMissingElements{missingElementFromTo(nums, start, end)};

  if (kMissingElements < k)
    return nums[end] + (k - kMissingElements);

  int mid{-1};
  while (start + 1 != end) {
    mid = start + (end - start) / 2;
    kMissingElements = missingElementFromTo(nums, start, mid);

    if (kMissingElements >= k) // Go left
      end = mid;
    else // Go right and subtract from k
      start = mid, k -= kMissingElements;
  }
  return nums[start] + k;
}

void testKthMissingElements() {
  std::vector<int> vec{};
  assert(missingElement(vec, 14) == -1);

  vec = {1};
  assert(missingElement(vec, 14) == -1);

  vec = {1, 2};
  assert(missingElement(vec, 14) == 16);

  vec = {1, 3};
  assert(missingElement(vec, 1) == 2);

  vec = {1, 2, 4};
  assert(missingElement(vec, 3) == 6);

  vec = {4, 7, 9, 10};
  assert(missingElement(vec, 3) == 8);

  vec = {1, 2, 7, 8, 10, 11, 19, 20, 21, 22};
  assert(missingElement(vec, 4) == 6);

  vec = {1, 2, 7, 10, 11, 12, 19, 20, 21, 22};
  assert(missingElement(vec, 6) == 9);

  vec = {1, 3, 7, 8, 10, 11, 19, 20, 21, 22};
  assert(missingElement(vec, 1) == 2);
}
int main(int argc, char *argv[]) {
  testKthMissingElements();
  std::cout << "bye" << '\n';
  return 0;
}
