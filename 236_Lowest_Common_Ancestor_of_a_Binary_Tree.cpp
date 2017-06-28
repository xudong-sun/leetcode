/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

_______3______
/              \
___5__          ___1__
/      \        /      \
6      _2       0       8
      /  \
      7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

#include "essentials.h"
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		ans = NULL;
		found = false;
		numOfNodes(root, p, q);
		return ans;
	}
private:
	int numOfNodes(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return 0;
		int tmp = int(root == p) + int(root == q);
		if (tmp == 2) {
			updateAns(root);
			return 2;
		}
		tmp += numOfNodes(root->left, p, q);
		if (tmp == 2) {
			updateAns(root);
			return 2;
		}
		tmp += numOfNodes(root->right, p, q);
		if (tmp == 2) {
			updateAns(root);
			return 2;
		}
		return tmp;
	}
	void updateAns(TreeNode* ans) {
		if (!found) {
			this->ans = ans;
			found = true;
		}
	}
	TreeNode* ans;
	bool found;
};

int main() {
	auto sol = std::make_unique<Solution>();
	auto tree = std::make_shared<TreeNode>(std::vector < int > {3, 5, 1, 6, 2, 0, 8, TreeNode::null, TreeNode::null, 7, 4});
	assert(sol->lowestCommonAncestor(tree.get(), tree->left, tree->right)->val == 3);
	assert(sol->lowestCommonAncestor(tree.get(), tree->left, tree->left->right->right)->val == 5);
	tree = std::make_shared<TreeNode>(std::vector < int > {1, 2});
	assert(sol->lowestCommonAncestor(tree.get(), tree.get(), tree->left)->val == 1);
}