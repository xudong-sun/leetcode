/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

#include "essentials.h"

#define __SOLUTION_3

#ifdef __SOLUTION_1

// Binary Index Tree
class Solution {
public:
	std::vector<int> countSmaller(const std::vector<int>& nums) {
		// discretize
		int n = nums.size();
		std::map<int, int> mapping;
		for (auto x : nums) mapping[x] = 0;
		int i = 1;
		for (auto it = mapping.begin(); it != mapping.end(); it++, i++) (*it).second = i;
		std::vector<int> dnums(n, 0);
		for (int i = 0; i < n; i++) dnums[i] = mapping[nums[i]];
		// BIT
		std::vector<int> bit(mapping.size() + 1, 0);
		std::vector<int> ans(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			ans[i] = BITGet(bit, dnums[i] - 1);
			BITUpdate(bit, dnums[i]);
		}
		return ans;
	}
private:
	void BITUpdate(std::vector<int>& bit, int pos) {
		int n = bit.size();
		while (pos < n) {
			bit[pos]++;
			pos += pos & (-pos);
		}
	}
	int BITGet(const std::vector<int>& bit, int pos) {
		int ans = 0;
		while (pos > 0) {
			ans += bit[pos];
			pos = pos & (pos - 1);
		}
		return ans;
	}
};

#endif

#ifdef __SOLUTION_2

// Segment Tree
class Solution {
public:
	std::vector<int> countSmaller(const std::vector<int>& nums) {
		// discretize
		int n = nums.size();
		std::map<int, int> mapping;
		for (auto x : nums) mapping[x] = 0;
		int i = 0;
		for (auto it = mapping.begin(); it != mapping.end(); it++, i++) (*it).second = i;
		std::vector<int> dnums(n, 0);
		for (int i = 0; i < n; i++) dnums[i] = mapping[nums[i]];
		// segment tree
		int tree_size = mapping.size();
		std::vector<int> tree(tree_size * 4, 0);
		std::vector<int> ans(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			ans[i] = getRangeSum(tree, 0, 0, dnums[i] - 1, 0, tree_size - 1);
			updateTree(tree, 0, dnums[i], 0, tree_size - 1);
		}
		return ans;
	}
private:
	void updateTree(std::vector<int>& tree, int pos, int x, int l, int r) {
		tree[pos]++;
		if (l == r) return;
		int m = l + ((r - l) >> 1);
		if (x <= m) updateTree(tree, 2 * pos + 1, x, l, m);
		else updateTree(tree, 2 * pos + 2, x, m + 1, r);
	}
	int getRangeSum(const std::vector<int>& tree, int pos, int x, int y, int l, int r) {
		if (x <= l && y >= r) return tree[pos];
		else if (x > r || y < l) return 0;
		else {
			int m = l + ((r - l) >> 1);
			return getRangeSum(tree, 2 * pos + 1, x, y, l, m) + getRangeSum(tree, 2 * pos + 2, x, y, m + 1, r);
		}
	}
};

#endif

#ifdef __SOLUTION_3

// binary search tree
// keep track of #smaller_numbers, #duplicates at each node
class Solution {
public:
	std::vector<int> countSmaller(const std::vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return {};
		std::vector<int> ans(n, 0);
		TreeNode* bst = new TreeNode(nums.back());
		for (int i = n - 2; i >= 0; i--) ans[i] = updateBST(bst, nums[i]);
		return ans;
	}
private:
	struct TreeNode {
		int val, smallCount, dupCount;
		TreeNode* left, *right;
		TreeNode(int val) : val(val), smallCount(0), dupCount(1), left(nullptr), right(nullptr) {}
	};
	int updateBST(TreeNode* node, int x) {
		if (node->val == x) {
			node->dupCount++;
			return node->smallCount;
		}
		else if (node->val > x) {
			node->smallCount++;
			if (node->left != nullptr) return updateBST(node->left, x);
			else {
				node->left = new TreeNode(x);
				return 0;
			}
		}
		else {
			if (node->right != nullptr) return node->smallCount + node->dupCount + updateBST(node->right, x);
			else {
				node->right = new TreeNode(x);
				return node->smallCount + node->dupCount;
			}
		}
	}
};

#endif

int main() {
	auto sol = std::make_unique<Solution>();
	commons::print(sol->countSmaller(std::vector < int > {5, 2, 6, 1})); // 2,1,1,0
	commons::print(sol->countSmaller(std::vector < int > {3, 2, 2, 6, 1, 6})); // 3,1,1,1,0,0
	commons::print(sol->countSmaller(std::vector < int > {1})); // 0
	commons::print(sol->countSmaller(std::vector<int>())); // []
	commons::pause();
}