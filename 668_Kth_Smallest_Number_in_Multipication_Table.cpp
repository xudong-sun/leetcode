/*
Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?

Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.

Example 1:
Input: m = 3, n = 3, k = 5
Output:
Explanation:
The Multiplication Table:
1	2	3
2	4	6
3	6	9

The 5-th smallest number is 3 (1, 2, 2, 3, 3).
Example 2:
Input: m = 2, n = 3, k = 6
Output:
Explanation:
The Multiplication Table:
1	2	3
2	4	6

The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
Note:
The m and n will be in the range [1, 30000].
The k will be in the range [1, m * n]
*/

#include "essentials.h"

class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int l = 1, r = m*n;
    while (l < r) {
      int x = (l + r) / 2;
      if (count(m, n, k, x)) r = x;
      else l = x + 1;
    }
    return l;
  }
private:
  bool count(int m, int n, int k, int x) {
    int v = 0;
    for (int i = 1; i <= m; i++) {
      v += std::min(x/i, n);
      if (v >= k) return true;
    }
    return false;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->findKthNumber(3, 3, 5) == 3);
  assert(sol->findKthNumber(2, 3, 6) == 6);
  assert(sol->findKthNumber(5, 7, 1) == 1);
  assert(sol->findKthNumber(30, 23, 101) == 30);
  assert(sol->findKthNumber(100, 1, 11) == 11);
  assert(sol->findKthNumber(1, 100, 11) == 11);
}

