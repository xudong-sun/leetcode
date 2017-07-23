/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]
*/

#include "essentials.h"

class Solution {
public:
	std::vector<int> maxNumber(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
		std::vector<int> result(k, 0);
		int x1 = std::max(0, k - static_cast<int>(nums2.size())), x2 = std::min(k, static_cast<int>(nums1.size()));
		for (int k1 = x1; k1 <= x2; k1++) result = std::max(result, merge(maxNumber(nums1, k1), maxNumber(nums2, k - k1)));
		return result;
	}
private:
	// O(n), find the maxNumber of length k in a vector
	// use a stack, pop out smaller numbers
	std::vector<int> maxNumber(const std::vector<int>& nums, int k) {
		std::vector<int> result(k, 0);
		int pos = 0, n=nums.size();
		for (int i = 0; i < n; i++) {
			while (pos > 0 && pos > k - n + i && result[pos - 1] < nums[i]) pos--;
			if (pos < k) result[pos++] = nums[i];
		}
		return result;
	}
	/* This implementation is obsolete with O(nk)
	std::vector<int> maxNumber(const std::vector<int>& nums, int k) {
		std::vector<int> result;
		int start = 0;
		for (int i = 0; i < k; i++) {
			int end = nums.size() - k + i;
			int maxDigit = -1, index = 0;
			for (; start <= end; start++) {
				if (nums[start] > maxDigit) {
					maxDigit = nums[start];
					index = start;
				}
			}
			result.push_back(maxDigit);
			start = index + 1;
		}
		return result;
	}*/
	// O(k) on average, O(k^2) worst case, merge
	std::vector<int> merge(const std::vector<int>& nums1, const std::vector<int>& nums2) {
		std::vector<int> result;
		auto resultIt = std::back_inserter(result);
		auto it1 = nums1.cbegin(), it2 = nums2.cbegin();
		while (it1 != nums1.cend() && it2 != nums2.cend()) {
			if (*it1 > *it2) *resultIt = *it1++;
			else if (*it1 < *it2) *resultIt = *it2++;
			else *resultIt = *(compare(it1, nums1.cend(), it2, nums2.cend())++);
		}
		if (it1 != nums1.cend()) std::copy(it1, nums1.cend(), resultIt);
		if (it2 != nums2.cend()) std::copy(it2, nums2.cend(), resultIt);
		return result;
	}
	// To compare how to merge when two digits are equal, we have to compare the following digits
	// If all digits are the same until the end of the vector, choose the longer one
	std::vector<int>::const_iterator& compare(std::vector<int>::const_iterator& it1, std::vector<int>::const_iterator end1, std::vector<int>::const_iterator& it2, std::vector<int>::const_iterator end2) {
		auto itt1 = it1, itt2 = it2;
		while (itt1 != end1 && itt2 != end2) {
			if (*itt1 > *itt2) return it1;
			else if (*itt1 < *itt2) return it2;
			itt1++; itt2++;
		}
		return itt1 == end1 ? it2 : it1;
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	commons::print(sol->maxNumber(std::vector < int > {3, 4, 6, 5}, std::vector < int > {9, 1, 2, 5, 8, 3}, 5));  // 9, 8, 6, 5, 3
	commons::print(sol->maxNumber(std::vector < int > {6, 7}, std::vector < int > {6, 0, 4}, 5));  // 6, 7, 6, 0, 4
	commons::print(sol->maxNumber(std::vector < int > {3, 9}, std::vector < int > {8, 9}, 3));  // 9, 8, 9
	commons::print(sol->maxNumber(std::vector < int > {2, 2, 1, 3, 8}, std::vector < int > {2, 2, 2, 3, 5}, 9)); // 2, 2, 3, 8, 2, 2, 2, 3, 5
	commons::print(sol->maxNumber(std::vector < int > {3, 3, 5, 3, 3, 5, 4}, std::vector < int > {3, 3, 5}, 10)); // 3, 3, 5, 3, 3, 5, 4, 3, 3, 5
	commons::print(sol->maxNumber(std::vector < int > {3, 3, 5, 3, 3, 2, 4}, std::vector < int > {3, 3, 5}, 10)); // 3, 3, 5, 3, 3, 5, 3, 3, 2, 4
	commons::print(sol->maxNumber(std::vector < int > {1, 1, 4}, std::vector < int > {1, 3, 5, 9}, 7)); // 1, 3, 5, 9, 1, 1, 4
	commons::pause();
}