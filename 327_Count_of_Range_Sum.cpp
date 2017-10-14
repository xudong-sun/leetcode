/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n^2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/

#include "essentials.h"

// O(nlongn), cumulative sum + binary search tree

class Solution {
public:
    int countRangeSum(const std::vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0) return 0;
        int count = 0;
        long long sum = 0;
        for (auto num : nums) {
            sum += num;
            count += BSTCount(sum - lower, tree) - BSTCount(sum - upper - 1, tree);
            BSTAddNode(sum, tree);
        }
        return count;
    }
private:
    struct TreeNode {
        long long val;
        int count; // #nodes less than or equal to val
        TreeNode* left, *right;
        TreeNode(long long val) : val(val), count(1), left(nullptr), right(nullptr) {}
    };
    void BSTAddNode(long long val, TreeNode* node) {
        if (val == node->val) {
            node->count++;
        }
        else if (val < node->val) {
            node->count++;
            if (node->left == nullptr) { node->left = new TreeNode(val); return; }
            else return BSTAddNode(val, node->left);
        }
        else {
            if (node->right == nullptr) { node->right = new TreeNode(val); return; }
            else return BSTAddNode(val, node->right);
        }
    }
    // count #nodes less than or equal to `thres`
    int BSTCount(long long thres, TreeNode* node) {
        int count = 0;
        while (node) {
            if (thres == node->val) { count += node->count; break; }
            else if (thres < node->val) node = node->left;
            else { count += node->count; node = node->right; }
        }
        return count;
    }
    TreeNode* tree = new TreeNode(0);
};

int main() {
    assert(Solution().countRangeSum({-2,5,-1}, -2, 2) == 3);
    assert(Solution().countRangeSum({1,1,1,1,1,1}, 2, 4) == 12);
    assert(Solution().countRangeSum({3,0,-1,-1,-2,1,0}, 0, 3) == 10);
    assert(Solution().countRangeSum({3}, 3, 3) == 1);
    assert(Solution().countRangeSum({3}, 3, 1000000) == 1);
    assert(Solution().countRangeSum({3}, 1, 3) == 1);
    assert(Solution().countRangeSum({3}, -1, 2) == 0);
    assert(Solution().countRangeSum({}, -1, 1) == 0);
    assert(Solution().countRangeSum({2147483647,-2147483648,-1,0,2147483647,2147483647,-2147483647}, -1, 0) == 5);
}

