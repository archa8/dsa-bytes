#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

Note: Consider 0 based indexing
*/

int lastOccurrence(vector<int>& arr, int x) {
  int n = arr.size(), l = 0, h = n - 1, idx = -1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (arr[m] == x) {
      idx = m;
      l = m + 1;
    }
    else if (x < arr[m])
      h = m - 1;
    else
      l = m + 1;
  }
  return idx;
} // Time: O(log n), Space: O(1)

/* In the brute force approach, traverse the array from the end to the start and return the first index where arr[i] == x. This takes O(n) time. */
// approach will be similar for first occurrence

int main() {
  vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
  int x = 2;
  int ans = lastOccurrence(arr, x);
  cout << "The last occurrence of " << x << " is at index: " << ans << "\n";
  return 0;
}