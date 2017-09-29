/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/


#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1

// similar to 041_First_Missing_Positive
// 136ms
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
         for (size_t i = 0; i < nums.size(); i++) {
             while (nums[i] != i + 1) {
                 int pos = nums[i] - 1;
                 if (nums[i] == nums[pos]) break;
                 std::swap(nums[i], nums[pos]);
             }
         }
         std::vector<int> res;
         for (size_t i = 0; i < nums.size(); i++)
             if (nums[i] != i + 1) res.push_back(nums[i]);
         return res;
    }
};

#endif

#ifdef __SOLUTION_2

// flip sign for nums[nums[i]-1], if nums[i] has not appeared before
// 143ms
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> res;
        for (auto num : nums) {
            num = abs(num);
            if (nums[num - 1] < 0) res.push_back(num);
            else nums[num - 1] *= -1;
        }
        return res;
    }
};

#endif

int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<int> vec1 {4,3,2,7,8,2,3,1};
    commons::print(sol->findDuplicates(vec1)); // [2,3]
    std::vector<int> vec2 {3,4,2,3,4,2};
    commons::print(sol->findDuplicates(vec2)); // [2,3,4]
    std::vector<int> vec3 {5,4,3,2,1};
    commons::print(sol->findDuplicates(vec3)); // []
    std::vector<int> vec4 {1,1,3};
    commons::print(sol->findDuplicates(vec4)); // [1]
}

