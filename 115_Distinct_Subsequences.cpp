/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

#include "essentials.h"


// DP, O(nk), n: length of S; k: length of T
// a[i,j] = #subsequences of S[:i] for T[:j]
// a[i,j] = a[i-1,j] + (s[i-1] == t[j-1]) * a[i-1,j-1]
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int ls = s.length(), lt = t.length();
        std::vector<int> a(ls + 1, 1);
        for (int j = 1; j <= lt; j++) {
            std::vector<int> aa(a);
            a[0] = 0;
            for (int i = 1; i <= ls - (lt - j); i++) {
                a[i] = a[i - 1];
                if (s[i - 1] == t[j - 1]) a[i] += aa[i - 1];
            }
        }
        return a[ls];
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    assert(sol->numDistinct("rabbbit", "rabbit") == 3);
    assert(sol->numDistinct("abcdabca", "aca") == 4);
    assert(sol->numDistinct("aaaaa", "aaa") == 10);
    assert(sol->numDistinct("ab", "abb") == 0);
    assert(sol->numDistinct("abcde", "") == 1);
    assert(sol->numDistinct("", "") == 1);
}

