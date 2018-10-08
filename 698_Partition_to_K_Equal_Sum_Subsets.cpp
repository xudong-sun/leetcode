/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/


#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1

// Solution 1: dfs
// O(k! k^(n-k))

class Solution {
public:
  bool canPartitionKSubsets(std::vector<int>& nums, int k) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    int target = sum / k;
    std::sort(nums.begin(), nums.end(), [](int x, int y) { return x > y; });
    if (nums[0] > target) return false;
    std::vector<int> sums(k, 0);
    signal_stop = false;
    return dfs_start(0, 0, 0, k, nums.size(), sums, nums, target);
  }
private:
  // find a number for each bin to start DFS
  bool dfs_start(int state, int level, int index, int k, int n, std::vector<int>& sums, std::vector<int>& nums, int target) {
    if (signal_stop) return true;
    if (level == k) return dfs_work(state, 0, k, n, sums, nums, target);
    if (index + (k - level) > n) return false;
    int z = 1 << index;
    bool result = false;
    result |= dfs_start(state, level, index+1, k, n, sums, nums, target);
    sums[level] = nums[index];
    result |= dfs_start(state+z, level+1, index+1, k, n, sums, nums, target);
    sums[level] = 0;
    return result;
  }
  // test if this dfs_start setup meets the requirement
  bool dfs_work(int state, int index, int k, int n, std::vector<int>& sums, std::vector<int>& nums, int target) {
    if (signal_stop) return true;
    if (index == n) {
      signal_stop = true;
      return true;
    }
    if ((state & (1 << index)) > 0) return dfs_work(state, index+1, k, n, sums, nums, target);
    bool result = false;
    for (int i = 0; i < k; i++) {
      if (sums[i] + nums[index] <= target) {
        sums[i] += nums[index];
        result |= dfs_work(state, index+1, k, n, sums, nums, target);
        sums[i] -= nums[index];
      }
    }
    return result;
  }
  bool signal_stop = false;
};

#endif

#ifdef __SOLUTION_2

// DP: a[state]: the remainder if "state" is chosen
// O(n 2^k)

class Solution {
public:
  bool canPartitionKSubsets(std::vector<int>& nums, int k) {
    int max = 0, target = 0;
    for (int num : nums) {
      if (num > max) max = num;
      target += num;
    }
    if (target % k != 0) return false;
    if (max > target) return false;
    target /= k;
    int n = nums.size();
    int max_state = 1 << n;
    std::vector<int> a(max_state, -1);
    a[0] = 0;
    for (int state = 0; state < max_state; state++) {
      for (int i = 0; i < n; i++) {
        int z = 1 << i;
        if ((state & z) == 0 && a[state] != -1 && a[state] + nums[i] <= target) a[state+z] = (a[state] + nums[i]) % target;
      }
    }
    return a[max_state-1] == 0;
  }
};

#endif

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums = {4,3,2,3,5,2,1};
  assert(sol->canPartitionKSubsets(nums, 4) == true);
  nums = {7,3,3,3,1,1,8,8,2};
  assert(sol->canPartitionKSubsets(nums, 4) == true);
  nums = {2,5,8,3};
  assert(sol->canPartitionKSubsets(nums, 2) == false);
  nums = {1,2,3,4,5};
  assert(sol->canPartitionKSubsets(nums, 3) == true);
  assert(sol->canPartitionKSubsets(nums, 2) == false);
  assert(sol->canPartitionKSubsets(nums, 1) == true);
  nums = {4,4,4,4};
  assert(sol->canPartitionKSubsets(nums, 8) == false);
  nums = {3};
  assert(sol->canPartitionKSubsets(nums, 1) == true);
}


