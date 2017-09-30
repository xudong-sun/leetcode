/*
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/


#include "essentials.h"
// check out 437_Path_Sum_III, SOLUTION 2, subtask 2
class Solution {
public:
    bool checkSubarraySum(const std::vector<int>& nums, int k) {
        if (k == 0) {
            for (size_t i = 0; i < nums.size() - 1; i++) if (nums[i] == 0 && nums[i+1] == 0) return true;
            return false;
        }
        k = abs(k);
        std::unordered_set<int> sums;
        int curSum = 0, lastSum = 0;
        for (auto num : nums) {
            curSum = (curSum + num) % k;
            if (sums.find(curSum) != sums.cend()) return true;
            sums.insert(lastSum); lastSum = curSum;
        }
        return false;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->checkSubarraySum({23,2,4,6,7}, 6));
    assert(sol->checkSubarraySum({23,2,4,6,7}, -6));
    assert(sol->checkSubarraySum({23,2,6,4,7}, 6));
    assert(sol->checkSubarraySum({23,2,6,3,2}, 6));
    assert(!sol->checkSubarraySum({23,2,6,3}, 6));
    assert(sol->checkSubarraySum({2,2}, 2));
    assert(!sol->checkSubarraySum({10}, 1));
    assert(sol->checkSubarraySum({2,3}, 1));
    assert(sol->checkSubarraySum({0,7}, 7));
    assert(sol->checkSubarraySum({2,2,2,2,2,2}, 3));
    assert(!sol->checkSubarraySum({2,2,2,2,2,2}, 7));
    assert(!sol->checkSubarraySum({2,2,2,2,2,2}, -7));
    assert(!sol->checkSubarraySum({}, 1));
    assert(!sol->checkSubarraySum({1,2,3}, 0));
    assert(!sol->checkSubarraySum({4,0,2,1,3,0,3,0,1}, 0));
    assert(sol->checkSubarraySum({1,2,0,0,3}, 0));
    assert(sol->checkSubarraySum({1,2,0,0,3}, 7));
}

