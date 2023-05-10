/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.



Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
*/


#include "essentials.h"

class Solution {
public:
  int maxSubarraySumCircular(const std::vector<int>& nums) {
    int ans = nums[0];
    int x = 0;
    for (int v : nums) {
      x = (x > 0) ? (x + v) : v;
      if (x > ans) ans = x;
    }
    int n = nums.size();
    std::vector<int> left_sum(n, 0);
    std::vector<int> right_sum(n, 0);
    std::vector<int> left_max(n, 0);
    std::vector<int> right_max(n, 0);
    left_sum[0] = nums[0];
    right_sum[n - 1] = nums[n - 1];
    left_max[0] = nums[0];
    right_max[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      left_sum[i] = left_sum[i - 1] + nums[i];
      left_max[i] = (left_sum[i] > left_max[i - 1]) ? left_sum[i] : left_max[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      right_sum[i] = right_sum[i + 1] + nums[i];
      right_max[i] = (right_sum[i] > right_max[i + 1]) ? right_sum[i] : right_max[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
      int a = left_max[i] + right_max[i + 1];
      if (a > ans) ans = a;
    }
    return ans;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums = {1, -2, 3, -2};
  assert(sol->maxSubarraySumCircular(nums) == 3);
  nums = {5, -3, 5};
  assert(sol->maxSubarraySumCircular(nums) == 10);
  nums = {-3, -2, -3};
  assert(sol->maxSubarraySumCircular(nums) == -2);
}

