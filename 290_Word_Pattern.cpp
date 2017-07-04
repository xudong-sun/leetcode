/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

#include "essentials.h"

class Solution {
public:
	bool wordPattern(std::string pattern, std::string str) {
		std::stringstream ss;
		ss << str;
		std::unordered_map<char, std::string> mapping;
		std::unordered_set<std::string> words;
		std::string s;
		for (auto ch : pattern) {
			if (!(ss >> s)) return false;
			if (mapping.find(ch) == mapping.end()) {
				if (words.find(s) != words.end()) return false;
				words.insert(s);
				mapping[ch] = s;
			}
			else {
				if (mapping[ch] != s) return false;
			}
		}
		if (ss >> s) return false;
		return true;
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->wordPattern("abba", "cat dog dog cat"));
	assert(!sol->wordPattern("abba", "cat dog dog fish"));
	assert(!sol->wordPattern("aaaa", "cat dog dog cat"));
	assert(!sol->wordPattern("abba", "dog dog dog dog"));
	assert(!sol->wordPattern("abb", "cat dog dog cat"));
	assert(!sol->wordPattern("abba", "cat dog dog"));
}