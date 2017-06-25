/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
Solution:
XOR all the entries
*/

#include "essentials.h"

class Solution {
public:
	int singleNumber(std::vector<int>& nums) {
		int ans = 0;
		for (size_t i = 0; i < nums.size(); i++) ans ^= nums[i];
		return ans;
	}
};

int main() {
	Solution* sol = new Solution();
	std::cout << sol->singleNumber(std::vector < int > {4, 2, 5, 4, 5}) << std::endl;
	delete sol;
	commons::pause();
}