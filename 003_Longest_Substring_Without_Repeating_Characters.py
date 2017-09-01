'''
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''

# two pointers, O(N)
# [improved] use a map instead of a set
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        maxl = 0
        chars = {}
        i = j = 0
        lens = len(s)
        while j < lens:
            c = s[j]
            if c not in chars or chars[c] < i:
                chars[c] = j
            else:
                if j - i > maxl: maxl = j - i
                # the map records where each char is, so `i` can now directly jump there
                i, chars[c] = chars[c] + 1, j
            j += 1
        if j - i > maxl: maxl = j - i
        return maxl

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().lengthOfLongestSubstring('abcabcbb'), 3)
    def test2(self):
        self.assertEqual(Solution().lengthOfLongestSubstring('bbbbb'), 1)
    def test3(self):
        self.assertEqual(Solution().lengthOfLongestSubstring('pwwkew'), 3)
    def test4(self):
        self.assertEqual(Solution().lengthOfLongestSubstring('aabcdef'), 6)
    def test5(self):
        self.assertEqual(Solution().lengthOfLongestSubstring(''), 0)
    def test6(self):
        self.assertEqual(Solution().lengthOfLongestSubstring('abba'), 2)

if __name__ == '__main__':
    unittest.main()
