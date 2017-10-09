/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/


#include "essentials.h"

// similar to 072_Edit_Distance, DP, O(mn)
// a[i,j] = min steps for word1[:i] and word2[:j]
// a[i,j] = word1[i-1] == word2[j-1] ? min{a[i-1,j] + 1, a[i,j-1] + 1, a[i-1,j-1]} : ...
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        size_t m = word1.size(), n = word2.size();
        std::vector<int> step(n+1, 0);
        iota(step.begin(), step.end(), 0);
        for (size_t i = 1; i <= m; i++) {    
            std::vector<int> step0(step.cbegin(), step.cend());
            step[0]++;
            for (size_t j = 1; j <= n; j++)
                if (word1[i-1] == word2[j-1]) step[j] = std::min({step0[j] + 1, step[j-1] + 1, step0[j-1]});
                else step[j] = std::min(step0[j] + 1, step[j-1] + 1);
        }
        return step[n];
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->minDistance("sea", "eat") == 2);
    assert(sol->minDistance("aaaaa", "aaaa") == 1);
    assert(sol->minDistance("aaaa", "aaaaa") == 1);
    assert(sol->minDistance("abcde", "xyz") == 8);
    assert(sol->minDistance("abcd", "dcba") == 6);
    assert(sol->minDistance("abab", "baba") == 2);
    assert(sol->minDistance("abc", "bfc") == 2);
    assert(sol->minDistance("aasa", "aasa") == 0);
    assert(sol->minDistance("", "abc") == 3);
    assert(sol->minDistance("abc", "") == 3);
}

