#include <climits>
#include <iostream>
#include <vector>

int const MAX_CHARS{26};
int const MAX_DICT{MAX_CHARS * MAX_CHARS};

int getStringIdx(const std::string &str) {
  return (str[0] - 'a') * MAX_CHARS + (str[1] - 'a');
}

void countSort(std::vector<std::string> &vec) {
  std::vector<std::vector<std::string>> freq(MAX_DICT + 1);

  int vecSize{(int)vec.size()};
  for (int i = 0; i < vecSize; ++i)
    freq[getStringIdx(vec[i])].push_back(vec[i]);

  int idx{};
  for (int i = 0; i < MAX_DICT + 1; ++i)
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
  std::vector<std::string> vec{"axz", "axa", "zzz", "abc", "abe"};
  print(vec);
  countSort(vec);
  print(vec);
  return 0;
}
