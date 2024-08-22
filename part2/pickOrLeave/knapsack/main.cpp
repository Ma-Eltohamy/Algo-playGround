#include <iostream>
#include <vector>

std::vector<int> w{10, 4, 6, 5, 1};
std::vector<int> v{10, 15, 2, 8, 2};

std::vector<std::vector<int>> arr(5, std::vector<int>(22, -1));

int knapsack(int idx, int remainingWeight) {
  if (idx == (int)w.size() || remainingWeight <= 0)
    return 0;

  if (arr[idx][remainingWeight] != -1)
    return arr[idx][remainingWeight];

  int pick = v[idx] + knapsack(idx + 1, remainingWeight - w[idx]);
  int leave = knapsack(idx + 1, remainingWeight);

  return arr[idx][remainingWeight] = std::max(pick, leave);
}

int main(int argc, char *argv[]) {
  std::cout << knapsack(0, 21) << '\n';
  return 0;
}
