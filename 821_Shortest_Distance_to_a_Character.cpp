/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]


Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/

#include "essentials.h"

class Solution {
public:
  std::vector<int> shortestToChar(std::string S, char C) {
    std::vector<int> pos;
    for (size_t i = 0; i < S.size(); i++) {
      if (S[i] == C) pos.push_back(i);
    }
    std::vector<int> result;
    for (int i = 0; i <= pos[0]; i++) result.push_back(pos[0] - i);
    for (size_t j = 1; j < pos.size(); j++) {
      int mid = (pos[j-1] + pos[j]) / 2;
      for (int i = pos[j-1]+1; i <= mid; i++) result.push_back(i - pos[j-1]);
      for (int i = mid+1; i <= pos[j]; i++) result.push_back(pos[j] - i);
    }
    int j = pos.size() - 1;
    for (size_t i = pos[j]+1; i < S.size(); i++) result.push_back(i - pos[j]);
    return result;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<int> ans = {3,2,1,0,1,0,0,1,2,2,1,0};
  assert(sol->shortestToChar("loveleetcode", 'e') == ans);
  ans = {0};
  assert(sol->shortestToChar("a", 'a') == ans);
}

