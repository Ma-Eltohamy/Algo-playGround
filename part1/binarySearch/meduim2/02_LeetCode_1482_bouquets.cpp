#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool isPossible(const std::vector<int> &bloomDay, int m, int k, int curDay) {
  int bloomDaySize{(int)bloomDay.size()};
  int flowersInBouquet{k};

  for (int i = 0; i < bloomDaySize && m > 0; ++i) {
    if (bloomDay[i] > curDay)
      flowersInBouquet = k;
    else {
      --flowersInBouquet;
      if (!flowersInBouquet)
        --m, flowersInBouquet = k;
    }
  }

  if (!m)
    return true;
  return false;
}

int minDays(std::vector<int> &bloomDay, int m, int k) {
  int bloomDaySize{(int)bloomDay.size()};

  if (m * k > bloomDaySize)
    return -1;

  int minDays{*std::min_element(bloomDay.begin(), bloomDay.end())};
  int maxDays{*std::max_element(bloomDay.begin(), bloomDay.end())};
  int diliveryDay{-1};

  while (minDays <= maxDays) {
    int mid{minDays + (maxDays - minDays) / 2};

    if (isPossible(bloomDay, m, k, mid))
      maxDays = mid - 1, diliveryDay = mid;
    else
      minDays = mid + 1;
  }

  return diliveryDay;
}
int main(int argc, char *argv[]) {
  std::vector<int> vec{7, 7, 7, 7, 12, 7, 7};
  std::cout << minDays(vec, 2, 3);
  return 0;
}
