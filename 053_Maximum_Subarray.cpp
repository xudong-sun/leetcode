/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1
// Solution O(n). Recursion

class Solution {
public:
	int maxSubArray(std::vector<int>& nums) 
	{
		if (nums.size() == 0) return 0;
		int max = nums[0], max_temp = max;
		for (int i = 1; i < nums.size(); i++)
		{
			if (max_temp>0) max_temp += nums[i]; else max_temp = nums[i];
			if (max_temp > max) max = max_temp;
		}
		return max;
	}
};

#endif

#ifdef __SOLUTION_2
// Solution O(n). Divide and Conquer

class Solution {
public:
	int maxSubArray(std::vector<int>& nums)
	{
		int max_value, max_left, max_right, sum;
		maxSubArray(nums, &max_value, &max_left, &max_right, &sum, 0, nums.size() - 1);
		return max_value;
	}
private:
	void maxSubArray(std::vector<int>& nums, int* max_value, int* max_left, int* max_right, int* sum, int l, int r)
	{
		if (l == r)
		{
			*max_value = nums[l]; *max_left = nums[l]; *max_right = nums[l]; *sum = nums[l];
			return;
		}
		int m = (l + r) / 2;
		int max_l, max_r, max_margin_ll, max_margin_lr, max_margin_rl, max_margin_rr, sum_l, sum_r;
		maxSubArray(nums, &max_l, &max_margin_ll, &max_margin_lr, &sum_l, l, m);
		maxSubArray(nums, &max_r, &max_margin_rl, &max_margin_rr, &sum_r, m + 1, r);
		*max_value = std::max(std::max(max_l, max_r), max_margin_lr + max_margin_rl);
		*max_left = std::max(max_margin_ll, sum_l + max_margin_rl);
		*max_right = std::max(max_margin_rr, sum_r + max_margin_lr);
		*sum = sum_l + sum_r;
	}
};

#endif

int main() {
	Solution* sol = new Solution();
	std::vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	std::cout << sol->maxSubArray(nums) << std::endl;
	commons::pause();
	delete sol;
}