/*
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/

#include "essentials.h"

// greedy, rule based
class Solution {
public:
  bool isPossible(std::vector<int>& nums) {
    std::deque<int> deq;
    int prev_num = 0, ptr = -1;
    for (auto num : nums) {
      if (num == prev_num) {
        if (ptr == -1) deq.push_back(1);
        else deq[ptr--]++;
      } else if (num == prev_num + 1) {
        if (ptr != -1) {
          if (deq[ptr] < 3) return false;
          for (int i = 0; i <= ptr; i++) deq.pop_front();
        }
        ptr = deq.size() - 1;
        std::sort(deq.rbegin(), deq.rend());
        if (ptr == -1) deq.push_back(1);
        else deq[ptr--]++;
        prev_num = num;
      } else {
        if (deq.size() > 0 && deq.back() < 3) return false;
        deq = {1};
        ptr = -1;
        prev_num = num;
      }
    }
    if (deq.size() > 0 && deq.back() < 3) return false;
    return true;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> arr = {1,2,3,3,4,5};
  assert(sol->isPossible(arr) == true);
  arr = {1,2,3,4,4,5};
  assert(sol->isPossible(arr) == false);
  arr = {1,2,3,5,6,7};
  assert(sol->isPossible(arr) == true);
  arr = {-1,0,1,2,7,8,9};
  assert(sol->isPossible(arr) == true);
  arr = {1,1,1,2,2,2,3,3,3,4};
  assert(sol->isPossible(arr) == true);
  arr = {1,1,2,2,2,2,3,3,3,3,4,4};
  assert(sol->isPossible(arr) == true);
  arr = {1,1,2,2,2,2,3,3,3,4,4,4};
  assert(sol->isPossible(arr) == false);
  arr = {0,0,0,0,1,1,1,1,2,2,2,2};
  assert(sol->isPossible(arr) == true);
  arr = {0,1,1,2,2,2,3,3,3,4,4,5};
  assert(sol->isPossible(arr) == true);
  arr = {0};
  assert(sol->isPossible(arr) == false);
}

