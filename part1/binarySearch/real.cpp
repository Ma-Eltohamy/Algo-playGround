#include <cmath>
#include <iostream>

double mathfunc(double x) {
  return 4 * std::pow(x, 7) + 3 * std::pow(x, 5) - 1000;
}

// double realBinarySearch(double EPS = 1e-9) {
//   double start{0.0}, end{3};
//   double mid{start + (end - start) / 2};
//
//   while (end - start > EPS) {
//     mid = start + (end - start) / 2;
//
//     if (mathfunc(mid) > 3.0)
//       end = mid;
//     else
//       start = mid;
//   }
//   return start;
// }

bool realBinarySearch(double target, double EPS = 1e-9) {
  double start{0}, end = {1};

  while (std::fabs(end - start > EPS)) {
    double mid{start + (end - start) / 2};

    // if (mid == target)
    if (std::fabs(mid - target) <= 1e-9)
      return true;

    if (mid > target)
      end = mid;
    else
      start = mid;
  }

  return false;
}
int main(int argc, char *argv[]) {
  std::cout << realBinarySearch(0.8685191) << '\n';
  // std::cout << realBinarySearch() << '\n';
  // std::cout << mathfunc(2.15507) << '\n';
  // std::cout << mathfunc(2.15411) << '\n';
  // std::cout << fabs(-2.15411) << '\n';
  return 0;
}
