/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

Constraints:

The number of nodes in each tree is in the range [0, 100].
Each tree will have unique node values in the range [0, 99].
*/


#include "essentials.h"
#define null INT_MIN

class Solution {
public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) return true;
		else if (root1 == nullptr || root2 == nullptr) return false;
    if (root1->val != root2->val) return false;
    bool case1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    bool case2 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    return case1 || case2;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  TreeNode* root1 = new TreeNode({1,2,3,4,5,6,null,null,null,7,8});
  TreeNode* root2 = new TreeNode({1,3,2,null,6,4,5,null,null,null,null,null,null,8,7});
  assert(sol->flipEquiv(root1, root2) == true);
}

