/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
*/

/*
Hint: find the pattern in terms of bits
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) 
	{
		vector<int> ans;
		ans.push_back(0);
		int total = 1 << n;
		for (int i = 1; i < total; i++)
		{
			int j = 0; while ((i & (1 << j)) == 0) j++;
			ans.push_back(ans.back() ^ (1 << j));
		}
		return ans;
	}
};