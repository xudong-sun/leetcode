/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

#include "essentials.h"

// greedy algorithm.
// find the position where all character exists behind it; then find the smallest char before that position
class Solution {
public:
	std::string removeDuplicateLetters(std::string s) {
		std::map<char, int> mapping;
		for (char ch = 'a'; ch <= 'z'; ch++) mapping[ch] = 0;
		std::for_each(s.cbegin(), s.cend(), [&mapping](char ch) { mapping[ch]++; });
		std::string result = "";
		auto firstit = s.begin(), lastit = s.end();
		char ch = 'z';
		auto chit = s.begin();
		while (firstit != lastit) {
			if (*firstit < ch) {
				ch = *firstit;
				chit = firstit;
			}
			if (--mapping[*firstit++] == 0) {
				result += ch;
				std::for_each(++chit, firstit, [&mapping](char ch){ mapping[ch]++; });
				lastit = std::remove_if(chit, lastit, [ch](char c){ return c == ch; });
				ch = 'z';
				firstit = chit;
			}
		}
		return result;
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->removeDuplicateLetters("bcabc") == "abc");
	assert(sol->removeDuplicateLetters("cbacdcbc") == "acdb");
	assert(sol->removeDuplicateLetters("abc") == "abc");
	assert(sol->removeDuplicateLetters("ccbaa") == "cba");
	assert(sol->removeDuplicateLetters("zzzzzz") == "z");
	assert(sol->removeDuplicateLetters("") == "");
}