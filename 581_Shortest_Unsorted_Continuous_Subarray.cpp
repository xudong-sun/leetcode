/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/


#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1

// O(nlogn), sort, 48ms
class Solution {
public:
    int findUnsortedSubarray(const std::vector<int>& nums) {
        std::vector<int> sorted(nums);
        std::sort(sorted.begin(), sorted.end());
        size_t i = 0, j = nums.size() - 1;
        while (i < nums.size() && nums[i] == sorted[i]) i++;
        if (i == nums.size()) return 0;
        while (j > i && nums[j] == sorted[j]) j--;
        return j - i + 1;
    }
};

#endif

#ifdef __SOLUTION_2

// O(n), 35ms
// i: one past first index of the unsorted subarray; j: last index of the unsorted subarray
class Solution {
public:
    int findUnsortedSubarray(const std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        std::vector<int> tmp{nums[0]};
        int i, j = -1;
        for (size_t k = 1; k < nums.size(); k++) {
            auto num = nums[k];
            if (num >= tmp.back()) tmp.push_back(num);
            else {
                if (j < 0) i = k - 2;
                j = k;
                while (i >= 0 && tmp[i] > num) i--;
            }
        }
        return (j < 0) ? 0 : (j - i);
    }
};

#endif

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->findUnsortedSubarray(std::vector<int>{2,6,4,8,10,9,15}) == 5);
    assert(sol->findUnsortedSubarray(std::vector<int>{4,3,3,7,4,7,7,8,8,8,10}) == 5);
    assert(sol->findUnsortedSubarray(std::vector<int>{2,2,5,6,1,1}) == 6);
    assert(sol->findUnsortedSubarray(std::vector<int>{3,3,3,4,5,5,6,6,6}) == 0);
    assert(sol->findUnsortedSubarray(std::vector<int>{3,4,3,4}) == 2);
    assert(sol->findUnsortedSubarray(std::vector<int>{5}) == 0);
    assert(sol->findUnsortedSubarray(std::vector<int>{}) == 0);
}

