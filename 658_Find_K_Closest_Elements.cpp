/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^4
Absolute value of elements in the array and x will not exceed 10^4
*/

#include "essentials.h"

class Solution {
public:
  std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    auto pos = std::lower_bound(arr.begin(), arr.end(), x);
    bool reach_head = false, reach_tail = false;
    auto prev = pos;
    if (pos == arr.begin()) reach_head = true;
    else prev--;
    while (k > 0) {
      if (reach_head) pos++;
      else if (reach_tail) prev--;
      else {
        if (x - *prev <= *pos - x) {
          if (prev == arr.begin()) reach_head = true;
          else prev--;
        }
        else {
          pos++;
          if (pos == arr.end()) reach_tail = true;
        }
      }
      k--;
    }
    if (reach_head == false) prev++;
    std::vector<int> result;
    std::copy(prev, pos, std::back_inserter(result));
    return result;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> arr = {1,2,3,4,5};
  std::vector<int> ans = {1,2,3,4};
  assert(sol->findClosestElements(arr, 4, 3) == ans);
  assert(sol->findClosestElements(arr, 4, -1) == ans);
  arr = {1,2,3,3,3,4,4,5};
  ans = {3,3,3};
  assert(sol->findClosestElements(arr, 3, 3) == ans);
  ans = {2,3,3,3,4};
  assert(sol->findClosestElements(arr, 5, 3) == ans);
  ans = {1,2,3,3,3,4,4,5};
  assert(sol->findClosestElements(arr, 8, 3) == ans);
}

