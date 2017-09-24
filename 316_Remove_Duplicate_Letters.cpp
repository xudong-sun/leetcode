/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

#include "essentials.h"

#define __SOLUTION_2

#ifdef __SOLUTION_1
// greedy algorithm
// find the position where all character exists behind it; then find the smallest char before that position
// 16ms
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

#endif

#ifdef __SOLUTION_2
// same algorithm as above
// we use a heap to record the last position of each character
// 6ms
class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::map<char, size_t> mapping;
        for (size_t i = 0; i < s.size(); i++) mapping[s[i]] = i;
        std::string result = "";
        std::vector<size_t> positions;
        for (auto it = mapping.cbegin(); it != mapping.cend(); it++) positions.push_back(it->second);
        auto comp = [](size_t p1, size_t p2) { return p1 > p2; };
        std::make_heap(positions.begin(), positions.end(), comp);
        auto start_it = s.cbegin();
        while (positions.size() > 0) {
            size_t pos = positions.front();
            std::pop_heap(positions.begin(), positions.end(), comp); positions.pop_back();
            char ch = s[pos];
            if (mapping.find(ch) == mapping.cend()) continue;
            auto end_it  = s.cbegin() + pos + 1;
            while (result.back() != s[pos]) {
                char next_result = 'z' + 1;
                for (auto it = start_it; it != end_it; it++) {
                    if (*it < next_result && mapping.find(*it) != mapping.cend()) {
                        next_result = *it; start_it = it;
                    }
                }
                result += next_result;
                mapping.erase(*(start_it++));
            }
        }
        return result;
    }
};

#endif

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->removeDuplicateLetters("bcabc") == "abc");
	assert(sol->removeDuplicateLetters("cbacdcbc") == "acdb");
	assert(sol->removeDuplicateLetters("abc") == "abc");
	assert(sol->removeDuplicateLetters("ccbaa") == "cba");
	assert(sol->removeDuplicateLetters("zzzzzz") == "z");
	assert(sol->removeDuplicateLetters("") == "");
}
