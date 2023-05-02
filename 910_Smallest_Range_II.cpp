/*
You are given an integer array nums and an integer k.

For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after changing the values at each index.



Example 1:

Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
Example 2:

Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
Example 3:

Input: nums = [1,3,6], k = 3
Output: 3
Explanation: Change nums to be [4, 6, 3]. The score is max(nums) - min(nums) = 6 - 3 = 3.
*/


#include "essentials.h"

class Solution {
public:
  int smallestRangeII(std::vector<int>& nums, int k) {
    if (nums.size() == 1) return 0;
    std::sort(nums.begin(), nums.end());
    int ans = nums.back() - nums.front();
    for (size_t i = 1; i < nums.size(); i++) {
      int x = std::max(nums[i - 1] + k, nums.back() - k) - std::min(nums.front() + k, nums[i] - k);
      if (x < ans) ans = x;
    }
    return ans;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums = {1};
  assert(sol->smallestRangeII(nums, 0) == 0);
  nums = {0, 10};
  assert(sol->smallestRangeII(nums, 2) == 6);
  nums = {1, 3, 6};
  assert(sol->smallestRangeII(nums, 3) == 3);
}

