#include <iostream>

// std::string s1{"abazdc"};
// std::string s2{"bacbadz"};

std::string s1{"cbdadcbda"};
std::string s2{"babcbd"};

// std::string s1{"bcda"};
// std::string s2{"abcdasyz"};
int lcs(int idx1, int idx2) {
  if (idx1 >= (int)s1.size() || idx2 >= (int)s2.size())
    return 0;

  int pick{};
  for (int j = idx1)
    for (int i = idx2; i < (int)s2.size(); ++i)
      if (s1[idx1] == s2[i])
        pick = std::max(lcs(idx1 + 1, i + 1) + 1, pick);

  return pick;
}

int main(int argc, char *argv[]) {
  std::cout << lcs(0, 0) << '\n';
  return 0;
}
