/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].
*/

#include "essentials.h"

// Sum of all prime factors

class Solution {
public:
  int minSteps(int n) {
    int ans = 0;
    int i = 2;
    while (n >= i*i) {
      while (n % i == 0) {
        ans += i;
        n /= i;
      }
      i++;
    }
    if (n > 1) ans += n;
    return ans;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->minSteps(3) == 3);
  assert(sol->minSteps(30) == 10);
  assert(sol->minSteps(27) == 9);
  assert(sol->minSteps(54) == 11);
  assert(sol->minSteps(1) == 0);
}

