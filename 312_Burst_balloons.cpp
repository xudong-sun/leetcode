/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100

Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

#include "essentials.h"

// Solution O(n^3), DP
// a[i,j]: maxCoins for balloons ranging from [i,j]
// a[i,j] = max(a[i,k-1] + nums[i-1] * nums[k] * nums[j+1] + a[k+1,j]), i<=k<=j

class Solution {
public:
	int maxCoins(std::vector<int>& nums) {
		std::vector<int> x{ 1 };
		std::copy_if(nums.cbegin(), nums.cend(), std::back_inserter(x), [](int x) { return x != 0; });
		x.push_back(1);
		int n = x.size();
		std::vector<std::vector<int>> a;
		for (int i = 0; i < n; i++) a.emplace_back(n, 0);
		for (int i = 1; i < n - 1; i++) a[i][i] = x[i - 1] * x[i] * x[i + 1];
		for (int l = 1; l < n; l++) {
			for (int i = 1; i < n - 1 - l; i++) {
				int j = i + l;
				for (int k = i; k <= j; k++)
					a[i][j] = std::max(a[i][j], a[i][k - 1] + x[i - 1] * x[k] * x[j + 1] + a[k + 1][j]);
			}
		}
		return a[1][n - 2];
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->maxCoins(std::vector < int > {3, 1, 5, 8}) == 167);
	assert(sol->maxCoins(std::vector < int > {3, 1, 0, 5, 0, 0, 8, 0}) == 167);
	assert(sol->maxCoins(std::vector < int > {8}) == 8);
	assert(sol->maxCoins(std::vector < int > {0}) == 0);
	assert(sol->maxCoins(std::vector<int>()) == 0);
}