#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

Note: Only one element is shifted per rotation, so basically the index with the minimum element is the number of rotations.
*/

int findKRotation(vector<int>& arr) {
  int n = arr.size(), l = 0, h = n - 1;
  int k = INT_MAX, idx = -1;
  while (l <= h) {
    int m = (h + l) / 2;
    if (arr[l] < arr[h]) { // subarray already sorted
      if (arr[l] < k) {
        idx = l;
        k = arr[l];
      }
      break;
    }
    if (arr[m] >= arr[l]) { // left part sorted
      if (arr[l] < k) { // keep minimum
        idx = l;
        k = arr[l];
      }
      l = m + 1; // eliminate left part
    }
    else { // right part sorted
      if (arr[m] < k) {
        idx = m;
        k = arr[m];
      }
      h = m - 1; // eliminate right part
    }
  }
  return idx;
} // Time: O(log n), Space: O(1)
// brute force approach would be O(n), linear search to find minimum and then the idx part is the same

int main()
{
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
  int ans = findKRotation(arr);
  cout << "The array is rotated " << ans << " times.\n";
  return 0;
}