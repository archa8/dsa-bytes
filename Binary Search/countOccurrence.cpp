#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.
*/

int lastOcc(vector<int>& arr, int x) {
  int n = arr.size(), l = 0, h = n - 1, idx = -1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (arr[m] == x) {
      idx = m;
      l = m + 1;
    }
    else if (arr[m] < x)
      l = m + 1;
    else
      h = m - 1;
  }
  return idx;
}

int firstOcc(vector<int>& arr, int x) {
  int n = arr.size(), l = 0, h = n - 1, idx = -1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (arr[m] == x) {
      idx = m;
      h = m - 1;
    }
    else if (arr[m] < x)
      l = m + 1;
    else
      h = m - 1;
  }
  return idx;
}

int countOccurrence(vector<int>& arr, int x) {
  int n = arr.size();
  int s = firstOcc(arr, x), e = lastOcc(arr, x);
  int res = (s == -1 && e == -1) ? 0 : (e - s + 1);
  return res;
} // Time: O(2 * log n), Space: O(1)
// for the brute force approach, traverse the array, increment counter and count occurrences - O(n) time, O(1) space

int main() {
  vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
  int x = 2;
  int ans = countOccurrence(arr, x);
  cout << x << " occurs " << ans << " times" << "\n";
  return 0;
}