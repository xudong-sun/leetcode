/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

/*
Solution O(n). Recursion

#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) 
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
*/

/*
Solution O(n). Divide and Conquer
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int max_value, max_left, max_right, sum;
		maxSubArray(nums, &max_value, &max_left, &max_right, &sum, 0, nums.size() - 1);
		return max_value;
	}
private:
	void maxSubArray(vector<int>& nums, int* max_value, int* max_left, int* max_right, int* sum, int l, int r)
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
		*max_value = max(max(max_l, max_r), max_margin_lr + max_margin_rl);
		*max_left = max(max_margin_ll, sum_l + max_margin_rl);
		*max_right = max(max_margin_rr, sum_r + max_margin_lr);
		*sum = sum_l + sum_r;
	}
};