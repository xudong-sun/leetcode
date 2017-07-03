/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n^2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1
// binary search the answer space of [1,n]

class Solution {
public:
	int findDuplicate(std::vector<int>& nums) {
		int l = 1, r = nums.size();
		while (l < r) {
			int m = l + ((r - l) >> 1);
			int cnt = std::count_if(nums.cbegin(), nums.cend(), [m](int x) { return x <= m; });
			if (cnt > m) r = m;
			else l = m + 1;
		}
		return l;
	}
};

#endif

#ifdef __SOLUTION_2
// similar to 142_Linked_list_Cycle_II
// treat nums[x] = y as a ListNode x pointing to y

class Solution {
public:
	int findDuplicate(std::vector<int>& nums) {
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		slow = 0;
		do {
			slow = nums[slow];
			fast = nums[fast];
		} while (slow != fast);
		return slow;
	}
};

#endif

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->findDuplicate(std::vector < int > {3, 2, 4, 1, 2, 5}) == 2);
	assert(sol->findDuplicate(std::vector < int > {1, 2, 3, 4, 1}) == 1);
	assert(sol->findDuplicate(std::vector < int > {5, 2, 1, 5, 4, 5}) == 5);
	assert(sol->findDuplicate(std::vector < int > {1, 1}) == 1);
}