/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

_______6______
/              \
___2__          ___8__
/      \        /      \
0      _4       7       9
      /  \
      3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

#include "essentials.h"
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (1) {
			if (root->val > p->val && root->val > q->val) root = root->left;
			else if (root->val < p->val && root->val < q->val) root = root->right;
			else return root;
		}
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	auto tree = std::make_shared<TreeNode>(std::vector < int > {6, 2, 8, 0, 4, 7, 9, TreeNode::null, TreeNode::null, 3, 5});
	assert(sol->lowestCommonAncestor(tree.get(), tree->left, tree->right)->val == 6);
	assert(sol->lowestCommonAncestor(tree.get(), tree->left, tree->left->right)->val == 2);
}