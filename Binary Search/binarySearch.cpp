#include <bits/stdc++.h>
using namespace std;

// works only on sorted arrays
int binarySearch(vector<int>& arr, int key) {
  int low = 0, high = arr.size() - 1; // can use size_t for indices as there are only positive integers
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
      return mid;

    if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
} // Binary Search (Iterative) - Time: O(log n), Space: O(1)

int main() {
  vector<int> arr = {2, 3, 4, 10, 40};
  int key = 10;
  int res = binarySearch(arr, key);
  if (res != -1)
    cout << "Element is present at index " << res << endl;
  else
    cout << "Element is not present in array" << endl;
  return 0;
} 
// Test: key not in array (e.g., key = 5)
// Test: empty array
// Test: single element array
