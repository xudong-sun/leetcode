/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

// x1 stores the smallest number; x2 stores the number where <x,y>,x<y has smallest y
// very similar to 300_Longest_Increasing_Subsequence, Solution 2

#include "essentials.h"

class Solution {
public:
    bool increasingTriplet(const std::vector<int>& nums) {
        int x1 = INT_MAX, x2 = INT_MAX;
        for (auto x : nums) {
            if (x > x2) return true;
            if (x > x1 and x < x2) x2 = x; 
            if (x < x1) x1 = x;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    auto sol = std::make_unique<Solution>();
    assert(sol->increasingTriplet(std::vector<int>{1,2,3,4,5}));
    assert(!sol->increasingTriplet(std::vector<int>{5,4,3,2,1}));
    assert(sol->increasingTriplet(std::vector<int>{0,-3,5,2,1,-2,-1}));
    assert(!sol->increasingTriplet(std::vector<int>{0,-3,5,2,1,0,0,-2}));
    assert(!sol->increasingTriplet(std::vector<int>{1,2}));
    assert(!sol->increasingTriplet(std::vector<int>{}));
    return 0;
}
