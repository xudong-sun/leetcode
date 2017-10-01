/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
        / \
        2   3
        / \     
        4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Note: The length of path between two nodes is represented by the number of edges between them.
*/

#include "essentials.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
private:
    int depth(TreeNode* node) {
        if (node == NULL) return 0;
        else {
            int l = depth(node->left), r = depth(node->right);
            if (l + r > ans) ans = l + r;
            return std::max(l, r) + 1;
        }
    }
    int ans;
};

int main() {
    auto sol = std::make_unique<Solution>();
    auto tree = std::make_shared<TreeNode>(std::vector<int>{1,2,3,4,5});
    assert(sol->diameterOfBinaryTree(tree.get()) == 3);
    tree = std::make_shared<TreeNode>(std::vector<int>{1,2,TreeNode::null,4,5,TreeNode::null,TreeNode::null,8});
    assert(sol->diameterOfBinaryTree(tree.get()) == 3);
    tree = std::make_shared<TreeNode>(std::vector<int>{1,TreeNode::null,3,TreeNode::null,TreeNode::null,6});
    assert(sol->diameterOfBinaryTree(tree.get()) == 2);
    tree = std::make_shared<TreeNode>(std::vector<int>{1});
    assert(sol->diameterOfBinaryTree(tree.get()) == 0);
    assert(sol->diameterOfBinaryTree(NULL) == 0);
}

