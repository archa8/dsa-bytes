#include <bits/stdc++.h>
using namespace std;

int calculateTotalHours(vector<int>& piles, int speed) {
  int totalH = 0;
  for (int b : piles)
    totalH += ceil((double)b / speed);
  return totalH;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int maxPile = *max_element(piles.begin(), piles.end());
  int l = 1, h = maxPile, ans = maxPile;
  while (l <= h) {
    int m = (l + h) / 2;
    int totalH = calculateTotalHours(piles, m);
    if (totalH <= h) {
      ans = m;
      h = m - 1;
    }
    else 
      l = m + 1;
  }
  return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h);
    return 0;
}
