/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.
*/

#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1

// DP O(n^2), lis[i] stores the length of lis for nums[:i+1]
class Solution {
public:
	int lengthOfLIS(const std::vector<int>& nums) {
		if (nums.size() == 0) return 0;
		std::vector<int> lis{ 1 };
		for (size_t i = 1; i < nums.size(); i++) {
			int x = 1;
			for (size_t j = 0; j < i; j++) {
				if (nums[j] < nums[i] && x < lis[j] + 1) x = lis[j] + 1;
			}
			lis.push_back(x);
		}
		return *std::max_element(lis.cbegin(), lis.cend());
	}
};

#endif

#ifdef __SOLUTION_2

// DP O(nlongn), lis[n] stores the smallest possible value of all the largest value in the lis of length n+1
// e.g. [4,5,6,3], lis[0]=3; lis[1]=5; lis[2]=6
// if lis[n-1] < x <= lis[n], update lis[n]=x
class Solution {
public:
	int lengthOfLIS(const std::vector<int>& nums) {
		if (nums.size() == 0) return 0;
		std::vector<int> lis{ nums[0] };
		for (size_t i = 1; i < nums.size(); i++) {
			int x = nums[i];
			if (x <= lis[0]) lis[0] = x;
			else if (x > lis.back()) lis.push_back(x);
			else {
				int l = 0, r = lis.size() - 1;
				while (l < r - 1) {
					int m = (l + r) / 2;
					if (lis[m] < x) l = m;
					else r = m;
				}
				lis[r] = x;
			}
		}
		return lis.size();
	}
};

#endif

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->lengthOfLIS(std::vector < int > {10, 9, 2, 5, 3, 7, 101, 18}) == 4);
	assert(sol->lengthOfLIS(std::vector < int > {2, 1}) == 1);
	assert(sol->lengthOfLIS(std::vector<int>()) == 0);
}