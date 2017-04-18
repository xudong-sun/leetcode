/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

#include <string>
using namespace std;
class Solution {
public:
	int compareVersion(string version1, string version2) 
	{
		while (true)
		{
			size_t index1 = version1.find(".");
			size_t index2 = version2.find(".");
			if (index1 == string::npos && index2 == string::npos)
			{
				int value1 = string2int(version1);
				int value2 = string2int(version2);
				return value1 == value2 ? 0 : (value1 > value2 ? 1 : -1);
			}
			else
			{
				int value1 = index1 == string::npos ? string2int(version1) : string2int(version1.substr(0, index1));
				int value2 = index2 == string::npos ? string2int(version2) : string2int(version2.substr(0, index2));
				if (value1 > value2) return 1; else if (value1 < value2) return -1;
				if (index1 == string::npos) version1 = ""; else version1.erase(0, index1 + 1);
				if (index2 == string::npos) version2 = ""; else version2.erase(0, index2 + 1);
			}
		}
	}
private:
	int string2int(string string)
	{
		int value = 0;
		for (size_t i = 0; i < string.size(); i++) value = value * 10 + string[i] - '0';
		return value;
	}
};