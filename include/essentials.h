#ifndef __ESSENTIALS_H
#define __ESSENTIALS_H

#include <string>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <iostream>
#include <memory>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <algorithm>

#include <assert.h>

#include "commons.h"
#include "print_utils.h"

class ListNode {
public:
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(const std::vector<int>& nums) : val(nums[0]) {
		auto node = this;
		for (size_t i = 1; i < nums.size(); i++) {
			int num = nums[i];
			auto new_node = new ListNode(num);
			node->next = new_node;
			node = new_node;
		}
	}
	~ListNode() {
		if (next != NULL) delete next;
	}
	int val;
	ListNode *next;
};

std::ostream& operator<<(std::ostream& os, const ListNode& list) {
	os << list.val;
	if (list.next != NULL) {
		os << " -> " << *(list.next);
	}
	return os;
}

class TreeNode {
public:
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(const std::vector<int>& nums) : val(nums[0]), left(NULL), right(NULL) {
		std::vector<TreeNode*> nodes{ this };
		for (size_t i = 1; i < nums.size(); i++) {
			int num = nums[i];
			if (num == null) { nodes.push_back(NULL); }
			else {
				auto node = new TreeNode(nums[i]);
				nodes.push_back(node);
			}
		}
		for (size_t i = 0; 2 * i + 1 < nums.size(); i++)
			if (nodes[i] != NULL) {
				nodes[i]->left = nodes[2 * i + 1];
				if (2 * i + 2 < nums.size()) nodes[i]->right = nodes[2 * i + 2];
			}
	}
	~TreeNode() {
		if (left != NULL) delete left;
		if (right != NULL) delete right;
	}
	int val;
	TreeNode *left;
	TreeNode *right;
	const static int null = INT_MIN;
};

// print the tree in pre-order traversal
std::ostream& operator<<(std::ostream& os, const TreeNode& node) {
	os << node.val;
	if (node.left == NULL) os << ", null";
	else os << ", " << *(node.left);
	if (node.right == NULL) os << ", null";
	else os << ", " << *(node.right);
	return os;
}

#endif