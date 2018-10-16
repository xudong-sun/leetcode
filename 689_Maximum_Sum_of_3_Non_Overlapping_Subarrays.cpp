/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/


#include "essentials.h"

class Solution {
public:
  std::vector<int> maxSumOfThreeSubarrays(const std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> sum(n, 0);
    for (int i = 0; i < k; i++) sum[0] += nums[i];
    for (int i = 1; i < n-k+1; i++) sum[i] = sum[i-1] - nums[i-1] + nums[i+k-1];
    std::vector<std::vector<int>> a(n-k+1, std::vector<int>(3, 0));  // value
    std::vector<std::vector<int>> b(n-k+1, std::vector<int>(3, -1));  // position
    a[0][0] = sum[0]; b[0][0] = 0;
    for (int i = 1; i < k; i++) {
      if (sum[i] > a[i-1][0]) {
        a[i][0] = sum[i]; b[i][0] = i;
      } else {
        a[i][0] = a[i-1][0]; b[i][0] = b[i-1][0];
      }
    }
    for (int i = k; i < n-k+1; i++) {
      if (a[i-k][1] + sum[i] > a[i-1][2]) {
        a[i][2] = a[i-k][1] + sum[i]; b[i][2] = i;
      } else {
        a[i][2] = a[i-1][2]; b[i][2] = b[i-1][2];
      }
      if (a[i-k][0] + sum[i] > a[i-1][1]) {
        a[i][1] = a[i-k][0] + sum[i]; b[i][1] = i;
      } else {
        a[i][1] = a[i-1][1]; b[i][1] = b[i-1][1];
      }
      if (sum[i] > a[i-1][0]) {
        a[i][0] = sum[i]; b[i][0] = i;
      } else {
        a[i][0] = a[i-1][0]; b[i][0] = b[i-1][0];
      }
    }
    std::vector<int> result(3, 0);
    result[2] = b[n-k][2];
    result[1] = b[result[2]-k][1];
    result[0] = b[result[1]-k][0];
    return result;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums {1,2,1,2,6,7,5,1};
  std::vector<int> ans {0,3,5};
  assert(sol->maxSumOfThreeSubarrays(nums, 2) == ans);
  nums = {7,5,7,6,8,9,1,11,1,2};
  ans = {0,3,7};
  assert(sol->maxSumOfThreeSubarrays(nums, 3) == ans);
}


