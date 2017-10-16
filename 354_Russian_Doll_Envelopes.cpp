/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

#include "essentials.h"

// similar to 300_Longest_Increasing_Subsequence
class Solution {
public:
    int maxEnvelopes(std::vector<std::pair<int, int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(),
            [] (std::pair<int, int> x1, std::pair<int, int> x2) {
              return x1.first < x2.first || 
              (x1.first == x2.first && x1.second > x2.second);
            });
        std::vector<int> heights;
        for (auto envelope : envelopes) {
            int h = envelope.second;
            size_t pos = binSearch(heights, h);
            if (pos == heights.size()) heights.push_back(h);
            else heights[pos] = h;
        }
        return heights.size();
    }
private:
    // bin-search; if val not found, return the index where it should be
    size_t binSearch(const std::vector<int>& heights, int val) {
        size_t x = 0, y = heights.size();
        while (x < y) {
            size_t m = (x + y) / 2;
            if (heights[m] == val) return m;
            else if (heights[m] < val) x = m + 1;
            else y = m;
        }
        return x;
    }
};

int main() {
    auto sol = std::make_unique<Solution>();
    std::vector<std::pair<int, int>> envelopes {{5,4},{6,4},{6,7},{2,3}};
    assert(sol->maxEnvelopes(envelopes) == 3);
    envelopes.clear();
    envelopes.insert(envelopes.cend(), {{1,1},{1,2},{1,3},{2,1},{3,1}});
    assert(sol->maxEnvelopes(envelopes) == 1);
    envelopes.clear();
    assert(sol->maxEnvelopes(envelopes) == 0);
}
