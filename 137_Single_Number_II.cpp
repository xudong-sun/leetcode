/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
Solution:
For each bit, count the number of 1's across all numbers, then mod 3
*/

#include "essentials.h"
#define MAX_NUM_BIT 32

class Solution {
public:
	int singleNumber(std::vector<int>& nums) {
		int cnt, ans = 0;
		for (size_t i = 0; i < MAX_NUM_BIT; i++) {
			cnt = 0;
			for (size_t j = 0; j < nums.size(); j++) {
				cnt += (nums[j] >> i) & 1;
			}
			ans |= (cnt % 3) << i;
		}
		return ans;
	}
};

int main() {
	Solution* sol = new Solution();
	std::cout << sol->singleNumber(std::vector < int > {4, 2, 5, 5, 4, 5, 4}) << std::endl;
	delete sol;
	commons::pause();
}