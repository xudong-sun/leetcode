'''
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
'''

# DP, O(n)
class Solution(object):
    def numDecodings(self, s):
        l = len(s)
        if l == 0: return 0
        if s[0] == '0': return 0
        v0, v, pch = 1, 1, s[0]
        for ch in s[1:]:
            v0, v, pch = v, v * (ch != '0') + v0 * (10 <= int(pch + ch) <= 26), ch
        return v

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().numDecodings('12'), 2)
    def test2(self):
        self.assertEqual(Solution().numDecodings('102020'), 1)
    def test3(self):
        self.assertEqual(Solution().numDecodings('412202711'), 4)
    def test4(self):
        self.assertEqual(Solution().numDecodings('1'), 1)
    def test5(self):
        self.assertEqual(Solution().numDecodings('21301'), 0)
    def test6(self):
        self.assertEqual(Solution().numDecodings(''), 0)

if __name__ == '__main__':
    unittest.main()

