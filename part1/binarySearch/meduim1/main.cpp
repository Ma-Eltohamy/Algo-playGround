#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

// int triangleNumber(std::vector<int> &nums) {
//   int validTriangles{};
//   int numsSize{(int)nums.size()};
//
//   // {2, 2, 3, 4}
//   std::sort(nums.begin(), nums.end());
//
//   for (int i = numsSize - 1; i >= 0; --i) {
//     for (int j = i - 1; j >= 0; --j) {
//       // So if we sort the nums then tried to found the lower bound. When all
//       // after this bound become only true values to the end then we just
//       need
//       // to subtract it from the lower bound if it's exist
//       int lowerBound{-1};
//       int start{0}, end{j - 1};
//       while (start <= end) {
//         int mid{start + (end - start) / 2};
//
//         if (nums[j] + nums[mid] > nums[i])
//           lowerBound = mid, end = mid - 1;
//
//         else
//           start = mid + 1;
//       }
//       if (lowerBound != -1)
//         validTriangles += (j - lowerBound);
//     }
//   }
//   return validTriangles;
// }

int triangleNumber(std::vector<int> &nums) {
  int validTriangles{};
  int numsSize{(int)nums.size()};

  // {2, 2, 3, 4}
  std::sort(nums.begin(), nums.end());

  for (int i = numsSize - 1; i >= 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      int lowerBound{-1};
      int start{0}, end{j - 1};
      while (start <= end) {
        int mid{start + (end - start) / 2};

        if (nums[j] + nums[mid] > nums[i])
          lowerBound = mid, end = mid - 1;

        else
          start = mid + 1;
      }
      if (lowerBound != -1)
        validTriangles += (j - lowerBound);
    }
  }
  return validTriangles;
}

// int triangleNumber(std::vector<int> &nums) { // O(log n + n^3)
//   int validTriangles{};
//   int numsSize{(int)nums.size()};
//
//   // {2, 2, 3, 4}
//   std::sort(nums.begin(), nums.end());
//
//   for (int i = numsSize - 1; i >= 0; --i) {
//     for (int j = i - 1; j >= 0; --j) {
//       for (int k = j - 1; k >= 0; --k) {
//       // just check if the smallest two sides are smaller than the bigest
//       side
//       // بكل اختصار شوف لو اضغر ضلعين اصغر من اكبر ضلع اذن 100 بالميه هذا
//       مثلث صحيح
//         if (nums[k] + nums[j] > nums[i])
//           ++validTriangles;
//       }
//     }
//   }
//   return validTriangles;
// }

// int triangleNumber(std::vector<int> &nums) { // O(n^3) of all times
//   // This is a valid solution but exceding the time limit
//   int validTriangles{};
//   int numsSize{(int)nums.size()};
//
//   // Solving the problem without sorting them
//   for (int i = numsSize - 1; i >= 0; --i) {
//     for (int j = i - 1; j >= 0; --j) {
//       for (int k = j - 1; k >= 0; --k) {
//         if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] &&
//             nums[j] + nums[k] > nums[i])
//           ++validTriangles;
//       }
//     }
//   }
//   return validTriangles;
// }

void print(const std::vector<int> &nums) {
  int numsSize{(int)nums.size()};

  for (int i = 0; i < numsSize; ++i)
    std::cout << nums[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{2, 2, 3, 4};
  std::cout << triangleNumber(nums) << '\n';
  return 0;
}
