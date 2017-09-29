/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/


#include "essentials.h"

// almost the same as 442_Find_All_Duplicates_in_an_Array
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
         for (size_t i = 0; i < nums.size(); i++) {
             while (nums[i] != i + 1) {
                 int pos = nums[i] - 1;
                 if (nums[i] == nums[pos]) break;
                 std::swap(nums[i], nums[pos]);
             }
         }
         std::vector<int> res;
         for (size_t i = 0; i < nums.size(); i++)
             if (nums[i] != i + 1) res.push_back(i + 1);
         return res;
    }
};


int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<int> vec1 {4,3,2,7,8,2,3,1};
    commons::print(sol->findDisappearedNumbers(vec1)); // [5,6]
    std::vector<int> vec2 {3,4,2,3,4,2};
    commons::print(sol->findDisappearedNumbers(vec2)); // [1,5,6]
    std::vector<int> vec3 {5,4,3,2,1};
    commons::print(sol->findDisappearedNumbers(vec3)); // []
    std::vector<int> vec4 {1,1,3};
    commons::print(sol->findDisappearedNumbers(vec4)); // [2]
}


