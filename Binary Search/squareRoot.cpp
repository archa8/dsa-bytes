#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n). 
*/

int squareRoot(int n) {
  if (n < 2)
    return n;
  int low = 1, high = n / 2, ans = 0; // high can also be taken as n 
  // in that case the search space increases and the n < 2 condition can safely be removed
  while (low <= high) {
    int mid = low + (high - low) / 2;
    ll sq = (ll)mid * mid;
    if (sq <= n) {
      ans = mid;
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return ans;
}

int main() {
  int n = 36;
  cout << "Square root of " << n << " is " << squareRoot(n) << endl;
  return 0;
}