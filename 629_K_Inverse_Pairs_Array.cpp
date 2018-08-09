/*
Given two integers n and k, find how many different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs.

We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] then it's an inverse pair; Otherwise, it's not.

Since the answer may be very large, the answer should be modulo 10^9 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
Note:
The integer n is in the range [1, 1000] and k is in the range [0, 1000].
*/


#include "essentials.h"

// DP, O(n*k)
// a[n][k] = sum_{i=min(0,k-n+1)}^k {a[n-1][i]}
// a[n][0] = 1
// a[1][0] = a[1][1] = 1

class Solution {
public:
  int kInversePairs(int n, int k) {
    std::vector<int> a(k+1, 0);
    a[0] = 1;
    for (int m = 2; m <= n; m++) {
      std::vector<int> cumsum(k+1, 0);
      cumsum[0] = 1;
      for (int j = 1; j <= k; j++) cumsum[j] = update(a[j], cumsum[j-1]);
      for (int j = 1; j <= k; j++) {
        int q = std::max(0, j-m+1);
        if (q == 0) a[j] = cumsum[j];
        else a[j] = update(cumsum[j] + BIG, -cumsum[q-1]);
      }
      a[0] = 1;
    }
    return a[k];
  }
private:
  constexpr static int BIG = 1000000007;
  int update(int x, int y) {
    return (x + y) % BIG;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->kInversePairs(3, 0) == 1);
  assert(sol->kInversePairs(3, 1) == 2);
  assert(sol->kInversePairs(5, 5) == 22);
  assert(sol->kInversePairs(5, 6) == 20);
  assert(sol->kInversePairs(20, 10) == 10947079);
  assert(sol->kInversePairs(1000, 1000) == 663677020);
}

