/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

#include "essentials.h"

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) 
	{
		return searchInsert(nums, target, 0, nums.size() - 1);
	}
private:
	int searchInsert(std::vector<int>& nums, int target, int x, int y)
	{
		if (y < x) return x;
		if (x == y)
		{
			if (nums[x] >= target) return x;
			else return x + 1;
		}
		int m = (x + y) / 2;
		if (nums[m] == target) return m;
		if (nums[m] > target) return searchInsert(nums, target, x, m - 1); else return searchInsert(nums, target, m + 1, y);
	}
};

int main() {
	Solution* sol = new Solution();
	std::vector<int> vec{ 1, 3, 5, 6 };
	std::cout << sol->searchInsert(vec, 2) << std::endl;
	pause();
}