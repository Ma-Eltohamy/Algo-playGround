#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
bool isPossible(std::vector<int> &houses, std::vector<int> &heaters,
                int radius) {
  int housesSize{(int)houses.size()};
  int heatersSize{(int)heaters.size()};
  int startRange{}, endRange{};
  bool isCurWarmed{};
  int curHouse{};
  int curHeater{};

  while (curHouse < housesSize && curHeater < heatersSize) {
    startRange = heaters[curHeater] - radius;
    endRange = heaters[curHeater] + radius;
    isCurWarmed =
        startRange <= houses[curHouse] && houses[curHouse] <= endRange;
    if (!isCurWarmed) {
      ++curHeater;
    } else
      ++curHouse;
  }
  if (curHouse == housesSize)
    return true;
  return false;
}

int findRadius(std::vector<int> &houses, std::vector<int> &heaters) {
  std::sort(houses.begin(), houses.end());
  std::sort(heaters.begin(), heaters.end());

  int start{},
      end{std::max(houses[houses.size() - 1], heaters[heaters.size() - 1])};
  int smallestRadius{-1};

  while (start <= end) {
    int mid{start + (end - start) / 2};

    if (isPossible(houses, heaters, mid))
      smallestRadius = mid, end = mid - 1;
    else
      start = mid + 1;
  }
  return smallestRadius;
}

int main(int argc, char *argv[]) {
  // std::vector<int> houses{282475249, 622650073, 984943658, 144108930,
  //                         470211272, 101027544, 457850878, 458777923};
  // std::vector<int> heaters{823564440, 115438165, 784484492, 74243042,
  //                          114807987, 137522503, 441282327, 16531729,
  //                          823378840, 143542612};
  std::vector<int> houses{1, 1, 1, 1, 1, 1, 999, 999, 999, 999, 999};
  std::vector<int> heaters{499, 500, 501};
  std::cout << findRadius(houses, heaters) << '\n';
  return 0;
}
