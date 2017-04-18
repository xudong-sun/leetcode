/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
	int removeElement(vector<int>& nums, int val) 
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