/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
    2   3
    \   \ 
    3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
    3
    / \
    4   5
    / \   \ 
    1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

#include "essentials.h"

class Solution {
public:
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        else {
            auto result = robNode(root);
            return std::max(result.first, result.second);
        }
    }
private:
    // return: {maximum money if rob this node, maximum money if not rob this node}, in terms of its subtree
    std::pair<int, int> robNode(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) return {node->val, 0};
        else if (node->right == NULL) {
            auto child = robNode(node->left);
            return {node->val + child.second, std::max(child.first, child.second)};
        }
        else if (node->left == NULL) {
            auto child = robNode(node->right);
            return {node->val + child.second, std::max(child.first, child.second)};
        }
        else {
            auto child1 = robNode(node->left), child2 = robNode(node->right);
            return {node->val + child1.second + child2.second, std::max(child1.first, child1.second) + std::max(child2.first, child2.second)};
        }
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    auto tree = std::make_shared<TreeNode>(std::vector<int>{3,2,3,TreeNode::null,3,TreeNode::null,1});
    assert(sol->rob(tree.get()) == 7);
    tree = std::make_shared<TreeNode>(std::vector<int>{3,4,5,1,3,TreeNode::null,1});
    assert(sol->rob(tree.get()) == 9);
    tree = std::make_shared<TreeNode>(std::vector<int>{2,3});
    assert(sol->rob(tree.get()) == 3);
    tree = std::make_shared<TreeNode>(std::vector<int>{2});
    assert(sol->rob(tree.get()) == 2);
}

