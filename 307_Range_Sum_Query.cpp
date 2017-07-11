/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

#include "essentials.h"

// Binary Index Tree (BIT), aka Fenwick Tree
// simpler than segment tree. point update, region query

#define __SOLUTION_2

#ifdef __SOLUTION_1

// O(nlogn), Binary Index Tree
class NumArray {
public:
	NumArray(std::vector<int> nums) {
		this->nums = nums;
		bit = std::vector<int>(nums.size() + 1, 0);
		for (size_t i = 0; i < nums.size(); i++) {
			int idx = i + 1;
			while (idx < bit.size()) {
				bit[idx] += nums[i];
				idx += idx & -idx;
			}
		}
	}

	void update(int i, int val) {
		int idx = i + 1;
		int oldValue = nums[i];
		nums[i] = val;
		while (idx < bit.size()) {
			bit[idx] += val - oldValue;
			idx += idx & -idx;
		}
	}

	int sumRange(int i, int j) {
		// first find `common`
		// e.g. 9..11 = (bit[11] + bit[10] + bit[8]) - (bit[9] + bit[8])
		// if we find out `common` == 8, then 9..11 = (bit[11] + bit[10]) - (bit[9])
		// checkout 201_Bitwise_AND_of_Numbers_Range.py for algorithm to find `common`
		j++;
		int common = j;
		while (common > i) common = common & (common - 1);
		int x = 0;
		while (j > common) {
			x += bit[j];
			j = j & (j - 1);
		}
		while (i > common) {
			x -= bit[i];
			i = i & (i - 1);
		}
		return x;
	}
private:
	std::vector<int> bit;
	std::vector<int> nums; // this field can be removed, since nums can be reconstructed from bit
};

#endif

#ifdef __SOLUTION_2

// O(nlogn), Segment Tree
class NumArray {
public:
	NumArray(const std::vector<int>& nums) {
		if (nums.size() > 0) tree = buildTree(nums, 0, nums.size() - 1);
	}

	void update(int i, int val) {
		updateTree(i, val, tree);
	}

	int sumRange(int i, int j) {
		return getSum(i, j, tree);
	}
private:
	struct TreeNode {
		int left_boundary, right_boundary, val;
		std::shared_ptr<TreeNode> left, right;
		TreeNode(int val, int l, int r) : val(val), left_boundary(l), right_boundary(r), left(nullptr), right(nullptr) {}
	};
	std::shared_ptr<TreeNode> buildTree(const std::vector<int>& nums, int l, int r) {
		if (l == r) return std::make_shared<TreeNode>(nums[l], l, r);
		auto node = std::make_shared<TreeNode>(0, l, r);
		int m = l + (r - l) / 2;
		node->left = buildTree(nums, l, m);
		node->right = buildTree(nums, m + 1, r);
		node->val = node->left->val + node->right->val;
		return node;
	}
	int updateTree(int p, int val, std::shared_ptr<TreeNode> node) {
		if (node->left == nullptr) {
			int diff = val - node->val;
			node->val = val;
			return diff;
		}
		int m = node->left_boundary + (node->right_boundary - node->left_boundary) / 2;
		int diff;
		if (p <= m) diff = updateTree(p, val, node->left);
		else diff = updateTree(p, val, node->right);
		node->val += diff;
		return diff;
	}
	int getSum(int i, int j, std::shared_ptr<TreeNode> node) {
		if (i <= node->left_boundary && j >= node->right_boundary) return node->val;
		else if (i > node->right_boundary || j < node->left_boundary) return 0;
		else {
			int m = node->left_boundary + (node->right_boundary - node->left_boundary) / 2;
			if (i > m) return getSum(i, j, node->right);
			else if (j <= m) return getSum(i, j, node->left);
			else return getSum(i, j, node->left) + getSum(i, j, node->right);
		}
	}
	std::shared_ptr<TreeNode> tree;
};

#endif

int main() {
	auto sol = std::make_unique < NumArray >(std::vector < int > {1, 3, 5, 7});
	assert(sol->sumRange(0, 2) == 9);
	sol->update(1, 2);
	assert(sol->sumRange(0, 2) == 8);
	assert(sol->sumRange(1, 3) == 14);
}