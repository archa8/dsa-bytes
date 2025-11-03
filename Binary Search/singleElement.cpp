#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.
*/

// here, all the elements appear twice except one, so the length of the array is always odd. also, since the array is sorted, the pairs appear
// side-by-side, as for eg, in [1, 1, 2, 2, 3, 4, 4], for the pairs [1,1] and [2,2] first elements are at even indices and thus there is an
// alignment, but after 3, the alignment, which is exactly the property used to find the single element

int singleElement(vector<int>& arr) {
  int n = arr.size();
  if (n == 1) return arr[0];
  if (arr[0] != arr[1]) return arr[0];
  if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

  int l = 0, h = n - 2;
  while (l <= h) {
    int m = (l + h) / 2;
    if (arr[m] != arr[m - 1] && arr[m] != arr[m + 1])
      return arr[m];
    if ((m % 2 == 1 && arr[m] == arr[m - 1]) || (m % 2 == 0 && arr[m] == arr[m + 1]))
      l = m + 1;
    else
      h = m - 1;
  }
  return -1;
} // Time: O(log n), Space: O(1)

int main()
{
  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
  int ans = singleElement(arr);
  cout << "The single element is: " << ans << "\n";
  return 0;
}