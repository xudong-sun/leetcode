/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Word
{
	unsigned int length;
	unsigned int code;
};

bool wordCompare(Word word1, Word word2)
{
	return word1.length > word2.length ? true : false;
}

class Solution {
public:
	int maxProduct(vector<string>& words) 
	{
		vector<Word> temp;
		for (size_t i = 0; i < words.size(); i++)
		{
			Word word;
			string thisWord = words[i];
			word.length = thisWord.length();
			word.code = 0;
			for (size_t i = 0; i < word.length; i++) word.code |= 1 << (thisWord[i] - 'a');
			temp.push_back(word);
		}
		sort(temp.begin(), temp.end(), wordCompare);
		int maxValue = 0;
		for (size_t i = 0; i < temp.size(); i++)
		{
			int length1 = temp[i].length;
			for (size_t j = 0; j < temp.size(); j++)
			{
				int length2 = temp[j].length;
				if (length1*length2 <= maxValue) break;
				if ((temp[i].code & temp[j].code) == 0) maxValue = length1*length2;
			}
		}
		return maxValue;
	}
	
};
