/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-10^5 <= value of elements <= 10^5.
*/

#include "essentials.h"

class Solution {
public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
    std::vector<std::pair<int, int>> init;
    std::vector<size_t> pointers;
    int max = -100000;
    for (int i = 0; i < nums.size(); i++) {
      init.push_back({-nums[i][0], i});
      if (nums[i][0] > max) max = nums[i][0];
      pointers.push_back(0);
    }
    std::priority_queue<std::pair<int, int>> heap(init.begin(), init.end());
    int range = max + heap.top().first;
    std::vector<int> result = {-heap.top().first, max};
    while (true) {
      int x = heap.top().second;
      heap.pop();
      if (++pointers[x] == nums[x].size()) break;
      int value = nums[x][pointers[x]];
      if (value > max) max = value;
      heap.push({-value, x});
      int min = -heap.top().first;
      if (max - min < range) {
        range = max - min;
        result = {min, max};
      }
    }
    return result;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
  std::vector<int> ans = {20,24};
  assert(sol->smallestRange(nums) == ans);
  nums = {{1,11},{2,12},{3,13,14}};
  ans = {1,3};
  assert(sol->smallestRange(nums) == ans);
  nums = {{-10000,0,1},{-100,10000}};
  ans = {-100,0};
  assert(sol->smallestRange(nums) == ans);
  nums = {{-3,-1,0,1}};
  ans = {-3,-3};
  assert(sol->smallestRange(nums) == ans);
}

