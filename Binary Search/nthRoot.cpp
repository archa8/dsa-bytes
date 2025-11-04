#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1. 
*/

int nthRoot(int n, int m) {
  int l = 1, h = m;
  while (l <= h) {
    int mid = (l + h) / 2;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
      ans *= mid;
      if (ans > m)
        break;
    }
    if (ans == m)
      return mid;
    if (ans < m)
      l = mid + 1;
    else
      h = mid - 1;
  }
  return -1;
} // time complexity: O(log m * n), where log m is for binary search and n is for calculating mid^n

int main() {
  int n = 3, m = 27;
  cout << nthRoot(n, m) << endl;
  return 0;
}