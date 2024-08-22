#include <climits>
#include <iostream>
#include <vector>

void countSort(std::vector<std::string> &vec) {
  int const MAX_CHARS{26};
  std::vector<std::vector<std::string>> freq(MAX_CHARS + 1);

  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    freq[vec[i][0] - 'a'].push_back(vec[i]);

  int idx{};
  for (int i = 0; i < MAX_CHARS + 1; ++i)
    for (int j = 0; j < (int)freq[i].size(); ++j)
      vec[idx] = freq[i][j], ++idx;
}

void print(std::vector<std::string> &vec) {
  int vecSize{(int)vec.size()};

  for (int i = 0; i < vecSize; ++i)
    std::cout << vec[i] << ' ';
  std::cout << '\n';
}

int main(int argc, char *argv[]) {
  std::vector<std::string> vec{"ziad", "belal", "adam", "baheir", "ali"};
  print(vec);
  countSort(vec);
  print(vec);
  return 0;
}
