'''
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
'''


class Solution(object):
    def isIsomorphic(self, s, t):
        mapping = {}
        mapping_values = set()
        for c1, c2 in zip(s, t):
            if c1 in mapping:
                if mapping[c1] != c2: return False
            else:
                if c2 in mapping_values: return False
                mapping[c1] = c2
                mapping_values.add(c2)
        return True

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertTrue(Solution().isIsomorphic('egg', 'add'))
    def test2(self):
        self.assertFalse(Solution().isIsomorphic('foo', 'bar'))
    def test3(self):
        self.assertTrue(Solution().isIsomorphic('paper', 'title'))
    def test4(self):
        self.assertFalse(Solution().isIsomorphic('abc', 'add'))
    def test5(self):
        self.assertTrue(Solution().isIsomorphic('abcd', 'abcd'))
    def test6(self):
        self.assertTrue(Solution().isIsomorphic('', ''))

if __name__ == '__main__':
    unittest.main()

