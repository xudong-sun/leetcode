/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
*/

#include "essentials.h"

// similar to 300_Longest_Increasing_Subsequence
class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end());
        std::vector<int> right_end;
        for (auto pair : pairs) {
            size_t pos = binSearch(right_end, pair[1]);
            if (pos == 0 || right_end[pos-1] < pair[0]) {
                if (pos == right_end.size()) right_end.push_back(pair[1]);
                else right_end[pos] = pair[1];
            }
        }
        return right_end.size();
    }
private:
    size_t binSearch(const std::vector<int>& v, int val) {
        size_t x = 0, y = v.size();
        while (x < y) {
            size_t m = (x + y) / 2;
            if (v[m] == val) return m;
            else if (v[m] < val) x = m + 1;
            else y = m;
        }
        return x;
    }
};


int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<std::vector<int>> pairs {{1,2},{2,3},{3,4}};
    assert(sol->findLongestChain(pairs) == 2);
    pairs.clear();
    pairs.insert(pairs.cend(), {{1,1},{1,2},{1,3}});
    assert(sol->findLongestChain(pairs) == 1);
    pairs.clear();
    assert(sol->findLongestChain(pairs) == 0);
}
