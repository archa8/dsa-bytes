#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.
*/

int findFloor(vector<int>& arr, int x) {
  int n = arr.size(), low = 0, high = n - 1;
  int floor = -1; // no floor exists
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= x) {
      floor = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return floor;
} // Time: O(log n), Space: O(1)

int findCeil(vector<int>& arr, int x) {
  int n = arr.size(), low = 0, high = n - 1, ceil = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] <= x) {
      ceil = mid;
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return ceil;
} // Time: O(log n), Space: O(1)

/*A pair can be used to store the results:
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	int f = findFloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}
*/

int main() {
  vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
  int x = 5;
  int c = findCeil(arr, x), f = findFloor(arr, x);
  cout << "Floor: " << arr[f] << ", Ceil: " << arr[c] << "\n";
  return 0; 
}