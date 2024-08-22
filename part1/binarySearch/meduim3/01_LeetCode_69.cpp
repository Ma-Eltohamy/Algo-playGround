#include <cmath>
#include <iostream>

long getSqrt(double curNum) { return (long)curNum * curNum; }
int mySqrt(int x) {
  if (x == 0)
    return 0;

  double start{0}, end{(double)x + 1}, EPS{1e-9};
  while (std::fabs(end - start) > EPS) {
    double mid{start + (end - start) / 2};

    if (getSqrt(mid) > x)
      end = mid;
    else
      start = mid;
  }
  return start;
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 11; ++i)
    std::cout << mySqrt(i) << ' ';
  std::cout << '\n';
  std::cout << mySqrt(2147395599) << ' ';
  return 0;
}
