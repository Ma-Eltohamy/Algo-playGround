#include <iostream>
#include <queue>
#include <vector>

bool isValid(std::vector<int> &arr, std::vector<bool> &visited,
             std::queue<int> &q, int idx) {
  bool validIdx{idx >= 0 && idx < (int)arr.size()};

  if (validIdx && !visited[idx]) {
    if (arr[idx] == 0)
      return true;

    q.push(idx), visited[idx] = true;
  }

  return false;
}

bool bfs(std::vector<int> &arr, int start) {
  std::queue<int> q;
  std::vector<bool> visited((int)arr.size());

  q.push(start);
  visited[start] = true;

  int curIdx{start};
  int postIdx{};
  int preIdx{};

  while (!q.empty()) {
    curIdx = q.front();
    q.pop();

    postIdx = curIdx + arr[curIdx];
    preIdx = curIdx - arr[curIdx];

    if (isValid(arr, visited, q, postIdx))
      return true;

    if (isValid(arr, visited, q, preIdx))
      return true;
  }

  return false;
}

bool canReach(std::vector<int> &arr, int start) {
  if (arr[start] == 0)
    return true;
  return bfs(arr, start);
}
int main(int argc, char *argv[]) {
  std::vector<int> arr{0, 1};
  std::cout << canReach(arr, 1) << '\n';
  return 0;
}
