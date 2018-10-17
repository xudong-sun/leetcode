"""
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
"""

from collections import defaultdict

class Solution(object):
    def longestPalindrome(self, s):
        count = defaultdict(int)
        for ch in s:
            count[ch] += 1
        includeSingle = False
        total = 0
        for k, v in count.iteritems():
            if v % 2 == 0: total += v
            else:
                total += v - 1
                includeSingle = True
        if includeSingle: total += 1
        return total

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().longestPalindrome("abccccdd"), 7)
    def test2(self):
        self.assertEqual(Solution().longestPalindrome("abaaba"), 6)
    def test3(self):
        self.assertEqual(Solution().longestPalindrome("aaaaa"), 5)
    def test4(self):
        self.assertEqual(Solution().longestPalindrome("z"), 1)
    def test5(self):
        self.assertEqual(Solution().longestPalindrome(""), 0)

if __name__ == "__main__":
    unittest.main()

