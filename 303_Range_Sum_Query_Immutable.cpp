/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include "essentials.h"

class NumArray {
public:
	NumArray(const std::vector<int>& nums) {
		if (nums.size() == 0) return;
		cumsum.push_back(nums[0]);
		for (size_t i = 1; i < nums.size(); i++) cumsum.push_back(cumsum.back() + nums[i]);
	}
	int sumRange(int i, int j) {
		return i == 0 ? cumsum[j] : cumsum[j] - cumsum[i - 1];
	}
private:
	std::vector<int> cumsum{};
};

int main() {
	auto sol = std::make_unique<NumArray>(std::vector < int > {-2, 0, 3, -5, 2, -1});
	assert(sol->sumRange(0, 2) == 1);
	assert(sol->sumRange(2, 5) == -1);
	assert(sol->sumRange(0, 5) == -3);
}