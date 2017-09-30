/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/


#include "essentials.h"

// check out 437_Path_Sum_III, SOLUTION_2, subtask 2
class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int ans = 0, curSum = 0;
        count[0] = 1;
        for (auto num : nums) {
            curSum += num;
            if (count.find(curSum - k) != count.cend()) ans += count[curSum - k];
            count[curSum]++;
        }
        return ans;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->subarraySum({1,1,1}, 2) == 2);
    assert(sol->subarraySum({1,5,11,5}, 11) == 1);
    assert(sol->subarraySum({0,4,-1,2,-1,-1,1,2,3,0}, 6) == 6);
    assert(sol->subarraySum({1,2,1,2,1}, 3) == 4);
    assert(sol->subarraySum({3,-2,4}, 0) == 0);
    assert(sol->subarraySum({0}, 0) == 1);
    assert(sol->subarraySum({}, 0) == 0);
}

