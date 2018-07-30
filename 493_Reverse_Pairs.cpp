/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/


#include "essentials.h"

// Solution 1: Binary search tree. Average O(nlogn). Worst O(n^2)
// Solution 2: Binary index tree. O(nlogn)
// Solution 3: Merge sort. Count while merging. O(nlogn)

#define __SOLUTION_3

#ifdef __SOLUTION_1

class Solution {
public:
  int reversePairs(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int ans = 0;
    BSTNode* bst = new BSTNode(nums[0]);
    for (size_t i = 1; i < nums.size(); i++) {
      int num = nums[i];
      if (num < -(1<<30)) ans += i;
      else if (num < (1<<30)) ans += i - BSTQuery(bst, num*2);
      BSTInsert(bst, num);
    }
    return ans;
  }
private:
  struct BSTNode {
    int value, count;
    BSTNode *left, *right;
    BSTNode(int value) : value(value), count(1), left(nullptr), right(nullptr) {}
  };
  // insert value into BST
  void BSTInsert(BSTNode* bst, int value) {
    if (value < bst->value) {
      bst->count++;
      if (bst->left == nullptr) {
        bst->left = new BSTNode(value);
      } else {
        BSTInsert(bst->left, value);
      }
    } else if (value > bst->value) {
      if (bst->right == nullptr) {
        bst->right = new BSTNode(value);
      } else {
        BSTInsert(bst->right, value);
      }
    } else {
      bst->count++;
    }
  }
  // find number of nodes <= value
  int BSTQuery(BSTNode* bst, int value) {
    if (bst == nullptr) return 0;
    if (value == bst->value) return bst->count;
    else if (value < bst->value) return BSTQuery(bst->left, value);
    else return bst->count + BSTQuery(bst->right, value);
  }
};

#endif

#ifdef __SOLUTION_2

class Solution {
public:
  int reversePairs(std::vector<int>& nums) {
    // discretize
    std::map<int, int> index;
    for (auto num: nums) index[num] = 0;
    int n = 1;
    for (auto& p : index) p.second = n++;
    // BIT
    int ans = 0;
    std::vector<int> bit(n, 0);
    for (size_t i = 0; i < nums.size(); i++) {
      int num = nums[i];
      if (num < -(1<<30)) ans += i;
      else if (num < (1<<30)) {
        auto it = index.lower_bound(num*2+1);
        if (it != index.end()) {
          int idx = it->second - 1;
          ans += i - BITQuery(&bit, idx);
        }
      }
      int idx = index.at(num);
      BITInsert(&bit, idx);
    }
    return ans;
  }
private:
  void BITInsert(std::vector<int>* bit, int value) {
    while (value < bit->size()) {
      (bit->at(value))++;
      value += value & -value;
    }
  }
  int BITQuery(std::vector<int>* bit, int value) {
    int res = 0;
    while (value > 0) {
      res += bit->at(value);
      value &= value - 1;
    }
    return res;
  }
};

#endif

#ifdef __SOLUTION_3

class Solution {
public:
  int reversePairs(std::vector<int>& nums) {
    if (nums.size() < 2) return 0;
    size_t m = nums.size() / 2;
    auto mid = nums.begin() + m;
    std::vector<int> left(nums.begin(), mid);
    std::vector<int> right(mid, nums.end());
    int res = reversePairs(left) + reversePairs(right);
    auto p = merge(left, right);
    std::copy(p.first.begin(), p.first.end(), nums.begin());
    return p.second + res;
  }
private:
  std::pair<std::vector<int>, int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    size_t i = 0, j = 0;
    int res = 0;
    while (i < left.size() && j < right.size()) {
      if (right[j] >= -(1<<30)) {
        if (right[j] >= (1<<30)) break;
        while (i < left.size() && left[i] <= right[j] * 2) i++;
      }
      if (i < left.size()) res += left.size() - i;
      j++;
    }
    std::vector<int> merged;
    auto leftit = left.begin(), rightit = right.begin();
    while (leftit != left.end() && rightit != right.end()) {
      if (*leftit < *rightit) merged.push_back(*(leftit++));
      else merged.push_back(*(rightit++));
    }
    while (leftit != left.end()) merged.push_back(*(leftit++));
    while (rightit != right.end()) merged.push_back(*(rightit++));
    return {merged, res};
  }
};

#endif


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums {1,3,2,3,1};
  assert(sol->reversePairs(nums) == 2);
  nums = {2,4,3,5,1};
  assert(sol->reversePairs(nums) == 3);
  nums = {1,-1,4,0,-5,2,-3,-1,0,1};
  assert(sol->reversePairs(nums) == 22);
  nums = {1<<30,INT_MAX,INT_MIN,1<<30,(1<<30)-1,-(1<<30),1,0};
  assert(sol->reversePairs(nums) == 16);
  nums = {0};
  assert(sol->reversePairs(nums) == 0);
  nums = {};
  assert(sol->reversePairs(nums) == 0);
}


