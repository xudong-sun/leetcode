/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/


#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1

// DP, O(n), 39ms
class Solution {
public:
    bool canPartition(const std::vector<int>& nums) {
         int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
         if (sum % 2 == 1) return false;
         sum /= 2;
         std::vector<bool> can(sum + 1, false);
         can[0] = true;
         int curMax = 0;
         for (auto num : nums) {
             for (int i = std::min(curMax + num, sum); i >= num; i--) if (can[i - num]) can[i] = true;
             curMax += num;
         }
         return can[sum];
    }
};

#endif

#ifdef __SOLUTION_2

// std::vector<bool> can be replaced with std::bitset, 9ms
// This solution is efficient in both time and space
class Solution {
public:
    bool canPartition(const std::vector<int>& nums) {
        int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2 == 1) return false;
        std::bitset<10001> bits(1);
        for (auto num : nums) bits |= bits << num;
        return bits[sum / 2];
    }
};

#endif

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->canPartition(std::vector<int>{1,5,11,5}));
    assert(!sol->canPartition(std::vector<int>{1,2,3,5}));
    assert(!sol->canPartition(std::vector<int>{2,2,3,5}));
    assert(sol->canPartition(std::vector<int>(100, 1)));
    assert(!sol->canPartition(std::vector<int>{2,4}));
    assert(!sol->canPartition(std::vector<int>{10}));
}

