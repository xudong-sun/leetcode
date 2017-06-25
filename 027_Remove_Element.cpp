/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include "essentials.h"

class Solution 
{
public:
	int removeElement(std::vector<int>& nums, int val) 
	{
		unsigned int i = 0, j = 0;
		while (i < nums.size())
		{
			if (nums[i] != val) nums[j++] = nums[i];
			i++;
		}
		return j;
	}
};

int main() {
	Solution* sol = new Solution();
	std::vector<int> vec { 1, 2, 3, 4, 5 };
	std::cout << sol->removeElement(vec, 3) << std::endl;
	std::cout << vec << std::endl;
	pause();
}