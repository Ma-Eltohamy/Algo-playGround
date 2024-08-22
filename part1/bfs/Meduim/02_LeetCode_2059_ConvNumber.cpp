#include <iostream>
#include <queue>
#include <vector>

bool isValid(std::vector<int> &nums, std::vector<bool> &visited, // O(1)
             std::queue<int> &q, int cur, int goal) {
  if (cur == goal) // because goal may be a negative number
    return true;

  bool validRange{0 <= cur && cur <= 1000};
  if (validRange && !visited[cur])
    q.push(cur), visited[cur] = true;

  return false;
}

int minimumOperations(std::vector<int> &nums, int start, int goal) {
  int numsSize{(int)nums.size()};

  if (start == goal)
    return 0;

  std::queue<int> q;
  std::vector<bool> visited(1001); // O(1) space
  q.push(start);
  visited[start] = true;

  int curNode{start};
  int qSize{}, level{};
  int plus{}, mins{}, Xor{};

  while (!q.empty()) { // O(# of operations)
    qSize = q.size();
    ++level;
    while (qSize--) {
      curNode = q.front();
      q.pop();

      for (int i = 0; i < numsSize; ++i) { // O(numsSize)
        plus = curNode + nums[i];
        mins = curNode - nums[i];
        Xor = curNode ^ nums[i];

        if (isValid(nums, visited, q, plus, goal) ||
            isValid(nums, visited, q, mins, goal) ||
            isValid(nums, visited, q, Xor, goal))
          return level;
      }
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums{3, 5, 7};
  std::cout << minimumOperations(nums, 0, -4) << '\n';
  return 0;
}
