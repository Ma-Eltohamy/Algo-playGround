#include <iostream>
#include <string>
#include <vector>

std::string res = "    "; // 4

void all_subsets(int idx) {
  if (idx == (int)res.size()) {
    std::cout << res << '\n';
    return;
  }

  res[idx] = '0';
  all_subsets(idx + 1);

  res[idx] = '1';
  all_subsets(idx + 1);
}

int main(int argc, char *argv[]) {
  all_subsets(0);
  return 0;
}
