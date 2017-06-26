/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

#include "essentials.h"

// O(logn) binary search

class Solution {
public:
	int hIndex(std::vector<int>& citations) {
		return searchAns(citations, 0, citations.size());
	}
private:
	int searchAns(std::vector<int>& citations, int x, int y) {
		if (x == y) return x;
		int m = (x + y + 1) / 2;
		if (citations[citations.size() - m] >= m) return searchAns(citations, m, y);
		else return searchAns(citations, x, m - 1);
	}
};

int main() {
	auto sol = new Solution();
	assert(sol->hIndex(std::vector < int > {0, 1, 3, 5, 6}) == 3);
	assert(sol->hIndex(std::vector < int > {0, 3, 3, 5, 6}) == 3);
	assert(sol->hIndex(std::vector < int > {0, 0, 0, 0, 0, 0}) == 0);
	assert(sol->hIndex(std::vector < int > {5, 6, 7, 8, 9}) == 5);
	assert(sol->hIndex(std::vector<int>()) == 0);
}