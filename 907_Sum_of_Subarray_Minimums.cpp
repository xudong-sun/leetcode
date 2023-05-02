/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
*/

#include "essentials.h"

class Solution {
public:
  int sumSubarrayMins(const std::vector<int>& arr) {
    std::stack<std::tuple<int, int, int>> stack;  // <value, index, cum_sum>
    int ans = 0;
    for (int i = 0; i < int(arr.size()); i++) {
      int x = arr[i];
      while (!stack.empty()) {
        if (std::get<0>(stack.top()) < x) break;
        stack.pop();
      }
      int new_cum;
      if (stack.empty()) {
        new_cum = Mul(x, i + 1);
      } else {
        int old_cum = std::get<2>(stack.top());
        new_cum = Mul(x, i - std::get<1>(stack.top()));
        new_cum = Add(old_cum, new_cum);
      }
      ans = Add(ans, new_cum);
      stack.push(std::make_tuple(x, i, new_cum));
    }
    return ans;
  }

private:
  int Mul(int a, int b) {
    int64_t x = a * b;
    return x % modulo_;
  }
  int Add(int a, int b) {
    return (a + b) % modulo_;
  }
  const int modulo_ = 1000000007;
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> arr = {3, 1, 2, 4};
  assert(sol->sumSubarrayMins(arr) == 17);  // 3+2+4+8
  arr = {11,81,94,43,3};
  assert(sol->sumSubarrayMins(arr) == 444);
  arr = {5, 4, 2, 3, 2, 3, 4, 1};
  assert(sol->sumSubarrayMins(arr) == 76);  // 5+8+6+9+10+13+17+8
}


