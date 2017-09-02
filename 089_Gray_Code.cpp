/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/

#include "essentials.h"

class Solution {
public:
	std::vector<int> grayCode(int n) {
		std::vector<int> ans;
		ans.push_back(0);
		int total = 1 << n;
		for (int i = 1; i < total; i++) ans.push_back(ans.back() ^ (i & -i));
		return ans;
	}
};

int main() {
	Solution* sol = new Solution();
	std::cout << sol->grayCode(3) << std::endl;
	commons::pause();
	delete sol;
}
