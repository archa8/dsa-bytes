#include <bits/stdc++.h>
using namespace std;

/*Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.
*/

int upperBound(vector<int> &arr, int x, int n) {
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
      ans = mid + 1;
    if (arr[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;

    /*
    this whole block can also be written as:
        if (arr[mid] > x) {
          ans = mid;
          high = mid - 1;
        }
        else
          low = mid + 1;
    */
  }
  return ans;
} // Upper Bound - Time: O(log n), Space: O(1)
// Brute force will be linear search - O(n)

int main()
{
  vector<int> arr = {3, 5, 8, 9, 15, 19};
  int n = 6, x = 9;
  int ind = upperBound(arr, x, n);
  cout << "The upper bound is the index: " << ind << "\n";
  return 0;
}