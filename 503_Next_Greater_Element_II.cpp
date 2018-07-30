/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
*/

#include "essentials.h"

// Stack, O(n)
// Elements in stack: small -> large -> small
// Elements are pushed and popped at the front
class Solution {
public:
  std::vector<int> nextGreaterElements(std::vector<int>& nums) {
    if (nums.size() == 0) return {};
    std::vector<int> ans(nums.size(), INT_MIN);
    std::deque<std::pair<int, int>> deque {{nums.size()-1, nums[nums.size()-1]}};
    for (int i = nums.size()-2; i >= 0; i--) {
      int num = nums[i];
      // pop out all the elements smaller than num
      while (deque.size() > 1 && deque[0].second < num && ans[deque[0].first] != INT_MIN) deque.pop_front();
      // find the first element in stack larger than num
      int j = 0;
      while (j < deque.size() && deque[j].second == num) j++;
      if (j < deque.size() && deque[j].second > num) ans[i] = deque[j].second;
      // push num to the front of stack
      deque.push_front({i, num});
    }
    // now find the missing entries (since it is circular)
    int j = 0, k = deque.size()-1;
    while (ans[deque[k].first] == INT_MIN && j < k) {
      if (deque[j].second <= deque[k].second) j++;
      else {
        ans[deque[k].first] = deque[j].second;
        k--;
      }
    }
    // assign -1
    while (k >= 0 && ans[deque[k].first] == INT_MIN) ans[deque[k--].first] = -1;
    return ans;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> nums {1,2,1}, ans {2,-1,2};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {5,8,6,8,2,3,6};
  ans = {8,-1,8,-1,3,6,8};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {4,4,4,4,4};
  ans = {-1,-1,-1,-1,-1};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {3,2,2,2,5,2,2};
  ans = {5,5,5,5,-1,3,3};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {1,2,3,4,5,6,7};
  ans = {2,3,4,5,6,7,-1};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {7,6,5,4,3,2,1};
  ans = {-1,7,7,7,7,7,7};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {1};
  ans = {-1};
  assert(sol->nextGreaterElements(nums) == ans);
  nums = {};
  ans = {};
  assert(sol->nextGreaterElements(nums) == ans);
}


