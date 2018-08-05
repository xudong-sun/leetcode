/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
*/


#include "essentials.h"

class Solution {
public:
  std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
    if (k == 1) return std::vector<double>(nums.begin(), nums.end());
    BSTNode* tree = new BSTNode(nums[0]);
    for (int i = 1; i < k; i++) BSTUpdate(tree, nums[i], 1);
    std::vector<double> result;
    size_t i = k, j = 0;
    while (true) {
      if (k % 2 == 1) result.push_back(BSTFindKth(tree, (k+1)/2));
      else {
        long long val1 = BSTFindKth(tree, k/2), val2 = BSTFindKth(tree, k/2+1);
        result.push_back((val1 + val2) * 0.5);
      }
      if (i == nums.size()) break;
      BSTUpdate(tree, nums[i++], 1);
      BSTUpdate(tree, nums[j++], -1);
    }
    return result;
  }
private:
  struct BSTNode {
    int value, count, selfcount;
    BSTNode *left, *right;
    BSTNode(int value) : value(value), count(1), selfcount(1), left(nullptr), right(nullptr) {}
  };
  void BSTUpdate(BSTNode* node, int x, int v) {
    if (x < node->value) {
      node->count += v;
      if (node->left == nullptr) node->left = new BSTNode(x);
      else BSTUpdate(node->left, x, v);
    } else if (x > node->value) {
      if (node->right == nullptr) node->right = new BSTNode(x);
      else BSTUpdate(node->right, x, v);
    } else {
      node->count += v;
      node->selfcount += v;
    }
  }
  int BSTFindKth(BSTNode* node, int k) {
    if (node->count < k) return BSTFindKth(node->right, k - node->count);
    else {
      if (node->count - node->selfcount < k) return node->value;
      else return BSTFindKth(node->left, k);
    }
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
  std::vector<double> ans = {1,-1,-1,3,5,6};
  assert(sol->medianSlidingWindow(nums, 3) == ans);
  ans = {0,1,1,4,5.5};
  assert(sol->medianSlidingWindow(nums, 4) == ans);
  ans = {1,3,-1,-3,5,3,6,7};
  assert(sol->medianSlidingWindow(nums, 1) == ans);
  ans = {3};
  assert(sol->medianSlidingWindow(nums, 8) == ans);
  ans = {2,3,4};
  assert(sol->medianSlidingWindow(nums, 6) == ans);
}

