/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/

#include "essentials.h"

class Solution {
public:
  char findTheDifference(std::string s, std::string t) {
    std::unordered_map<char, int> count;
    for (auto ch : t) count[ch]++;
    for (auto ch : s) count[ch]--;
    for (char ch = 'a'; ch <= 'z'; ch++) if (count[ch] > 0) return ch;
  }
};

int main() {
  auto sol = std::make_unique<Solution>();
  assert(sol->findTheDifference("abcd", "abcde") == 'e');
  assert(sol->findTheDifference("aabbc", "bcacab") == 'c');
  assert(sol->findTheDifference("", "x") == 'x');
}



