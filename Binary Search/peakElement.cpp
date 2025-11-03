#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an array of length N, peak element is defined as the element greater than both of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number. 
*/

int peakElement(vector<int>& arr) {
  int n = arr.size(), l = 0, h = n - 1;
  while (l < h) {
    int m = (l + h) / 2;
    if (arr[m] > arr[m + 1])
      h = m; // move to left half including m
    else
      l = m + 1; // move to right half
  }
  return l;
}

int main() {
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  cout << peakElement(nums) << endl;
  return 0;
}