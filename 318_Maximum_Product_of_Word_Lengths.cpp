/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

#include "essentials.h"

class Solution {
public:
    int maxProduct(const std::vector<std::string>& words) {
        std::vector<Word> temp;
        for (auto word : words) {
            unsigned int code = 0;
            std::for_each(word.cbegin(), word.cend(), [&code](char ch) { code |= 1 << (ch - 'a'); });
            temp.emplace_back(word.size(), code);
        }
        std::sort(temp.begin(), temp.end(), [](const Word& word1, const Word& word2) { return word1.length > word2.length; });
        unsigned int maxValue = 0;
        for (size_t i = 0; i < temp.size(); i++) {
            size_t length1 = temp[i].length;
            for (size_t j = i + 1; j < temp.size(); j++) {
                size_t length2 = temp[j].length;
                if (length1 * length2 <= maxValue) break;
                if ((temp[i].code & temp[j].code) == 0) maxValue = length1 * length2;
            }
        }
        return maxValue;
    }
private:
    struct Word {
        size_t length;
        unsigned int code;
        Word(unsigned int length, unsigned int code) : length(length), code(code) {}
    };
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->maxProduct(std::vector<std::string> { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" }) == 16);
    assert(sol->maxProduct(std::vector<std::string> { "a", "ab", "abc", "d", "cd", "bcd", "abcd" }) == 4);
    assert(sol->maxProduct(std::vector<std::string> { "a", "aa", "aaa", "aaaa" }) == 0);
    assert(sol->maxProduct(std::vector<std::string> { "abc" }) == 0);
    assert(sol->maxProduct(std::vector<std::string>()) == 0);
}
