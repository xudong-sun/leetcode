/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

#include "essentials.h"

class Solution {
public:
	int missingNumber(std::vector<int>& nums) 
	{
		int n = nums.size(), key = 0;
		for (int i = 0; i < n; i++) key ^= i ^ nums[i];
		key ^= n;
		return key;
	}
};

int main() {
	auto sol = new Solution();
	std::cout << sol->missingNumber(std::vector < int > {0, 3, 1}) << std::endl;
	delete sol;
	commons::pause();
}