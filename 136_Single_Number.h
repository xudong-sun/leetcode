/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
Solution:
XOR all the entries
*/

#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		int ans = 0;
		for (unsigned int i = 0; i < nums.size(); i++) ans ^= nums[i];
		return ans;
	}
};