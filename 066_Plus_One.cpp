/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include "essentials.h"

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits) 
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

int main() {
	Solution* sol = new Solution();
	std::cout << sol->plusOne(std::vector < int > {1, 9, 9}) << std::endl;
	commons::pause();
	delete sol;
}