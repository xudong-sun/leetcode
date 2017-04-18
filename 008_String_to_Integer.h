/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <string>

using namespace std;

/* standard version
class Solution {
public:
	int myAtoi(string str) 
	{
		size_t pos = str.find_first_not_of(" \n\t\r");
		if (pos == string::npos) return 0;
		bool sign = true;
		if (str[pos] == '-') { sign = false; pos++; }
		else if (str[pos] == '+') pos++;
		int value = 0;
		while (pos < str.size())
		{
			if (str[pos] < '0' || str[pos] > '9') break;
			if (value > INT_MAX / 10) return sign ? INT_MAX : INT_MIN;
			value = value * 10 + str[pos] - '0';
			if (value < 0) return sign ? INT_MAX : INT_MIN;
			pos++;
		}
		return sign ? value : -value;
	}
};
*/

#include <regex>

class Solution
{
public:
	int myAtoi(string str)
	{
		tr1::regex pattern("(\\s*)([+-]?)(\\d*)(\\s*)");
		smatch matcher;
		bool match = regex_match(str, matcher, pattern);
		if (!match) return 0;
		bool sign = matcher[2] == "-" ? false : true;
		int value = 0;
		string digits = matcher[3];
		for (size_t i = 0; i < digits.size(); i++)
		{
			if (value > INT_MAX / 10) return sign ? INT_MAX : INT_MIN;
			value = value * 10 + digits[i] - '0';
			if (value < 0) return sign ? INT_MAX : INT_MIN;
		}
		return sign ? value : -value;
	}
};