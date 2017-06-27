/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

#include "essentials.h"

bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int l = 1, r = n;
		while (l < r) {
			int m = l + ((r - l) >> 1);
			if (isBadVersion(m)) r = m;
			else l = m + 1;
		}
		return l;
	}
};

bool isBadVersion(int version) {
	return version >= 1702766719;
}
int main() {
	auto sol = new Solution();
	assert(sol->firstBadVersion(2126753390) == 1702766719);
	delete sol;
}