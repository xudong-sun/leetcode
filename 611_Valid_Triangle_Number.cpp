/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

#include "essentials.h"

// O(n^2), two pointers
class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n-2; i++) {
            int p = i, q = i;
            for (int j = i+1; j < n-1; j++) {
                if (p <= j) p = j + 1;
                int lower = nums[j] - nums[i], upper = nums[j] + nums[i];
                while (p < n && nums[p] <= lower) p++;
                while (q < n && nums[q] < upper) q++;
                if (q > p) ans += q - p;
            }
        }
        return ans;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<int> nums {2,2,3,4};
    assert(sol->triangleNumber(nums) == 3);
    nums.assign({2,2,3,4,100,0});
    assert(sol->triangleNumber(nums) == 3);
    nums.assign({2,2,2,2,2});
    assert(sol->triangleNumber(nums) == 10);
    nums.assign({5,4,3,2,1});
    assert(sol->triangleNumber(nums) == 3);
    nums.clear();
    assert(sol->triangleNumber(nums) == 0);
    nums.push_back(2);
    assert(sol->triangleNumber(nums) == 0);
    nums.push_back(3);
    assert(sol->triangleNumber(nums) == 0);
}
