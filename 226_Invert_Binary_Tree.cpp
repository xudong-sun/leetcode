/*
Invert a binary tree.

4
/   \
2     7
/ \   / \
1   3 6   9
to
4
/   \
7     2
/ \   / \
9   6 3   1
*/

#include "essentials.h"

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return NULL;
		auto queue = new std::queue<TreeNode*>();
		queue->push(root);
		while (!queue->empty()) {
			auto node = queue->front();
			queue->pop();
			std::swap(node->left, node->right);
			if (node->left != NULL) queue->push(node->left);
			if (node->right != NULL) queue->push(node->right);
		}
		delete queue;
		return root;
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	auto tree = new TreeNode(std::vector < int > {4, 2, 7, 1, 3, 6, 9});
	tree = sol->invertTree(tree);
	commons::print(*tree);
	delete tree;
	tree = new TreeNode(std::vector < int > {4, 2, 7, TreeNode::null, 3, 6});
	tree = sol->invertTree(tree);
	commons::print(*tree);
	delete tree;
	tree = new TreeNode(std::vector < int > {1, 2});
	tree = sol->invertTree(tree);
	commons::print(*tree);
	delete tree;
	commons::pause();
}