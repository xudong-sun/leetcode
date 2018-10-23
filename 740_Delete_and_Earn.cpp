/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation:
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation:
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/

#include "essentials.h"

// DP: a[i] = max(a[i-2]+c[i]*i, a[i-1])

class Solution {
public:
  int deleteAndEarn(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    std::array<int, 10001> count = {0};
    int m = 0;
    for (int num : nums) {
      count[num]++;
      if (num > m) m = num;
    }
    int x = 0, y = count[1], z = 0;
    for (int i = 2; i <= m; i++) {
      z = std::max(x + count[i] * i, y);
      x = y;
      y = z;
    }
    return y;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums = {3,4,2};
  assert(sol->deleteAndEarn(nums) == 6);
  nums = {2,2,3,3,3,4};
  assert(sol->deleteAndEarn(nums) == 9);
  nums = {1,1,1,2,10000};
  assert(sol->deleteAndEarn(nums) == 10003);
  nums = {3};
  assert(sol->deleteAndEarn(nums) == 3);
  nums = {};
  assert(sol->deleteAndEarn(nums) == 0);
}

