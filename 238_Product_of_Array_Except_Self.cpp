/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include "essentials.h"

class Solution {
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums) 
	{
		size_t n = nums.size();
		std::vector<int> ans(n, 1);
		for (size_t i = 1; i < n; i++) ans[i] = ans[i - 1] * nums[i - 1];
		int temp = 1;
		for (size_t i = n - 2; i < n; i--)
		{
			temp *= nums[i + 1]; ans[i] *= temp;
		}
		return ans;
	}
};

int main() {
	auto sol = new Solution();
	std::cout << sol->productExceptSelf(std::vector < int > {1, 2, 3, 4}) << std::endl;
	delete sol;
	commons::pause();
}