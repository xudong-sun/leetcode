/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

/*
Solution:
key: XOR of the two numbers
code: used to separate them, by whether key&code==0
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) 
	{
		int key = 0;
		for (int i = 0; i < nums.size(); i++) key ^= nums[i];
		int code = 1;
		while ((key & code) == 0) code <<= 1;
		int key1 = 0, key2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if ((nums[i] & code) == 0) key1 ^= nums[i]; else key2 ^= nums[i];
		}
		vector<int> ans; ans.clear(); ans.push_back(key1); ans.push_back(key2); return ans;
	}
};