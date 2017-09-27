/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
    /  \
    5   -3
    / \    \
    3   2   11
    / \   \
    3  -2   1
Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/


#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1
// O(n^2) solution, 119ms

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        auto m = pathSumSubTree(root, sum);
        return m.second + m.first[sum];
    }
private:
    // {if path includes this node, <value, count>; if path does not include this node, #path that equals sum}
    std::pair<std::map<int, int>, int> pathSumSubTree(TreeNode* node, int sum) {
        if (node == NULL) return {std::map<int, int>{}, 0};
        if (node->left == NULL && node->right == NULL) return {std::map<int, int>{{node->val, 1}}, 0};
        else {
            std::map<int, int> mapping;
            auto child1 = pathSumSubTree(node->left, sum), child2 = pathSumSubTree(node->right, sum);
            for (auto m : child1.first) {
                mapping[m.first + node->val] = m.second;
            }
            for (auto m : child2.first) {
                mapping[m.first + node->val] += m.second;
            }
            mapping[node->val]++;
            auto cnt = child1.second + child2.second;
            if (child1.first.find(sum) != child1.first.cend()) cnt += child1.first.at(sum);
            if (child2.first.find(sum) != child2.first.cend()) cnt += child2.first.at(sum);
            return {mapping, cnt};
        }
    }
};

#endif

#ifdef __SOLUTION_2
// Subtask 1: given an array of numbers, find the number of pairs <i,j>, such that j>i && num[j]-num[i]==target
// Solution: similar to 001_Two_Sum, we use a map to record the numbers that appeared before i
// Subtask 2: given an array of numbers, find the number of intervals [i,j], such that the sum of num[i..j]==target
// Solution: we convert the numbers to sum[0..j], and it falls back to subtask 1
// for this task, we use dfs, with the idea in subtask 2
// O(n), 9ms

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        total = 0;
        std::unordered_map<int, int> mapping{{0, 1}};
        pathSum(root, sum, mapping, 0);
        return total;
    }
private:
    void pathSum(TreeNode* node, int target, std::unordered_map<int, int>& mapping, int curSum) {
        if (node == NULL) return;
        curSum += node->val;
        if (mapping.find(curSum - target) != mapping.cend()) total += mapping.at(curSum - target);
        mapping[curSum]++;
        pathSum(node->left, target, mapping, curSum);
        pathSum(node->right, target, mapping, curSum);
        if (mapping[curSum] == 1) mapping.erase(curSum); else mapping[curSum]--;
    }
    int total = 0;
};

#endif

int main() {
    auto sol = std::make_unique<Solution>();
    auto tree = std::make_shared<TreeNode>(std::vector<int>{10,5,-3,3,2,TreeNode::null,11,3,-2,TreeNode::null,1});
    assert(sol->pathSum(tree.get(), 8) == 3);
    tree = std::make_shared<TreeNode>(std::vector<int>{1,TreeNode::null,2,TreeNode::null,TreeNode::null,TreeNode::null,3,TreeNode::null,TreeNode::null,TreeNode::null,TreeNode::null,TreeNode::null,TreeNode::null,TreeNode::null,4});
    assert(sol->pathSum(tree.get(), 3) == 2);
}

