/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

1
/   \
2     3
\
5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

#include "essentials.h"

class Solution {
public:
	std::vector<std::string> binaryTreePaths(TreeNode* root) {
		if (root == NULL) return res;
		traverse(root, std::to_string(root->val));
		return res;
	}
private:
	void traverse(TreeNode* node, std::string path) {
		bool is_leaf = true;
		if (node->left != NULL) {
			traverse(node->left, path + "->" + std::to_string(node->left->val));
			is_leaf = false;
		}
		if (node->right != NULL) {
			traverse(node->right, path + "->" + std::to_string(node->right->val));
			is_leaf = false;
		}
		if (is_leaf) res.push_back(path);
	}
	std::vector<std::string> res;
};

int main() {
	auto sol = std::make_unique<Solution>();
	auto tree = std::make_shared<TreeNode>(std::vector < int > {1, 2, 3, TreeNode::null, 5});
	commons::print(sol->binaryTreePaths(tree.get()));
	sol = std::make_unique<Solution>();
	commons::print(sol->binaryTreePaths(NULL));
	commons::pause();
}