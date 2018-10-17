"""
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
"""

class Solution(object):
    def isPalindrome(self, s):
        l = len(s)
        for i in xrange(l/2):
            if s[i] != s[l-i-1]: return False
        return True
    def validPalindrome(self, s):
        l = len(s)
        for i in xrange(l/2):
            if s[i] != s[l-i-1]:
                return self.isPalindrome(s[(i+1):(l-i)]) or self.isPalindrome(s[i:(l-i-1)])
        return True

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertTrue(Solution().validPalindrome("aba"))
    def test2(self):
        self.assertTrue(Solution().validPalindrome("abba"))
    def test3(self):
        self.assertTrue(Solution().validPalindrome("abca"))
    def test4(self):
        self.assertFalse(Solution().validPalindrome("abcda"))
    def test5(self):
        self.assertTrue(Solution().validPalindrome("abccb"))
    def test6(self):
        self.assertTrue(Solution().validPalindrome("abcbbcbca"))
    def test7(self):
        self.assertFalse(Solution().validPalindrome("aabab"))
    def test8(self):
        self.assertTrue(Solution().validPalindrome("z"))
    def test9(self):
        self.assertTrue(Solution().validPalindrome(""))

if __name__ == "__main__":
    unittest.main()

