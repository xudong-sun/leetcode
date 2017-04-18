/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) 
	{
		int n = digits.size();
		digits[n - 1]++;
		for (int i = n - 1; i > 0; i--)
		{
			if (digits[i] <= 9) break;
			digits[i] -= 10; digits[i - 1]++;
		}
		if (digits[0] == 10)
		{
			digits.push_back(0);
			digits[0] = 1;
			for (int i = 1; i <= n; i++) digits[i] = 0;
		}
		return digits;
	}
};