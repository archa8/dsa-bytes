/*Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.*/

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int x) {
  int n = arr.size(), low = 0, high = n - 1;
  int ans = n; // position if x is greater than all elements
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= x){
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
} // Time: O(log n), Space: O(1)

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
} // should return 3 as arr[3] = 7 is the first element greater than 6