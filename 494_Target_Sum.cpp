/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/


#include "essentials.h"

// can be solved by either dfs or dp
#define __SOLUTION_2

#ifdef __SOLUTION_1

// DP, O(ns), 26ms
class Solution {
public:
    int findTargetSumWays(const std::vector<int>& nums, int S) {
        if (nums.size() == 0) return 0;
        if (abs(S) > MAX / 2) return 0;
        std::array<int, MAX> data{0};
        data[MAX / 2 + nums[0]] += 1; data[MAX / 2 - nums[0]] += 1;
        for (size_t k = 1; k < nums.size(); k++) {
            auto num = nums[k];
            std::array<int, MAX> data0{0};
            for (int i = num; i < MAX; i++) data0[i - num] += data[i];
            for (int i = 0; i < MAX - num; i++) data0[i + num] += data[i];
            std::copy(data0.cbegin(), data0.cend(), data.begin());
        }
        return data[S + MAX / 2];
    }
private:
    const static int MAX = 2001;
};

#endif

#ifdef __SOLUTION_2

// improvement on SOLUTION_1, O(ns), 6ms
// we only need to find a subset of positives sum to SUM, where SUM = (S + sum(nums)) / 2
class Solution {
public:
    int findTargetSumWays(const std::vector<int>& nums, int S) {
        int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if ((S + sum) % 2 != 0) return 0;
        int SUM = (S + sum) / 2;
        if (SUM < 0 || SUM > MAX) return 0;
        std::array<int, MAX + 1> data{1,0};
        for (auto num : nums) {
            for (int i = MAX - num; i >= 0; i--) data[i + num] += data[i];
        }
        return data[SUM];
    }
private:
    const static int MAX = 1000;
};

#endif

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->findTargetSumWays({1,1,1,1,1}, 3) == 5);
    assert(sol->findTargetSumWays({1,0}, 1) == 2);
    assert(sol->findTargetSumWays({3}, -3) == 1);
    assert(sol->findTargetSumWays({3}, 0) == 0);
    assert(sol->findTargetSumWays({1,2,7,9,981}, 10000) == 0);
    assert(sol->findTargetSumWays({0,1}, 1) == 2);
}

