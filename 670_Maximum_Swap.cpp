/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 10^8]
*/

#include "essentials.h"

class Solution {
public:
  int maximumSwap(int num) {
    std::deque<int> nums;
    while (num > 0) {
      nums.push_front(num % 10);
      num /= 10;
    }
    for (size_t i = 0; i < nums.size(); i++) {
      bool is_large = true;
      size_t pos = i;
      for (size_t j = i+1; j < nums.size(); j++) {
        if (nums[j] > nums[pos] || (nums[j] == nums[pos] && !is_large)) {
          pos = j;
          is_large = false;
        }
      }
      if (!is_large) {
        std::swap(nums[i], nums[pos]);
        break;
      }
    }
    int ans = 0;
    for (auto num : nums) ans = ans * 10 + num;
    return ans;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->maximumSwap(2736) == 7236);
  assert(sol->maximumSwap(9973) == 9973);
  assert(sol->maximumSwap(1992) == 9912);
  assert(sol->maximumSwap(53512) == 55312);
  assert(sol->maximumSwap(9001) == 9100);
  assert(sol->maximumSwap(23333) == 33332);
  assert(sol->maximumSwap(2) == 2);
  assert(sol->maximumSwap(0) == 0);
}


