#include <iostream>
#include <vector>

long long _fib(int n, std::vector<long long> &res) {
  if (n <= 1)
    return 1;

  if (res[n] == -1) {
    res[n] = _fib(n - 1, res) + _fib(n - 2, res);
    return res[n];
  }
  return res[n];
}

long long fib(int n) {
  std::vector<long long> res(n + 1, -1);
  return _fib(n, res);
}

long long iterativeFib(int n) {
  long long n_1 = 0;
  long long n_2 = 1;
  long long cur;
  for (int i = 0; i <= n; ++i) {
    cur = n_1 + n_2;
    n_2 = n_1;
    n_1 = cur;
  }

  return cur;
}

int main(int argc, char *argv[]) {
  std::cout << fib(80) << '\n';
  std::cout << iterativeFib(80) << '\n';
  return 0;
}
