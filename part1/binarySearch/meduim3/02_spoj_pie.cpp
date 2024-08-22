#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double circle_area(double r) {
  const double PI = acos(-1.0);
  return PI * r * r;
}

bool isPossible(std::vector<double> &pieRadius, double curRadius, int people) {
  int curPeople{};
  for (int i = 0; i < (int)pieRadius.size(); ++i)
    curPeople += pieRadius[i] / curRadius;

  return curPeople >= people;
}

double largest_area(vector<double> &pieRadius, int people) {
  double EPS{1e-9};
  double start{0}, end{-1};
  for (int i = 0; i < (int)pieRadius.size(); ++i) {
    pieRadius[i] = circle_area(pieRadius[i]);
    end = std::max(end, pieRadius[i]);
  }

  // while gets time limit execeded on spoj
  for (int i = 0; i < 100; ++i) {
    double mid{start + (end - start) / 2};

    if (isPossible(pieRadius, mid, people))
      start = mid;
    else
      end = mid;
  }

  return start;
}

int main() {
  int cases, n, f;
  cin >> cases;

  while (cases--) {
    cin >> n >> f;
    vector<double> pie_radius(n);

    for (int i = 0; i < n; i++)
      cin >> pie_radius[i];

    double area = largest_area(pie_radius, f + 1); // +1 for the host person

    cout << fixed;
    cout << setprecision(4) << area << "\n";
  }
  return 0;
}
