/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <string>
#define MAX_NUM_ROMAN_SYMBOL 7
using namespace std;

class Solution {
public:
	int romanToInt(string s) 
	{
		return romanToInt(s, 0);
	}

private:
	struct RomanTable
	{
		char symbol;
		int num;
	};
	static const RomanTable roman_table[MAX_NUM_ROMAN_SYMBOL]; 

	int romanToInt(string s, int level)
	{
		if (s == "") return 0;
		for (int i = level; i < MAX_NUM_ROMAN_SYMBOL; i++)
		{
			size_t z = s.find_first_of(roman_table[i].symbol);
			if (z != string::npos) return roman_table[i].num - romanToInt(s.substr(0, z), i) + romanToInt(s.substr(z + 1));
		}
		return 0;
	}
};
const Solution::RomanTable Solution::roman_table[7] = { { 'M', 1000 }, { 'D', 500 }, { 'C', 100 }, { 'L', 50 }, { 'X', 10 }, { 'V', 5 }, { 'I', 1 } };
