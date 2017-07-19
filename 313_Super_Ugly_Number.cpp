/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

#include "essentials.h"

// checkout 264_Ugly_Number_II
// use the k-pointers solution. O(nk)
// the heap solution (building a heap of size k) has O(n k logk), since most of the times, k numbers are popped in/out of the heap

class Solution {
public:
	int nthSuperUglyNumber(int n, std::vector<int>& primes) {
		size_t k = primes.size();
		std::vector<int> x(k, 0);
		std::vector<int> ugly{ 1 };
		for (int z = 1; z < n; z++) {
			int u = INT_MAX;
			for (size_t i = 0; i < k; i++) {
				if (ugly[x[i]] * primes[i] == ugly.back()) x[i]++;
				u = std::min(u, ugly[x[i]] * primes[i]);
			}
			ugly.push_back(u);
		}
		return ugly.back();
	}
};

int main() {
	auto sol = std::make_unique<Solution>();
	assert(sol->nthSuperUglyNumber(12, std::vector < int > {2, 7, 13, 19}) == 32);
	assert(sol->nthSuperUglyNumber(10, std::vector < int > {2}) == 512);
	assert(sol->nthSuperUglyNumber(10, std::vector < int > {3, 5, 7, 13, 17, 19, 29, 31, 37, 41, 47, 59, 71, 73, 79, 83, 97, 127, 131, 137}) == 21);
}