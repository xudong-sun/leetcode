/*
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.



Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
*/


#include "essentials.h"

using LetterCount = std::unordered_map<char, int>;

class Solution {
public:
  std::vector<std::string> wordSubsets(const std::vector<std::string>& words1, const std::vector<std::string>& words2) {
    LetterCount common_subset;
    for (const auto& word : words2) {
      auto c = GetLetterCount(word);
      for (const auto& p : c) {
        char letter = p.first;
        int count = p.second;
        if (count > common_subset[letter]) {
          common_subset[letter] = count;
        }
      }
    }
    std::vector<std::string> ans;
    for (const auto& word : words1) {
      auto c = GetLetterCount(word);
      bool flag = true;
      for (const auto& p : common_subset) {
        char letter = p.first;
        int count = p.second;
        if (count > c[letter]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans.push_back(word);
      }
    }
    return ans;
  }
private:
  LetterCount GetLetterCount(const std::string& word) {
    LetterCount c;
    for (auto ch : word) {
      c[ch] += 1;
    }
    return c;
  }
};


int main() {
  auto sol = std::make_unique<Solution>();
  std::vector<std::string> words1 = {"amazon","apple","facebook","google","leetcode"};
  std::vector<std::string> words2 = {"e","o"};
  commons::print(sol->wordSubsets(words1, words2)); // ["facebook","google","leetcode"]
}

