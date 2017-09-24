/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include "essentials.h"

// Basic thoughts:
// 1. if we divide the array into two parts, the first half is less than or equal to the second half (partition algorithm), it would be easier to wiggle. We only need to take care of the "equal" cases
// 2. if the array is sorted, then we can do: nums[::2], nums[1::2] = nums[:half][::-1], nums[half:][::-1]. This guarantees the wiggle requirement
//
// With the above in mind, we come up with this solution:
// 1. partition the array into smaller and larger parts
// 2. nums[::2], nums[1::2] = nums[:half][::-1], nums[half][::-1], i.e. first half at even positions, second half at odd positions
// 3. for the even half, move elements that are equal to "median" to the front; for the odd half, move elements that are equal to "median" to the back of the array
//
// Example:
// original array: [1,3,2,2,3,1]
// 1. -> [1,1,2,2,3,3], median is 2
// 2. -> [1,3,2,2,1,3]
// 3. -> [2,3,1,3,1,2] (Note: even half: 1,2,1 -> 2,1,1; odd half: 3,2,3 -> 3,3,2)
class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        size_t median_pos = (nums.size() - 1) / 2;
        std::nth_element(nums.begin(), nums.begin() + median_pos, nums.end());
        int median = nums[median_pos];
        size_t i = 1, j = median_pos % 2 == 0 ? median_pos + 2 : median_pos + 1;
        while (i <= median_pos) {
            std::swap(nums[i], nums[j]);
            i += 2; j += 2;
        }
        size_t p = 0;
        for (size_t i = 0; i < nums.size(); i += 2)
            if (nums[i] == median) { std::swap(nums[i], nums[p]); p += 2; }
        p = nums.size() % 2 == 0 ? nums.size() - 1 : nums.size() - 2;
        for (int i = p; i >= 0; i -= 2)
            if (nums[i] == median) { std::swap(nums[i], nums[p]); p -= 2; }
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<int> nums {1,5,1,1,6,4};
    sol->wiggleSort(nums);
    commons::print(nums);
    nums.clear();
    nums.insert(nums.cbegin(), {1,3,2,2,3,1});
    sol->wiggleSort(nums);
    commons::print(nums);
    nums.clear();
    nums.insert(nums.cbegin(), {2,1,1});
    sol->wiggleSort(nums);
    commons::print(nums);
    nums.clear();
    nums.insert(nums.cbegin(), {1});
    sol->wiggleSort(nums);
    commons::print(nums);
    nums.clear();
    nums.insert(nums.cbegin(), {1,2,3,2,2,1,2,3});
    sol->wiggleSort(nums);
    commons::print(nums);
    nums.clear();
    nums.insert(nums.cbegin(), {1,3,2,2,1,1,2});
    sol->wiggleSort(nums);
    commons::print(nums);
}

