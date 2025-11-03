#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 
*/

bool rotatedSorted(vector<int>& arr, int k) {
  int n = arr.size(), l = 0, h = n - 1;
  while (l <= h) {
    int m = (l + h) / 2;
    if (arr[m] == k)
      return true;
    if (arr[m] == arr[l] && arr[m] == arr[h]) {
      l++;
      h--;
      continue;
    }
    if (arr[l] <= arr[m]) {
      if (k >= arr[l] && k < arr[m])
        h = m - 1;
      else
        l = m + 1;
    }
    else {
      if (k > arr[m] && k <= arr[h])
        l = m + 1;
      else
        h = m - 1;
    }
  }
  return false;
} // Time: O(log n) on average, O(n) in worst case, Space: O(1)
// Worst case occurs when there are many duplicates
// brute force approach would be O(n), linear search

int main() {
  vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 10;
    bool ans = rotatedSorted(arr, k);
    if (!ans)
      cout << "Target is not present.\n";
    else
      cout << "Target is present in the array.\n";
    return 0;
}