/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/

#include "essentials.h"

class Solution {
public:
  std::vector<int> findErrorNums(std::vector<int>& nums) {
    std::unordered_set<int> data {};
    int dup, miss;
    for (auto num : nums) {
      if (data.find(num) != data.end()) dup = num;
      data.insert(num);
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (data.find(i) == data.end()) {
        miss = i;
        break;
      }
    }
    return {dup, miss};
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> q {1,2,2,4};
  std::vector<int> ans {2,3};
  assert(sol->findErrorNums(q) == ans);
  q = std::vector<int> {3,5,1,6,5,2};
  ans = std::vector<int> {5,4};
  assert(sol->findErrorNums(q) == ans);
  q = std::vector<int> {1,1};
  ans = std::vector<int> {1,2};
  assert(sol->findErrorNums(q) == ans);
}


