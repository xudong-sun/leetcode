/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include "essentials.h"
#define MAX_NUM_CONVERSION_TABLE 13
using namespace std;

class Solution {
public:
	string intToRoman(int num) 
	{
		return intToRoman(num, 0);
	}
private:
	struct RomanConversionTable
	{
		string symbol;
		int num;
	};
	static const RomanConversionTable roman_table[MAX_NUM_CONVERSION_TABLE];
	string intToRoman(int num, int level)
	{
		for (int i = level; i < MAX_NUM_CONVERSION_TABLE; i++)
		{
			if (num >= roman_table[i].num) return roman_table[i].symbol + intToRoman(num - roman_table[i].num, i);
		}
		return "";
	}
};
const Solution::RomanConversionTable Solution::roman_table[MAX_NUM_CONVERSION_TABLE] = { { "M", 1000 }, { "CM", 900 }, { "D", 500 }, { "CD", 400 }, { "C", 100 }, { "XC", 90 }, { "L", 50 }, { "XL", 40 }, { "X", 10 }, { "IX", 9 }, { "V", 5 }, { "IV", 4 }, { "I", 1 } };

int main() {
	Solution* sol = new Solution();
	std::cout << sol->intToRoman(1234) << std::endl;
	pause();
}
