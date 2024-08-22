#include <iostream>

// std::string str1{"abcd"}; // 2
// std::string str2{"hxbd"};

// std::string str1{"abazdc"}; // 4
// std::string str2{"bacbadz"};

std::string str1{"cbdadcbda"}; // 5
std::string str2{"babcbd"};

// std::string str1{"bcda"}; // 4
// std::string str2{"abcdasyz"};

int lcs(int idx1, int idx2) {
  if (idx1 == (int)str1.size() || idx2 == (int)str2.size())
    return 0;

  int pick{}, choice2{}, choice3{}, leaveAll{};

  if (str1[idx1] == str2[idx2])
    pick = lcs(idx1 + 1, idx2 + 1) + 1;

  choice2 = lcs(idx1, idx2 + 1);
  choice3 = lcs(idx1 + 1, idx2);

  leaveAll = lcs(idx1 + 1, idx2 + 1);

  return std::max(std::max(pick, choice2), std::max(choice3, leaveAll));
}

int main(int argc, char *argv[]) {
  std::cout << lcs(0, 0) << '\n';
  return 0;
}
