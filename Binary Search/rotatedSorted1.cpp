#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.
*/

int rotatedSearch(vector<int>& arr, int k) {
  int n = arr.size(), l = 0, h = n - 1;
  while (l <= h) {
    int m = (l + h) / 2;
    if (arr[m] == k)
      return m;
    if (arr[l] <= arr[m]) { // left half is sorted
      if (k >= arr[l] && k <= arr[m]) // element lies in left half
        h = m - 1;
      else // element lies in right half
        l = m + 1;
    }
    else { // right half is sorted
      if (k >= arr[m] && k <= arr[h]) // element lies in right half
        l = m + 1;
      else // element lies in left half
        h = m - 1;
    }
  }
  return -1;
} // Time: O(log n), Space: O(1)
// brute approach will be linear search - O(n) time

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int k = 1;
    int ans = rotatedSearch(arr, k);
    cout << "The index is: " << ans << "\n";
    return 0;
}