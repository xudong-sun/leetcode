/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


#include "essentials.h"

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::unordered_map<char, size_t> pmap;
        std::for_each(p.cbegin(), p.cend(), [&pmap](char ch) { pmap[ch]++; });
        size_t i = 0, j = 0;
        std::unordered_map<char, std::list<size_t>> smap;
        std::vector<int> res;
        while (j < s.size()) {
            char ch = s[j];
            auto& l = smap[ch];
            l.push_back(j++);
            if (l.size() > pmap[ch]) {
                while (i < l.front()) smap[s[i++]].pop_front();
                l.pop_front(); i++;
            }
            if (j - i == p.size()) res.push_back(i);
        }
        return res;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    commons::print(sol->findAnagrams("cbaebabacd", "abc")); // [0,6]
    commons::print(sol->findAnagrams("abab", "ab")); // [0,1,2]
    commons::print(sol->findAnagrams("abbaabaab", "abab")); // [0,1,2,5]
    commons::print(sol->findAnagrams("abcdefg", "abd")); // []
    commons::print(sol->findAnagrams("", "abc")); // []
    std::string s(10000, 'a');
    commons::print(sol->findAnagrams(s + s, s).size()); // 10001
}

