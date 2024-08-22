#include <iostream>
#include <vector>

// std::string str1{"abcd"}; // 2
// std::string str2{"hxbd"};

// std::string str1{"abazdc"}; // 4
// std::string str2{"bacbadz"};

// std::string str1{"cbdadcbda"}; // 5
// std::string str2{"babcbd"};

std::string str1{"bcda"}; // 4
std::string str2{"abcdasyz"};

std::vector<std::vector<int>> mem((int)str1.size(),
                                  std::vector<int>((int)str2.size(), -1));

int lcs(int idx1, int idx2) {
  if (idx1 == (int)str1.size() || idx2 == (int)str2.size())
    return 0;

  if (mem[idx1][idx2] != -1)
    return mem[idx1][idx2];

  int pick{};
  if (str1[idx1] == str2[idx2])
    return mem[idx1][idx2] = lcs(idx1 + 1, idx2 + 1) + 1;

  int keepFirst = lcs(idx1, idx2 + 1); // why adding + pick  here is wrong
  // (because here we're just keeping a char not picking it)
  int keepSecond = lcs(idx1 + 1, idx2); // why adding + pick here is wrong

  return mem[idx1][idx2] = std::max(keepFirst, keepSecond);
}

int main(int argc, char *argv[]) {
  std::cout << lcs(0, 0) << '\n';
  return 0;
}
