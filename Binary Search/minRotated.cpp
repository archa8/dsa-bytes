#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an integer array arr of size N, sorted in ascending order (with distinct values), the array is rotated at any index which is unknown. Find the minimum element in the array. 
*/

int minRotated(vector<int>& arr) {
  int n = arr.size(), l = 0, h = n - 1;
  while (l < h) { // if l == h, then m == l == h, so neither l nor h changes, which leads to infinite loop, so equality is not included
    if (arr[l] < arr[h])
      return arr[l];
    int m = l + (h - l) / 2;
    if (arr[m] > arr[h])
      l = m + 1;
    else
      h = m;
  }
  return arr[l];
} // Time: O(log n), Space: O(1)
// Brute force approach would be O(n), linear search with comparisons to find minimum

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int res = minRotated(nums);
    cout << "Minimum element is " << res << endl;
    return 0;
}