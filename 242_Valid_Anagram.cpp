/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include "essentials.h"

class Solution {
public:
	bool isAnagram(std::string s, std::string t) {
		if (s.size() != t.size()) return false;
		auto set = std::unordered_multiset < char >();
		for (auto ch : s) set.insert(ch);
		for (auto ch : t) {
			auto pos = set.find(ch);
			if (pos == set.end()) return false;
			set.erase(pos);
		}
		return true;
	}
};

int main() {
	auto sol = new Solution();
	assert(sol->isAnagram("anagram", "nagaram"));
	assert(!sol->isAnagram("rat", "car"));
	assert(sol->isAnagram("", ""));
	assert(!sol->isAnagram("", "a"));
	delete sol;
	commons::pause();
}