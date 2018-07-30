/*
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.

Example 1:
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
Note: 1 <= n <= 10^9
*/

#include "essentials.h"

// Step 1: binary strings that avoid 11: C(n) = C(n-1) + C(n-2), C(0) = 1, C(1) = 2
// Step 2: ex1. 1010 = C(3) [0xxx] + C(1) [100x]
//         ex2. 11110 = C(4) [0xxxx] + C(3) [10xxx]
//         ex3. 101101 = C(5) [0xxxxx] + C(3) [100xxx] + C(2) [1010xx]

class Solution {
public:
  int findIntegers(int num) {
    int n = 0, z = 1;
    num++; // since we are counting valid numbers smaller than num
    while (z <= num) {
      z <<= 1; n++;
    }
    std::vector<int> C(n, 0);
    C[0] = 1; C[1] = 2;
    for (int i = 2; i < n; i++) C[i] = C[i-1] + C[i-2];
    int ans = 0;
    bool lastbit = false;
    while (n > 0) {
      z >>= 1; n--;
      if ((num & z) > 0) {
        ans += C[n];
        if (lastbit) break;
        lastbit = true;
      } else {
        lastbit = false;
      }
    }
    return ans;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->findIntegers(3) == 3);
  assert(sol->findIntegers(4) == 4);
  assert(sol->findIntegers(5) == 5);
  assert(sol->findIntegers(10) == 8);
  assert(sol->findIntegers(45) == 21);
  assert(sol->findIntegers(1) == 2);
  assert(sol->findIntegers(1000000000) == 2178309);
}

