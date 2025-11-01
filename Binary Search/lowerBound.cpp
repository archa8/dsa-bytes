/*Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.*/

int lowerBound(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
} // Lower Bound - Time: O(log n), Space: O(1)
// Brute force will be linear search - O(n)