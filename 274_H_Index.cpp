/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N - h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

#include "essentials.h"

// an immediate solution would be sort with O(nlogn)
// but we can use bucket sort, and reduce complexity to O(n)

class Solution {
public:
	int hIndex(std::vector<int>& citations) {
		int n = citations.size();
		std::vector<int> buckets(n + 1, 0);
		for (const int x : citations) buckets[std::min(x, n)]++;
		int cnt = buckets[n], h = n;
		while (cnt < h) cnt += buckets[--h];
		return h;
	}
};

int main() {
	auto sol = new Solution();
	assert(sol->hIndex(std::vector < int > {3, 0, 6, 1, 5}) == 3);
	assert(sol->hIndex(std::vector < int > {3, 0, 6, 3, 5}) == 3);
	assert(sol->hIndex(std::vector < int > {0, 0, 0, 0, 0, 0}) == 0);
	assert(sol->hIndex(std::vector<int>()) == 0);
}