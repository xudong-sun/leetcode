/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

// Hint: use a static, so that results can be saved between different test cases.
// Solution: DP, O(n^1.5)

#include "essentials.h"

class Solution {
public:
	int numSquares(int n) {
		if (n < ans.size()) return ans[n];
		for (size_t i = ans.size(); i <= n; i++) {
			int x = INT_MAX;
			for (int j = 1; j*j <= i; j++) x = std::min(x, ans[i - j*j] + 1);
			ans.push_back(x);
		}
		return ans[n];
	}
private:
	static std::vector<int> ans;
};
std::vector<int> Solution::ans = { 0 };

int main() {
	auto sol = new Solution();
	int ans[10] = { 1, 2, 3, 1, 2, 3, 4, 2, 1, 2 };
	for (int i = 1; i <= 10; i++) assert(sol->numSquares(i) == ans[i - 1]);
	assert(sol->numSquares(19) == 3);
	assert(sol->numSquares(12) == 3);
	assert(sol->numSquares(13) == 2);
	delete sol;
}