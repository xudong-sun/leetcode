/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include "essentials.h"

class Solution {
public:
	void moveZeroes(std::vector<int>& nums) 
	{
		unsigned int i = 0, j = 0;
		while (i < nums.size())
		{
			if (nums[i] == 0) break;
			i++;
		}
		if (i == nums.size()) return;
		j = i; i++;
		while (i < nums.size())
		{
			if (nums[i] != 0)
			{
				std::swap(nums[i], nums[j]);
				j++; i++;
			}
			else
			{
				i++;
			}
		}
	}
};

int main() {
	auto sol = new Solution();
	std::vector<int> vec{ 0, 1, 0, 3, 23, 0 };
	sol->moveZeroes(vec);
	std::cout << vec << std::endl;
	delete sol;
	commons::pause();
}