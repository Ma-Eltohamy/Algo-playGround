#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool isPossible(const std::vector<int> &nums, int threshold, int cur) {
  // It should return if the sum of all divisions are less than or equal
  // to the threshold
  //
  // Then, we need to pass the nums by refrence and also threshold, cur
  //
  // Now, need to get the sum of all divisions through a for loop

  int sum{}, numsSize{(int)nums.size()};
  for (int i = 0; i < numsSize; ++i)
    sum += std::ceil((double)nums[i] / cur);

  return sum <= threshold;
}

int smallestDivisor(std::vector<int> &nums, int threshold) {
  // Here we will implement the binary search algorithm
  // with a spcific range
  // I think best range is min and max value in the array and after doing
  // sorting (n log n) getting the min and max would be O(1);

  // update:
  // // after faling in case 52 i think we should start from number 1
  // //  and we can do it without sorting just using the max value in the nums
  // //  this would make it faster than nlogn every thing would be 1

  int numsSize{(int)nums.size()};

  // start would be min value and end would be max value
  int start{1}, end{*std::max_element(nums.begin(), nums.end())};
  int smallestDivisor{-1};

  while (start <= end) {
    int mid{start + (end - start) / 2};
    if (isPossible(nums, threshold, mid))
      smallestDivisor = mid, end = mid - 1;
    else
      start = mid + 1;
  }

  return smallestDivisor;
}

int main(int argc, char *argv[]) {
  // some operations
  return 0;
}
